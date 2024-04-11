#include <bits/stdc++.h>
using namespace std;

int component = 0, root, center[1000], diameter[1000] = {}, maxEdge[1000] = {};
bool visited[1000] = {};
vector<int> adj[1000];

void dfs(int u, int p, int d) {
    visited[u] = true;
    for (int v : adj[u])
        if (v != p)
            dfs(v, u, d + 1);
    if (d > diameter[component]) {
        root = u;
        diameter[component] = d;
    }
}

void dfs2(int u, int p, vector<int> path) {
    path.push_back(u);
    for (int v : adj[u])
        if (v != p)
            dfs2(v, u, path);
    if (path.size() > diameter[component]) {
        center[component] = path[path.size() / 2];
        diameter[component] = path.size() - 1;
        maxEdge[component] = (path.size() - 1) / 2 + (path.size() - 1) % 2;
    }
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

    int centerTree = 0, ret = 0;
    for (int i=0; i<n; i++)
        if (!visited[i]) {
            root = i;
            center[component] = i;
            dfs(i, -1, 0);
            dfs2(root, -1, {});
            if (diameter[component] > ret) {
                centerTree = component;
                ret = diameter[component];
            }
            component++;
        }

    int curMaxEdge = maxEdge[centerTree];
    vector<pair<int, int>> edges;
    for (int i=0; i<component; i++)
        if (i != centerTree) {
            edges.emplace_back(center[centerTree] + 1, center[i] + 1);
            ret = max({ret, diameter[i], curMaxEdge + maxEdge[i] + 1});
            if (curMaxEdge == maxEdge[i])
                curMaxEdge++;
        }

    cout << ret << "\n";
    for (auto e : edges)
        cout << e.first << " " << e.second << "\n";

    return 0;
}