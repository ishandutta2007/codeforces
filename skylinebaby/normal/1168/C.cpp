#include<bits/stdc++.h>
using namespace std;
int a[312345];
int dp[312345][19];
int pre[312345][19];
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int j = 0;j<=18;j++)
	{
		int last = n;
		for(int i = n-1;i>=0;i--)
		{
			if(a[i]&(1<<j)) 
			{
				pre[i][j] = last;
				last = i;
			}
		}
	}
	//for(int i = 0;i<n;i++) for(int k = 0;k<=1;k++) printf("pre[%d][%d] = %d\n",i,k,pre[i][k]);
	
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<=18;j++)
		{
			if (a[i]&(1<<j)) dp[i][j] = i;
			else dp[i][j] = n; 
		}
	}
	for(int i = n-1;i>=0;i--)
	{
		for(int j = 0;j<=18;j++)
		{
			for(int k = 0;k<=18;k++) if(a[i]&(1<<k))
			{
				if(pre[i][k]<n) dp[i][j] = min(dp[pre[i][k]][j],dp[i][j]);				
			}
		}
	}
	//for(int i = 0;i<n;i++) for(int k = 0;k<=1;k++) printf("dp[%d][%d] = %d\n",i,k,dp[i][k]);
	
	for(int i = 0;i<q;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		x--;y--;
		int flag = 0;
		for(int k = 0;k<=18;k++)
		{
			if(a[y]&(1<<k))
			{
				//printf("%d %d %d\n",k,dp[x][k],y);
				if(dp[x][k]<=y) flag = 1;
			}
			//printf("flag = %d\n",flag);
		}
		if(flag) printf("Shi\n");
		else printf("Fou\n");
	}
	return 0;
}