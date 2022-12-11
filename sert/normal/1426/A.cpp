#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    //cout << n << " " << x << ": ";
    if (n <= 2) cout << "1\n";
    else cout << (n - 3) / x + 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
#else

#endif
    cin >> t;
    while (t--) {
        solve();
    }
}