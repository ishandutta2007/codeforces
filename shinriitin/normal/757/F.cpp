#include <bits/stdc++.h>

using LL = long long;

const int max_N = (int) 2e5 + 21;
const int log_N = 20;

int n, m, s, Q[max_N], anc[max_N][log_N], dep[max_N], deg[max_N], ret[max_N];

std::vector<int> vec[max_N];

std::vector<std::pair<int, int>> _vec[max_N];

LL dis[max_N];

bool vis[max_N];

std::priority_queue<std::pair<LL, int>> pq;

inline void sp(int s) {
    memset(dis, 0x7f, (n + 1) * sizeof(LL));
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto &e : _vec[u]) {
            int v = e.first, w = e.second;
            LL tmp = dis[u] + w;
            if (dis[v] > tmp) {
                dis[v] = tmp;
                pq.push({-tmp, v});
            }
        }
    }
    for (int u = 1; u <= n; ++u) {
        if (dis[u] == dis[0]) continue;
        // printf("dis[%d] = %lld\n", u, dis[u]);
        for (auto &e : _vec[u]) {
            int v = e.first, w = e.second;
            LL tmp = dis[u] + w;
            if (dis[v] < tmp) continue;
            vec[u].push_back(v);
            ++deg[v];
        }
    }
}

inline void init_anc(int u) {
    dep[u] = dep[anc[u][0]] + 1;
    for (int i = 1; i < log_N; ++i) {
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    }
}

inline int lca(int u, int v) {
    if (dep[u] > dep[v]) {
        std::swap(u, v);
    }
    int k = dep[v] - dep[u];
    for (int i = 0; k; ++i, k >>= 1) {
        if (k & 1) {
            v = anc[v][i];
        }
    }
    if (u == v) return u;
    for (int i = log_N - 1; ~i; --i) {
        if (anc[u][i] == anc[v][i]) {
            continue;
        }
        u = anc[u][i];
        v = anc[v][i];
    }
    return anc[u][0];
}

void solve(int s) {
    sp(s);
    int tail = 0;
    Q[++tail] = s;
    for (int i = 1; i <= tail; ++i) {
        int u = Q[i];
        init_anc(u);
        for (auto v : vec[u]) {
            if (!--deg[v]) {
                Q[++tail] = v;
            }
            if (anc[v][0]) {
                anc[v][0] = lca(anc[v][0], u);
            } else {
                anc[v][0] = u;
            }
        }
    }
    for (int i = tail; i; --i) {
        int u = Q[i];
        ret[anc[u][0]] += ++ret[u];
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    while (m--) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        _vec[u].emplace_back(v, w);
        _vec[v].emplace_back(u, w);
    }
    solve(s);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == s) continue;
        ans = std::max(ans, ret[i]);
    }
    printf("%d\n", ans);
    return 0;
}