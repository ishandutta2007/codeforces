#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 5005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int a[maxn];
int dp[2][maxn][maxn];
int to(int x, int y)
{
	if(x <= y) return 0;
	return x - y;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if(n == 1)
	{
		printf("0\n");
		return 0;
	}
	ll inf = 1000000000;
	for(int i = n + 2; i >= 1; i--)
		for(int j = 0; j <= n; j++)
			for(int k = 0; k < 2; k++)
			{
				if(i > n)
					if(j != 0)
						dp[k][i][j] = inf;
					else
					{
						if(i == n + 2)
							dp[k][i][j] = 0;
						else
							if(k == 0) dp[k][i][j] = 0;
							else dp[k][i][j] = to(a[n], a[n - 1] - 1);
					}
				else
				{
					int ans1 = dp[0][i + 1][j];
					if(k && i >= 2) ans1 += to(a[i - 1], a[i - 2] - 1);
					dp[k][i][j] = ans1;
					if(j)
					{
						int ans2 = dp[1][i + 2][j - 1];
						int ns = a[i] - 1;
						if(k && i >= 2) ns = min(ns, a[i - 2] - 1);
						ans2 += to(a[i - 1], ns);
						dp[k][i][j] = min(dp[k][i][j], ans2);
					}
				}
			}
	int ls = n / 2;
	if(n & 1) ls++;
	for(int i = 1; i <= ls; i++)
		printf("%d ", dp[0][1][i]);
	return 0;
 }