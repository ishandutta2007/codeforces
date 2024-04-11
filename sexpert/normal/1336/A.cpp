#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
int h[MAXN], sz[MAXN];
vector<int> cost, adj[MAXN];

void dfs(int s, int p = 0, int he = 0) {
    h[s] = he;
    sz[s] = 1;
    for(auto v : adj[s])
        if(v != p) {
            dfs(v, s, he + 1);
            sz[s] += sz[v];
        }
    cost.push_back(h[s] - sz[s] + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    ll ans = 0;
    sort(cost.rbegin(), cost.rend());
    for(int i = 0; i < k; i++)
        ans += cost[i];
    cout << ans << '\n';
}