#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int max_b = 1000;
    vector<int> w(max_b + 1, 2e18); // ~process simulation dp~ (transitions forward)
    w[1] = 0;
    for (int i = 1; i < max_b; i++) {
        for (int x = 1; x <= i; x++) {
            int j = i + i / x;
            if (j <= max_b) {
                w[j] = min(w[j], w[i] + 1);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        k = min(k, 12 * n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        vector<int> dp(k + 1, 0); // process simulation dp
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            vector<int> new_dp = dp;
            for (int j = 0; j + w[b[i]] <= k; j++) {
                new_dp[j + w[b[i]]] = max(new_dp[j + w[b[i]]], dp[j] + c[i]);
            }
            dp = new_dp;
        }
        cout << dp[k] << '\n';
    }
}