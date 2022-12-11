#include <bits/stdc++.h>
using namespace std;
bool D = false;
const int INF = (int)1e9 + 41;
typedef long long ll;

ll solve(ll a, ll b, ll x, ll y, ll n) {
    //cout << a << " " << b << " " << x << " " << y << " " << n << "\n";
    if (n == 0 || a + b == x + y) return a * b;
    if (a == x) {
        ll t = min(n, b - y);
        return solve(a, b - t, x, y, n - t);
    } else {
        ll t = min(n, a - x);
        return solve(a - t, b, x, y, n - t);
    }
}

void solve() {
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    cout << min(solve(a, b, x, y, n), solve(b, a, y, x, n)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    D = true;
    t = 4;
#else

#endif
    cin >> t;
    while (t--) {
        solve();
    }
}