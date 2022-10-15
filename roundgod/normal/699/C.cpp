#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#define MAXN 101
using namespace std;
int dp[MAXN][3];
int a[MAXN];
int n;
int main()
{
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  scanf("%d",&a[i]);
	if(a[0]==1) dp[0][1]=1;
	if(a[0]==2) dp[0][2]=1;
	if(a[0]==3)
	{
		dp[0][1]=1;
		dp[0][2]=1;
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]==0) 
		{
			dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
			dp[i][1]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
			dp[i][2]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
		}
		if(a[i]==1) 
		{
			dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
			dp[i][1]=max(max(dp[i-1][0]+1,dp[i-1][1]),dp[i-1][2]+1);
			dp[i][2]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
		}
		if(a[i]==2) 
		{
			dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
			dp[i][1]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
			dp[i][2]=max(max(dp[i-1][0]+1,dp[i-1][1]+1),dp[i-1][2]);
		}
		if(a[i]==3) 
		{
			dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
			dp[i][1]=max(max(dp[i-1][0]+1,dp[i-1][1]),dp[i-1][2]+1);
			dp[i][2]=max(max(dp[i-1][0]+1,dp[i-1][1]+1),dp[i-1][2]);
		}
	}
	int x=n-max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
	printf("%d",x);
	return 0;
}