#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, q, s, t, rt, ans, f[N];
long long k, dis1[N], diss[N], dist[N], dis[N];
std::vector<std::pair<int, int>> e[N];
std::vector<long long> d;
std::vector<int> p;

void getDis(int u, int fa, long long dis[]) {
    for (auto i : e[u]) {
        int v = i.first, w = i.second;
        if (v == fa) { continue; }
        dis[v] = dis[u] + w;
        getDis(v, u, dis);
    }
}
void getFurthest() {
    getDis(1, 0, dis1);
    s = std::max_element(dis1 + 1, dis1 + n + 1) - dis1;
    getDis(s, 0, diss);
    t = std::max_element(diss + 1, diss + n + 1) - diss;
    getDis(t, 0, dist);
    for (int u = 1; u <= n; u++) {
        dis[u] = std::max(diss[u], dist[u]);
    }
}

void dfs(int u, int fa) {
    d.push_back(dis[u]);
    p.push_back(u);
    int v = p[std::lower_bound(d.begin(), d.end(), dis[u] - k) - d.begin() - 1];
    f[u] = 1; f[v]--;
    for (auto i : e[u]) {
        int v = i.first;
        if (v == fa) { continue; }
        dfs(v, u);
        f[u] += f[v];
    }
    ans = std::max(ans, f[u]);
    d.pop_back();
    p.pop_back();
}

int main() {
    n = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w}); e[v].push_back({u, w});
    }
    getFurthest();
    rt = std::min_element(dis + 1, dis + n + 1) - dis;
    d.push_back(-1e18);
    p.push_back(0);
    q = read();
    for (int i = 0; i < q; i++) {
        scanf("%lld", &k);
        ans = 0;
        dfs(rt, 0);
        printf("%d\n", ans);
    }
    return 0;
}