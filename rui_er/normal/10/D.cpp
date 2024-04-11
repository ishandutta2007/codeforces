//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2001;
 
int n, m, ans;
int r = 1, c = 1;
int a[MAXN], b[MAXN], dp[MAXN][MAXN];
stack<int> s;

int main()
{
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for(int i=1;i<=m;i++) scanf("%d", &b[i]);
	for(int i=1;i<=n;i++)
	{
		int maxdp = 0;
		for(int j=1;j<=m;j++)
		{
			if(a[i] != b[j]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = maxdp + 1;
			if(a[i] > b[j]) maxdp = max(maxdp, dp[i-1][j]);
		}
	}
	for(int j=m;j>=1;j--)
	{
		for(int i=n;i>=1;i--)
		{
			if(dp[i][j] > ans && a[i] == b[j])
			{
				ans = dp[i][j];
				r = i;
				c = j;
			}
		}
	}
	printf("%d\n", ans);
	for(int i=r;i>=1;i--)
	{
		if(a[i] != b[c]) continue;
		s.push(b[c]);
		if(dp[i][c] == 1) break;
		for(int j=c-1;j>=1;j--)
		{
			if(b[j] < b[c] && dp[i-1][j] + 1 == dp[i][c])
			{
				c = j;
				break;
			}
		}
	}
	while(!s.empty())
	{
		printf("%d ", s.top());
		s.pop();
	}
	printf("\n");
	return 0;
}