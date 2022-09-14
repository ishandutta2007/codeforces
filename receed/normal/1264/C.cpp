#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int MOD = 998244353;
const int N = 200001;
ll c[N], a[N], p[N], rp[N], ps[N];

ll pw(ll x, ll k) {
    ll res = 1;
    for (int i = 30; i >= 0; i--) {
        res = res * res % MOD;
        if (k & (1 << i))
            res = res * x % MOD;
    }
    return res;
}

ll rev(ll x) {
    return pw(x, MOD - 2);
}

ll q(ll l, ll r) {
    ll pp = p[r] * rp[l] % MOD, cs = (ps[r + 1] - ps[l] + MOD) % MOD * rp[l] % MOD;
    ll rp = rev((MOD + 1 - pp) % MOD);
    ll ns = (cs - pp * (r - l + 1) % MOD + MOD) % MOD * rp % MOD;
    return ((rev(pp) + MOD - 1) * ns + r - l) % MOD;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m, v, rs = pw(100, MOD - 2);
    cin >> n >> m;
    p[0] = rp[0] = 1;
    rep(i, n) {
        cin >> a[i];
        a[i] = a[i] * rs % MOD;
        p[i + 1] = p[i] * a[i] % MOD;
        rp[i + 1] = rev(p[i + 1]);
    }
    rep(i, n + 1)
        ps[i + 1] = (ps[i] + p[i]) % MOD;
    set<int> s {0, n};
    ll ans = q(0, n);
    rep(z, m) {
        cin >> v;
        v--;
        int r = *s.lower_bound(v + 1), l = *--s.lower_bound(v);
        c[v] ^= 1;
        if (c[v]) {
            ans = (ans + q(l, v) + q(v, r) - q(l, r) + MOD) % MOD;
            s.insert(v);
        }
        else {
            ans = (ans - q(l, v) - q(v, r) + q(l, r) + MOD * 2) % MOD;
            s.erase(v);
        }
        cout << ans << '\n';
    }
}