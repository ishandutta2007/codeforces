#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;
const ll p = 31;

ll n, m, k, ans, kn, ky;
ll x, y;

void relax(ll kx) {
    ky = k - kx;
    x = n / (kx + 1);
    y = m / (ky + 1);
    ans = max(ans, x * y);
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> m >> k;

    if (k > n + m - 2) {
        cout << -1;
        return 0;
    }

    kn = k * n / (n + m);

    for (ll i = max(0ll, kn - 100000); i <= min(k, kn + 100000); i++)
        relax(i);

    for (ll i = 0; i <= min(100000ll, k); i++)
        relax(i);

    for (ll i = max(0ll, k - 100000ll); i <= k; i++)
        relax(i);

    kn = n;
    for (ll i = max(0ll, kn - 100000); i <= min(k, kn + 100000); i++)
        relax(i);

    kn = m;
    for (ll i = max(0ll, kn - 100000); i <= min(k, kn + 100000); i++)
        relax(k - i);

    cout << ans;

    //return 0;
}