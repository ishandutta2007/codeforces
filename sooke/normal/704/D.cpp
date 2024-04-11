#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int inf = 1e9;
const int N = 1e5 + 5, V = N * 2, E = 4e6 + 5;

int n1, n2, m, q, k1, k2, a1[N], a2[N], tb1[N], tb2[N], cnt1[N], cnt2[N], lim1[N], lim2[N];
int s, t, ss, tt, ans, dis[V], cur[V], deg[V];
bool flag, vis[V];

struct List {
    int tot, fst[V], nxt[E], to[E], val[E], flw[E];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v, int w) {
        nxt[tot] = fst[u]; to[tot] = v; val[tot] = w; fst[u] = tot++;
    }
    inline void link(int u, int v, int w) {
        insert(u, v, w); insert(v, u, 0);
    }
} e;

bool bfs() {
    memset(dis, 60, sizeof(dis));
    memcpy(cur, e.fst, sizeof(cur));
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

int dinic(int u, int _f) {
    if (u == t) { return _f; }
    int lef = _f;
    vis[u] = true;
    for (int &i = cur[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i], w = e.val[i], f = e.flw[i];
        if (dis[v] == dis[u] + 1 && w > f && !vis[v]) {
            int def = dinic(v, std::min(lef, w - f));
            if (def == 0) { dis[v] = -1; continue; }
            lef -= def; e.flw[i] += def; e.flw[i ^ 1] -= def;
            if (lef == 0) { break; }
        }
    }
    vis[u] = false;
    return _f - lef;
}

int main() {
    m = read(); q = read(); k1 = read(); k2 = read();
    if (k1 > k2) { std::swap(k1, k2); flag = true; }
    for (int i = 0; i < m; i++) {
        a1[i] = read(); tb1[n1++] = a1[i];
        a2[i] = read(); tb2[n2++] = a2[i];
    }
    std::sort(tb1, tb1 + n1);
    n1 = std::unique(tb1, tb1 + n1) - tb1;
    std::sort(tb2, tb2 + n2);
    n2 = std::unique(tb2, tb2 + n2) - tb2;
    s = 0; t = n1 + n2 + 3;
    ss = n1 + n2 + 1; tt = n1 + n2 + 2;
    for (int i = 0; i < m; i++) {
        a1[i] = std::lower_bound(tb1, tb1 + n1, a1[i]) - tb1;
        a2[i] = std::lower_bound(tb2, tb2 + n2, a2[i]) - tb2;
        cnt1[a1[i]]++; cnt2[a2[i]]++;
        int u = a1[i] + 1, v = n1 + a2[i] + 1;
        e.link(u, v, 1);
    }
    memset(lim1, 60, n1 * 4);
    memset(lim2, 60, n2 * 4);
    for (int i = 0; i < q; i++) {
        int opt = read(), x = read(), y = read(), u;
        if (opt == 1) {
            u = std::lower_bound(tb1, tb1 + n1, x) - tb1;
            if (tb1[u] == x) { lim1[u] = std::min(lim1[u], y); }
        } else {
            u = std::lower_bound(tb2, tb2 + n2, x) - tb2;
            if (tb2[u] == x) { lim2[u] = std::min(lim2[u], y); }
        }
    }
    for (int i = 0; i < n1; i++) {
        int u = i + 1;
        int l = std::max(0, (cnt1[i] - lim1[i] + 1) / 2);
        int r = (cnt1[i] + lim1[i]) / 2;
        if (l > r) { printf("-1\n"); return 0; }
        e.link(ss, u, r - l);
        deg[ss] -= l; deg[u] += l;
    }
    for (int i = 0; i < n2; i++) {
        int u = n1 + i + 1;
        int l = std::max(0, (cnt2[i] - lim2[i] + 1) / 2);
        int r = (cnt2[i] + lim2[i]) / 2;
        if (l > r) { printf("-1\n"); return 0; }
        e.link(u, tt, r - l);
        deg[u] -= l; deg[tt] += l;
    }
    for (int u = 1; u <= tt; u++) {
        if (deg[u] > 0) { e.link(s, u, deg[u]); }
        if (deg[u] < 0) { e.link(u, t, -deg[u]); }
    }
    e.link(tt, ss, inf);
    while (bfs()) { dinic(s, inf); }
    s = ss; t = tt; ans = e.flw[e.tot - 2];
    e.val[e.tot - 1] = e.flw[e.tot - 1] = 0;
    e.val[e.tot - 2] = e.flw[e.tot - 2] = 0;
    while (bfs()) { ans += dinic(s, inf); }
    printf("%lld\n", 1ll * k1 * ans + 1ll * k2 * (m - ans));
    for (int i = 0; i < m; i++) {
        putchar(e.flw[i * 2] != flag ? 'r' : 'b');
    }
    return 0;
}