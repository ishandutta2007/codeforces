#include<cstdio>
#include<algorithm>
using namespace std;
double f[55][55][55],g[55],S=0,T=0;int n,m,a[55];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)scanf("%d",a+i);
    g[0]=1;for(int i=1;i<=n;i++)g[i]=g[i-1]*i;
    f[0][0][0]=1;
    for(int i=0;i<m;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                for(int l=j;l<=n;l++)
                    f[i+1][l][max(k,(l-j+a[i]-1)/a[i])]+=g[l]/g[j]/g[l-j]*f[i][j][k];
    for(int i=1;i<=n;i++)S+=i*f[m][n][i],T+=f[m][n][i];
    printf("%.9lf\n",S/T);
    return 0;
}