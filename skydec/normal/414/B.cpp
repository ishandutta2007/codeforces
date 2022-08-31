#include<stdio.h>
#define jsb 1000000007
#define MAXN 2005
using namespace std;
int f[MAXN][MAXN];
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)f[1][i]=1;
    for(int i=2;i<=k;i++)
    for(int j=1;j<=n;j++)
    for(int s=j;s<=n;s+=j)
    f[i][s]=(f[i-1][j]+f[i][s])%jsb;
    int ans=0;
    for(int i=1;i<=n;i++)ans=(ans+f[k][i])%jsb;
    printf("%d\n",ans);
    return 0;
}