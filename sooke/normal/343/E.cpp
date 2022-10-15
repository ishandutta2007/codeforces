#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int inf = 1e9;
const int N = 2e2 + 5, E = 5e3 + 5;

int n, m, q, s, t, tot, ans, dis[N], anc[N], fst[N], lst[N], nxt[N];
bool vis[N];

struct Edge {
    int u, v, w;
} edg[N];

bool operator <(const Edge &i, const Edge &j) {
    return i.w > j.w;
}

struct List {
    int tot, fst[N], nxt[E], to[E], val[E], flw[E];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v, int w) {
        nxt[tot] = fst[u]; to[tot] = v; val[tot] = w; fst[u] = tot++;
    }
    inline void link(int u, int v, int w) {
        insert(u, v, w); insert(v, u, w);
    }
} e;

bool bfs() {
    memset(dis, 60, n * 4 + 4);
    dis[s] = 0;
    std::queue<int> que;
    for (que.push(s); !que.empty(); que.pop()) {
        int u = que.front();
        for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
            int v = e.to[i], w = e.val[i], f = e.flw[i];
            if (dis[v] > dis[u] + 1 && w > f) {
                dis[v] = dis[u] + 1;
                if (v == t) { return true; }
                que.push(v);
            }
        }
    }
    return false;
}

int dinic(int u, int f) {
    if (u == t) { return f; }
    vis[u] = true;
    int lef = f;
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i], w = e.val[i], f = e.flw[i];
        if (dis[v] == dis[u] + 1 && w > f && !vis[v]) {
            int def = dinic(v, std::min(lef, w - f));
            if (def == 0) { dis[v] = -1; continue; }
            lef -= def; e.flw[i] += def; e.flw[i ^ 1] -= def;
            if (lef == 0) { break; }
        }
    }
    vis[u] = false;
    return f - lef;
}

void build(std::vector<int> p) {
    if (p.size() <= 1) { return; }
    do {
        s = p[rand() % p.size()];
        t = p[rand() % p.size()];
    } while (s == t);
    memset(e.flw, 0, e.tot * 4);
    int f = 0;
    while (bfs()) { f += dinic(s, inf); }
    ans += f;
    edg[tot++] = (Edge) {s, t, f};
    std::vector<int> l, r;
    for (auto u : p) {
        if (dis[u] <= n) {
            l.push_back(u);
        } else {
            r.push_back(u);
        }
    }
    build(l); build(r);
}

int find(int u) {
    return anc[u] == u ? u : anc[u] = find(anc[u]);
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(), w = read();
        e.link(u, v, w);
    }
    std::vector<int> all;
    for (int u = 1; u <= n; u++) { all.push_back(u); }
    build(all);
    for (int u = 1; u <= n; u++) { anc[u] = fst[u] = lst[u] = u; }
    std::sort(edg, edg + tot);
    for (int i = 0; i < tot; i++) {
        int u = edg[i].u, v = edg[i].v;
        u = find(u); v = find(v);
        anc[u] = v;
        nxt[lst[u]] = fst[v];
        fst[v] = fst[u];
    }
    printf("%d\n", ans);
    for (int u = fst[find(1)]; u > 0; u = nxt[u]) {
        printf("%d ", u);
    }
    return 0;
}