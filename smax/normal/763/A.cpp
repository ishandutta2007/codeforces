#include <bits/stdc++.h>
using namespace std;

int c[100000];
bool visited[100000] = {};
pair<int, int> edges[100000];
vector<int> adj[100000];

bool dfs(int u, int color) {
    if (visited[u])
        return true;
    if (color != -1 && c[u] != color)
        return false;

    bool ret = true;
    visited[u] = true;
    for (int v : adj[u])
        ret &= dfs(v, (color == -1 ? c[v] : color));
    visited[u] = false;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    for (int i=0; i<n; i++)
        cin >> c[i];

    int i = 0;
    while (i < n - 1 && c[edges[i].first] == c[edges[i].second])
        i++;

    if (i == n - 1)
        cout << "YES\n1\n";
    else if (dfs(edges[i].first, -1))
        cout << "YES\n" << edges[i].first + 1 << "\n";
    else if (dfs(edges[i].second, -1))
        cout << "YES\n" << edges[i].second + 1 << "\n";
    else
        cout << "NO\n";

    return 0;
}