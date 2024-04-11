#include<bits/stdc++.h>
using namespace std;
int a[123456];
int cal[132][112];
int dp[123][123];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) for(int j = i; j <= n; j++)
		{
			vector<int> temp;
			for(int s = i; s <= j; s++) temp.push_back(a[s]);
			sort(temp.begin(), temp.end());
			int z = j - i + 1;
			int nd = 0;
			for(int k = 0; k < z; k++) 
			{
				if(temp[k] > nd) 
				{
					break;
				}
				nd = temp[k] + 1;
			}
			cal[i][j] = nd;
		}
		for(int i = 1; i <= n; i++) for(int j = i; j <= n; j++) 
		{
			dp[i][j] = cal[i][j] + 1;
		}
		for(int k = 0; k < n; k++) for(int i = 1; i <= n; i++) 
		{
			int j = i + k;
			if(j > n) continue;
			for(int l = i; l < j; l++)
			{
				dp[i][j] = max(dp[i][j], cal[i][l] + 1 + dp[l + 1][j]);
			}
			//printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) for(int j = i; j <= n; j++)
		{
			ans += dp[i][j];
		}
		printf("%d\n", ans);
	}
	return 0;
 }