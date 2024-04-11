#include<cstdio>

using namespace std;

int cnt1,cnt2,x,y;
long long l,r,mid,ans;

int check(long long now)
{
    if(now-now/x>=cnt1&&now-now/y>=cnt2&&now-now/x/y>=cnt1+cnt2)return 1;
    return 0;
}

int main()
{
    scanf("%d%d%d%d",&cnt1,&cnt2,&x,&y);
    l=0;
    r=1e16;
    while(l<r)
    {
        mid=l+r>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    if(check(l))ans=l;
    printf("%I64d",ans);
}