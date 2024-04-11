#include <bits/stdc++.h>

using LL = long long;

const int MAXN = 1e5 + 5;

std::vector<std::pair<int, int>> G[MAXN];
int n, m;

std::vector<int> key;

std::vector<std::tuple<int, int, int>> edges;

int fa[MAXN];

int Fa(int x) {
    return fa[x] == x ? x : fa[x] = Fa(fa[x]);
}

LL dist[50][MAXN];

bool vis[MAXN];

void Dijkstra(int st, int idx) {
    static std::priority_queue<std::pair<LL, int>> heap;
    
    while (!heap.empty()) heap.pop();
    
    memset(dist[idx], 0x3f, sizeof dist[idx]);
    memset(vis, 0, sizeof vis);
    
    dist[idx][st] = 0;
    heap.emplace(0, st);
    
    while (!heap.empty()) {
        int now = heap.top().second; heap.pop();
        
        if (vis[now]) continue;
        vis[now] = 1;
        
        for (auto e: G[now]) {
            int to = e.first;
            if (dist[idx][to] <= dist[idx][now] + e.second) continue;
            dist[idx][to] = dist[idx][now] + e.second;
            heap.emplace(-dist[idx][to], to);
        }
    }
}

LL dis[50][50];

std::vector<std::pair<int, int>> tr_G[MAXN];

LL depth[MAXN];

int anc[MAXN][18], dep[MAXN];

void DFS(int now) {
    for (int i = 1; i <= 17; ++i)
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    
    for (auto e: tr_G[now]) {
        int to = e.first;
        if (to == anc[now][0]) continue;
        anc[to][0] = now;
        dep[to] = dep[now] + 1;
        depth[to] = depth[now] + e.second;
        DFS(to);
    }
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    int delta = dep[u] - dep[v];
    for (int i = 0; i <= 17; ++i)
        if (delta & (1 << i))
            u = anc[u][i];
    for (int i = 17; i >= 0; --i)
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    return u == v ? u : anc[u][0];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        static int u, v, w;
        
        scanf("%d%d%d", &u, &v, &w);
        
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
        
        edges.emplace_back(u, v, w);
    }
    
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    
    for (auto e: edges) {
        int u = std::get<0>(e), v = std::get<1>(e), w = std::get<2>(e);
        
        if (Fa(u) != Fa(v)) {
            fa[fa[u]] = fa[v];
            
            tr_G[u].emplace_back(v, w);
            tr_G[v].emplace_back(u, w);
        } else {
            key.push_back(u);
            key.push_back(v);
        }
    }
    
    DFS(1);
    
    std::sort(key.begin(), key.end());
    key.erase(std::unique(key.begin(), key.end()), key.end());
    
    for (int i = 0; i < (int)key.size(); ++i) {
        Dijkstra(key[i], i);
        for (int j = 0; j < (int)key.size(); ++j)
            dis[i][j] = dist[i][key[j]];
    }
    
    int q; scanf("%d", &q);
    while (q--) {
        static int u, v;
        
        scanf("%d%d", &u, &v);
        
        LL ans = depth[u] + depth[v] - depth[LCA(u, v)] * 2;
        
        for (int i = 0; i < (int)key.size(); ++i)
            for (int j = 0; j < (int)key.size(); ++j)
                ans = std::min(ans, dist[i][u] + dist[j][v] + dis[i][j]);
        
        printf("%I64d\n", ans);
    }
    
    return 0;
}