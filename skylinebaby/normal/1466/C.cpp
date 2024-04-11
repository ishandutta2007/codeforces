#include<bits/stdc++.h>
using namespace std;
char a[112345];
int dp[2][2][112345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		cin >> a;
		
		int n = (int)strlen(a);
		dp[0][0][0] = 0;
		dp[0][1][0] = 1;
		dp[1][0][0] = 0;
		dp[1][1][0] = 1;		
		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) dp[j][k][i] = 2 * n;
				if(a[i - 1] != a[i] && (i == 1 || a[i - 2] != a[i]))
				{
					for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) for(int l = 0; l < 2; l++)
						dp[j][k][i] = min(dp[j][k][i], dp[l][j][i - 1] + k);				
				}
				else if(i == 1 || a[i - 2] != a[i])
				{
					for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) for(int l = 0; l < 2; l++)	
					{
						if(j == 0 && k == 0) continue;
						dp[j][k][i] = min(dp[j][k][i], dp[l][j][i - 1] + k);
					}
				}
				else if(a[i - 1] != a[i])
				{
					for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) for(int l = 0; l < 2; l++)	
					{
						if(l == 0 && k == 0) continue;
						dp[j][k][i] = min(dp[j][k][i], dp[l][j][i - 1] + k);
					}					
				}
				else
				{
					for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) for(int l = 0; l < 2; l++)	
					{
						if(l == 0 && k == 0) continue;
						if(j == 0 && k == 0) continue;
						dp[j][k][i] = min(dp[j][k][i], dp[l][j][i - 1] + k);
					}						
				}
			//for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) 
				//printf("dp[%d][%d][%d] = %d\n", j, k, i, dp[j][k][i]);
			
		}
		int ans = 2 * n;
		for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) ans = min(ans, dp[j][k][n - 1]);
		printf("%d\n", ans);
	}

	return 0;
 }