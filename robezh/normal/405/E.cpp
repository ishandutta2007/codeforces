#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

struct Tp{
    int x, y, z;
};

struct edge {
    int to, id;
};

int n, m;
vector<edge> G[N];
bool vis[N], vise[N];
vector<int> in[N];

void dfs(int v) {
    vis[v] = true;
    for(auto e : G[v]) {
        if(vise[e.id]) continue;
        if(vis[e.to]) {
            in[v].push_back(e.to);
            vise[e.id] = true;
        }
        else {
            vise[e.id] = true;
            dfs(e.to);
            if(in[e.to].size() % 2 == 1) in[e.to].push_back(v);
            else in[v].push_back(e.to);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    if(m % 2 == 1) return cout << "No solution" << endl, 0;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    dfs(0);
    for(int i = 0; i < n; i++) {
        assert(in[i].size() % 2 == 0);
        for(int j = 0; j < in[i].size(); j += 2) {
            cout << in[i][j] + 1 << " " << i + 1 << " " << in[i][j + 1] + 1 << "\n";
        }
    }

}