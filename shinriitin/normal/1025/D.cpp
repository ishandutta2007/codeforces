#include <bits/stdc++.h>

const int max_N = 700 + 21;

int n, a[max_N], gcd[max_N][max_N];

bool dp[max_N][max_N][2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            gcd[i][j] = gcd[j][i] = std::__gcd(a[i], a[j]);
        }
        gcd[0][i] = gcd[i][0] = 233;
        gcd[n + 1][i] = gcd[i][n + 1] = 233;
    }
    for (int i = 1; i <= n; ++i) {
        if (gcd[i - 1][i] > 1) dp[i][i][0] = true;
        if (gcd[i][i + 1] > 1) dp[i][i][1] = true;
    }
    for (int i = 1; i <= n + 1; ++i) {
        dp[i][i - 1][0] = dp[i][i - 1][1] = true;
    }
    for (int len = 1; len < n; ++len) {
        for (int i = 1; i + len <= n; ++i) {
            for (int j = i; j <= i + len; ++j) {
                if (gcd[i - 1][j] > 1) {
                    dp[i][i + len][0] |= (dp[i][j - 1][1] && dp[j + 1][i + len][0]);
                }
                if (gcd[j][i + len + 1] > 1) {
                    dp[i][i + len][1] |= (dp[i][j - 1][1] && dp[j + 1][i + len][0]);
                }
            }
        }
    }
    puts((dp[1][n][0] || dp[1][n][1]) ? "Yes" : "No");
    return 0;
}