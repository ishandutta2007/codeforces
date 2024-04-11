#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int inf = 1e9;
const int V = 1e2 + 5, E = 1e6 + 5;

int n, m, s, t, ans, dis[V], flw[V], pre[V], deg[V];
bool inq[V];

struct List {
    int tot, fst[V], nxt[E], to[E], val[E], flw[E], cst[E];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v, int w, int c) {
        nxt[tot] = fst[u]; to[tot] = v; val[tot] = w; cst[tot] = c; fst[u] = tot++;
    }
    inline void link(int u, int v, int w, int c) {
        insert(u, v, w, c); insert(v, u, 0, -c);
    }
} e;

bool spfa() {
    memset(dis, 60, sizeof(dis));
    dis[s] = 0; flw[s] = inf;
    std::queue<int> que;
    for (que.push(s); !que.empty(); que.pop()) {
        int u = que.front();
        for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
            int v = e.to[i], w = e.val[i], f = e.flw[i], c = e.cst[i];
            if (dis[v] > dis[u] + c && w > f) {
                dis[v] = dis[u] + c; pre[v] = i;
                flw[v] = std::min(flw[u], w - f);
                if (!inq[v]) { inq[v] = true; que.push(v); }
            }
        }
        inq[u] = false;
    }
    return dis[t] < inf;
}

void ek() {
    ans += flw[t] * dis[t];
    for (int u = t; u != s; u = e.to[pre[u] ^ 1]) {
        e.flw[pre[u]] += flw[t];
        e.flw[pre[u] ^ 1] -= flw[t];
    }
}

int main() {
    n = read(); m = read();
    s = 0; t = n + 1;
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(), w = read(), f = read();
        if (w > f) {
            e.link(u, v, inf, 2);
            e.link(u, v, w - f, 1);
            e.link(v, u, f, 1);
            deg[u] -= f; deg[v] += f;
        } else {
            e.link(u, v, inf, 2);
            e.link(u, v, f - w, 0);
            e.link(v, u, w, 1);
            deg[u] -= w; deg[v] += w;
            ans += f - w;
        }
    }
    for (int u = 1; u <= n; u++) {
        if (deg[u] > 0) { e.link(s, u, deg[u], 0); }
        if (deg[u] < 0) { e.link(u, t, -deg[u], 0); }
    }
    e.link(n, 1, inf, 0);
    while (spfa()) { ek(); }
    printf("%d\n", ans);
    return 0;
}