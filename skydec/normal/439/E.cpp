#include<cstdio>
#define MAXN 110000
#define jsb 1000000007ll
using namespace std;
typedef long long LL;
#define int1 LL
int q;
int u[MAXN];
int1 fac[MAXN];
int1 nf[MAXN];
int1 Pow(int1 a,int1 b)
{
    int1 c=1;
    for(;b;b>>=1,a=a*1ll*a%jsb)
    if(b&1)c=c*1ll*a%jsb;
    return c;
}
void init(int1 x)
{
     u[1]=1;
     for(int1 i=2;i<=x;i++)
     {
             u[i]=1;int1 p=i;
             for(int1 j=2;j*j<=p;j++)
             {
                     int1 k=0;
                     while(p%j==0)
                     {
                                  p/=j;
                                  k++;
                                  }
                     if(k>1)u[i]=0;
                     if(k==1)u[i]*=-1;
                     }
             if(p!=1)u[i]*=-1;
             //printf("%d ",u[i]);
                     }
     fac[0]=1;
     for(int1 i=1;i<=x;i++)fac[i]=fac[i-1]*1ll*i%jsb;
     for(int1 i=0;i<=x;i++)nf[i]=Pow(fac[i],jsb-2);
}
int1 C(int1 n,int1 m)
{
     if(n<m)return 0;
    return (nf[m]*1ll*nf[n-m]%jsb)*1ll*fac[n]%jsb;
}
int main()
{
    init(100000);
    scanf("%d",&q);
    while(q--)
    {
              int1 ans=0;
              int1 n,f;scanf("%I64d%I64d",&n,&f);
              for(int1 i=1;i*i<=n;i++)
              if(n%i==0)
              {
                        ans=(ans+u[i]*1ll*C((n/i)-1,f-1)%jsb)%jsb;
                        if(i*i!=n)
                        ans=(ans+u[n/i]*1ll*C(i-1,f-1)%jsb)%jsb;
                        }
              if(ans<0)ans+=jsb;
              printf("%I64d\n",ans);
              }
    return 0;
}