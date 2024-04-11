#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
#define what_is(x) cerr << #x << " is " << x << endl;

const int mod = 998244353;
const int N = (int)2e5 + 50, H = 20, M = (1 << 18) + 5;

int n, m;
ll a[N];
vi f1[H], f2;
int inv2 = (998244353 + 1) / 2;
ll res[H * 2];

void FST(vi& a, bool inv) {
    for (int n = sz(a), step = 1; step < n; step *= 2) {
        for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
                int &u = a[j], &v = a[j + step]; tie(u, v) = pii((u + v) % mod, (u - v) % mod);
            }
    }
    if (inv) {
        ll d = 1;
        for (int n = sz(a), step = 1; step < n; step *= 2) {
            d = (d * inv2) % mod;
        }
        trav(x, a) x = (int)(x * d % mod);
    }
}

struct Z2Basis {
    vl v;
    int sz = 0;

    Z2Basis(int _m) {
        v = vl(_m, 0);
    }

    void add(ll x) {
        if(!x) return ;
        for(int i = m - 1; i >= 0; i--) {
            if(v[i] == 0 && ((x >> i) & 1)) {
                v[i] = x;
                sz++;
                return ;
            }
            else {
                x = min(x, v[i] ^ x);
            }
            if(!x) return ;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    Z2Basis z2(m);
    rep(i, 0, n) {
        cin >> a[i];
        z2.add(a[i]);
    }
//    for(ll x : z2.v) {
//        cout << bitset<35>(x) << endl;
//    }
    int r = m / 2, l = m - r;
    for(int i = 0; i <= l; i++) f1[i] = vi(1 << r, 0);
    f2 = vi(1 << r, 0);
    vl xs;
    for(int i = m / 2; i < m; i++) {
        if(z2.v[i]) xs.push_back(z2.v[i]);
    }

//    cout << z2.sz<< endl;
    for(int mask = 0; mask < (1 << sz(xs)); mask++) {
        ll cur = 0;
        for(int j = 0; j < sz(xs); j++) if(mask >> j & 1) cur ^= xs[j];
        f1[__builtin_popcountll(cur >> r)][cur & ((1 << r) - 1)]++;
    }
    xs.clear();
    for(int i = 0; i < m / 2; i++) {
        if(z2.v[i]) xs.push_back(z2.v[i]);
    }
    for(int mask = 0; mask < (1 << sz(xs)); mask++) {
        ll cur = 0;
        for(int j = 0; j < sz(xs); j++) if(mask >> j & 1) cur ^= xs[j];
        f2[cur]++;
    }
    for(int i = 0; i <= l; i++) FST(f1[i], false);
    FST(f2, false);

    for(int i = 0; i <= l; i++) {
        for(int j = 0; j < (1 << r); j++) {
            f1[i][j] = (int)(1LL * f1[i][j] * f2[j] % mod);
        }
        FST(f1[i], true);
        for(int j = 0; j < (1 << r); j++) {
            int c = i + __builtin_popcount(j);
            res[c] = (res[c] + f1[i][j]) % mod;
        }
    }
    ll pw = 1;
    for(int i = 0; i < n - z2.sz; i++) pw = (pw * 2 % mod);
    for(int i = 0; i <= m; i++) cout << (res[i] * pw % mod + mod) % mod << " ";







}