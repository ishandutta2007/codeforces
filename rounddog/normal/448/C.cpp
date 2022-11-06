#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 5020
#define inf 1048576

using namespace std;

int dp[maxn],a[maxn],q,ans,n,m,cnt;
bool l;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	dp[0]=0;
	a[0]=a[n+1]=0;
	for (int i=1;i<=n+1;i++)
	{
		dp[i]=inf;
	    for (int j=i-1;j>=0&&a[j+1]>=a[i];j--)
	        dp[i]=min(dp[i],dp[j]+max(a[i]-a[j],a[j]-a[i])+2*(i-j-1));
	}
	printf("%d\n",dp[n+1]/2);
	return 0;
}