#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;
const ll md = (ll)1e9 + 7;
ll o_1e6;

ll f[N], o[N];

ll fast_pow(ll a, ll deg) {
    if (deg == 0 || a == 0) return 1;
    if (deg % 2) return (a * fast_pow(a, deg - 1)) % md;
    ll q = fast_pow(a, deg / 2);
    return (q * q) % md;
}

ll putt(ll n, ll k) {
    //cerr << n << " " << k << "\n";
    return (((f[n - 1] * o[k - 1]) % md) * o[n - k]) % md;
}

ll cnt(ll f, ll w, ll n) {
    if (w < n || f < n - 1)
        return 0;
    //cerr << n << "\n";
    ll res = putt(w, n);
    ll r2 = (n == 1 ? 0 : putt(f, n - 1));
    if (f - n >= 0) r2 += 2 * putt(f, n);
    if (f - n - 1 >= 0) r2 += putt(f, n + 1);
    //cerr << "end = " << n << "\n";
    return (res * r2) % md;
}

ll fi(ll x) {
    ll res = x;
    ll xx = x;
    for (ll i = 2; i * i <= xx; i++) {
        if (x % i == 0) {
            res = res * (i - 1) / i;
            while (x % i == 0)
                x /= i;
        }
    }
    //cerr << res << " " << x << "\n";
    if (x > 1)
        res = res * (x - 1) / x;
    return res;
}

int main() {
    init();
/*ll ff = 1;
    for (ll i = 1; i <= 1000000; i++)
        ff = (ff * i) % md;
    for (ll i = 1; true; i++) {
        if (i * ff % md == 1) {
            cout << i;
            return 0;
        }
    }*/

    o[1000000] = 397802501;
    for (ll i = 999999; i >= 1; i--)
        o[i] = (o[i + 1] * (i + 1)) % md;
    o[0] = 1;
    f[0] = 1;
    for (ll i = 1; i <= 1000000; i++)
        f[i] = (f[i - 1] * i) % md;

    //cout << (f[34] * o[34]) % md;
    //return 0;

    ll f, w, h;
    cin >> f >> w >> h;
    ll all = 0, good = 0;

    if (f == 0) {
        if (w > h)
            cout << 1;
        else
            cout << 0;
        return 0;
    }

    if (w == 0) {

            cout << 1;
        return 0;
    }

    for (ll i = 1; i <= 110000; i++) {
        all = (all + cnt(f, w, i)) % md;
        good = (good + cnt(f, w - h * i, i)) % md;
    }

    //cerr << good << " " << all << "\n";

    if (good == 0 || all == 0) {
        cout << 0;
        return 0;
    }

    ll all_1 = fast_pow(all, fi(md) - 1);

    //cout << all << " " << all_1 << "\n";

    if ((all * all_1) % md != 1) {
        cerr << "fail\n";
        exit(34);
    }

    cout << (good * all_1) % md;

    return 0;
}