#include <bits/stdc++.h>

const int inf = 999999999;

int N, D;
int c[80005];
int dp[80005][505];
int ans;

int main()
{
    scanf("%d%d", &N, &D);
    for (int i = 0; i < N; i++) {
        int a; scanf("%d", &a);
        c[a]++;
    }
    for (int i = D; i < 30002; i++)
        for (int j = 1; j < 501; j++)
            dp[i][j] = -inf;
    dp[D][251] = c[D];
    for (int i = D; i < 30002; i++) {
        for (int j = 1; j < 501; j++) {
            int k = D+j-251;
            ans = std::max(ans, dp[i][j]);
            if (i+k-1 > 0) dp[i+k-1][j-1] = std::max(dp[i+k-1][j-1], dp[i][j] + c[i+k-1]);
            if (i+k > 0) dp[i+k][j] = std::max(dp[i+k][j], dp[i][j] + c[i+k]);
            if (i+k+1 > 0) dp[i+k+1][j+1] = std::max(dp[i+k+1][j+1], dp[i][j] + c[i+k+1]);
        }
    }
    printf("%d\n", ans);
}