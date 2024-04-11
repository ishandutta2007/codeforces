#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int inf = 2e9;
const int N = 1e2 + 5, V = 1e5 + 5, E = 1e6 + 5;

int n, m, s, t, dis[V], flw[V], pre[V], a[N][N];
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
    for (int u = s; u <= t; u++) { dis[u] = inf; }
    dis[s] = 0; flw[s] = inf;
    std::queue<int> que;
    for (que.push(s); !que.empty(); que.pop()) {
        int u = que.front();
        for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
            int v = e.to[i], w = e.val[i], f = e.flw[i], c = e.cst[i];
            if (dis[v] > dis[u] + c && w > f) {
                dis[v] = dis[u] + c;
                flw[v] = std::min(flw[u], w - f);
                pre[v] = i;
                if (!inq[v]) { inq[v] = true; que.push(v); }
            }
        }
        inq[u] = false;
    }
    return dis[t] < inf;
}

void ek() {
    for (int u = t, i; u != s; u = e.to[i ^ 1]) {
        i = pre[u];
        e.flw[i] += flw[t]; e.flw[i ^ 1] -= flw[t];
    }
}

int check(int u) {
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i], f = e.flw[i];
        if (f == -1) { return v; }
    }
    return -1;
}

int main() {
    n = read(); m = read();
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            a[u][v] = u == v ? 0 : 2;
        }
    }
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        a[u][v] = 1; a[v][u] = 0;
    }
    s = 0; t = n + n * n + 1;
    for (int u = 1; u <= n; u++) {
        for (int i = 1; i < n; i++) {
            e.link(s, u, 1, i - 1);
        }
    }
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (u < v) {
                if (a[u][v] == 0) {
                    e.link(u, u * n + v, 1, 0);
                    e.link(u * n + v, t, 1, 0);
                }
                if (a[u][v] == 1) {
                    e.link(v, u * n + v, 1, 0);
                    e.link(u * n + v, t, 1, 0);
                }
                if (a[u][v] == 2) {
                    e.link(u, u * n + v, 1, 0);
                    e.link(v, u * n + v, 1, 0);
                    e.link(u * n + v, t, 1, 0);
                }
            }
        }
    }
    while (spfa()) { ek(); }
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (u < v && a[u][v] == 2) {
                int i = check(u * n + v);
                a[u][v] = i == v;
                a[v][u] = i == u;
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            printf("%d", a[u][v]);
        }
        printf("\n");
    }
    return 0;
}