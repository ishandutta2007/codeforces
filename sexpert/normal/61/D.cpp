#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 10;
ll sz[MAXN], cost[MAXN], hv[MAXN];
vector<ii> adj[MAXN];
vector<array<int, 3>> edges;

void dfs(int s, int p = 0) {
    sz[s] = 1;
    cost[s] = 0;
    hv[s] = 0;
    for(auto &[v, w] : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
        sz[s] += sz[v];
        cost[s] += cost[v] + 2*w;
        hv[s] = max(hv[s], w + hv[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    dfs(1);
    cout << cost[1] - hv[1] << '\n';
}