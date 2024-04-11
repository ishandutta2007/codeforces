#include<bits/stdc++.h>
using namespace std;
int dp[12345];

int main()
{
	int a,b,c,n,k;
	scanf("%d %d",&n,&k);
	int ans = 0;	
	int tot = 0;
	for(int i = 0;i<n;i++) 
	{
		scanf("%d",&dp[i]);
		tot += dp[i];
	}
	for(int i = 0;i<k;i++)
	{
		int sum = 0;
		for(int j = i;j<n;j+=k) sum += dp[j];
		ans = max(ans,abs(tot-sum));
	}
	printf("%d\n",ans);
	return 0;
}