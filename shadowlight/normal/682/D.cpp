#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int dp[2][1001][1001][13];

int main() {
    int n, m, k1;
    cin >> n >> m >> k1;
    string s, t;
    cin >> s >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= k1; k++) {
                /*if (dp[i][j][k - 1] >= k) {
                    dp[i][j][k] = dp[i][j][k - 1];
                    par[i][j][k] = par[i][j][k - 1];
                }*/
                if (s[i - 1] == t[j - 1]) {
                    if (dp[1][i][j][k] <= dp[0][i - 1][j - 1][k - 1] + 1) {
                        dp[1][i][j][k] = dp[0][i - 1][j - 1][k - 1] + 1;
                    }
                    if (dp[1][i][j][k] <= dp[1][i - 1][j - 1][k] + 1) {
                        dp[1][i][j][k] = dp[1][i - 1][j - 1][k] + 1;
                    }
                }
                if (dp[0][i - 1][j][k] > dp[0][i][j][k]) {
                    dp[0][i][j][k] = dp[0][i - 1][j][k];
                }
                if (dp[0][i][j - 1][k] > dp[0][i][j][k]) {
                    dp[0][i][j][k] = dp[0][i][j - 1][k];
                }
                dp[0][i][j][k] = max(dp[0][i][j][k], dp[1][i][j][k]);
                //cout << i << " " << j << " " << dp[0][i][j][k] << " " << dp[1][i][j][k] << endl;
            }
        }
    }
    cout << max(dp[0][n][m][k1], dp[1][n][m][k1]);
}