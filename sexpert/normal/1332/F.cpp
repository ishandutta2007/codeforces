#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 10;
const ll MOD = 998244353;
ll dp[MAXN][3], ans;
vector<int> adj[MAXN];

void dfs(int s, int p = 0) {
    dp[s][0] = dp[s][1] = dp[s][2] = 1;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
        dp[s][0] = (dp[s][0] * (2LL*dp[v][0] + 2LL*dp[v][1] - dp[v][2])) % MOD;
        dp[s][1] = (dp[s][1] * (2LL*dp[v][0] + dp[v][1] - dp[v][2])) % MOD;
        dp[s][2] = (dp[s][2] * (dp[v][0] + dp[v][1] - dp[v][2])) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    ans = (dp[1][0] + dp[1][1] - dp[1][2]) % MOD;
    cout << (ans + MOD - 1) % MOD << '\n';
}