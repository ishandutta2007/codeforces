#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int sz[MAXN],fa[MAXN],fav,fau;
vector<int> G[MAXN];
ll dp[MAXN][MAXN];
int dir[MAXN][MAXN];
void dfs(int v,int p)
{
    sz[v]=1; fa[v]=p;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to];
    }
}
void dfs2(int v,int p,int u,int d)
{
    dir[u][v]=d;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v,u,d);
    }
}
ll solve(int u,int v)
{
    if(u>v) return solve(v,u);
    if(dir[u][v]==v) 
    {
        if(fa[u]==v) return 1LL*sz[u]*(n-sz[u]);
        else return 1LL*sz[v]*(n-sz[v]);
    }
    if(dp[u][v]!=-1) return dp[u][v];
    ll &res=dp[u][v]; res=0;
    int xsz=(fa[dir[u][v]]==u?n-sz[dir[u][v]]:sz[u]);
    int ysz=(fa[dir[v][u]]==v?n-sz[dir[v][u]]:sz[v]);
    res=1LL*xsz*ysz+max(solve(dir[u][v],v),solve(dir[v][u],u));
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) for(auto to:G[i]) dfs2(to,i,i,to);
    ll ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            ans=max(ans,solve(i,j));
    printf("%lld\n",ans);
    return 0;
}