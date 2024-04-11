#include <bits/stdc++.h>
using namespace std;
vector<int> ADJ[1000000];
vector<int> adj[1000000];
int VIS[1000000];
int lvl[1000000];
int VISS[1000000];
int dis[100000];
bool DEL[1000000];
int P[1000000];
int dp[1000000][20];
int cur[1000000];
int n,m;
int tim=1;
int sz[1000000];
int cnt=0;
void DFFS(int v)
{
    VISS[v]=tim;
    cnt++;
    sz[v]=1;
    if (tim==1)
        cur[dis[v]]=v;
    for (int i=0;i<ADJ[v].size();i++)
    {
        int u=ADJ[v][i];
        if (VISS[u]==tim || DEL[u])continue;
        if (tim==1)
            dis[u]=dis[v]+1;
        DFFS(u);
        sz[v]+=sz[u];
    }
    if (tim==1){
    for (int i=0;i<20;i++)
    {
        if (dis[v]-(1<<i)>=0)
            dp[v][i]=cur[dis[v]-(1<<i)];
    }}
}
int id;
void DFS(int v)
{
    VIS[v]=tim;
    for (int i=0;i<ADJ[v].size();i++)
    {
        int u=ADJ[v][i];
        if (VIS[u]==tim || DEL[u])continue;
        if (sz[u]*2>cnt)
            DFS(u);
    }
    if(id==-1)
        id=v;
}
void decompose(int v,int pa)
{
    id=-1;
    cnt=0;
    DFFS(v);
    DFS(v);
    int x=id;
    if (pa!=-1)
        adj[pa].push_back(x),adj[x].push_back(pa);
    tim++;
    P[x]=pa;
    DEL[x]=1;
    int k=ADJ[x].size();
    for (int i=0;i<ADJ[x].size();i++)
    {
        int u=ADJ[x][i];
        if (DEL[u])continue;
        decompose(u,x);
    }
}
int LCA(int u,int v)
{
    if (dis[u]>dis[v])
        swap(u,v);
    int x=dis[v]-dis[u];
    for (int i=0;i<20;i++)
        if (x & (1<<i))
            v=dp[v][i];
    if (u==v)
        return v;
    for (int i=19;i>=0;i--)
        if (dp[v][i]!=dp[u][i])
            v=dp[v][i],u=dp[u][i];
    return dp[v][0];
}
int dist(int v,int u)
{
    return dis[v]+dis[u]-2*dis[LCA(u,v)];
}
int ans[1000000];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        ans[i]=100000000;
    for (int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ADJ[x].push_back(y);
        ADJ[y].push_back(x);
    }
    decompose(1,-1);
    int pp=0;
    for (int i=-1;i<m;i++)
    {
        int t,v;
        if (i>=0)
            scanf("%d%d",&t,&v);
        else
            t=1,v=1;
        if (t==1)
        {
            int u=v;
            pp=0;
            while(v!=-1)
            {
                ans[v]=min(ans[v],dist(u,v));
                v=P[v];
            }
        }
        else
        {
            int ret=100000000;
            int u=v;
            pp=0;
            while(v!=-1)
            {
                ret=min(ret,ans[v]+dist(v,u));
                v=P[v];
            }
            printf("%d\n",ret);
        }
    }
}