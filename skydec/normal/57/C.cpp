#include<stdio.h>
#include<cstring>
#define MAXN 1100000
#define jsb 1000000007
using namespace std;
int f[MAXN],g[MAXN];
int n;
int Pow(int a,int b)
{
    int c=1;for(;b;b>>=1,a=a*1ll*a%jsb)if(b&1)c=c*1ll*a%jsb;
    return c;
}
int C(int m,int n)
{
    int res=f[m]*1ll*g[n]%jsb;
    res=res*1ll*g[m-n]%jsb;
    return res;
}
int main()
{
    //freopen("pretty.in","r",stdin);
    //freopen("pretty.out","w",stdout);
    scanf("%d",&n);
    if(n==1)
    {
            printf("1\n");
            return 0;
            }
    f[0]=1;for(int i=1;i<=n;i++)f[i]=f[i-1]*1ll*i%jsb;
    g[n]=Pow(f[n],jsb-2);
    for(int i=n-1;i>=0;i--)g[i]=g[i+1]*1ll*(i+1)%jsb;
    int ans=0;
    for(int k=2;k<=n;k++)
    {
            int res=C(n,k)*1ll*C(n-1,k-1)%jsb;
            ans=(ans+res)%jsb;
            //printf("%d %d\n",res,ans);
            }
    ans=ans*2ll%jsb;
    ans=(ans+n)%jsb;
    printf("%d\n",(ans+jsb)%jsb);
    return 0;
}