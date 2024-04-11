#include<stdio.h>
using namespace std;
typedef long long LL;
LL n,x,y,c;
LL min(LL a,LL b){if(a<b)return a;return b;}
LL max(LL a,LL b){return a+b-min(a,b);}
LL calc(LL X)
{
           LL ans=0;
           ans=((1+1+2ll*(X-1))*X)/2;
           LL mx=1+2ll*(X-1);
           LL mup=max(0,-(x-1-((mx-1)/2)));
           ans-=mup*(mup+1)/2;
           LL mdo=max(0,-(n-x-((mx-1)/2)));
           ans-=mdo*(mdo+1)/2;
           return ans;
}
LL check(LL tim)
{
            LL ans=0;
            LL lmost=y-1;
            LL rmost=n-y;
            LL upmost=x-1;
            LL downmost=n-x;
            ans+=calc(tim);
            if(tim>lmost)ans-=calc(tim-lmost);
            ans+=calc(tim);
            if(tim>rmost)ans-=calc(tim-rmost);
            ans++;
            ans+=min(upmost,tim);
            ans+=min(downmost,tim);
            return ans;
}
int main()
{
    scanf("%I64d%I64d%I64d%I64d",&n,&x,&y,&c);
    LL l,r,ans;
    l=0;r=2000000000;
    while(l<r)
    {
              LL mid=(l+r)>>1;
              if(check(mid)>=c)
              {
                               r=mid;
                               ans=mid;
                               }
              else l=mid+1ll;
              }
    if(check(l)>=c)ans=l;
    printf("%I64d\n",ans);
    return 0;
}