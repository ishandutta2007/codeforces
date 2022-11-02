#include<stdio.h>
#include<algorithm>

using namespace std;

int ans,n,m,k,a[1010];

inline int work(int x)
{
    int nowans=0;
    while(x)
    {
        nowans+=x%2;
        x/=2;
    }
    return nowans;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m+1;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        if(work(a[i]^a[m+1])<=k)ans++;
    printf("%d",ans);
}