#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 2e3 + 5;
vector<int> adj[MAXN];
int a[MAXN], n, d, bound;
ll dp[MAXN][2], ans;

void pre(int s, int p = 0) {
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        pre(v, s);
    }
    for(auto &v : adj[s])
        if(v == p)
            swap(v, adj[s][(int)adj[s].size() - 1]);
    if(p)
        adj[s].pop_back();
}

void dfs(int s) {
    for(auto v : adj[s])
        dfs(v);
    if(a[s] < bound || a[s] > bound + d)
        return;
    if(a[s] == bound) {
        dp[s][1] = 1;
        for(auto v : adj[s])
            dp[s][1] = (dp[s][1] * (dp[v][0] + dp[v][1] + 1)) % MOD;
    }
    else {
        dp[s][0] = 1;
        dp[s][1] = 1;
        for(auto v : adj[s]) {
            dp[s][0] = (dp[s][0] * (dp[v][0] + 1)) % MOD;
            dp[s][1] = (dp[s][1] * (dp[v][0] + dp[v][1] + 1)) % MOD;
        }
        dp[s][1] -= dp[s][0];
        dp[s][1] %= MOD;
        if(dp[s][1] < 0)
            dp[s][1] += MOD;
    }
    ans = (ans + dp[s][1]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> d >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pre(1);
    /*for(int i = 1; i <= n; i++) {
        for(auto v : adj[i])
            cout << v << " ";
        cout << '\n';
    }*/
    for(bound = 1; bound <= 2000; bound++) {
        memset(dp, 0, sizeof dp);
        dfs(1);
        //cout << ans << endl;
        //for(int i = 1; i <= n; i++)
        //    cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << ans << '\n';
}