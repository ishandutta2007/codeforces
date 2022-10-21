#include <bits/stdc++.h>
using namespace std;

const int N = 150050;
typedef long long ll;

set<int> G[N];
int n;
ll a[N];
int par[N], sub[N];

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const {return k < o.k;}
    bool operator<(ll x) const {return p < x;}
};

struct LineContainer : multiset<Line, less<>> {
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if(y == end()) {x -> p = inf; return false;}
        if(x ->k == y ->k) x->p = x->m > y->m? inf: -inf;
        else x ->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while(isect(y, z)) z = erase(z);
        if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

int dfs1(int v, int p) {
    sub[v] = 1;
    for(int nxt : G[v])
        if(nxt != p) sub[v] += dfs1(nxt, v);
    return sub[v];
}

int dfs2(int v, int p, int nn) {
    for(int nxt : G[v]) {
        if(nxt != p && sub[nxt] > nn / 2) return dfs2(nxt, v, nn);
    }
    return v;
}

LineContainer lc;
ll res = 0;

void dfs_add(int v, int p, ll sum, ll sum2, ll dep) {
    lc.add(sum, sum2);
    for(int nxt : G[v]) {
        if(nxt != p) dfs_add(nxt, v, sum + a[nxt], sum2 + a[nxt] * (dep + 1), dep + 1);
    }
}

void dfs_solve(int v, int p, ll sum, ll sum2, ll dep) {
    res = max(res, lc.query(dep) + sum2);
    for(int nxt : G[v]) {
        if(nxt != p) dfs_solve(nxt, v, sum + a[nxt], sum2 + sum + a[nxt], dep + 1);
    }
}


void decompose(int v, int p) {
    dfs1(v, -1);
    int centroid = dfs2(v, -1, sub[v]);
    par[centroid] = p;

    lc.clear();
    lc.add(a[centroid], a[centroid]);
    for(int nxt : G[centroid]) {
        dfs_solve(nxt, centroid, a[nxt], a[nxt], 1);
        dfs_add(nxt, centroid, a[centroid] + a[nxt], a[centroid] + 2 * a[nxt], 2);
    }
    lc.clear();
    lc.add(a[centroid], a[centroid]);
    for(auto it = G[centroid].rbegin(); it != G[centroid].rend(); it++) {
        int nxt = *it;
        dfs_solve(nxt, centroid, a[nxt], a[nxt], 1);
        dfs_add(nxt, centroid, a[centroid] + a[nxt], a[centroid] + 2 * a[nxt], 2);
    }
    res = max(res, lc.query(0));



    for(int nxt : G[centroid]) {
        G[nxt].erase(centroid);
        decompose(nxt, centroid);
    }
    G[centroid].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    decompose(0, -1);
    cout << res << endl;
}