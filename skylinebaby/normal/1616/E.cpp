#include<bits/stdc++.h>
using namespace std;
int dp[26][112345];
char a[112345];
char b[112345];
int B[212345];
int lowbit(int x)
{
	return (x & (-x));
}
void add(int x)
{
	int N = x;
	while(N < 212345) 
	{
		B[N]++;
		N += lowbit(N);
	}
}
int query(int x)
{
	int N = x;
	int ans = 0;
	while(N)
	{
		ans += B[N];
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
		int n;
		scanf("%d", &n);
		cin >> a;
		cin >> b;
		for(int i = 0; i < 26; i++) dp[i][n] = n;
		for(int i = 0; i < 26; i++)
		{
			for(int j = n - 1; j >= 0; j--) 
			{
				dp[i][j] = dp[i][j + 1];
				if(a[j] == 'a' + i) dp[i][j] = j;
			}
		}
		for(int i = 0; i <= 2 * n; i++) B[i] = 0;
		long long ans = 1ll * n * n;
		long long cur = 0;
		int now[26];
		for(int i = 0; i < 26; i++) now[i] = -1;
		for(int i = 0; i < n; i++)
		{
			int z = b[i] - 'a';
			for(int j = 0; j < z; j++)
			{
				int l = now[j] + 1;
				int k = dp[j][l];
				//printf("j, l, k %d %d %d\n", j, l, k);
				if(k == n) continue;
	
				int q = query(k + 1);
				ans = min(ans, cur + k - q);
				//printf("j = %d, ans = %lld\n", j, ans);
			}
			int l = now[z] + 1;
			int k = dp[z][l];
			if(k == n) break;
			now[z] = k;
			int q = query(k + 1);
			cur += k - q;
			//printf("%d, cur = %lld\n", i, cur);
			add(k + 1);
		}
		if(ans == 1ll * n * n)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n", ans);
		}
	}
	return 0;
}