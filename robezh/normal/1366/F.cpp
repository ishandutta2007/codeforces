#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const ll INF = (ll)1e18 + 50;

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

const int N = 2005, mod = (int)1e9 + 7;

struct edge {
    int to, cost;
};

int n, m, q;
vector<edge> G[N];
ll dp[N][N];
int mx[N][N];
ll inv2 = (mod + 1) / 2;
vector<pll> add[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    for(int i = 0; i < N; i++) fill(dp[i], dp[i] + N, -INF);
    dp[0][0] = 0;
    LineContainer lc;
//    while(true) {
//        ll k, m; cin >> k >> m;
//        lc.add(k, m);
//        for(auto p : lc) cout << "(" << p.k << ", " << p.m << ", " << p.p << "), ";
//        cout << endl;
//
//    }

    for(int len = 0; len <= m; len++) {
        for(int v = 0; v < n; v++) {
            if(dp[len][v] == -INF) continue;
            int mxe = 0;
            for(auto &e : G[v]) {
                if(dp[len][v] + e.cost > dp[len+1][e.to]) {
                    dp[len+1][e.to] = dp[len][v] + e.cost;
                    mx[len+1][e.to] = max(mx[len][v], e.cost);
                }
                mxe = max(mxe, e.cost);
            }
            if(mxe >= mx[len][v]) lc.add(mxe, 1LL * dp[len][v] - 1LL * len * mxe);
        }
    }
    ll res = 0;

    ll s = 1;
    auto it = lc.lower_bound(1);
    while(it != lc.end()) {
        auto nxt = it; nxt++;
//            ll upp = (nxt == lc.end() ? q : lc.div(it->m - nxt->m, nxt->k - it->k));
        ll upp = (nxt == lc.end() ? q : it->p);
        upp = min(upp, 1LL * q);
//            assert(lc.query(upp) == upp * it->k + it->m);
//            if(nxt != lc.end()) assert(lc.query(upp + 1) == (upp + 1) * nxt->k + nxt->m);
        res += (s * it->k % mod + it->m + upp * it->k % mod + it->m) % mod * (upp - s + 1) % mod * inv2 % mod;
        res %= mod;
        it = nxt;
        s = upp + 1;
        if(upp == q) break;
    }
    cout << (res % mod + mod) % mod << '\n';



}