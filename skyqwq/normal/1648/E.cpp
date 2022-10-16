// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 400005, L = 19;

int n, m, idx, X[N], Y[N];

struct E{
    int a, b, c;
    bool operator < (const E &x) const {
        return c < x.c;
    }
} e[N];

set<int> s[N];


vector<int> b[N], c[N];

bool vis[N];

int d[N];

struct DSU{
    int f[N], sz[N];
    void init(int n) { for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1; }
    int inline find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    void inline merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        //if (sz[x] > sz[y]) swap(x, y);
        sz[y] += sz[x], f[x] = y;
    }
} t1, t2, t3;


PII ta[N];

int t, w[N], fa[N][L];

vector<int> g[N];

void inline clr() {
    t = 0;
    for (int i = 1; i <= n; i++)
        vis[i] = 0, s[i].clear(), b[i].clear(), c[i].clear();
    for (int i = 1; i <= idx; i++) {
        g[i].clear();
        d[i] = 0;
        for (int j = 0; j < L; j++) fa[i][j] = 0;
    }
    idx = 0;
}

void inline Add(int x, int y, int z) {
    ta[++t] = mp(x, y);
    x = t3.find(x), y = t3.find(y);
    if (x == y) return;
    w[++idx] = z;
    g[idx].pb(x), g[idx].pb(y);
    t3.f[x] = t3.f[y] = t3.f[idx] = idx;
}

void inline chk(int p, int q, int z) {
    for (int x: c[p])
        for (int y: c[q]) {
            if (!s[x].count(y)) {
                Add(x, y, z);
                return;
            }
        }
}

void merge(int x, int y, int z) {
    x = t1.find(x), y = t1.find(y);
    if (x == y) return;
    t1.f[x] = y; t1.sz[y] += t1.sz[x];
    for (int p: b[x])
        for (int q: b[y]) {
            chk(p, q, z);
        }
    for (int i = 1; i <= t; i++) {
        int A = ta[i].fi, B = ta[i].se;
        A = t2.find(A), B = t2.find(B);
        if (A != B) {
            if (c[A].size() > c[B].size()) swap(A, B);
            t2.f[A] = B;
            for (int o: c[A]) c[B].pb(o);
            vis[A] = 1;
        }   
    }
    t = 0;
    vector<int> ne;
    for (int p: b[x])
        if (t2.find(p) == p) ne.pb(p);
    for (int p: b[y])
        if (t2.find(p) == p) ne.pb(p);
    b[y] = ne;
}


int inline lca(int x, int y) {
     if (d[x] < d[y]) swap(x, y);
     for (int i = L - 1; ~i; i--)
         if (d[x] - (1 << i) >= d[y]) x = fa[x][i];
     if (x == y) return x;
     for (int i = L - 1; ~i; i--)
         if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
     return fa[x][0];
}


void dfs(int u) {
    for (int i = 1; i < L; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v: g[u]) {
        fa[v][0] = u;
        d[v] = d[u] + 1;
        dfs(v);
    }
}

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(m); idx = n;
        t1.init(n), t2.init(n); t3.init(n);
        for (int i = 1; i <= n; i++) b[i].pb(i), c[i].pb(i);
        for (int i = 1; i <= m; i++) {
            read(e[i].a), read(e[i].b), read(e[i].c);
            X[i] = e[i].a, Y[i] = e[i].b;
            s[e[i].a].insert(e[i].b);
            s[e[i].b].insert(e[i].a);
        }
        sort(e + 1, e + 1 + m);
        for (int i = 1; i <= m; i++) {
            merge(e[i].a, e[i].b, e[i].c);
        }
        d[idx] = 1;
        dfs(idx);
        for (int i = 1; i <= m; i++) {
            int x = X[i], y = Y[i];
            printf("%d ", w[lca(x, y)]);
        }
        puts("");
        clr();
    }
    return 0;
}