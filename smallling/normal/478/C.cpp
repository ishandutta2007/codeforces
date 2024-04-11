#include<cstdio>
#include<algorithm>

using namespace std;

int ans,a[4],now;

int main()
{
    for(int i=1;i<=3;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+3);
    now=a[3]-a[2];
    ans=min(now/2,a[1]);
    a[1]-=ans;
    a[3]-=ans*2;
    ans+=a[1];
    a[2]-=a[1];
    a[3]-=a[1];
    a[1]=0;
    now=a[3]-a[2];
    now=min(min(now,a[3]/2),a[2]);
    ans+=now;
    a[3]-=now*2;
    a[2]-=now;
    ans+=min(a[3]/3,a[2]/3)*2;
    now=min(a[3]/3,a[2]/3);
    a[3]-=now*3;
    a[2]-=now*3;
    now=min(a[3],a[2]/2);
    ans+=now;
    a[3]-=now;
    a[2]-=now*2;
    now=min(a[3]/2,a[2]);
    ans+=now;
    printf("%d",ans);
}