#include <bits/stdc++.h>
using namespace std;
bool D = false;

void solve() {
    int n, m;
    cin >> n >> m;
    bool ok = false;
    while (n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b == c && m % 2 == 0) ok = true;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    D = true;
#else

#endif
    cin >> t;
    while (t--) {
        solve();
    }
}