#include <bits/stdc++.h>
using namespace std;

bool visited[200000] = {};
vector<int> adj[200000];

int dfs(int u) {
    if (visited[u])
        return 0;
    visited[u] = true;
    int ret = u;
    for (int v : adj[u])
        ret = max(ret, dfs(v));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<pair<int, int>> components;
    for (int i=0; i<n; i++)
        if (!visited[i])
            components.push_back(make_pair(i, dfs(i)));

    int ret = 0, maxEnd = 0;
    for (auto p : components) {
        if (p.first < maxEnd)
            ret++;
        maxEnd = max(maxEnd, p.second);
    }

    cout << ret << "\n";

    return 0;
}