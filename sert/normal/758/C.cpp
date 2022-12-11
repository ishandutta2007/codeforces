#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-12;
const ll md = (int)1e9 + 7;
const ll o_10e6 = 397802501;
const int N = (int)1e5 + 34;

int n;
string s;
int a[N];

int main() {
    init();
    ll n, m, x, y, k;
    ll it, ad;
    cin >> n >> m >> k >> y >> x;
    y--;
    x--;

    if (n == 1) {
        ll mn = k / m;
        ll mx = (k + m - 1) / m;
        cout << mx << " " << mn << " ";
        if ((k - 1) % m >= x) cout << mx; else cout << mn;
        return 0;
    }

    ll t = (n * 2 - 2) * m;
    it = k / t;
    k %= t;


    ll mx = -1e18 - 1;
    ll mn = 1e18 + 1;
    ll h;

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        if (i * m + j < k) t = 1; else t = 0;
        if (i == 0 || i + 1 == n) t += it;
        else t += it * 2;
        mn = min(mn, t);
        mx = max(mx, t);
        if (i == y && j == x) h = t;
    }

    for (int i = 0; i < n - 2; i++)
    for (int j = 0; j < m; j++) {
        if ((n + i) * m + j >= k) continue;
        t = 2 + it * 2;
        mn = min(mn, t);
        mx = max(mx, t);
        if (y == n - i - 2 && j == x) h = t;
    }

    cout << mx << " " << mn << " " << h;

    return 0;
}