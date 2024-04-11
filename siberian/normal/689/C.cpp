#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

ll m;

void read() {
    cin >> m;
}

const ll INF = 1e18 + 10;

ll mul(ll a, ll b) {
    if (a > (INF + b - 1) / b) return INF;
    return a * b;
}

ll pow(ll n, ll x) {
    ll ans = 1;
    for (int i = 0; i < x; i++) {
        ans = mul(ans, n);
    }
    return ans;
}

ll get_sqr(ll n, ll x) {
    ll l = 0, r = n;
    while (l < r - 1) {
        ll mid = (l + r) / 2;
        if (pow(mid, x) <= n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

ll get(ll n) {
    ll mxK = get_sqr(n, 3);
    //cout << "n = " << n << " mxK = " << mxK << endl;
    ll ans = 0;
    for (ll k = 2; k <= mxK; k++) {
        ll have = pow(k, 3);
        //cout << have << endl;
        ans += n / have;
        if (ans > m) return ans;
    }
    return ans;
}

ll ans;

void run() {
    //cout << get(64) << endl;
    //exit(0);
    ll l = 0, r = INF;
    assert(get(r) >= m);
    while (l < r - 1) {
        //cout << l << " " << r << endl;
        ll mid = (l + r) / 2;
        if (get(mid) >= m)
            r = mid;
        else
            l = mid;
    }
    ans = -1;
    if (get(r) == m) {
        ans = r;
    } 
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}