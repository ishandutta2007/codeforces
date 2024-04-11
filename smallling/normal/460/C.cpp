#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a[100010],n,m,w,Max,mid,ans,sum[100010];

inline bool check(int x)
{
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
    {
        sum[i]+=sum[i-1];
        if(sum[i]-sum[max(i-w,0)]+a[i]<x)sum[i]+=x-sum[i]+sum[max(i-w,0)]-a[i];
        if(sum[i]>m)return 0;
    }
    return 1;
}

int main()
{
    scanf("%d%d%d",&n,&m,&w);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),Max=max(Max,a[i]);
    int l=1,r=m+Max;
    while(l<=r)
    {
        mid=l+r>>1;
        if(check(mid))l=mid+1,ans=mid;
        else r=mid-1;
    }
    printf("%d",ans);
}