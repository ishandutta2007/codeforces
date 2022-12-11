#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<vector<int>> graph(n), revGraph(n);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        --u; --v;
        graph[u].push_back(v);
        revGraph[v].push_back(u);
    }
    vector<int> dist(n, 1000000000), unvisitedOuts(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    auto registerDist = [&] (int v, int d) {
        if (d >= dist[v]) return;
        // printf("registered %d %d\n", d, v);
        pq.emplace(d, v);
        dist[v] = min(dist[v], d);
    };
    for (int i = 0; i < n; ++i) {
        unvisitedOuts[i] = graph[i].size();
    }
    registerDist(n-1, 0);
    while (!pq.empty()) {
        auto [cdist, cur] = pq.top(); pq.pop();
        if (dist[cur] < cdist) continue;
        dist[cur] = cdist;
        // printf("visit %d %d\n", cur, cdist);
        for (int prev : revGraph[cur]) {
            // printf("peeking %d->%d\n", prev, cur);
            --unvisitedOuts[prev];
            registerDist(prev, cdist + 1 + unvisitedOuts[prev]);
        }
    }
    printf("%d\n", dist[0]);
}