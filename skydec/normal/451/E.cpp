#include<stdio.h>
#define jsb 1000000007
using namespace std;
typedef long long LL;
int n;
LL a[25];LL sum;
LL ans=0;
LL Pow(LL x,LL y)
{
          LL c=1;
          for(;y;y>>=1,x=x*x%jsb)
          if(y&1)c=c*x%jsb;
          return c;
}         
LL get(LL x,LL y)
{
          if(y>x)return 0;
          LL s1=1,s2=1;
          for(LL b=0;b<y;b++)
          {
                 s2=s2*(b+1ll)%jsb;
                 s1=s1*(x-b)%jsb;
                 }
          s1=s1*Pow(s2,jsb-2);
          return s1;
}
LL lucas(LL x,LL y)
{
            if(!y)return 1;
            return get(x%jsb,y%jsb)*lucas(x/jsb,y/jsb)%jsb;
}
int main()
{
    scanf("%d%I64d",&n,&sum);
    for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    for(int i=0;i<(1<<n);i++)
    {
            LL pp=0;int sign=1;
            for(int j=1;j<=n;j++)
            if((1<<(j-1))&i)pp+=a[j]+1,sign*=-1;
            if(pp>sum+n-1)continue;
            ans=(ans+sign*1ll*lucas(sum+n-1-pp,n-1)%jsb)%jsb;
            }
    if(ans<0)ans+=jsb;
    printf("%I64d\n",ans);
    return 0;
}