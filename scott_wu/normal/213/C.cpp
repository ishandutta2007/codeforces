#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 305;
const int INF = 1e9;

int N;
int dp[2*MAXN][MAXN][MAXN];
int board[2*MAXN][MAXN];

int main()
{
    for (int i = 0; i < 2 * MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            board[i][j] = 0;
    for (int i = 0; i < 2 * MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            for (int k = 0; k < MAXN; k++)
                dp[i][j][k] = -INF;
    
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i+j][j];
    
    dp[0][0][0] = board[0][0];
    for (int i = 0; i < 2 * N - 2; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
            {
                for (int l = 0; l < 2; l++)
                    for (int m = 0; m < 2; m++)
                    {
                        int nj = j + l, nk = k + m;
                        if (nj >= N || nk >= N)
                            continue;
                        int nval = dp[i][j][k] + board[i+1][nj] + board[i+1][nk];
                        if (nj == nk)
                            nval -= board[i+1][nj];
                        dp[i+1][nj][nk] = max (dp[i+1][nj][nk], nval);
                    }
            }
    /*for (int i = 0; i <= 2 * N - 2; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }*/
    cout << dp[2*N-2][N-1][N-1] << "\n";
    //system ("Pause");
    return 0;
}