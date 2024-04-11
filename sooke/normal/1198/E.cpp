#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5, E = 1e6 + 5, M = 2e2 + 5;

int n, m, s, t, ans, dis[N], numx, numy, bx[M], by[M];
bool vis[N];

struct Block { int x, y, r, c; } a[M];

struct List {
    int tot, fst[N], nxt[E], to[E], val[E], flw[E];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v, int w) {
        nxt[tot] = fst[u]; to[tot] = v; val[tot] = w; fst[u] = tot++;
    }
    inline void link(int u, int v, int w) {
        insert(u, v, w); insert(v, u, 0);
    }
} e;

bool bfs() {
    std::fill(dis + s, dis + t + 1, 0);
    std::queue<int> que; dis[s] = 1;
    for (que.push(s); !que.empty(); que.pop()) {
        int u = que.front();
        for (int i = e.fst[u], v, w, f; ~i; i = e.nxt[i]) {
            v = e.to[i]; w = e.val[i]; f = e.flw[i];
            if (dis[v] == 0 && w > f) {
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
    vis[u] = true; int lf = _f;
    for (int i = e.fst[u], v, w, f; ~i; i = e.nxt[i]) {
        v = e.to[i]; w = e.val[i]; f = e.flw[i];
        if (dis[v] == dis[u] + 1 && w > f && !vis[v]) {
            int df = dinic(v, std::min(w - f, lf));
            if (df == 0) {
                dis[v] = 0; continue;
            } lf -= df; e.flw[i] += df; e.flw[i ^ 1] -= df;
        }
        if (lf == 0) { break; }
    }
    vis[u] = false; return _f - lf;
}

int main() {
    m = read(); n = read();
    for (int i = 0; i < n; i++) {
        bx[numx++] = a[i].x = read();
        by[numy++] = a[i].y = read();
        bx[numx++] = a[i].r = read() + 1;
        by[numy++] = a[i].c = read() + 1;
    }
    std::sort(bx, bx + numx);
    numx = std::unique(bx, bx + numx) - bx;
    std::sort(by, by + numy);
    numy = std::unique(by, by + numy) - by;
    s = 0; t = numx + numy - 1;
    for (int i = 1; i < numx; i++) { e.link(s, i, bx[i] - bx[i - 1]); }
    for (int i = 1; i < numy; i++) { e.link(numx - 1 + i, t, by[i] - by[i - 1]); }
    for (int i = 0; i < n; i++) {
        a[i].x = std::lower_bound(bx, bx + numx, a[i].x) - bx;
        a[i].y = std::lower_bound(by, by + numy, a[i].y) - by;
        a[i].r = std::lower_bound(bx, bx + numx, a[i].r) - bx;
        a[i].c = std::lower_bound(by, by + numy, a[i].c) - by;
        for (int x = a[i].x; x < a[i].r; x++) {
            for (int y = a[i].y; y < a[i].c; y++) { e.link(x + 1, numx + y, 2e9); }
        }
    }
    while (bfs()) { ans += dinic(s, 2e9); }
    printf("%d\n", ans);
    return 0;
}