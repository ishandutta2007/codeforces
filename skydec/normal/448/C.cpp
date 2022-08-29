#include<stdio.h>
using namespace std;
#define MAXN 5005
#define min(a,b) ((a)<(b)?(a):(b))
int n;
int a[MAXN];
int f[MAXN][MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
    f[i][j]=10000;
    f[0][0]=0;
    for(int i=1;i<=n;i++)
    {
            int up=min(a[i],n);
            for(int j=0;j<=up;j++)f[i][j]=f[i-1][j];
            for(int j=1;j<=up;j++)f[i][j]=min(f[i][j],f[i][j-1]+1);
            for(int j=0;j<=up;j++)if(j!=a[i])f[i][j]++;
            for(int j=up-1;j>=0;j--)f[i][j]=min(f[i][j],f[i][j+1]);
            }
    printf("%d\n",f[n][0]);
    return 0;
}