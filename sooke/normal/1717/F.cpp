#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int inf = 1e9;
const int N = 1e5 + 5, E = 1e6 + 5;

int n, m, s, p, t, dis[N], cur[N], eu[N], ev[N], dir[N], a[N], opt[N];
bool vis[N];
std::map<std::pair<int, int>, int> map;

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
    memcpy(cur, e.fst, (t + 1) * 4);
    memset(dis, 60, (t + 1) * 4);
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
    return f - lef;
}

bool solve() {
    int pos = 0, neg = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        if (opt[i] == 0) { continue; }
        if (a[i] % 2 != 0) { return false; }
        a[i] /= 2;
        if (a[i] > 0) { pos += a[i]; }
        if (a[i] < 0) { neg -= a[i]; }
    }
    res = std::max(pos, neg);
    s = 0; p = n + 1; t = n + 2;
    if (pos < neg) { e.link(s, p, neg - pos); }
    if (pos > neg) { e.link(p, t, pos - neg); }
    for (int i = 1; i <= n; i++) {
        if (opt[i] == 0) {
            if (pos < neg) { e.link(p, i, inf); }
            if (pos > neg) { e.link(i, p, inf); }
            continue;
        }
        if (a[i] > 0) { e.link(s, i, +a[i]); }
        if (a[i] < 0) { e.link(i, t, -a[i]); }
    }
    for (int i = 1; i <= m; i++) {
        e.link(eu[i], ev[i], 1);
    }
    while (bfs()) { res -= dinic(s, inf); }
    if (res > 0) { return false; }
    for (int u = 1; u <= n; u++) {
        for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
            int v = e.to[i], w = e.val[i], f = e.flw[i];
            if (v >= 1 && v <= n && w == 1) {
                if (f == 1) { dir[map[{u, v}]] = -1; }
            }
        }
    }
    return true;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        opt[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    for (int i = 1; i <= m; i++) {
        eu[i] = read(); ev[i] = read();
        dir[i] = 1; a[eu[i]]++; a[ev[i]]--;
        map[{eu[i], ev[i]}] = i;
        map[{ev[i], eu[i]}] = -i;
    }
    if (solve()) {
        printf("YES\n");
        for (int i = 1; i <= m; i++) {
            if (dir[i] == 1) {
                printf("%d %d\n", eu[i], ev[i]);
            } else {
                printf("%d %d\n", ev[i], eu[i]);
            }
        }
    } else {
        printf("NO\n");
    }
    return 0;
}