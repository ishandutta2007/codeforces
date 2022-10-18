#include<bits/stdc++.h>
using namespace std;
int B[1012345];
long long a[512345];
long long s[512345];
long long f[512345];
int dp[512345];
int n;
int lowbit(int x)
{
	return (x & (-x));
}
void add(int x, int v)
{
	int N = x;
	while(N <= n + 10) 
	{
		B[N] = max(B[N], v);
		N += lowbit(N);
	}
}
int query(int x)
{
	int N = x;
	int ans = -1234567;
	while(N)
	{
		ans = max(ans, B[N]);
		N -= lowbit(N);
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		f[0] = 0;
		s[0] = 0;
		for(int i = 0; i <= n; i++) dp[i] = -1234567;
		for(int i = 0; i <= n + 10; i++) B[i] = -1234567;
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		for(int i = 1; i <= n; i++) f[i] = s[i] = s[i - 1] + a[i];
		sort(f, f + n + 1);
		int sz = unique(f, f + n + 1) - f;
		for(int i = 0; i <= n; i++) s[i] = 5 + lower_bound(f, f + sz, s[i]) - f;
		dp[0] = 0;
		add(s[0], 0);
		for(int i = 1; i <= n; i++)
		{
			dp[i] = max(dp[i], query(s[i] - 1) + i);
			if(a[i] < 0) dp[i] = max(dp[i], dp[i - 1] - 1);
			if(!a[i]) dp[i] = max(dp[i], dp[i - 1]);
			add(s[i], dp[i] - i);
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}