#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN];
int n,m,s,dfn[MAXN],low[MAXN],st[MAXN];
int vis[MAXN];
int deg[MAXN];
int u[MAXN],v[MAXN];
int cmp[MAXN],cnt,tot,t;
void dfs(int v)
{
    dfn[v]=low[v]=++tot;
    vis[v]=1;
    st[t++]=v;
    for(auto to:G[v])
    {
        if(!vis[to])
        {
            dfs(to);
            low[v]=min(low[v],low[to]);
        }
        else if(vis[to]==1) low[v]=min(low[v],dfn[to]);
    }
    if(dfn[v]==low[v])
    {
        int u;
        do
        {
            u=st[t-1]; t--;
            cmp[u]=cnt;
            vis[u]=2;
        }while(u!=v);
        cnt++;
    }
}
int tarjan()
{
    t=tot=cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
    return cnt;
}
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].push_back(v[i]);
    }
    int ans=0;
    int cnt=tarjan();
    for(int i=0;i<m;i++) if(cmp[u[i]]!=cmp[v[i]]) deg[cmp[v[i]]]++;
    for(int i=0;i<cnt;i++) if(i!=cmp[s]&&deg[i]==0) ans++;
    printf("%d\n",ans);
    return 0;
}