#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 25;
int val[MAXN], dp[MAXN], dp2[MAXN], ans[MAXN];
vector<int> adj[MAXN];

void dfs(int s, int p = 0) {
    for(auto v : adj[s]) {
        if(v != p)
            dfs(v, s);
    }
    dp[s] = (val[s] ? 1 : -1);
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dp[s] += max(dp[v], 0);
    }
    if(p != 0) {
        for(auto &v : adj[s]) {
            if(v == p)
                swap(v, adj[s][adj[s].size() - 1]);
        }
        adj[s].pop_back();
    }
}

void dfs2(int s) {
    int sz = adj[s].size();
    vector<int> pf(sz), sf(sz);
    for(int i = 0; i < sz; i++)
        pf[i] = max(0, dp[adj[s][i]]) + (i ? pf[i - 1] : 0);
    for(int i = sz - 1; i >= 0; i--)
        sf[i] = max(0, dp[adj[s][i]]) + ((i == sz - 1) ? 0 : sf[i + 1]);
    for(int i = 0; i < sz; i++) {
        int v = adj[s][i];
        if(i == 0)
            dp2[v] = (val[s] ? 1 : -1) + max(dp2[s], 0) + (sz > 1 ? sf[1] : 0);
        else if(i == sz - 1)
            dp2[v] = (val[s] ? 1 : -1) + max(dp2[s], 0) + pf[sz - 2];
        else
            dp2[v] = (val[s] ? 1 : -1) + max(dp2[s], 0) + pf[i - 1] + sf[i + 1];
    }
    ans[s] = dp[s] + (s == 1 ? 0 : max(0, dp2[s]));
    for(auto v : adj[s])
        dfs2(v);
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
    dfs(1);
    dfs2(1);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << '\n';
}