#include <bits/stdc++.h>
using namespace std;

#define N 500100

int n, dep[N], x[N], y[N], z[N];
vector <int> adj[N];

int m, id[N], ans[N];

void dfs(int u, int pa = 0) {
    dep[u] = dep[pa] + 1;
    for (auto e : adj[u]) {
        int v = x[e] ^ y[e] ^ u;
        if (v == pa) continue;
        dfs(v, u);
    }
}

struct Segment_Tree {
    int d[N], mx[2][N<<2];
    bool val[N], rev[N<<2];
#define le v << 1
#define ri v << 1 | 1
#define mi (vl + vr >> 1)
    inline void apply(int v) {
        rev[v] ^= 1;
        swap(mx[0][v], mx[1][v]);
    }
    inline void push_dn(int v) {
        if (rev[v]) {
            apply(le);
            apply(ri);
            rev[v] = 0;
        }
    }
    inline void push_up(int v) {
        mx[0][v] = max(mx[0][le], mx[0][ri]);
        mx[1][v] = max(mx[1][le], mx[1][ri]);
    }

    void build(int v, int vl, int vr) {
        rev[v] = 0, mx[0][v] = mx[1][v] = 0;
        if (vl == vr) mx[val[vl]][v] = d[vl];
        else {
            build(le, vl, mi), build(ri, mi + 1, vr);
            push_up(v);
        }
    }
    void modify(int v, int vl, int vr, int l, int r) {
        if (l > vr || vl > r) return;
        if (l <= vl && vr <= r) apply(v);
        else {
            push_dn(v);
            modify(le, vl, mi, l, r);
            modify(ri, mi + 1, vr, l, r);
            push_up(v);
        }
    }
#undef le
#undef ri
#undef mi
} X;

int T, dt[N], ft[N];

void dfs_init(int u, int dp, int pa = 0) {
    dt[u] = ++T; X.d[T] = dp;
    for (auto e : adj[u]) {
        int v = x[e] ^ y[e] ^ u;
        if (v == pa) continue;
        X.val[T+1] = X.val[dt[u]] ^ z[e];
        dfs_init(v, dp + 1, u);
    }
    ft[u] = T;
}

void solve(int rt) {
    T = 0;
    X.val[1] = 0;
    dfs_init(rt, 0);
    X.build(1, 1, n);
    for (int i = 1; i <= m; i ++) {
        int e = id[i];
        int u = dt[x[e]] < dt[y[e]] ? y[e] : x[e];
        X.modify(1, 1, n, dt[u], ft[u]);
        ans[i] = max(ans[i], X.mx[0][1]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v, t; i < n; i ++) {
        scanf("%d %d %d", &u, &v, &t);
        adj[u].push_back(i);
        adj[v].push_back(i);
        x[i] = u, y[i] = v, z[i] = t;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++) scanf("%d", &id[i]);
    dep[0] = -1;
    dfs(1);
    int rt = max_element(dep + 1, dep + n + 1) - dep;
    solve(rt);
    dfs(rt);
    solve(max_element(dep + 1, dep + n + 1) - dep);
    for (int i = 1; i <= m; i ++) printf("%d\n", ans[i]);

    return 0;
}