#include<bits/stdc++.h>
using namespace std;
const int N=40005,b=32767;
int dp[N];
int main()
{
	for(int i=0;i<=b;i++)
		dp[i]=-1;
	dp[0]=0;
	for(int j=1;j<=15;j++)
		for(int i=1;i<=b;i++)
			if(dp[i]==-1&&(dp[(i<<1)&b]==j-1||dp[(i+1)&b]==j-1))
				dp[i]=j;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d ",dp[n]);
	}
	return 0;
}