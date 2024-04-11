#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
const int N = (int)1e5 + 50;
//const ld INF = 1/.0;

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k > o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
//        return a / b;
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? -inf : inf;
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
} lc[N];

int n, a[N], b[N];
int idx[N];
ll res[N];
vector<int> G[N];

int unite(int i, int j) {
    if(lc[i].size() > lc[j].size()) swap(i, j);
    for(const Line &ln : lc[i]) {
        lc[j].add(ln.k, ln.m);
    }
    lc[i].clear();
    return j;
}

void dfs(int v, int p) {
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v);
        idx[v] = unite(idx[v], idx[nxt]);
    }
    if(!lc[idx[v]].empty()) {
        res[v] = lc[idx[v]].query(a[v]);
    }
    lc[idx[v]].add(b[v], res[v]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) idx[i] = i;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++) cout << res[i] << " ";
}