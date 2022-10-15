#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5, L = 19;

int n, q, s, t, ans;
std::vector<std::pair<int, int>> e[N];

namespace DiamaterFinder {
    int dis[N];

    void dfs(int u, int fa) {
        for (auto i : e[u]) {
            int v = i.first, w = i.second;
            if (v == fa) { continue; }
            dis[v] = dis[u] + w;
            dfs(v, u);
        }
    }
    void solve() {
        dfs(1, 0);
        s = std::max_element(dis + 1, dis + n + 1) - dis;
        dfs(s, 0);
        t = std::max_element(dis + 1, dis + n + 1) - dis;
    }
}

int *disp;

bool compare(std::pair<int, int> i, std::pair<int, int> j) {
    return disp[i.first] - disp[i.second] > disp[j.first] - disp[j.second];
}

struct RootedTree {
    int rt, lgn, ft[L][N], dis[N], far[N], hs[N], top[N], bot[N], cov[N], sum[N];
    std::vector<std::pair<int, int>> d;

    void dfs1(int u, int fa) {
        ft[0][u] = fa;
        for (int i = 1; i <= lgn; i++) {
            ft[i][u] = ft[i - 1][ft[i - 1][u]];
        }
        far[u] = dis[u];
        for (auto i : e[u]) {
            int v = i.first, w = i.second;
            if (v == fa) { continue; }
            dis[v] = dis[u] + w;
            dfs1(v, u);
            far[u] = std::max(far[u], far[v]);
            if (far[hs[u]] < far[v]) { hs[u] = v; }
        }
    }
    void dfs2(int u, int tp) {
        top[u] = tp; bot[u] = u;
        if (hs[u] > 0) {
            dfs2(hs[u], tp);
            bot[u] = bot[hs[u]];
        }
        if (u == tp) {
            d.push_back({bot[u], ft[0][u]});
        }
        for (auto i : e[u]) {
            int v = i.first;
            if (v == ft[0][u] || v == hs[u]) { continue; }
            dfs2(v, v);
        }
    }
    void build(int _rt) {
        rt = _rt; lgn = log(n) / log(2) + 1e-7;
        dfs1(rt, 0); dfs2(rt, rt); disp = dis;
        std::sort(d.begin(), d.end(), compare);
        cov[0] = -1;
        for (int i = 0; i < d.size(); i++) {
            sum[i + 1] = sum[i] + dis[d[i].first] - dis[d[i].second];
            for (int u = d[i].first; u != d[i].second; u = ft[0][u]) {
                cov[u] = i;
            }
        }
    }

    int query(int s, int k) {
        k = std::min(k * 2 - 1, (int) d.size());
        int res, u, v;
        if (cov[s] < k) {
            res = sum[k];
        } else {
            u = s, v;
            for (int i = lgn; i >= 0; i--) {
                v = ft[i][u];
                if (cov[v] >= k) { u = v; }
            }
            u = ft[0][u];
            res = sum[k] + far[s] - dis[d[cov[u]].first];
            u = s;
            for (int i = lgn; i >= 0; i--) {
                v = ft[i][u];
                if (cov[v] >= k - 1) { u = v; }
            }
            u = ft[0][u];
            res = std::max(res, sum[k - 1] + far[s] - dis[u]);
        }
        return res;
    }
} sr, tr;

int main() {
    n = read(); q = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w}); e[v].push_back({u, w});
    }
    DiamaterFinder::solve();
    sr.build(s); tr.build(t);
    for (int i = 0; i < q; i++) {
        int u = read(), k = read();
        u = (u - 1 + ans) % n + 1;
        k = (k - 1 + ans) % n + 1;
        ans = std::max(sr.query(u, k), tr.query(u, k));
        printf("%d\n", ans);
    }
    return 0;
}