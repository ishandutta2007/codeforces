/*
- One CC: 0
- 1 non-clique CC: One
    - No vtx with deg = n-1: Anything not an AP
    - Some vtx with deg = n-1: Any vtx with deg < n-1
- Isolated vtx: 1, take that one duh
- All clique, at least 3 cliques: one from two of them
- All clique, 2 cliques: smaller one
*/

#include <bits/stdc++.h>

using namespace std;

struct APFinder {
    int n; // number of nodes
    vector<vector<int>> adj; // adjacency list of graph

    vector<bool> visited;
    vector<int> tin, low;
    int timer;

    set<int> cutpts;

    APFinder(vector<vector<int>> adj) : n(adj.size()), adj(adj) {}

    void IS_CUTPOINT(int v) {
        cutpts.insert(v);
    }

    void dfs(int v, int p = -1) {
        visited[v] = true;
        tin[v] = low[v] = timer++;
        int children=0;
        for (int to : adj[v]) {
            if (to == p) continue;
            if (visited[to]) {
                low[v] = min(low[v], tin[to]);
            } else {
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if (low[to] >= tin[v] && p!=-1)
                    IS_CUTPOINT(v);
                ++children;
            }
        }
        if(p == -1 && children > 1)
            IS_CUTPOINT(v);
    }

    void find_cutpoints() {
        timer = 0;
        visited.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                dfs (i);
        }
    }
};

vector<int> solve() {
    int n; cin >> n;
    vector<string> adj(n);
    for (int i = 0; i < n; ++i) cin >> adj[i];
    vector<int> deg(n);
    vector<vector<int>> adjl(n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (adj[i][j] == '1') {
        ++deg[i];
        adjl[i].push_back(j);
    }
    for (int i = 0; i < n; ++i) if (deg[i] == 0) return {i};
    vector<vector<int>> ccs;
    vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        queue<int> q; 
        q.push(i);
        vis[i] = true;
        ccs.emplace_back();
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            ccs.back().push_back(cur);
            for (int nxt = 0; nxt < n; ++nxt) {
                if (adj[cur][nxt] == '1' && !vis[nxt]) {
                    q.push(nxt);
                    vis[nxt] = true;
                }
            }
        }
    }
    APFinder apf(adjl);
    apf.find_cutpoints();
    if (ccs.size() == 1) return {};
    for (vector<int> &cc : ccs) {
        bool isClique = true;
        for (int i : cc) for (int j : cc) {
            if (i != j && adj[i][j] == '0') isClique = false;
        }
        if (isClique) continue;
        if (any_of(begin(cc), end(cc), [&cc, &deg] (int i) { return deg[i] + 1 == cc.size(); })) {
            for (int i : cc) if (deg[i] + 1 < cc.size()) return {i};
        }
        for (int i : cc) if (apf.cutpts.count(i) == 0) return {i};
        assert(false);
    }
    // all ccs are cliques
    if (ccs.size() >= 3) return {ccs[0][0], ccs[1][0]};
    else if (ccs[0].size() < ccs[1].size()) return ccs[0];
    else return ccs[1]; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        vector<int> ans = solve();
        cout << ans.size() << "\n";
        if (ans.size() > 0) {
            for (int v : ans) cout << v + 1 << " ";
            cout << "\n";
        }
    }
}