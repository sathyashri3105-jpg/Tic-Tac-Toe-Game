
#include <iostream>
using namespace std;

class TicTacToe
{
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe()
    {
        currentPlayer = 'X';

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = ' ';
            }
        }
    }

    void displayBoard()
    {
        cout << "\n";
        cout << "     TIC TAC TOE GAME\n\n";

        for (int i = 0; i < 3; i++)
        {
            cout << " ";
            for (int j = 0; j < 3; j++)
            {
                cout << " " << board[i][j] << " ";
                if (j < 2)
                    cout << "|";
            }

            cout << "\n";

            if (i < 2)
                cout << "   ---+---+---\n";
        }

        cout << "\n";
    }

    bool makeMove(int row, int col)
    {
        if (row < 1 || row > 3 || col < 1 || col > 3)
        {
            cout << "Invalid position! Choose between 1 and 3.\n";
            return false;
        }

        if (board[row - 1][col - 1] != ' ')
        {
            cout << "This position is already occupied! Try again.\n";
            return false;
        }

        board[row - 1][col - 1] = currentPlayer;
        return true;
    }

    bool checkWin()
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == currentPlayer &&
                board[i][1] == currentPlayer &&
                board[i][2] == currentPlayer)
                return true;

            if (board[0][i] == currentPlayer &&
                board[1][i] == currentPlayer &&
                board[2][i] == currentPlayer)
                return true;
        }

        if (board[0][0] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][2] == currentPlayer)
            return true;

        if (board[0][2] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][0] == currentPlayer)
            return true;

        return false;
    }

    bool checkDraw()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                    return false;
            }
        }

        return true;
    }

    void switchPlayer()
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void playGame()
    {
        int row, col;

        cout << "Welcome to Tic Tac Toe!\n";
        cout << "Player 1: X\n";
        cout << "Player 2: O\n";

        while (true)
        {
            displayBoard();

            cout << "Player " << currentPlayer << "'s turn\n";
            cout << "Enter row (1-3): ";
            cin >> row;

            cout << "Enter column (1-3): ";
            cin >> col;

            if (!makeMove(row, col))
                continue;

            if (checkWin())
            {
                displayBoard();
                cout << "Congratulations! Player "
                     << currentPlayer << " wins!\n";
                break;
            }

            if (checkDraw())
            {
                displayBoard();
                cout << "The game is a draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main()
{
    TicTacToe game;
    game.playGame();

    return 0;
}
