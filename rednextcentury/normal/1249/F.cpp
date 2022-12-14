#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[222][222];
int a[222];
vector<int> adj[1000000];
int n,k;
int tmp[222];
void dfs(int v,int pa) {
    dp[v][0]=a[v];
    for (auto u:adj[v]){
        if (u==pa)continue;
        dfs(u,v);
        for (int i=0;i<=k;i++)tmp[i]=dp[v][i];
        for (int i=0;i<=k;i++) {
            for (int j=0;j<=k;j++) {
                int dist = min(i+j+1,k);
                int cur = min(i,j+1);
                if (dist<k)continue;
                tmp[cur]=max(tmp[cur],dp[v][i]+dp[u][j]);
            }
        }
        for (int i=0;i<=k;i++)dp[v][i]=tmp[i];

    }
    for (int i=k-1;i>=0;i--)dp[v][i]=max(dp[v][i],dp[v][i+1]);
}
int main() {
    scanf("%d%d", &n, &k);
    k++;
    for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << dp[1][0] << endl;
}