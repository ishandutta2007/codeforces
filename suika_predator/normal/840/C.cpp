#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=301,MOD=1e9+7;
int n,tmp;
/*struct atom
{
	int x,id;
	inline bool operator<(const atom &a){return x<a.x;}
};*/
int a[MAXN];
int dp[MAXN][MAXN][MAXN];//i,current,other
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		for(int j=2;j*j<=tmp;j++)
		{
			while(tmp%(j*j)==0)
				tmp/=j*j;
		}
		a[i]=tmp;
	}
	sort(a+1,a+n+1);
	a[0]=-1;
	dp[0][0][0]=1;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;j+k<=n;k++)
				{
					if(j+k!=0)dp[i][0][j+k-1]=(dp[i][0][j+k-1]+(long long)dp[i-1][j][k]*(j+k))%MOD;//insert in the middle of two same numbers
					dp[i][0][j+k]=(dp[i][0][j+k]+(long long)dp[i-1][j][k]*(i-j-k))%MOD;//insert in the middle of two different numbers or on the border
				}
			}
			cnt=1;
		}
		else
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++)
				{
					if(k!=0)dp[i][j][k-1]=(dp[i][j][k-1]+(long long)dp[i-1][j][k]*k)%MOD;//insert in the middle of two same numbers different from current number
					dp[i][j][k]=(dp[i][j][k]+(long long)dp[i-1][j][k]*(i-2*cnt+j-k))%MOD;//insert in the middle of two same numbers different from current number or on the border beside one number different from current number
					dp[i][j+1][k]=(dp[i][j+1][k]+(long long)dp[i-1][j][k]*j)%MOD;//insert in the middle of two current numbers
					dp[i][j+1][k]=(dp[i][j+1][k]+(long long)dp[i-1][j][k]*(cnt*2-j*2))%MOD;//insert beside one current number
				}
			}
			cnt++;
		}
		/*
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				printf("%d ",dp[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n");
		*/
	}
	printf("%d\n",dp[n][0][0]);
	return 0;
}