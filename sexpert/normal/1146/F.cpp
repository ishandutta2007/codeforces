#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
const ll MOD = 998244353;

vector<int> adj[MAXN];
ll dp[MAXN][3];

ll mpow(ll b, ll e) {
    if(e == 0) return 1;
    if(e % 2) return (b * mpow(b, e - 1))%MOD;
    ll p = mpow(b, e/2);
    return (p * p)%MOD;
}

ll minv(ll b) {
    return mpow(b, MOD - 2);
}

void dfs(int s) {
    for(auto v : adj[s])
        dfs(v);
    if(adj[s].empty()) {
        dp[s][2] = 1;
        dp[s][1] = 0;
        dp[s][0] = 0;
        //cout << s << " " << dp[s][0] << " " << dp[s][1] << " " << dp[s][2] << endl;
        return;
    }
    ll tot = 0, prod = 1;
    for(auto v : adj[s])
        prod = (prod * (dp[v][0] + dp[v][2]))%MOD;
    dp[s][0] = prod;
    for(auto v : adj[s])
        tot = (tot + ((dp[v][1] + dp[v][2])*((minv(dp[v][0] + dp[v][2]) * prod)%MOD))%MOD)%MOD;
    dp[s][1] = tot;
    ll oprod = 1;
    for(auto v : adj[s])
        oprod = (oprod * (dp[v][0] + dp[v][2] + dp[v][1] + dp[v][2]))%MOD;
    dp[s][2] = (oprod - dp[s][1] - dp[s][0])%MOD;
    if(dp[s][2] < 0)
        dp[s][2] += MOD;
    //cout << s << " " << dp[s][0] << " " << dp[s][1] << " " << dp[s][2] << endl;
}

int main() {
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    dfs(1);
    cout << (dp[1][2] + dp[1][0])%MOD << endl;
}