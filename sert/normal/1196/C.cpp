#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e18 + 41;
const int N = (int)1e5;

void solve() {
    int n;
    int x0 = -N, x1 = N, y0 = -N, y1 = N;
    cin >> n;
    while (n--) {
        int x, y, l, d, r, u;
        cin >> x >> y >> l >> d >> r >> u;
        if (l == 0) x0 = max(x0, x);
        if (r == 0) x1 = min(x1, x);
        if (d == 0) y1 = min(y1, y);
        if (u == 0) y0 = max(y0, y);
    }
    if (x0 > x1 || y0 > y1) cout << "0\n";
    else cout << "1 " << x0 << " " << y0 << "\n";
}

int main() {
    //freopen("a.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;   
}