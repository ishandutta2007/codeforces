#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') graph[i].push_back(j);
    }
    queue<int> toAdd;
    vector<int> indeg(n);
    for (int i = 0; i < n; ++i) {
        for (int nxt : graph[i]) ++indeg[nxt];
    }
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0) toAdd.push(i);
    }
    vector<int> toposort;
    while (!toAdd.empty()) {
        int cur = toAdd.front(); toAdd.pop();
        toposort.push_back(cur);
        for (int nxt : graph[cur]) {
            --indeg[nxt];
            if (indeg[nxt] == 0) toAdd.push(nxt);
        }
    }
    vector<set<int>> ans(n);
    for (int v : toposort) {
        ans[v].insert(v);
        for (int nxt : graph[v]) ans[nxt].insert(begin(ans[v]), end(ans[v]));
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i].size();
        for (int v : ans[i]) cout << " " << v + 1;
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
}