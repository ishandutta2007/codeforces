#include<cstdio>
#include<algorithm>

using namespace std;

long long n,m,k,l,r,mid,ans;

int work(long long x)
{
    long long nowans=0;
    for(int i=1;i<=n;i++)
        nowans+=min(x/i,m);
    return nowans>=k;
}

int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    l=1;
    r=n*m;
    while(l<=r)
    {
        mid=l+r>>1ll;
        if(work(mid))r=mid-1,ans=mid;
        else l=mid+1;
    }
    printf("%I64d",ans);
}