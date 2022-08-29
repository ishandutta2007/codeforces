#include<stdio.h>   
using namespace std;
typedef long long LL;
LL f[4][4][50];
LL cost[4][4];
int n;
LL MIN(LL a,LL b){if(a<b)return a;return b;}
int main()
{
    for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++)scanf("%I64d",&cost[i][j]);
    scanf("%d",&n);
    for(int i=1;i<=3;i++)f[i][i][0]=(LL)(1e17);
    for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++)
    for(int k=1;k<=n;k++)
    f[i][j][k]=(LL)(1e17);
    for(int k=1;k<=n;k++)
    {
            for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            if(i!=j)
            f[i][j][k]=MIN(f[i][6-i-j][k-1]+cost[i][j]+f[6-i-j][j][k-1],f[i][j][k-1]+cost[i][6-i-j]+f[j][i][k-1]+cost[6-i-j][j]+f[i][j][k-1]);
            }
    printf("%I64d\n",f[1][3][n]);
    return 0;
}