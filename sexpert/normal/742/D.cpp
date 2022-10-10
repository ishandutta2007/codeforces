#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int sz[MAXN], wt[MAXN], cwt[MAXN], val[MAXN], cval[MAXN], cmax[MAXN], vis[MAXN], dp[MAXN];
vector<int> adj[MAXN];
vector<int> comps[MAXN];

void dfs(int s, int comp) {
    cwt[comp] += wt[s];
    cval[comp] += val[s];
    vis[s] = 1;
    comps[comp].push_back(s);
    for(auto v : adj[s]) {
        if(!vis[v])
            dfs(v, comp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, w;
    cin >> n >> m >> w;
    for(int i = 1; i <= n; i++)
        cin >> wt[i];
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cc = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i])
            dfs(i, cc++);
    }
    for(int i = 0; i < cc; i++) {
        for(int tw = w; tw >= 0; tw--) {
            if(tw - cwt[i] >= 0)
                dp[tw] = max(dp[tw], dp[tw - cwt[i]] + cval[i]);
            for(auto v : comps[i])
                if(tw - wt[v] >= 0)
                    dp[tw] = max(dp[tw], dp[tw - wt[v]] + val[v]);
        }
    }
    int mx = 0;
    for(int i = 0; i <= w; i++)
        mx = max(mx, dp[i]);
    cout << mx << endl;
}