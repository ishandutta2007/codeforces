#include <bits/stdc++.h>
#define maxn 1000005
#define ll long long
#define mod 998244353
using namespace std;
int n, m;
int a[maxn];
int dp[5][3][maxn];
 
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	for(int i = m + 1; i >= 0; i--)
		for(int k = 0; k < 5; k++)
			for(int l = 0; l < 3; l++)
			{
				if(a[i] < k || a[i + 1] < l)
					dp[k][l][i] = mod;
				else
				{
					if(i == m + 1)
						dp[k][l][i] = 0;
					else 
					{
						dp[k][l][i] = mod;
						for(int s = 0; s <= 2; s++)
						{
							if(k + s > a[i]) continue;
							dp[k][l][i] = min(dp[k][l][i], dp[l + s][s][i + 1] + (a[i] - (k + s)) % 3);
						}
					}
				}	
			} 
	int ans = (n - dp[0][0][1]) / 3;
	printf("%d\n", ans);
	return 0;
}