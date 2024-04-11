#include <cstdio>
#include <cstring>
#include <algorithm>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 5005, maxE = 100005;

int n, m, s, t, dis[maxN], q[maxN];
long long ans;
bool vis[maxN];

struct List {
    int len, fst[maxN], nxt[maxE], v[maxE], w[maxE], fl[maxE];
    
    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int vv, int ww) { v[len] = vv, w[len] = ww, nxt[len] = fst[u], fst[u] = len++; }
    inline void connect(int u, int vv, int ww) { insert(u, vv, ww), insert(vv, u, 0); }
} ls;

bool bfs() {
    memset(dis, 0, sizeof(dis)); dis[q[1] = s] = 1;
    for (int l = 1, r = 1; l <= r; l++) {
        int u = q[l];
        for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
            int v = ls.v[i], w = ls.w[i], fl = ls.fl[i];
            if (!dis[v] && fl < w) {
                dis[v] = dis[u] + 1;
                if (v == t) { return true; }
                q[++r] = v;
            }
        }
    }
    return false;
}
long long dinic(int u, long long f) {
    if (u == t) { return f; }
    long long lef = f;
    vis[u] = true;
    for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
        int v = ls.v[i], w = ls.w[i], fl = ls.fl[i];
        if (dis[v] == dis[u] + 1 && fl < w && !vis[v]) {
            long long df = dinic(v, std::min(lef, (long long) w - fl));
            if (!df) { dis[v] = 0; continue; }
            lef -= df; ls.fl[i] += df; ls.fl[i ^ 1] -= df;
            if (!lef) { break; }
        }
    }
    vis[u] = false;
    return f - lef;
}

int main() {
    n = read(); m = read(); s = 0; t = n + m + 1;
    for (int i = 1; i <= n; i++) { ls.connect(s, i, read()); } //     .
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read(); ans += w;
        ls.connect(u, n + i, 1e9); ls.connect(v, n + i, 1e9); //     inf.
        ls.connect(n + i, t, w); //     .
    }
    while (bfs()) { ans -= dinic(s, 1e18); }
    printf("%I64d\n", ans);
    return 0;
}