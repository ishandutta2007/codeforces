#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e5;

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    ll n, m, k;
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    ll a, b;
    ll g = gcd(n, m, a, b);
    vector<ll> na = {a}, nb = {b};
    if (a < 0) {
        na.pb(m + a);
        nb.pb(b - n);
    } else {
        na.pb(-m + a);
        nb.pb(b + n);
    }

    forn(i, k) {
        ll x, y;
        cin >> x >> y;
        ll ans = -1;
        forn(_x, 2) {
            forn(_y, 2) {
                y *= -1;
                //cerr << x <<' ' << y << '\n';
                if ((x - y) % g != 0 || ((x - y) / g % 2) != 0) {
                    continue;
                }
                forn (j, 2) {
                    ll k = -(x - y) / g * na[j];
                    ll l = (x - y) / g * nb[j];
                    //assert(x + k * n == y + l * m);

                    k /= 2, l /= 2;
                    ll d = m / g;
                    k = (k % d + d) % d;
                    /*
                    ll t = min(k / (m / g), l / (n / g));
                    k -= t * m;
                    l -= t * n;
                    if (k < 0) {
                        k += m / g;
                        l += n / g;
                    }*/
                    if (x + 2 * k * n >= 0)
                        if (ans == -1 || ans > x + 2 * k * n) {
                            ans = x + 2 * k * n;
                        }
                }
            }
            x *= -1;
        }
        cout << ans << '\n';
    }

    return 0;
}