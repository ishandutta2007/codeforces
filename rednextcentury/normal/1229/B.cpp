#include <bits/stdc++.h>
using namespace std;
int MX=20;
long long GCD[100004][21];
int par[100004][21];
long long a[100008];
long long ret=0;
vector<int> adj[1000000];
long long L[1000000];
long long mod = 1000000007;
void dfs(int v)
{
    GCD[v][0]=a[v];
    for (auto u:adj[v])
    {
        if (u!=par[v][0]){
            par[u][0]=v;
            L[u]=1+L[v];
            dfs(u);
        }
    }
}
int n;
long long ans[1000000];
void dfs2(int v,int pa=-1)
{
    if (a[v]==0){
        if (pa!=-1)
            ans[v]=ans[pa];
    }
    else {
        int cur = v;
        long long val = a[v];
        while(1)
        {
            int last=cur;
            for (int j=MX-1;j>=0;j--){
                if (par[cur][j]==0 && j!=0)continue;
                if (GCD[cur][j]%val==0) {
                    cur = par[cur][j];
                }
            }
            ans[v]+=((L[last]-L[cur])*val)%mod;
            ans[v]%=mod;
            if (cur==0)break;
            val=__gcd(val,a[cur]);
        }
    }
    for (auto u:adj[v])
    {
        if (u==pa)continue;
        dfs2(u,v);
    }
}
void solve()
{
    dfs(1);
    L[0]=-1;
    for (int i=1;i<MX;i++)
        for (int j=1;j<=n;j++)
            par[j][i]=par[par[j][i-1]][i-1];
    for (int i=1;i<MX;i++)
        for (int j=1;j<=n;j++)
            if (par[j][i]!=0)
                GCD[j][i]=__gcd(GCD[j][i-1],GCD[par[j][i-1]][i-1]);
    dfs2(1);
    for (int i=1;i<=n;i++)
        ret+=ans[i],ret%=mod;
}
int main()
{
   // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve();
    printf("%lld\n",ret);
}