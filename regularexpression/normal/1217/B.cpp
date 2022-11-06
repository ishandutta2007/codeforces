#include<bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18 + 10;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> d(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i] >> h[i];
    }
    int mxd = 0;
    for (int i = 0; i < n; i++) {
        mxd = max(mxd, d[i]);
    }
    x = max(0LL, x - mxd);
    int ans = INF;
    if (x == 0LL) {
        ans = 1;
    }
    for (int i = 0; i < n; i++) {
        if (h[i] >= d[i]) continue;
        ans = min(ans, (x + d[i] - h[i] - 1) / (d[i] - h[i]) + 1);
    }
    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}