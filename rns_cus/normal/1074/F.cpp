#include <bits/stdc++.h>
using namespace std;

#define N 200200
#define K 20

int n, q, fa[N][K], dep[N], st[N], ed[N], T;
vector <int> adj[N];

void dfs(int u, int pa = 0) {
    dep[u] = dep[pa] + 1; fa[u][0] = pa; st[u] = ++T;
    for (int i = 1; i <= __lg(dep[u]); i ++) fa[u][i] = fa[fa[u][i-1]][i-1];
    for (auto v : adj[u]) if (v != pa) dfs(v, u);
    ed[u] = T;
}

int anc(int u, int k) {
    if (!k) return u;
    for (int i = __lg(k); i >= 0; i --) if (k >> i & 1) u = fa[u][i];
    return u;
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    v = anc(v, dep[v] - dep[u]);
    if (u == v) return u;
    for (int i = __lg(dep[u]); i >= 0; i --)
        if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}
typedef long long ll;
ll addv[N << 2], ans[N << 3];
#define le v << 1
#define ri v << 1 | 1
#define mi (vl + vr >> 1)
void modify(int v, int vl, int vr, int l, int r, int d) {
    if (l > r || l > vr || vl > r) return;
    if (l <= vl && vr <= r) addv[v] += d;
    else {
        modify(le, vl, mi, l, r, d);
        modify(ri, mi + 1, vr, l, r, d);
    }
    if (addv[v]) ans[v] = vr - vl + 1;
    else ans[v] = ans[le] + ans[ri];
}
#undef le
#undef ri
#undef mi

typedef pair <int, int> pii;
map <pii, bool> exist;

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1, u, v; i < n; i ++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    } dep[0] = -1;
    dfs(1);
    assert(T == n);
    while (q --) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u > v) swap(u, v);
        int d = 1;
        if (exist[pii(u, v)]) d = -1;
        exist[pii(u, v)] ^= 1;
        int w = lca(u, v);
        if (dep[u] > dep[v]) swap(u, v);
        if (w == u) {
            u = anc(v, dep[v] - dep[u] - 1);
            modify(1, 1, n, st[u], st[v] - 1, d);
            modify(1, 1, n, ed[v] + 1, ed[u], d);
        }
        else {
            if (st[u] > st[v]) swap(u, v);
            modify(1, 1, n, 1, st[u] - 1, d);
            modify(1, 1, n, ed[u] + 1, st[v] - 1, d);
            modify(1, 1, n, ed[v] + 1, n, d);
        }
        printf("%d\n", n - ans[1]);
    }
}