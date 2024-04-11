#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define K 201

int n, a[N], dp[N][K][2];
const int mod = 998244353;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    dp[0][0][0] = dp[0][0][1] = 1;
    for (int i = 1; i <= n; i ++) {
        if (a[i] > 0) {
            int j = a[i];
            dp[i][j][0] = dp[i-1][j][1];
            for (int p = j + 1; p < K; p ++) {
                dp[i][j][0] += dp[i-1][p][0];
                if (dp[i][j][0] >= mod) dp[i][j][0] -= mod;
            }
            dp[i][j][1] = dp[i][j][0];
            for (int p = 0; p < j; p ++) {
                dp[i][j][1] += dp[i-1][p][1];
                if (dp[i][j][1] >= mod) dp[i][j][1] -= mod;
            }
            continue;
        }
        int sum0 = 0, sum1 = 0;
        for (int p = 1; p < K; p ++) {
            sum1 += dp[i-1][p][0];
            if (sum1 >= mod) sum1 -= mod;
        }
        for (int j = 1; j < K; j ++) {
            dp[i][j][0] = dp[i-1][j][1];
            sum1 -= dp[i-1][j][0];
            if (sum1 < 0) sum1 += mod;
            dp[i][j][0] += sum1;
            if (dp[i][j][0] >= mod) dp[i][j][0] -= mod;
            dp[i][j][1] = dp[i][j][0];
            sum0 += dp[i-1][j-1][1];
            if (sum0 >= mod) sum0 -= mod;
            dp[i][j][1] += sum0;
            if (dp[i][j][1] >= mod) dp[i][j][1] -= mod;
        }
    }
    int sum = 0;
    for (int i = 1; i < K; i ++) {
        sum += dp[n][i][0];
        if (sum >= mod) sum -= mod;
    }
    printf("%d\n", sum);
}