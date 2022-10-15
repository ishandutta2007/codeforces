#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],dd,vv;
vector<int> G[MAXN];
bool vis[MAXN];
void dfs_visit(int v,int p,int d,int x)
{
    vis[v]=true;
    if(d>dd) {dd=d; vv=v;}
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(a[to]==a[v]) dfs_visit(to,v,d+1,x);
        else if(x!=-1&&a[to]%x==0) dfs_visit(to,v,d+1,x);
    }
}
int find_diameter(int i,int x)
{
    dd=0;dfs_visit(i,0,1,x);
    dd=0;dfs_visit(vv,0,1,x);
    return dd;
}
int find_ans(int x=-1)
{
    memset(vis,false,sizeof(vis));
    int ans=0;
    if(x==-1)
    {
        for(int i=1;i<=n;i++) if(!vis[i]&&a[i]!=1) ans=max(ans,find_diameter(i,x));
    }
    else
    {
        for(int i=1;i<=n;i++) if(!vis[i]&&a[i]%x==0) ans=max(ans,find_diameter(i,x));
    }
    //printf("%d %d\n",x,ans)
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    int ans=0;
    for(int i=2;i*i<=200000;i++) ans=max(ans,find_ans(i));
    ans=max(ans,find_ans());
    printf("%d\n",ans);
    return 0;
}