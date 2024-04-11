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
int n,k,a[MAXN],s[MAXN];
vector<int> G[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(int v,int p)
{
    int now=INF;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        if(s[v]==-1) now=min(now,s[to]);
    }
    if(s[v]==-1) 
    {
        if(now==INF) s[v]=s[p];
        else s[v]=now;
    }
}
void dfs2(int v,int p)
{
    a[v]=s[v]-s[p];
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        add_edge(x,i);
    }
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    dfs(1,0);dfs2(1,0);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<0) {puts("-1"); return 0;}
        ans+=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}