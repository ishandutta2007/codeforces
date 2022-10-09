#include "bits/stdc++.h"

#define int long long
#define sqr(x) ((x) * (x))

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(1 << 22, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = a[i];
    }
    for (int mask = 0; mask < (1 << 22); mask++) {
        for (int i = 0; i < 22; i++) {
            if (mask & (1 << i)) {
                if (dp[mask ^ (1 << i)] != -1) {
                    dp[mask] = dp[mask ^ (1 << i)];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dp[(1 << 22) - 1 - a[i]] << " ";
    }
}