#include <bits/stdc++.h>
using namespace std;

#define N 500500

typedef long long ll;

int n, sz[N];
ll a[N];
vector <int> adj[N];

const ll inf = 1e18;

typedef long long ll;

struct line {
    ll m, b;
    ll val;
    double xLeft;
    bool type;
    line(ll _m = 0, ll _b = 0) {
        m = _m;
        b = _b;
        xLeft = -inf;
        type = 0;
        val = 0;
    }
    ll valueAt(ll x) const {
        return 1ll * m * x + b;
    }
    friend bool areParallel(const line &l1, const line &l2) {
        return l1.m == l2.m;
    }
    friend double intersectX(const line &l1, const line &l2) {
        return areParallel(l1, l2) ? inf : 1.0 * (l2.b - l1.b) / (l1.m - l2.m);
    }
    bool operator < (const line &l2) const {
        if (!l2.type) return m < l2.m;
        return xLeft > l2.val;
    }
} ;
set<line> hull;
void init() {
    hull.clear();
}
bool hasPrev(set<line> :: iterator it) {
    return it != hull.begin();
}
bool hasNext(set<line> :: iterator it) {
    return it != hull.end() && next(it) != hull.end();
}
bool irrelevant(const line &l1, const line &l2, const line &l3) {
    return intersectX(l1, l3) <= intersectX(l1, l2);
}
bool irrelevant(set < line > :: iterator it) {
    return hasPrev(it) && hasNext(it) && (irrelevant(*next(it), *it, *prev(it)));
}
set<line> :: iterator updateLeftBorder(set<line> :: iterator it) {
    if (!hasNext(it))
        return it;
    double val = intersectX(*it, *next(it));
    line buf(*it);
    it = hull.erase(it);
    buf.xLeft = val;
    it = hull.insert(it, buf);
    return it;
}
void add_line(ll m, ll b) {
    line l3 = line(m, b);
    auto it = hull.lower_bound(l3);
    if (it != hull.end() && areParallel(*it, l3)) {
        if (it -> b > b)
            it = hull.erase(it);
        else return;
    }
    it = hull.insert(it, l3);
    if (irrelevant(it)) {
        hull.erase(it);
        return;
    }
    while (hasPrev(it) && irrelevant(prev(it)))
        hull.erase(prev(it));
    while (hasNext(it) && irrelevant(next(it)))
        hull.erase(next(it));
    it = updateLeftBorder(it);
    if (hasPrev(it))
        updateLeftBorder(prev(it));
    if (hasNext(it))
        updateLeftBorder(next(it));
}
ll query(ll x) {
    line q;
    q.val = x;
    q.type = 1;
    auto bestLine = hull.lower_bound(q);
    if (bestLine == hull.end()) return inf;
    return bestLine -> valueAt(x);
}



void dfs(int u, int pa = 0) {
    sz[u] = 1;
    for (auto v : adj[u]) {
        if (v == pa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    bool fg = 1;
    for (auto v : adj[u]) {
        if (v == pa) continue; fg = 0;
        a[u] = max(a[u], a[v] - 1ll * n * sz[v] + 1ll * n * sz[u] - 1ll * sz[u] * sz[u] + 1ll * sz[u] * sz[v]);
    }
    if (fg) a[u] = n - 1;
}

ll ans = inf;

int b[N];

void DFS(int u, int pa = 0) {
    for (auto v : adj[u]) {
        if (v == pa) continue;
        DFS(v, u);
    }
    init();
    for (auto v : adj[u]) {
        if (v == pa) continue;
        ans = min(ans, query(sz[v]) - a[v]);
        add_line(sz[v], - a[v]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i ++) scanf("%d %d", &u, &v), adj[u].push_back(v), adj[v].push_back(u);
    if (n == 2) return puts("2"), 0;
    int u;
    for (u = 1; u <= n; u ++) if (adj[u].size() > 1) break;
    dfs(u);
    DFS(u);
    printf("%lld\n", 1ll * n * (n - 1) / 2 - ans);
    return 0;
}