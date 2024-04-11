#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define mod 1000000007
#define maxn 105
#define ll long long
using namespace std;
int dp[maxn][maxn * maxn];
int c[maxn][maxn];
int a[maxn];
int n;
int main()
{
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j <= i; j++)
		{
			if(j == 0) c[i][j] = 1;
			else
			{
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
				if(c[i][j] >= mod) c[i][j] -= mod;
			}
		}
	scanf("%d", &n);
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	bool fl = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] != a[1] && a[i] != a[n]) fl = 1;
	if(!fl)
	{
		printf("%d\n", n);
		return 0;
	}
	for(int i = 1; i <= n; i++)
		for(int j = i; j >= 0; j--)
			for(int k = j * maxn; k >= 0; k--)
			{
				if(j && (k >= a[i]))
				{
					dp[j][k] += dp[j - 1][k - a[i]];
					if(dp[j][k] >= mod) dp[j][k] %= mod;
				}
			}
	int ans = 0;
	for(int i = 1; i <= n; )
	{
		int j = i;
		while(j <= n && a[j] == a[i]) j++;
		for(int t = 1; t <= j - i; t++)
			if(dp[t][t * a[i]] == c[j - i][t]) 
				ans = max(ans, t);
		i = j;
	}
	printf("%d\n", ans);
	return 0;
}
/*
5 4 4 4 4 16
*/