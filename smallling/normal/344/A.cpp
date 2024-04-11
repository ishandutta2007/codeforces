#include<cstdio>

using namespace std;

int n,now,last,ans;

int main()
{
    scanf("%d",&n);
    ans=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&now);
        if(now!=last&&last)ans++;
        last=now;
    }
    printf("%d",ans);
}