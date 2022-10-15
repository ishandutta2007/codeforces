#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int inf = 1e9;
const int N = 2e2 + 5, V = N * 2, E = 1e6 + 5;

int n1, n2, m, k1, k2;
int s, t, ss, tt, dis[V], flw[V], pre[V], deg[V];
char str1[N], str2[N], str[N];
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
} e, _e;

bool spfa() {
    memset(dis, 60, sizeof(dis));
    dis[s] = 0;
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
    return dis[t] < inf && flw[t] > 0;
}

void ek() {
    flw[s] = std::max(0, flw[s] - flw[t]);
    for (int u = t; u != s; u = e.to[pre[u] ^ 1]) {
        e.flw[pre[u]] += flw[t];
        e.flw[pre[u] ^ 1] -= flw[t];
    }
}

int maxFlow() {
    flw[s] = inf;
    while (spfa()) { ek(); }
    return inf - flw[s];
}

int main() {
    n1 = read(); n2 = read(); m = read(); k1 = read(); k2 = read();
    s = 0; t = n1 + n2 + 3;
    ss = n1 + n2 + 1; tt = n1 + n2 + 2;
    scanf("%s%s", str1 + 1, str2 + 1);
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        e.link(u, n1 + v, 1, k1);
        e.link(n1 + v, u, 1, k2);
    }
    for (int i = 1; i <= n1; i++) {
        switch (str1[i]) {
            case 'U': {
                e.link(ss, i, inf, 0);
                e.link(i, tt, inf, 0);
                break;
            }
            case 'R': {
                e.link(ss, i, inf, 0);
                deg[ss]--; deg[i]++;
                break;
            }
            case 'B': {
                e.link(i, tt, inf, 0);
                deg[i]--; deg[tt]++;
                break;
            }
        }
    }
    for (int i = 1; i <= n2; i++) {
        switch (str2[i]) {
            case 'U': {
                e.link(ss, n1 + i, inf, 0);
                e.link(n1 + i, ss, inf, 0);
                break;
            }
            case 'R': {
                e.link(n1 + i, tt, inf, 0);
                deg[n1 + i]--; deg[tt]++;
                break;
            }
            case 'B': {
                e.link(ss, n1 + i, inf, 0);
                deg[ss]--; deg[n1 + i]++;
                break;
            }
        }
    }
    int sum = 0, ans = 0;
    for (int u = 1; u <= tt; u++) {
        if (deg[u] > 0) { e.link(s, u, deg[u], 0); sum += deg[u]; }
        if (deg[u] < 0) { e.link(u, t, -deg[u], 0); }
    }
    e.link(ss, tt, inf, 0);
    e.link(tt, ss, inf, 0);
    ans = maxFlow();
    if (ans != sum) { printf("-1\n"); return 0; }
    int ans1 = 0, ans2 = 0;
    e.val[e.tot - 1] = e.flw[e.tot - 1] = 0;
    e.val[e.tot - 2] = e.flw[e.tot - 2] = 0;
    _e = e; s = ss; t = tt;
    while (spfa()) { ek(); }
    for (int u = 1; u <= tt; u++) {
        for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
            if (i & 1) { continue; }
            ans1 += e.flw[i] * e.cst[i];
        }
    }
    std::swap(e, _e); s = tt; t = ss;
    while (spfa()) { ek(); }
    for (int u = 1; u <= tt; u++) {
        for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
            if (i & 1) { continue; }
            ans2 += e.flw[i] * e.cst[i];
        }
    }
    if (ans1 < ans2) {
        ans = ans1;
        for (int i = 0; i < m; i++) {
            str[i] = 'U';
            if (_e.flw[i * 4] == 1) { str[i] = 'R'; }
            if (_e.flw[i * 4 + 2] == 1) { str[i] = 'B'; }
        }
    } else {
        ans = ans2;
        for (int i = 0; i < m; i++) {
            str[i] = 'U';
            if (e.flw[i * 4] == 1) { str[i] = 'R'; }
            if (e.flw[i * 4 + 2] == 1) { str[i] = 'B'; }
        }
    }
    printf("%d\n%s\n", ans, str);
    return 0;
}