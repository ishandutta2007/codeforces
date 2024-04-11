#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)5e5 + 50;
const ll INF = (ll)1e18;
typedef long long ll;

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

struct revLC {
    LineContainer lc;
    void add(ll k, ll m) {
        lc.add(-k, -m);
    }
    ll query(ll x) {
        if(lc.empty()) return INF;
        return -lc.query(x);
    }
};

int n;
vi G[N];
int sub[N];
ll dp[N];
ll res = INF;

ll p2(ll x) {
    return x * x;
}

void dfs(int v, int p) {
    sub[v] = 1;
    dp[v] = INF;
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v);
        sub[v] += sub[nxt];
    }


    revLC lc;
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        res = min(res, dp[nxt] + 1LL * (n - sub[nxt]) * (n - sub[nxt]));
        dp[v] = min(dp[v], dp[nxt] + 1LL * (sub[v] - sub[nxt]) * (sub[v] - sub[nxt]));
        res = min(res, dp[nxt] + p2(n - sub[nxt]) + lc.query(n - sub[nxt]));
        lc.add(- 2 * sub[nxt], dp[nxt] + p2(sub[nxt]));
    }

    if(sub[v] == 1) dp[v] = 1;
//    cout << v + 1 << " " << dp[v] << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    LineContainer lc;

    cin >> n;
    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    cout << (1LL * n * (n - 1) / 2) + (1LL * n * n - res) / 2 << endl;

}