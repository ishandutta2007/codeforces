#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXD 55
#define MAXM 5000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,d,p;
int u[MAXN],v[MAXN];
vector<int> G[MAXM];
char str[MAXN][MAXD];
void add_edge(int u,int v)
{
    G[u].push_back(v);
}
int dfn[MAXM],low[MAXM],st[MAXM];
int vis[MAXM];
int ans;
int cmp[MAXM],cnt,tot,t;
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
        cnt++;
        do
        {
            u=st[t-1]; t--;
            cmp[u]=cnt;
            vis[u]=2;
        }while(u!=v);
    }
}
int tarjan()
{
    t=tot=cnt=0;
    memset(vis,0,sizeof(vis));
    dfs(0);
    return cnt;
}
int dfs_visit(int v)
{
    if(dfn[v]!=-1) return dfn[v];
    dfn[v]=0;
	for(auto to:G[v]) dfn[v]=max(dfn[v],dfs_visit(to));
    dfn[v]+=low[v];
    return dfn[v];
}

unordered_set<int> s;
int main()
{
    scanf("%d%d%d",&n,&m,&d);
    for(int i=0;i<m;i++) scanf("%d%d",&u[i],&v[i]);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    for(int i=0;i<m;i++)
        for(int j=0;j<d;j++)
            add_edge((u[i]-1)*d+j,(v[i]-1)*d+(j+1)%d);
    p=tarjan();
    for(int i=0;i<n*d;i++) G[i].clear(),G[i].shrink_to_fit();
    for(int i=0;i<m;i++)
        for(int j=0;j<d;j++)
        {
            int a=(u[i]-1)*d+j,b=(v[i]-1)*d+(j+1)%d;
            if(!cmp[a]||!cmp[b]) continue;
            if(cmp[a]==cmp[b]) continue;
            G[cmp[a]].push_back(cmp[b]);
        }
    memset(dfn,-1,sizeof(dfn));memset(low,0,sizeof(low));
    for(int i=0;i<n;i++)
    {
        s.clear();
        for(int j=0;j<d;j++)
        {
            if(str[i][j]!='1') continue;
            int c=cmp[i*d+j];
            if(!c) continue;
            s.insert(c);
        }
        for(auto x:s) low[x]++;
    }
    memset(vis,0,sizeof(vis));
    ans=dfs_visit(cmp[0]);
    printf("%d\n",ans);
    return 0;
}