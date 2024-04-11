#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> G[MAXN];
int f[MAXN],g[MAXN],choice[MAXN];
int match[MAXN];
int ans[MAXN];
void dfs(int v,int p)
{
    f[v]=g[v]=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        g[v]+=max(f[to],g[to]);
    }
    choice[v]=-1;
    for(auto to:G[v]) 
    {
        if(to==p) continue;
        if(g[v]-max(f[to],g[to])+g[to]+1>f[v])
        {
            choice[v]=to;
            f[v]=g[v]-max(f[to],g[to])+g[to]+1;
        }
    }
}
void solve(int v,int p,bool flag)
{
    if(flag)
    {
        for(auto to:G[v])
        {
            if(to==p) continue;
            if(f[to]>g[to]) solve(to,v,false); else solve(to,v,true);
        }
    }
    else
    {
        match[v]=choice[v];
        match[choice[v]]=v;
        for(auto to:G[v])
        {
            if(to==p) continue;
            if(to==choice[v]) solve(to,v,true);
            else {if(f[to]>g[to]) solve(to,v,false); else solve(to,v,true);}
        }
    }
}
vector<int> app[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    if(f[1]>g[1]) solve(1,0,false); else solve(1,0,true);
    for(int i=1;i<=n;i++)
    {
        if(!match[i])
        {
            for(auto to:G[i])
            {
                if(match[to]) 
                {
                    app[to].push_back(i);
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(match[i]&&!app[match[i]].size()) app[i].push_back(match[i]);
        if(app[i].size())
        {
            for(int j=0;j<(int)app[i].size()-1;j++) ans[app[i][j]]=app[i][j+1];
            ans[app[i].back()]=i;
            ans[i]=app[i][0];
        }
    }
    printf("%d\n",2*(n-max(f[1],g[1])));
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    puts("");
}