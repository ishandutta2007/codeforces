#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int, 3> edge;

vector<pair<int, int>> adj[500005];
int n, k;
ll dp[500005][2];

void dfs(int s, int p = -1) {
    vector<ll> wts;
    ll tot = 0;
    for(auto e : adj[s]) {
        if(e.first == p)
            continue;
        dfs(e.first, s);
        wts.push_back(e.second + dp[e.first][1] - dp[e.first][0]);
        tot += dp[e.first][0];
    }
    sort(wts.rbegin(), wts.rend());
    dp[s][0] = dp[s][1] = tot;
    for(int i = 0; i < min(k, (int)wts.size()); i++) {
        if(wts[i] > 0) {
            dp[s][0] += wts[i];
            if(i < k - 1)
                dp[s][1] += wts[i];
        }
    }
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1);
    cout << dp[1][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
        solve();
}