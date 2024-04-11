#include<stdio.h>
#include<algorithm>
#include<cstring>
#define MAXN 110000
using namespace std;
typedef long long LL;
int n,k;
LL data[MAXN];
LL sum[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%I64d",&data[i]);
    sort(data+1,data+1+n);
    for(int i=1;i<=n;i++)sum[i]=data[i]+sum[i-1];
    int ans=0;
    LL num=0;
    for(int i=1;i<=n;i++)
    {
            int l=1;int r=i;int res=0;
            while(l<r)
            {
                      int mid=(l+r)>>1;
                      if(data[i]*1ll*(i-mid+1)-(sum[i]-sum[mid-1])<=k)
                      res=mid,r=mid;
                      else l=mid+1;
                      }
            int mid=l;
            if(data[i]*1ll*(i-mid+1)-(sum[i]-sum[mid-1])<=k)
            res=mid,r=mid;
            res=i-res+1;
            if(res>ans){ans=res;num=data[i];}
            }
    printf("%d %I64d\n",ans,num);
    return 0;
}