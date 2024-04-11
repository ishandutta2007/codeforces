#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;

int n;
vector<int> G[N];
ll dp[N], sz[N];
ll res = 0;

void dfs(int v, int p) {
    sz[v] = 1;
    dp[v] = 1;
    for(int nxt : G[v]) {
        if(nxt != p) {
            dfs(nxt, v);
            sz[v] += sz[nxt];
            dp[v] += dp[nxt] + sz[nxt];
        }
    }
}

void dfs2(int v, int p, ll dp_up, ll sz_up) {
    dp[v] += dp_up + sz_up;
    sz[v] += sz_up;
    
    res = max(res, dp[v]);
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        sz[v] -= sz[nxt];
        dp[v] -= dp[nxt] + sz[nxt];
        dfs2(nxt, v, dp[v], sz[v]);
        sz[v] += sz[nxt];
        dp[v] += dp[nxt] + sz[nxt];
    }

    dp[v] -= dp_up + sz_up;
    sz[v] -= sz_up;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    dfs2(0, -1, 0, 0);
    cout << res << endl;
}