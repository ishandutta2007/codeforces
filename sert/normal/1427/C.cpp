#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 41;

inline void mxe(int &a, int b) {
    if (b > a) a = b;
}

void solve() {
    int r, n;
    cin >> r >> n;
    vector<int> x(n), y(n), t(n), dp(n, -INF);

    int mn = -2 * r - 2;
    int mx = -INF;

    for (int i = 0; i < n; i++) {
        mn++;
        if (mn >= 0) mx = max(mx, dp[mn]);

        cin >> t[i] >> x[i] >> y[i];
        if (x[i] - 1 + y[i] - 1 <= t[i]) dp[i] = 1;
        mxe(dp[i], mx + 1);

        for (int j = max(0, mn); j < i; j++) {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
                mxe(dp[i], dp[j] + 1);
        }
    }

    cout << max(0, *max_element(dp.begin(), dp.end())) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef SERT
    freopen("a.in", "r", stdin);
    solve();
    solve();
    solve();
#endif
    solve();
}