#include<bits/stdc++.h>
using namespace std;
int n, A[510], dp[510][510];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            if (i == 1)
            {
                dp[j][j] = 1;
                continue;
            }
            dp[j][j + i - 1] = dp[j + 1][j + i - 1] + 1;
            for (int k = j + 2; k <= j + i - 1; k++)
            {
                if (A[j] == A[k])
                {
                    dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j + 1][k - 1] + dp[k + 1][j + i - 1]);
                }
            }
            if (A[j] == A[j + 1])
            {
                dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j + 2][j + i - 1] + 1);
            }
        }
    }
    cout << dp[1][n];
    return (0);
}