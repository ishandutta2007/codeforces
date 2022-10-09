#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int dp[101][101][2][11];
int mod = 1e8;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n0, n1, k0, k1;
    cin >> n0 >> n1 >> k0 >> k1;
    dp[0][0][0][0] = 1;
    for (int i = 0; i <= n0; i++) {
        for (int j = 0; j <= n1; j++) {
            for (int t = 0; t < 2; t++) {
                int K = t == 0 ? k0 : k1;
                for (int k = 0; k <= K; k++) {
                    if (i < n0 && (t == 1 || k < K)) {
                        (dp[i + 1][j][0][t == 1 ? 1 : k + 1] += dp[i][j][t][k]) %= mod;
                    }
                    if (j < n1 && (t == 0 || k < K)) {
                        (dp[i][j + 1][1][t == 0 ? 1 : k + 1] += dp[i][j][t][k]) %= mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int t = 0; t < 2; t++) {
        int K = t == 0 ? k0 : k1;
        for (int k = 0; k <= K; k++) {
            (ans += dp[n0][n1][t][k]) %= mod;
        }
    }
    cout << ans;
}