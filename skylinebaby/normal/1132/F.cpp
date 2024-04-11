#include<bits/stdc++.h>
using namespace std;
char s[600];
int dp[510][510];
int main()
{
	int n;
	scanf("%d",&n);
	cin >> s;
	for(int i = 0;i<n;i++) dp[i][i] = 1;
	for(int i = 2;i<=n;i++) for(int j = 0;j+i<=n;j++)
	{
		dp[j][j+i-1] = dp[j][j+i-2]+1;
		if(s[j+i-1]==s[j+i-2]) 
		{
			dp[j][j+i-1] = dp[j][i+j-2];
			continue;
		}
		for(int k = j;k<j+i-2;k++)
		{
			if(s[k]==s[j+i-1]) dp[j][i+j-1] = min(dp[j][i+j-1],dp[j][k]+dp[k+1][i+j-2]);
		}
	}
	printf("%d\n",dp[0][n-1]);
	return 0;
}