#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int dp[30010][500];
int num[30010];
int main()
{
	int n,k,n1,t1,n2;
	cin>>n>>k;
	for(n1=1;n1<=n;n1++)
	{
		scanf("%d",&t1);
		num[t1]++;
	}
	for(n1=0;n1<500;n1++)
		dp[k][n1]=-inf;
	int ans=num[k];
	dp[k][250]=num[k];
	for(n1=k+1;n1<=30000;n1++)
		for(n2=0;n2<500;n2++)
		{
			dp[n1][n2]=-inf;
			if(n2-250+k>0)
			{
				if(n2-250+k>1&&n2-1>=1&&n1-(n2-250+k)>=k)
					dp[n1][n2]=max(dp[n1][n2],dp[n1-(n2-250+k)][n2-1]);
				if(n1-(n2-250+k)>=k)
					dp[n1][n2]=max(dp[n1][n2],dp[n1-(n2-250+k)][n2]);	
				if(n2+1<500&&n1-(n2-250+k)>=k)
					dp[n1][n2]=max(dp[n1][n2],dp[n1-(n2-250+k)][n2+1]);
				dp[n1][n2]+=num[n1];
				if(dp[n1][n2]>0)
				ans=max(ans,dp[n1][n2]);
			}
		}
	cout<<ans;
}