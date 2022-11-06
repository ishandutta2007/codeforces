#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, x;
    cin >> n >> x;
    int sum = 0;
    bool was = 0, ok = 1;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ok &= a == x;
        was |= a == x;
        sum += a;
    }
    if (ok) cout << "0\n"; else {
        if (was || x * n == sum) cout << "1\n"; else cout << "2\n";
    }
}

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}