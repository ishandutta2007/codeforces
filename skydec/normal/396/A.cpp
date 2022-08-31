#include<stdio.h>
#include<algorithm>
#include<cstring>
#define jsb 1000000007
#define MAXN 1510000
using namespace std;
int n;
int tmp[MAXN];
int tot=0;
int fac[MAXN];
int nwfac[MAXN];
int Pow(int a,int b)
{
    int c=1;for(;b;b>>=1,a=a*1ll*a%jsb)if(b&1)c=c*1ll*a%jsb;
    return c;
}
void fj(int x)
{
     for(int i=2;i*i<=x;i++)
     while(x%i==0)
     {
               tmp[++tot]=i;
               x/=i;
               }
     if(x!=1)tmp[++tot]=x;
}
int C(int a,int b)
{
    //printf("%d %d\n",a,b);
    return fac[a]*1ll*(nwfac[b]*1ll*nwfac[a-b]%jsb)%jsb;
    }
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            int u;scanf("%d",&u);fj(u);
            }
    fac[0]=1;nwfac[0]=1;for(int i=1;i<=500000;i++)fac[i]=fac[i-1]*1ll*i%jsb,nwfac[i]=Pow(fac[i],jsb-2);
    sort(tmp+1,tmp+1+tot);
    int ans=1;
    for(int i=1;i<=tot;i++)
    {
            int j=i;
            while(j<tot&&tmp[j+1]==tmp[i])j++;
            ans=ans*1ll*C(j-i+1-1+n,n-1)%jsb;
            i=j;
            }
    printf("%d\n",ans);
    return 0;
}