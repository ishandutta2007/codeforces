#include<bits/stdc++.h>
using namespace std;
int n, m, Mx = 4, C[30][30][30], dp[30][30][30][30];
char A[30][30];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i <= 25; i++)
    {
        for (int j = 0; j <= 25; j++)
        {
            for (int k = 0; k <= 25; k++)
            {
                C[i][j][k] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = j; k <= m; k++)
            {
                C[i][j][k] = C[i][j][k - 1];
                if (A[i][k] == '1')
                {
                    C[i][j][k] = 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = i; k <= n; k++)
            {
                for (int h = j; h <= m; h++)
                {
                    dp[i][j][k][h] = 0;
                    if (((dp[i][j][k - 1][h] || k <= i) & C[k][j][h]) == 1)
                    {
                        dp[i][j][k][h] = 1;
                        Mx = max(Mx, 2 * (k - i + 1 + h - j + 1));
                    }
                }
            }
        }
    }
    cout << Mx;
    return (0);
}