#include <bits/stdc++.h>
using namespace std;

const int MAX_N=2e5+10;

int n,x,y;
vector<vector<int>> G(MAX_N);
vector<int> a(MAX_N),dp(MAX_N),ans(MAX_N,0);

void dfs1(int v,int p){
    for (int u:G[v]){
        if (u==p) continue;
        dfs1(u,v);
        dp[v]+=max(0,dp[u]);
    }
}

void dfs2(int v,int p,int d){
    ans[v]=dp[v]+d;
    for (int u:G[v]){
        if (u==p) continue;
        dfs2(u,v,max(0,d+dp[v]-max(0,dp[u])));
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;++i) cin >> a[i];
    for (int i=0;i<n-1;++i){
        cin >> x >> y; --x,--y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    for (int i=0;i<n;++i) dp[i]=(a[i]?1:-1);
    dfs1(0,-1);
    dfs2(0,-1,0);
    for (int i=0;i<n;++i) cout << ans[i] << (i!=n-1?' ':'\n');
}