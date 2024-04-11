#include <bits/stdc++.h>

const int inf = 2e9;
const int N = 205, V = 4e4 + 5, E = 1e6 + 5;

int n, m, s, t, ban, a[N][N], b[V], num, tb[V], dis[V], cur[V];
long long ans, nowf;
bool vis[V];
std::vector<int> pi[V], pj[V];

struct List {
    int tot, fst[V], nxt[E], to[E], val[E], flw[E];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v, int w) {
        nxt[tot] = fst[u]; to[tot] = v; val[tot] = w; flw[tot] = 0; fst[u] = tot++;
    }
    inline void link(int u, int v, int w) {
        insert(u, v, w); insert(v, u, w);
    }
} e;

inline int get(int i, int j) {
    return i * m + j + 1;
}

bool bfs() {
    for (int u = s; u <= t; u++) {
        dis[u] = inf; cur[u] = e.fst[u];
    }
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

int dinic(int u, int nowf) {
    if (u == t) { return nowf; }
    int lef = nowf;
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
    return nowf - lef;
}

bool _bfs() {
    for (int u = s; u <= t; u++) {
        dis[u] = inf; cur[u] = e.fst[u];
    }
    dis[t] = 0;
    std::queue<int> que;
    for (que.push(t); !que.empty(); que.pop()) {
        int u = que.front();
        for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
            int v = e.to[i], w = e.val[i], f = e.flw[i];
            if (u == t && b[v] != ban) { continue; }
            if (dis[v] > dis[u] + 1 && w > f) {
                dis[v] = dis[u] + 1;
                if (v == s) { return true; }
                que.push(v);
            }
        }
    }
    return false;
}

int _dinic(int u, int nowf) {
    if (u == s) { return nowf; }
    int lef = nowf;
    vis[u] = true;
    for (int &i = cur[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i], w = e.val[i], f = e.flw[i];
        if (dis[v] == dis[u] + 1 && w > f && !vis[v]) {
            int def = _dinic(v, std::min(lef, w - f));
            if (def == 0) { dis[v] = -1; continue; }
            lef -= def; e.flw[i] += def; e.flw[i ^ 1] -= def;
            if (lef == 0) { break; }
        }
    }
    vis[u] = false;
    return nowf - lef;
}

int main() {
    scanf("%d", &n); m = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] > 0) { tb[num++] = a[i][j]; }
        }
    }
    std::sort(tb, tb + num);
    num = std::unique(tb, tb + num) - tb;
    s = 0; t = n * m + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != -1) {
                if (a[i][j] != 0) {
                    int x = std::lower_bound(tb, tb + num, a[i][j]) - tb;
                    pi[x].push_back(i); pj[x].push_back(j);
                    b[get(i, j)] = x + 1;
                    e.insert(get(i, j), t, inf);
                    e.insert(t, get(i, j), 0);
                }
                if (i + 1 < n && a[i + 1][j] != -1) {
                    e.link(get(i, j), get(i + 1, j), 1);
                }
                if (j + 1 < m && a[i][j + 1] != -1) {
                    e.link(get(i, j), get(i, j + 1), 1);
                }
            }
        }
    }
    for (int k = 0; k < num; k++) {
        ban = k + 1;
        while (_bfs()) { nowf -= _dinic(t, inf); }
        for (int _ = 0; _ < pi[k].size(); _++) {
            int u = get(pi[k][_], pj[k][_]);
            for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
                if (e.to[i] == t) { e.val[i] = 0; }
            }
            e.link(s, u, inf);
        }
        while (bfs()) { nowf += dinic(s, inf); }
        ans += 1ll * nowf * (tb[k + 1] - tb[k]);
    }
    printf("%lld\n", ans);
    return 0;
}