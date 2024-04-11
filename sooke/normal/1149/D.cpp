#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int N = 72, E = 405, C = 17, A = 1 << C, V = N << C;

int n, m, k, c, all, ans, col[N], anc[N], siz[N], dis[V];
std::priority_queue<std::pair<int, int>> que;

struct List {
    int tot, fst[N], nxt[E], to[E], val[E];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v, int w) { nxt[tot] = fst[u]; to[tot] = v; val[tot] = w; fst[u] = tot++; }
    inline void link(int u, int v, int w) { insert(u, v, w); insert(v, u, w); }
} e;

int findAnc(int u) { return anc[u] == u ? u : anc[u] = findAnc(anc[u]); }

void dijkstra() {
    memset(dis, 127, sizeof(int) * (n + 1 << c)); dis[1 << c] = 0; que.push({0, 1 << c});
    for (; !que.empty(); ) {
        int d = -que.top().first, u = que.top().second >> c, s = que.top().second & all - 1; que.pop();
        if (dis[u << c | s] < d) { continue; }
        for (int i = e.fst[u], v, w, t; ~i; i = e.nxt[i]) {
            v = e.to[i]; w = e.val[i]; t = s;
            if (col[u] != -1 && col[u] != col[v]) { t |= 1 << col[u]; }
            if (col[v] != -1 && (1 << col[v] & s)) { continue; }
            if (anc[u] == anc[v] && w != k) { continue; }
            if (dis[v << c | t] > dis[u << c | s] + w) {
                dis[v << c | t] = dis[u << c | s] + w;
                que.push({-dis[v << c | t], v << c | t});
            }
        }
    }
}

int main() {
    scanf("%d%d%d%*d", &n, &m, &k);
    for (int i = 1; i <= n; i++) { anc[i] = i; }
    for (int i = 1, u, v, w; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w); e.link(u, v, w);
        if (w == k) {
            u = findAnc(u); v = findAnc(v);
            if (u != v) { anc[u] = v; }
        }
    }
    for (int i = 1; i <= n; i++) { siz[findAnc(i)]++; }
    for (int i = 1; i <= n; i++) {
        if (anc[i] == i) { col[i] = siz[i] <= 3 ? -1 : c++; }
    }
    for (int i = 1; i <= n; i++) { col[i] = col[anc[i]]; }
    all = 1 << c; dijkstra();
    for (int i = 1; i <= n; i++) {
        ans = 2e9;
        for (int j = 0; j < all; j++) { ans = std::min(ans, dis[i << c | j]); }
        printf("%d ", ans);
    }
    return 0;
}