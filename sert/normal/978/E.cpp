//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;

void solve() {
    int n, w, bal = 0, mn = 0, mx = 0, x;
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> x;
        bal += x;
        mn = min(mn, bal);
        mx = max(mx, bal);
    }
    cout << max(0, w + 1 - (mx - mn)) << "\n";
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
#endif
    solve();
    return 0;
}