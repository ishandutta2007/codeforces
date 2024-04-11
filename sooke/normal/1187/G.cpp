#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int inf = 1e9;
const int N = 1e5 + 5, E = 1e7 + 5;

int n, m, q, k, k1, k2, s, t, ans, dis[N], flw[N], pre[N];
bool inq[N];

struct List {
    int tot, fst[N], nxt[E], to[E], val[E], flw[E], cst[E];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v, int w, int c) {
        nxt[tot] = fst[u]; to[tot] = v; val[tot] = w; cst[tot] = c; fst[u] = tot++;
    }
    inline void link(int u, int v, int w, int c) {
        insert(u, v, w, c); insert(v, u, 0, -c);
    }
} e;

bool spfa() {
    memset(dis, 60, (t + 2) * 4);
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
    return dis[t] < dis[t + 1];
}

void ek() {
    ans += flw[t] * dis[t];
    for (int u = t, i; u != s; u = e.to[i ^ 1]) {
        i = pre[u];
        e.flw[i] += flw[t]; e.flw[i ^ 1] -= flw[t];
    }
}

inline int get(int d, int u) {
    return d * n + u;
}

int main() {
    n = read(); m = read(); q = read(); k1 = read(); k2 = read();
    k = n + q; s = 0; t = get(k, n) + 1;
    for (int i = 0; i < q; i++) {
        int u = read();
        e.link(s, u, 1, 0);
    }
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        for (int d = 0; d < k; d++) {
            for (int j = 0; j < q; j++) {
                e.link(get(d, u), get(d + 1, v), 1, (2 * j + 1) * k2);
                e.link(get(d, v), get(d + 1, u), 1, (2 * j + 1) * k2);
            }
        }
    }
    for (int d = 1; d <= k; d++) {
        e.link(get(d, 1), t, inf, d * k1);
        for (int u = 1; u <= n; u++) {
            e.link(get(d - 1, u), get(d, u), inf, 0);
        }
    }
    while (spfa()) { ek(); }
    printf("%d\n", ans);
    return 0;
}