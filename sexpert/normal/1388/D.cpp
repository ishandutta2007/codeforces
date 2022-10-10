#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<ll> dp;
vector<int> ord, out;
ll res;

void dfs(int s) {
    for(auto v : adj[s]) {
        dfs(v);
        dp[s] += max(0LL, dp[v]);
    }
}

void calc(int s) {
    res += dp[s];
    for(auto v : adj[s])
        if(dp[v] >= 0)
            calc(v);
    ord.push_back(s);
    for(auto v : adj[s])
        if(dp[v] < 0)
            calc(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    adj.resize(n + 1);
    dp.resize(n + 1);
    out.resize(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> dp[i];
    for(int i = 1; i <= n; i++) {
        int to;
        cin >> to;
        if(to == -1)
            continue;
        adj[to].push_back(i);
        out[i] = 1;
    }
    for(int i = 1; i <= n; i++)
        if(!out[i])
            dfs(i);

    for(int i = 1; i <= n; i++)
        if(!out[i])
            calc(i);

    cout << res << '\n';
    for(auto x : ord)
        cout << x << " ";
    cout << '\n';
}