#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 105
#define MAXK 2005
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
int n,m;
int d[MAXN][MAXN];
int s,b,k,h;
int sx[MAXK],sa[MAXK],sf[MAXK];
int bx[MAXK],bd[MAXK];
void floyd_warshall()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++) 
              d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
vector<int> G[2*MAXK];
int match[MAXK];
bool used[MAXK];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0||(!used[w]&&dfs(w)))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=1;v<=s;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=(i==j?0:INF);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        d[u][v]=d[v][u]=1;
    }
    floyd_warshall();
    scanf("%d%d%d%d",&s,&b,&k,&h);
    for(int i=1;i<=s;i++) scanf("%d%d%d",&sx[i],&sa[i],&sf[i]);
    for(int i=1;i<=b;i++) scanf("%d%d",&bx[i],&bd[i]);
    for(int i=1;i<=s;i++)
        for(int j=1;j<=b;j++)
            if(sa[i]>=bd[j]&&d[sx[i]][bx[j]]<=sf[i]) add_edge(i,s+j);
    int res=bipartite_matching();
    printf("%lld\n",min(1LL*s*h,1LL*res*k));
    return 0;
}