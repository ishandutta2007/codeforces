#include<bits/stdc++.h>
#define MAXN 4005
#define SQRN 70
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dp[MAXN][70+SQRN][SQRN][2];
int n,a[MAXN],sum[MAXN];
int solve(int l,int r,int num,int turn)
{
	int dis=70+l-(n+1-r);
	if(dp[l][dis][num][turn]!=-INF) return dp[l][dis][num][turn];
	if(l>=r) 
	{
		if(turn==0) return INF; else return -INF;
	}
	if(turn==0) 
	{
		int ret=max(solve(l+num,r,num,1),solve(l+num+1,r,num+1,1));
		if(ret==-INF) return dp[l][dis][num][turn]=sum[l]-(sum[n]-sum[r-1]); else return dp[l][dis][num][turn]=ret;
	}
	else 
	{
		int ret=min(solve(l,r-num,num,0),solve(l,r-num-1,num+1,0));
		if(ret==INF) return dp[l][dis][num][turn]=sum[l]-(sum[n]-sum[r-1]); else return dp[l][dis][num][turn]=ret;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=0;i<MAXN;i++)
		for(int j=0;j<70+SQRN;j++)
			for(int k=0;k<SQRN;k++)
				for(int l=0;l<2;l++)
					dp[i][j][k][l]=-INF;
	printf("%d\n",solve(0,n+1,1,0));
	return 0;
}