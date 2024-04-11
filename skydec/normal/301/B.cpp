#include<stdio.h>
#include<cstring>
#define MAXN 105
using namespace std;
int f[MAXN][MAXN][MAXN];
void Min(int &x,int y){if(y<x)x=y;}
int x[MAXN],y[MAXN];int v[MAXN];
int n,d;
int abs(int u){if(u<0)return -u;return u;}
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=2;i<n;i++)scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)f[0][i][j]=d*(abs(x[i]-x[j])+abs(y[i]-y[j]));
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
            f[k][i][j]=f[k-1][i][j];
            Min(f[k][i][j],f[k-1][i][k]+f[k-1][k][j]-v[k]);
            }
    printf("%d\n",f[n][1][n]);
    return 0;
}