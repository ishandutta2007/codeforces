#include <iostream>

using namespace std;

bool statue[25][25];
bool good[9][9][9];
int xmove[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int ymove[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int main()
{
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 25; j++)
            statue[i][j] = false;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            for (int k = 0; k < 9; k++)
                good[i][j][k] = false;
    good[0][1][1] = true;
    for (int i = 8; i >= 1; i--)
        for (int j = 1; j <= 8; j++)
        {
            char ch; cin >> ch;
            if (ch == 'S') statue[j][i] = true;
        }
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            for (int k = 1; k <= 8; k++)
            {
                bool check = false;
                for (int l = 0; l < 9; l++)
                    check |= good[i-1][j+xmove[l]][k+ymove[l]];
                good[i][j][k] = check && !statue[j][k+i-1] && !statue[j][k+i];
            }
    bool found = false;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            found |= good[8][i][j];
    cout << (found ? "WIN" : "LOSE") << "\n";
    //system ("Pause");
    return 0;
}