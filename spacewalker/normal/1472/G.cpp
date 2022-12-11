#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; scanf("%d %d", &n, &m);
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d %d", &u, &v); --u; --v;
        graph[u].emplace_back(v);
    }
    vector<int> dist(n, -1);
    vector<int> toposort;
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        toposort.push_back(cur);
        for (int nxt : graph[cur]) { 
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    vector<int> ans(n, n + 1);
    reverse(begin(toposort), end(toposort));
    for (int v : toposort) {
        ans[v] = dist[v];
        for (int nxt : graph[v]) {
            if (dist[v] >= dist[nxt]) ans[v] = min(ans[v], dist[nxt]);
            else ans[v] = min(ans[v], ans[nxt]);
        }
    }
    for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}