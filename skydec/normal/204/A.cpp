#include<stdio.h>
using namespace std;
typedef long long LL;
LL ask(int fr,int d,LL limit)
{
           if(d==0)return fr*10+fr<=limit;
           LL u=1;
           for(int i=1;i<=d+1;i++)u*=10ll;
           LL l,r,ans;ans=-1;
           l=0;r=(u/10)-1;
           while(l<r)
           {
                     LL mid=(l+r)>>1;
                     if(fr*u+mid*10ll+fr<=limit)
                     l=mid+1,ans=mid;
                     else r=mid;
                     }
           if(fr*u+l*10ll+fr<=limit)ans=l;
           return ans+1;
}          
LL work(LL limit)
{
           LL ans=10;
           if(limit<10)return limit+1;
           for(int i=2;i<=18;i++)
           for(int j=1;j<=9;j++)
           ans+=ask(j,i-2,limit);
           return ans;
}
int main()
{
    LL l,r;scanf("%I64d%I64d",&l,&r);
    printf("%I64d\n",work(r)-work(l-1));
    return 0;
}