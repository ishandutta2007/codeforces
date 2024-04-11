#include<stdio.h>
#include<cstring>
#define MAXN 205
#define jsb 1000000007
using namespace std;
int Pow(int a,int b)
{
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%jsb)
    if(b&1)c=c*1ll*a%jsb;
    return c;
}
int n;
int times[10];
int fac[205];
int nwfac[205];
int f[10][205];
int g[105][105]; 
bool check()
{
     for(int i=1;i<=9;i++)if(times[i]>0)return 0;
     return 1;
}
int main()
{
    scanf("%d",&n);for(int i=0;i<=9;i++)scanf("%d",&times[i]);
    fac[0]=1;for(int i=1;i<=200;i++)fac[i]=fac[i-1]*1ll*i%jsb;
    nwfac[0]=1;for(int i=1;i<=200;i++)nwfac[i]=Pow(fac[i],jsb-2);
    f[0][0]=1;
    for(int i=1;i<=9;i++)
    for(int j=0;j<=n;j++)
    for(int k=times[i];k<=j;k++)
    f[i][j]=(f[i][j]+f[i-1][j-k]*1ll*nwfac[k]%jsb)%jsb;
    int ans=0;
    g[0][0]=1;
    for(int i=1;i<=n;i++)
    for(int j=0;j<=n;j++)
    for(int k=0;k<=j;k++)
    g[i][j]=(g[i][j]+g[i-1][j-k])%jsb;
    for(int i=1;i<=n;i++)
    for(int j=times[0];j<=n-i;j++)
    {
            ans=(ans+(f[9][i]*1ll*g[i][j]%jsb)*1ll*fac[i]%jsb)%jsb;
            }
    //if(check())ans=(ans+1)%jsb;
    printf("%d\n",ans);
    return 0;
}