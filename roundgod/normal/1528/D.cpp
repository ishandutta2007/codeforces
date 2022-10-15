#include<bits/stdc++.h>
#define MAXN 605
#define MAXM 605*605
#define INF 1000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXM],b[MAXM],c[MAXM];
ll dist[MAXN][MAXN],d[MAXN];
bool used[MAXN];
ll cost[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cost[i][j]=INF;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        a[i]++; b[i]++;
        cost[a[i]][b[i]]=c[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) dist[i][j]=INF;
        memset(used,false,sizeof(used));
        dist[i][i]=0;
        while(true)
        {
            int v=-1;
            for(int u=1;u<=n;u++)
                if(!used[u]&&(v==-1||dist[i][u]<dist[i][v])) v=u;
            if(v==-1) break;
            used[v]=true;
            for(int j=1;j<=n;j++) d[j]=INF;
            for(int u=1;u<=n;u++) 
            {
                if(cost[v][u]!=INF)
                {
                    int to=(u+dist[i][v])%n;
                    if(to==0) to=n;
                    d[to]=min(d[to],dist[i][v]+cost[v][u]);
                }
            }
            for(int u=2;u<=n;u++) d[u]=min(d[u],d[u-1]+1);
            d[1]=min(d[1],d[n]+1);
            for(int u=2;u<=n;u++) d[u]=min(d[u],d[u-1]+1);
            for(int u=1;u<=n;u++) dist[i][u]=min(dist[i][u],d[u]);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            printf("%lld%c",dist[i][j],j==n?'\n':' ');
    return 0;
}