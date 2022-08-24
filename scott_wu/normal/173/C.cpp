#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAXN = 510;

int n, m;
int board[MAXN][MAXN];
int rps[MAXN][MAXN];
int cps[MAXN][MAXN];
int b3[3][3] = 
{{1, 1, 1},
{0, 0, 1},
{1, 1, 1}};
int b5[5][5] = 
{{1, 1, 1, 1, 1},
{0, 0, 0, 0, 1},
{1, 1, 1, 0, 1},
{1, 0, 0, 0, 1},
{1, 1, 1, 1, 1}};

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    for (int i = 0; i < n; i++)
    {
        rps[i][0] = 0;
        for (int j = 0; j < m; j++)
            rps[i][j+1] = rps[i][j] + board[i][j];
    }
    for (int i = 0; i < m; i++)
    {
        cps[0][i] = 0;
        for (int j = 0; j < n; j++)
            cps[j+1][i] = cps[j][i] + board[j][i];
    }
    int ans = -100000;
    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < m - 1; j++)
        {
            int hi = min (min (i, j), min (n - 1 - i, m - 1 - j)) * 2 + 1;
            int l4 = 0, l2 = 0;
            for (int k = 3; k <= hi; k+=2)
            {
                int res = 0;
                if (k <= 5)
                {
                    if (k == 3)
                    {
                        for (int i1 = i - 1; i1 <= i + 1; i1++)
                            for (int j1 = j - 1; j1 <= j + 1; j1++)
                                res += b3[i1-i+1][j1-j+1] * board[i1][j1];
                    }
                    if (k == 5)
                    {
                        for (int i1 = i - 2; i1 <= i + 2; i1++)
                            for (int j1 = j - 2; j1 <= j + 2; j1++)
                                res += b5[i1-i+2][j1-j+2] * board[i1][j1];
                    }
                }
                else
                {
                    res = l4;
                    int t = k/2 - 2;
                    res += board[i-t][j-t-1];
                    res += cps[i+t+2][j-t-2] - cps[i-t][j-t-2];
                    res += rps[i+t+2][j+t+2] - rps[i+t+2][j-t-2];
                    res += cps[i+t+3][j+t+2] - cps[i-t-1][j+t+2];
                    res += rps[i-t-2][j+t+3] - rps[i-t-2][j-t-2];
                }
                if (ans < res) ans = res;
                l4 = l2;
                l2 = res;
            }
        }
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}