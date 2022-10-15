#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
ll n,sz[MAXN],f[MAXN],g[MAXN];
vector<int> G[MAXN];
void dfs(ll v,ll p)
{
    sz[v]=1; f[v]=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to]; f[v]+=f[to];
    }
    f[v]+=sz[v];
}
void dfs2(ll v,ll p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        g[to]=g[v]+n-2*sz[to];
        dfs2(to,v);
    }
}
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    g[1]=f[1];
    dfs2(1,0);
    ll ans=0;
    for(ll i=1;i<=n;i++) ans=max(ans,g[i]);
    printf("%lld\n",ans);
    return 0;
}