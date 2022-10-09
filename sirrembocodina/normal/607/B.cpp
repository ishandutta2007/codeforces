#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) {
        cin >> x;
    }
    vector<vector<int>> dp(n, vector<int>(n + 1, 2e9));
    for (int i = 0; i < n; i++) {
        dp[i][i + 1] = 1;
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len;
            for (int m = l + 1; m < r; m++) {
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m][r]);
            }
            if (a[l] == a[r - 1]) {
                if (len == 2) {
                    dp[l][r] = 1;
                } else {
                    dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
                }
            }
        }
    }
    cout << dp[0][n];
}