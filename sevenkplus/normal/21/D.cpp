#include<cstdio>
#include<algorithm>
using namespace std;
#define inf 1000000007
int a[15][15],d[15],u[2222],v[2222],w[2222],f[65537],n,m,S;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j)a[i][j]=inf;
    for(int i=0,x,y,z;i<m;i++)
        scanf("%d%d%d",&x,&y,&z),x--,y--,d[x]++,d[y]++,
        a[x][y]=min(a[x][y],z),a[y][x]=a[x][y],S+=z,
        u[i]=x,v[i]=y,w[i]=z;
    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    for(int i=0;i<m;i++)if(a[0][u[i]]==inf){puts("-1");return 0;}
    for(int i=1,j=0;i<(1<<n);i++)
    {
        f[i]=inf;if(i==(1<<j+1))j++;
        for(int k=0;k<j;k++)f[i]=min(f[i],f[i^(1<<j)^(1<<k)]+a[j][k]);
    }
    int P=0;for(int i=0;i<n;i++)if(d[i]&1)P+=(1<<i);
    printf("%d\n",f[P]==inf?-1:(f[P]+S));
    return 0;
}