#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,c[MAXN],sons[MAXN],sz[MAXN],ans[MAXN];
vector<int> G[MAXN];
set<int> valid;
void update(int v)
{
    if(sz[v]>=2&&(sons[v]||c[v]))
    {
        valid.insert(v);
    }
    else if(valid.count(v)) valid.erase(v);
}
void dfs(int v,int p)
{
    if(c[v]) sz[v]=1; else sz[v]=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(c[to]==1) sons[v]++;
        dfs(to,v);
        sz[v]+=sz[to];
    }
    update(v);
}
void change_root(int v,int to)
{
    sz[v]-=sz[to]; sz[to]+=sz[v];
    if(c[to]) sons[v]--; if(c[v]) sons[to]++;
    update(v); update(to);
}
void dfs2(int v,int p)
{
    if(valid.size()) ans[v]=1;
    if(c[v]) ans[v]=1;
    for(auto to:G[v])
    {
        if(c[to]) ans[v]=1;
    }
    for(auto to:G[v])
    {
        if(to==p) continue;
        change_root(v,to);
        dfs2(to,v);
        change_root(to,v);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0); dfs2(1,0);
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}