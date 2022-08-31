#include<stdio.h>
#define MAXN 2005
using namespace std;
typedef long long LL;
int n,k;
int data[MAXN];
int f[MAXN];
#define abs(x) ((x)>0?(x):-(x))
#define Min(a,b) ((a)<(b)?(a):(b))
int check(LL mid)
{
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=n;i++)
    for(int j=1;j<i;j++)
    if(abs(data[i]-data[j])<=(i-j)*1ll*mid)
    f[i]=Min(f[i],f[j]+i-j-1);
    int ans=n+1;
    for(int i=1;i<=n;i++)
    if(ans>f[i]+n-i-1)ans=f[i]+n-i-1;
    //printf("%d %d\n",mid,ans);
    return ans;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&data[i]);
    LL l,r,ans;
    l=0;r=2000000000;ans=0;
    while(l<r)
    {
              LL mid=(((l+r)*1ll)/2ll);
              if(check(mid)>k)l=mid+1ll;
              else
              {
                  r=mid;
                  ans=mid;
                  }
                  }
    if(check(l)<=k)ans=l;
    printf("%I64d\n",ans);
    return 0;
}