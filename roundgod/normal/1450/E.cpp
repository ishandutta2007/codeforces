#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,d[MAXN][MAXN];
vector<int> undir[MAXN];
void floyd_warshall()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int color[MAXN];
bool dfs(int v,int p,int c)
{
    color[v]=c;
    for(auto to:undir[v])
    {
        if(!color[to]&&!dfs(to,v,-c)) return false;
        else if(color[to]==c) return false;
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=(i==j?0:INF);
    for(int i=0;i<m;i++)
    {
        int u,v,b;
        scanf("%d%d%d",&u,&v,&b);
        undir[u].push_back(v); undir[v].push_back(u);
        if(b==1)//a[v]=a[u]+1
        {
            d[u][v]=min(d[u][v],1);
            d[v][u]=min(d[v][u],-1);
        }
        else
        {
            d[u][v]=min(d[u][v],1);
            d[v][u]=min(d[v][u],1);
        }
    }
    for(int i=1;i<=n;i++) if(!color[i]&&!dfs(i,0,1)) {puts("NO"); return 0;}
    floyd_warshall();
    for(int i=1;i<=n;i++) if(d[i][i]<0) {puts("NO"); return 0;}
    int maxi=-1,u=-1,v=-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(d[i][j]>maxi)
            {
                maxi=d[i][j];
                u=i;
                v=j;
            }
    puts("YES");
    printf("%d\n",d[u][v]);
    for(int i=1;i<=n;i++) printf("%d%c",d[u][i],i==n?'\n':' ');
    return 0;
}