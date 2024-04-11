#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
ll dp[MAXN][2], ans, val[MAXN], cbit;

void dfs(int s, int p = 0) {
    int x = (val[s] & (1 << cbit)) ? 1 : 0;
    dp[s][x] = 1;
    ll sum[2], sumsq[2], smx = 0;
    sum[0] = sum[1] = sumsq[0] = sumsq[1] = 0;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
        dp[s][x] += dp[v][0];
        dp[s][(x + 1)%2] += dp[v][1];
        sum[0] += dp[v][0];
        sum[1] += dp[v][1];
        sumsq[0] += dp[v][0]*dp[v][0];
        sumsq[1] += dp[v][1]*dp[v][1];
        smx += dp[v][0]*dp[v][1];
    }
    ans += dp[s][1];
    if(x == 1) {
        ans += (sum[0]*sum[0] - sumsq[0])/2ll;
        ans += (sum[1]*sum[1] - sumsq[1])/2ll;
    }
    else {
        //cout << sum[0] << " " << sum[1] << " " << sum[0]*sum[1] << endl;
        ans += (sum[0]*sum[1] - smx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll tot = 0;
    for(cbit = 0; cbit < 20; cbit++) {
        ans = 0;
        memset(dp, 0, sizeof dp);
        dfs(1);
        //for(int i = 1; i <= n; i++)
        //    cout << dp[i][0] << " " << dp[i][1] << endl;
        //cout << ans << endl;
        tot += (1ll << cbit)*ans;
    }
    cout << tot << endl;
}