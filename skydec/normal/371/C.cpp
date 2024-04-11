#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<map>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
typedef long long LL;
int opt[300];
int have[4];
int need[4];
int pri[4];
LL R;
bool check(LL x)
{
     LL res=0;
     rep(i,1,3)
     {
               LL o=x*1ll*need[i];
               if(o>have[i])res+=(o-have[i])*pri[i];
               }
     return res<=R;
}
int main()
{
    opt['B']=1;opt['C']=3;opt['S']=2;
    char str[105];scanf("%s",str+1);int len=strlen(str+1);
    rep(i,1,len)need[opt[str[i]]]++;
    rep(i,1,3)scanf("%d",&have[i]);
    rep(i,1,3)scanf("%d",&pri[i]);
    scanf("%I64d",&R);
    LL l,r,ans;ans=0;l=0;r=(LL)1e13;
    while(l<r)
    {
              LL mid=(l+r)>>1;
              if(check(mid))
              {
                            ans=mid;l=mid+1;
                            }
              else r=mid;
              }
    if(check(l))ans=l;
    printf("%I64d\n",ans);
    return 0;
}