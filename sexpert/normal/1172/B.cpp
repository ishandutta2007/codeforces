#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MAXN = 2e5 + 5;
ll dp[MAXN], fac[MAXN];
vector<int> adj[MAXN];

void dfs(int s, int p = 0) {
    dp[s] = 1;
    for(auto v : adj[s]) {
        if(v != p)  {
            dfs(v, s);
            dp[s] = (dp[s] * dp[v]) % MOD;
        }
    }
    // cout << s << " " << adj[s].size() << '\n';
    dp[s] = (dp[s] * fac[adj[s].size()]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for(ll i = 1; i < MAXN; i++)
        fac[i] = (i * fac[i - 1])%MOD;

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << (dp[1] * ((ll)n)) % MOD << '\n';
}