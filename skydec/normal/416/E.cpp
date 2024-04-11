#include<stdio.h>
using namespace std;
#define LL int
int f[505][505];
int bl[505][505];
int be[505][505];
int ans[505][505];
#define INF 510000000
int n,m;
inline void Min(LL &x,LL y){if(x>y)x=y;}
inline void relax(LL a,LL b,LL v)
{
     bl[a][b]=f[a][b]=v;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){f[i][j]=INF;bl[i][j]=INF+1;}
    for(int i=1;i<=n;i++)f[i][i]=0;
    while(m--)
    {
              LL a,b,v;scanf("%d%d%d",&a,&b,&v);
              relax(a,b,v);relax(b,a,v);
              }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    Min(f[i][j],f[i][k]+f[k][j]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    for(int k=1;k<=n;k++)
    if(f[i][k]+bl[k][j]==f[i][j])be[i][j]++;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    for(int k=1;k<=n;k++)
    if(f[i][k]+f[k][j]==f[i][j])ans[i][j]+=be[i][k];
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    printf("%d ",ans[i][j]);
    return 0;
}