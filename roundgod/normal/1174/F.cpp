#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 400005
#define MAXLOGN 18
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
int n,q,cur;
vector<int> G[MAXN];
int dp,dep[MAXN],pa[MAXN],sz[MAXN],wson[MAXN],st[MAXN],tpos[MAXN],top[MAXN],bottom[MAXN];
void dfs1(int v,int p,int d)
{
    dep[v]=d;pa[v]=p;sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs1(to,v,d+1);
        if(sz[to]>sz[wson[v]]) wson[v]=to;
        sz[v]+=sz[to];
    }
}
void dfs2(int v,int p,int num)
{
    top[v]=num;
    bottom[top[v]]=v;
    if(wson[v]) dfs2(wson[v],v,num);
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p||to==wson[v]) continue;
        dfs2(to,v,to);
    }
}
void init()
{
    memset(wson,0,sizeof(wson));
    dfs1(1,1,0);
    dfs2(1,0,1);
}
int getdis(int v)
{
    printf("d %d\n",v);
    fflush(stdout);
    int x; scanf("%d",&x);
    return x;
}
void answer(int v)
{
    printf("! %d\n",v);
    fflush(stdout);
    exit(0);
}
void go()
{
    int bot=bottom[top[cur]];
    int d=getdis(bot);
    assert((dp+dep[bot]-d)%2==0);
    int depy=(dp+dep[bot]-d)/2;
    while(dep[cur]!=depy) cur=wson[cur];
    if(depy==dp) answer(cur);
    printf("s %d\n",cur);
    fflush(stdout);
    int u;
    scanf("%d",&u);
    cur=u;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    init();
    cur=1;
    dp=getdis(1);
    if(dp==0) answer(1);
    while(true) go();
    return 0;
}