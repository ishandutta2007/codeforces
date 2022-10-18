#include<bits/stdc++.h>
using namespace std;
int a[123456];
int b[123456];
int dp[123456];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		for(int i = 0; i < n; i++) scanf("%d", &b[i]);
		int sum = 0;
		int tot = 0;
		int ans = 1023456789;
		for(int i = 0; i < n; i++)
		{
			sum += a[i] * a[i] + b[i] * b[i];
			tot += a[i] + b[i];
		}
		sum *= (n - 2);
		//printf("%d\n", sum);
		for(int i = 0; i < 12345; i++) dp[i] = 0;
		dp[0] = 99;
		for(int i = 0; i < n; i++)
		{
			for(int j = 12345; j >= 0; j--)
			{
				if(dp[j] == 100 + i - 1) dp[j] = 0; 
				if(dp[j - a[i]] == 100 + i - 1) dp[j] = 100 + i;
				if(dp[j - b[i]] == 100 + i - 1) dp[j] = 100 + i;
			}
		}
		for(int j = 0; j < 12345; j++)
		{
			if(dp[j])
			{
				ans = min(ans, sum + j * j + (tot - j) * (tot - j));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
 }