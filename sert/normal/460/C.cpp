#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;
ll a[N], b[N];
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    ll n, w, q;
    cin >> n >> q >> w;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll l = 0;
    ll r = 2e9;
    ll m;
    ll k, cur, x;
    while (r - l > 1) {
        m = (l + r) / 2;
        k = 0;
        cur = 0;
        for (ll i = 0; i < n; b[i++] = 0);
        for (ll i = 0; i < n; i++) {
            cur -= b[i];
            x = max(0ll, m - a[i] - cur);
            b[i + w] = x;
            cur += x;
            k += x;
        }
        if (k <= q)
            l = m;
        else
            r = m;
    }
    cout << l;
    return 0;
}