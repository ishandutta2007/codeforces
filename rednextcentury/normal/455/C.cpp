# include<iostream>
# include<algorithm>
# include<string>
# include<cstring>
# include<stdio.h>
# include<cmath>
# include<iomanip>
# include<map>
# include<cstdlib>
# include<vector>
# include<set>
# include<queue>
# include<assert.h>
# include<ctime>
using namespace std;
vector<int> groups[1000000];
int group[1000000];
int best[1000000];
bool vis[1000000];
int ans=0;
int len[1000000][2];
void Move(int u,int v,int p)
{
    if (p==0)
    best[v]=max((best[u]+1)/2+(best[v]+1)/2+1,max(best[v],best[u]));
    int n=groups[u].size();
    for (int i=0;i<n;i++)
    {
        groups[v].push_back(groups[u][i]);
        group[groups[u][i]]=v;
    }
    groups[u].clear();
}
vector<int> adj[1000000];
void dfs(int v)
{
    vis[v]=1;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])continue;
        dfs(u);
        if (len[u][0]+1>len[v][0])
        {
            len[v][1]=len[v][0];
            len[v][0]=len[u][0]+1;
        }
        else if (len[u][0]+1>len[v][1])
            len[v][1]=len[u][0]+1;
    }
    ans=max(ans,len[v][0]+len[v][1]);
}
void add(int s,int e,int p=0)
{
    int u=group[s];
    int v=group[e];
    if (u==v)
        return;
    if (groups[u].size()<groups[v].size())
        Move(u,v,p);
    else
        Move(v,u,p);
}
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++)
    {
        groups[i].push_back(i);
        group[i]=i;
        best[i]=0;
    }
    for (int i=0;i<m;i++)
    {
        int s,e;
        scanf("%d%d",&s,&e);
        adj[s].push_back(e);
        adj[e].push_back(s);
        add(s,e,1);
    }
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            dfs(i);
            best[group[i]]=ans;
            ans=0;
        }
    }
    for (int i=0;i<q;i++)
    {
        int typ;
        scanf("%d",&typ);
        if (typ==1)
        {
            int v;
            cin>>v;
            printf("%d\n",best[group[v]]);
        }
        else
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v);
        }
    }
}