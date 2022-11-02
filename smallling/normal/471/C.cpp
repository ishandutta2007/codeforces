#include<stdio.h>
#include<algorithm>

using namespace std;

long long n;

int l,r,mid,now,ans;

inline int check(int x)
{
    if(1ll*x*(x+1)/2ll*3ll-1ll*x<=n)return 1;
    return 0;
}

int main()
{
    scanf("%I64d",&n);
    l=0;
    r=1e6;
    while(l<=r)
    {
        mid=l+r>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    now=ans;
    for(int i=1;i<=now;i++)
        if((n+1ll*i)%3!=0)ans--;
    printf("%d",ans);
}