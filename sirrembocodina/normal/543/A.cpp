#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int mod;

void add(int& a, int b) { //  (a += b) %= mod
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m, b;
    cin >> n >> m >> b >> mod;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(b + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k <= b - a[i]; k++) {
                add(dp[j + 1][k + a[i]], dp[j][k]);
            }
        }
    }
    int ans = 0;
    for (int k = 0; k <= b; k++) {
        add(ans, dp[m][k]);
    }
    cout << ans << endl;
}