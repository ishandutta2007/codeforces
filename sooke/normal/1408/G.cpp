#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 998244353;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}

const int N = 1505;

int n, m, _n, anc[N * 2], tms, vis[N * 2], tms2, vis2[N * 2], id[N * 2], gg[N * 2];
int siz[N * 2], f[N * 2][N];
bool can[N * 2];
std::vector<int> e[N * 2];

struct Edge {
    int u, v, w;
} edg[N * N];

bool operator <(const Edge &i, const Edge &j) {
    return i.w < j.w;
}

int find(int u) {
    return anc[u] == u ? u : anc[u] = find(anc[u]);
}

void dfs1(int u) {
    siz[u] = u <= n;
    for (auto v : e[u]) {
        dfs1(v);
        siz[u] += siz[v];
        gg[u] += gg[v];
    }
    can[u] = gg[u] + siz[u] - 1 == siz[u] * (siz[u] - 1) / 2;
}

void dfs2(int u) {
    siz[u] = u <= n;
    f[u][0] = 1;
    for (auto v : e[u]) {
        dfs2(v);
        for (int i = siz[u] + siz[v]; i >= 0; i--) {
            int res = 0;
            for (int j = std::max(0, i - siz[u]); j <= siz[v] && j <= i; j++) {
                res = add(res, 1ll * f[u][i - j] * f[v][j] % mod);
            }
            f[u][i] = res;
        }
        siz[u] += siz[v];
    }
    f[u][0] = 0;
    if (can[u]) { f[u][1] = add(f[u][1], 1); }
}

int main() {
    n = read();
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            int w = read();
            if (u < v) { edg[m++] = (Edge) {u, v, w}; }
        }
    }
    std::sort(edg, edg + m); _n = n;
    for (int u = 1; u <= n * 2; u++) {
        anc[u] = u;
    }
    for (int i = 0, j; i < m; i = j) {
        std::vector<int> p;
        tms++;
        for (j = i; j < m && edg[i].w == edg[j].w; j++) {
            int u = edg[j].u, v = edg[j].v;
            u = find(u); v = find(v);
            if (u == v) { gg[u]++; continue; }
            anc[u] = v;
            if (vis[u] != tms) { p.push_back(u); }
            if (vis[v] != tms) { p.push_back(v); }
        }
        tms++; tms2++;
        for (auto u : p) {
            if (vis[u] == tms) { continue; }
            vis[u] = tms;
            if (vis2[find(u)] != tms2) {
                vis2[find(u)] = tms2;
                id[find(u)] = ++_n;
                id[_n] = _n;
            }
        }
        tms++;
        for (auto u : p) {
            if (vis[u] == tms) { continue; }
            vis[u] = tms;
            e[id[find(u)]].push_back(u);
        }
        tms++;
        for (auto u : p) {
            if (vis[u] == tms) { continue; }
            vis[u] = tms;
            anc[find(u)] = id[find(u)];
        }
    }
    dfs1(_n); dfs2(_n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", f[_n][i]);
    }
    return 0;
}