#include <bits/stdc++.h>

#define int int64_t

using namespace std;

void relax(int& a, int b) {
    a = min(a, b);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> t(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        cin >> c[i];
    }
    vector<int> dp(n + 1, 2e18);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        vector<int> new_dp = dp;
        for (int j = 0; j <= n; j++) {
            relax(new_dp[min(n, j + t[i] + 1)], dp[j] + c[i]);
        }
        dp = new_dp;
    }
    cout << dp[n];
}