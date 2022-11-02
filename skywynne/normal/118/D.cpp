#include<bits/stdc++.h>
using namespace std;
const int NX = 1e8;
long long n, m, k, p, t, r, q, dp[215][115][2];
int main()
{
    cin >> n >> m >> k >> p;
    for (int i = 0; i < 115; i++)
    {
        dp[0][i][0] = dp[0][i][1] = 1;
    }
    dp[1][1][0] = dp[1][0][1] = 1;
    for (int i = 2; i <= n + m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j > i)
            {
                break;
            }
            if (j + m < i)
            {
                continue;
            }
            dp[i][j][1] = (dp[i - 1][j][0] + dp[i - 1][j][1] + NX) % NX;
            if (i - p - 1 >= 0 && i - j >= p + 1)
            {
                dp[i][j][1] = (dp[i][j][1] - dp[i - p - 1][j][0] + NX) % NX;
            }
            if (j > 0)
            {
                dp[i][j][0] = (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + NX) % NX;
                if (j - k - 1 >= 0 && i - k - 1 >= 0 && i >= k + 1)
                {
                    dp[i][j][0] = (dp[i][j][0] - dp[i - k - 1][j -k - 1][1] + NX) % NX;
                }
            }
        }
    }
    cout << (dp[n + m][n][0] + dp[n + m][n][1] + NX) % NX;
    return (0);
}