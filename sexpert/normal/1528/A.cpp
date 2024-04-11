#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
vector<int> adj[MAXN];
int l[MAXN], r[MAXN];
ll dp[MAXN][2];

void dfs(int s, int p = 0) {
    dp[s][0] = dp[s][1] = 0;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
        dp[s][0] += max(dp[v][0] + abs(l[v] - l[s]), dp[v][1] + abs(r[v] - l[s]));
        dp[s][1] += max(dp[v][0] + abs(l[v] - r[s]), dp[v][1] + abs(r[v] - r[s]));
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        adj[i].clear();
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}