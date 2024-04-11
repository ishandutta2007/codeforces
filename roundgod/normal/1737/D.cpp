#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN];
vector<pair<P,int> > edges;
ll d[MAXN][MAXN];
void floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        edges.clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=(i==j?0:INF);
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(u!=v) d[u][v]=d[v][u]=1;
            edges.push_back(make_pair(P(u,v),w));
        }
        floyd();
        ll ans=INF;
        for(int i=0;i<m;i++)
        {
            int u=edges[i].F.F,v=edges[i].F.S;
            ans=min(ans,1LL*edges[i].S*(d[1][u]+d[n][v]+1));
            ans=min(ans,1LL*edges[i].S*(d[n][u]+d[1][v]+1));
            for(int j=1;j<=n;j++)
            {
                ans=min(ans,1LL*edges[i].S*(d[1][j]+d[j][n]+1+(u==v?0:1)+d[u][j]));
                ans=min(ans,1LL*edges[i].S*(d[1][j]+d[j][n]+1+(u==v?0:1)+d[v][j]));
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}