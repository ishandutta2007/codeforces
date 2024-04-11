#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int r, n;
    cin >> r >> n;
    n++;
    vector<int> x(n), y(n), t(n);
    for (int i = 1; i < n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    vector<int> dp(n, -2e18);
    dp[0] = 0;
    int mx = -2e18;
    if (r == 1) {
        cout << n - 1 << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (i - 2 * r + 2 >= 0) {
            mx = max(mx, dp[i - 2 * r + 2]);
        }
        dp[i] = mx + 1;
        for (int j = max(0ll, i - 2 * r + 3); j < i; j++) {
            if (abs(x[j] - x[i]) + abs(y[j] - y[i]) <= t[i] - t[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    forn (i, n) {
        mx = max(mx, dp[i]);
    }
    cout << mx << endl;
}