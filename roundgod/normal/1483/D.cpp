#include<bits/stdc++.h>
#define MAXN 605
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q;
ll d[MAXN][MAXN];
ll f[MAXN][MAXN],g[MAXN][MAXN];
struct edge
{
    int u,v,cost;
};
void floyd_warshall()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
vector<edge> E;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            d[i][j]=(i==j?0:INF);
            f[i][j]=-INF;
        }
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        E.push_back((edge){u,v,w});
        d[u][v]=d[v][u]=min(d[u][v],1LL*w);
    }
    floyd_warshall();
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int u,v; ll w;
        scanf("%d%d%lld",&u,&v,&w);
        f[u][v]=f[v][u]=max(f[u][v],w);
    }
    for(int v=1;v<=n;v++)
        for(int uu=1;uu<=n;uu++)
        {
            g[v][uu]=-INF;
            for(int vv=1;vv<=n;vv++) if(f[uu][vv]!=-INF) g[v][uu]=max(g[v][uu],f[uu][vv]-d[v][vv]); 
        }
    int ans=0;
    for(auto e:E)
    {
        int u=e.u,v=e.v;
        ll w=e.cost;
        bool f=false;
        for(int uu=1;uu<=n;uu++) if(w+d[u][uu]<=g[v][uu]) {f=true; break;}
        if(f) ans++;
    }
    printf("%d\n",ans);
    return 0;
}