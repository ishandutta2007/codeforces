#include<bits/stdc++.h>
using namespace std;
int n, m, k, t, dp[35][35][55];
int main()
{
    for (int i = 1; i <= 30; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            for (int l = 1; l <= min(i * j, 50); l++)
            {
                if (i * j == l)
                {
                    continue;
                }
                dp[i][j][l] = 1e9;
            }
        }
    }
    for (int i = 1; i <= 30; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            for (int l = 1; l <= min(i * j, 50); l++)
            {
                for (int h = 1; h < i; h++)
                {
                    if (j * h < l)
                    {
                        dp[i][j][l] = min(dp[i][j][l], j * j + dp[i - h][j][l - j * h]);
                        continue;
                    }
                    dp[i][j][l] = min(dp[i][j][l], j * j + dp[h][j][l]);
                }
                for (int h = 1; h < j; h++)
                {
                    if (i * h < l)
                    {
                        dp[i][j][l] = min(dp[i][j][l], i * i + dp[i][j - h][l - i * h]);
                        continue;
                    }
                    dp[i][j][l] = min(dp[i][j][l], i * i + dp[i][h][l]);
                }
            }
        }
    }
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d%d%d", &n, &m, &k);
        printf("%d\n", dp[n][m][k]);
    }
    return (0);
}