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
int n,m,k,a[MAXN];
vector<int> G[MAXN];
bool good[MAXN];
deque<int> order;
int dp[MAXN],color[MAXN];
bool dfs_visit(int v)
{
    color[v]=1;
    for(auto to:G[v])
    {
        if(!good[to]) continue;
        if(color[to]==0&&!dfs_visit(to)) return false;
        if(color[to]==1) return false;
    }
    color[v]=2;
    order.push_back(v);
    return true;
}
bool toposort()
{
    memset(color,0,sizeof(color));
    for(int i=1;i<=n;i++)
    {
        if(good[i]&&!color[i]) 
            if(!dfs_visit(i)) return false;
    }
    return true;
}
bool check(int x)
{
    for(int i=1;i<=n;i++) if(a[i]<=x) good[i]=true; else good[i]=false;
    order.clear();
    if(!toposort()) return true;
    if(order.size()&&k==1) return true;
    memset(dp,0,sizeof(dp));
    for(auto x:order)
    {
        for(auto to:G[x])
        {
            if(!good[to]) continue;
            dp[x]=max(dp[x],dp[to]+1);
            if(dp[x]>=k-1) return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    int l=0,r=INF+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)) r=mid; else l=mid;
    }
    if(r==INF+1) puts("-1"); else printf("%d\n",r);
    return 0;
}