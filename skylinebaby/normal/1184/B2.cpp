#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
int w[maxn][maxn], x[maxn], y[maxn], a[maxn], f[maxn], d[maxn];
int ca[maxn], cb[maxn];

struct dinic {
    static const int maxn = 2000 + 5;
    static const int inf = 1e9;
    struct edge {
        int dest, cap, rev;
        edge(int d, int c, int r): dest(d), cap(c), rev(r) {}
    };
    vector<edge> g[maxn];
    int qu[maxn], ql, qr;
    int lev[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i)
            g[i].clear();
    }
    void add_edge(int a, int b, int c) {
        g[a].emplace_back(b, c, g[b].size() - 0);
        g[b].emplace_back(a, 0, g[a].size() - 1);
    }
    bool bfs(int s, int t) {
        memset(lev, -1, sizeof(lev));
        lev[s] = 0;
        ql = qr = 0;
        qu[qr++] = s;
        while (ql < qr) {
            int x = qu[ql++];
            for (edge &e : g[x]) if (lev[e.dest] == -1 && e.cap > 0) {
                lev[e.dest] = lev[x] + 1;
                qu[qr++] = e.dest;
            }
        }
        return lev[t] != -1;
    }
    int dfs(int x, int t, int flow) {
        if (x == t) return flow;
        int res = 0;
        for (edge &e : g[x]) if (e.cap > 0 && lev[e.dest] == lev[x] + 1) {
            int f = dfs(e.dest, t, min(e.cap, flow - res));
            res += f;
            e.cap -= f;
            g[e.dest][e.rev].cap += f;
        }
        if (res == 0) lev[x] = -1;
        return res;
    }
    int operator()(int s, int t) {
        int flow = 0;
        for (; bfs(s, t); flow += dfs(s, t, inf));
        return flow;
    }
};

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
            w[i][j] = i == j ? 0 : 1e8;
    }
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        if (u == v) continue;
        w[u][v] = w[v][u] = 1;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
        }
    }

    int s, b, k, h; scanf("%d%d%d%d", &s, &b, &k, &h);
    for (int i = 0; i < s; ++i) {
        scanf("%d%d%d", &x[i], &a[i], &f[i]);
        --x[i];
        ++ca[x[i]];
    }
    for (int i = 0; i < b; ++i) {
        scanf("%d%d", &y[i], &d[i]);
        --y[i];
        ++cb[y[i]];
    }

    dinic flow;
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < b; ++j) {
            if (a[i] >= d[j] && w[x[i]][y[j]] <= f[i])
                flow.add_edge(i, j + s, 1);
        }
    }

    for (int i = 0; i < s; ++i) flow.add_edge(s + b, i, 1);
    for (int i = 0; i < b; ++i) flow.add_edge(i + s, s + b + 1, 1);

    long long ans = s * 1ll * h;
    int prv = 0;

    for (int i = 1; i <= s; ++i) {
        flow.add_edge(s + b + 2, s + b, 1);
        prv += flow(s + b + 2, s + b + 1);
        ans = min(ans, (s - i) * 1ll * h + prv * 1ll * k);
    }

    printf("%lld\n", ans);
    return 0;
}