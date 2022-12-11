#include <bits/stdc++.h>
using namespace std;

const int MD = (int)1e9 + 7;
inline void add(int &a, int b) {
    a += b;
    if (a >= MD) a -= MD;
}

void solve() {
    int od = 0, ev = 0;
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            add(ans, od + 1);
            add(ev, od + 1);
        } else {
            add(ans, ev + 1);
            add(od, ev + 1);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    t = 2;
#endif
    while (t--) {
        solve();
    }
}