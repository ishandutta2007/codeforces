#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 2;
vector<int> adj[MAXN];
long long mx, dp[MAXN], wt[MAXN];
int vist[MAXN], used[MAXN], k = 0;

long long dfs(int u, bool bld)
{
    dp[u] = wt[u];
    vist[u] = 1;
    for(auto v : adj[u])
    {
        if(vist[v])
            continue;
        
        long long x = max(dfs(v, bld), 0ll);
        if(!bld || !used[v])
            dp[u] += x;
    }
    
    if(!bld)
        mx = max(mx, dp[u]);
    else
    {
        if(dp[u] == mx)
        {
            k++;
            used[u] = true;
        }
    }
    return dp[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> wt[i + 1];
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    mx = -1000000000000000000;
    dfs(1, false);
    memset(vist, 0, sizeof(vist));
    dfs(1, true);
    cout << mx*k << " " << k << endl;
}