#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, q, ans, tms, dfn[N], low[N], vol, stc[N], col[N];
int ft[N], dep[N], siz[N], hs[N], top[N], tms0, dfn0[N];
int qn, qm, a[N], eu[N], ev[N], id[N], c[N];
std::vector<std::pair<int, int>> e[N];
std::vector<int> p, tr[N];

bool compare(int u, int v) {
    return dfn0[u] < dfn0[v];
}

void tarjan(int u, int fw) {
    dfn[u] = low[u] = ++tms; stc[++vol] = u;
    int tmp = vol;
    for (auto i : e[u]) {
        int v = i.first, w = i.second;
        if (w == fw) { continue; }
        if (dfn[v] == 0) {
            tarjan(v, w);
            low[u] = std::min(low[u], low[v]);
        } else {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        for (int i = tmp; i <= vol; i++) {
            col[stc[i]] = u;
        }
        vol = tmp - 1;
    }
}
void tarjan(int n) {
    for (int u = 1; u <= n; u++) {
        dfn[u] = low[u] = 0;
    }
    for (int u = 1; u <= n; u++) {
        if (dfn[u] == 0) {
            tarjan(u, -1);
            tr[n + 1].push_back(u);
            tr[u].push_back(n + 1);
        }
    }
}

void dfs1(int u, int fa) {
    ft[u] = fa; dep[u] = dep[fa] + 1; siz[u] = 1;
    for (auto v : tr[u]) {
        if (v == fa) { continue; }
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[hs[u]] < siz[v]) { hs[u] = v; }
    }
}
void dfs2(int u, int tp) {
    top[u] = tp; dfn0[u] = tms0++;
    if (hs[u] > 0) { dfs2(hs[u], tp); }
    for (auto v : tr[u]) {
        if (v == ft[u] || v == hs[u]) { continue; }
        dfs2(v, v);
    }
}

int findLca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            u = ft[top[u]];
        } else {
            v = ft[top[v]];
        }
    }
    return dep[u] < dep[v] ? u : v;
}

void insert(int u) {
    if (vol > 1) {
        int lca = findLca(u, stc[vol]);
        for (int v = stc[vol]; vol && dfn0[v] > dfn0[lca]; vol--, v = stc[vol]) {
            if (dfn0[stc[vol - 1]] <= dfn0[lca]) {
                eu[qm] = v; ev[qm] = lca; qm++;
            } else {
                eu[qm] = v; ev[qm] = stc[vol - 1]; qm++;
            }
        }
        if (stc[vol] != lca) { stc[++vol] = lca; }
    }
    stc[++vol] = u;
}

int solve() {
    tarjan(p.size());
    for (int i = 1; i < qn; i++) {
        if (col[id[a[0]]] != col[id[a[i]]]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    n = read(); m = read(); q = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }
    tarjan(n);
    memcpy(c, col, (n + 1) * 4);
    for (int u = 1; u <= n; u++) {
        for (auto i : e[u]) {
            int v = i.first;
            if (c[u] == c[v]) { continue; }
            tr[c[u]].push_back(c[v]);
        }
    }
    dfs1(n + 1, 0); dfs2(n + 1, n + 1);
    for (int qi = 1, R = 0; qi <= q; R = (R + ans * qi) % n, qi++) {
        qn = read(); qm = read();
        p.clear(); p.push_back(n + 1);
        for (int i = 0; i < qn; i++) {
            a[i] = read(); a[i] = c[(a[i] + R - 1) % n + 1];
            p.push_back(a[i]);
        }
        for (int i = 0; i < qm; i++) {
            eu[i] = read(); eu[i] = c[(eu[i] + R - 1) % n + 1];
            ev[i] = read(); ev[i] = c[(ev[i] + R - 1) % n + 1];
            p.push_back(eu[i]); p.push_back(ev[i]);
        }
        std::sort(p.begin(), p.end(), compare);
        p.resize(std::unique(p.begin(), p.end()) - p.begin());
        for (int i = 0; i < p.size(); i++) {
            insert(p[i]);
        }
        for (int v = stc[vol]; vol; vol--, v = stc[vol]) {
            if (vol > 1) {
                eu[qm] = v; ev[qm] = stc[vol - 1]; qm++;
            }
        }
        p.clear();
        for (int i = 0; i < qn; i++) {
            p.push_back(a[i]);
        }
        for (int i = 0; i < qm; i++) {
            p.push_back(eu[i]); p.push_back(ev[i]);
        }
        std::sort(p.begin(), p.end(), compare);
        p.resize(std::unique(p.begin(), p.end()) - p.begin());
        for (int i = 0; i < p.size(); i++) {
            e[i + 1].clear(); id[p[i]] = i + 1;
        }
        for (int i = 0; i < qm; i++) {
            if (eu[i] == n + 1 || ev[i] == n + 1) { continue; }
            e[id[eu[i]]].push_back({id[ev[i]], i});
            e[id[ev[i]]].push_back({id[eu[i]], i});
        }
        ans = solve();
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}