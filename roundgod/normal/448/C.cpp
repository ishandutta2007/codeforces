#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
    int a[5010],dp[5010],n,i,j;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    for(i=1;i<=n+1;i++)
        dp[i]=2000000000;
    dp[0]=0;
        for(i=1;i<=n+1;i++)
          for(j=i-1;j>=0&&a[j+1]>=a[i];j--)
             dp[i]=min(dp[i],dp[j]+max(a[j]-a[i],a[i]-a[j])+(i-j)*2-2);
    printf("%d",dp[n+1]/2);
    return 0;
}