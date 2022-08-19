#include <bits/stdc++.h>
#define v 60
#define maxn 100005
#define ll long long
#define ld double
using namespace std;
struct th
{
	ll num;
	int id;
	bool operator < (const th &u)const
	{
		if(num != u.num) return num < u.num;
		return id < u.id;
	}
}p[v][maxn]; 
int id[v][maxn];
ll a[maxn];
int dp[v][maxn];
int fr[v][maxn];
int main()
{
	int n;
	cin>>n;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		for(int j = 0; j < v; j++)
		{
			ll ns = (1ll << j);
			if(a[i] & ns) ans--;
			p[j][i].num = (a[i] & (ns * 2 - 1));
			p[j][i].id = i;
		}
	}
//	cout<<ans<<endl;
	for(int j = 0; j < v; j++)
	{
		sort(p[j] + 1, p[j] + n + 1);
		for(int i = 1; i <= n; i++)
			id[j][p[j][i].id] = i;
	}
	for(int j = 0; j < v; j++)
	{
		for(int i = 0; i <= n; i++)
		{
			dp[j][i] = v * maxn * 10;
			ll ns = p[j][i].num & (1ll << j);
			if(ns) ns = 1;
			int nx = 0;
			if(j) nx = id[j - 1][p[j][i].id];
			for(int s = 0; s < 2; s++)
			{
				if(s < ns) continue;
				int pls = 0;
				if(s == 1) pls = n;
				if(s > ns) 
				{
					if(j) dp[j][i] = min(dp[j][i], pls + fr[j - 1][0]);
					else dp[j][i] = min(dp[j][i], pls);
				}
				if(s == ns)
				{
					if(j) dp[j][i] = min(dp[j][i], pls + fr[j - 1][nx]);
					else dp[j][i] = min(dp[j][i], pls);
				}
			}
			dp[j][i] += (n - i);
		//	cout<<i<<" "<<j<<" "<<dp[j][i]<<" "<<ns<<endl; 
		}
		for(int i = n; i >= 0; i--)
			if(i == n) fr[j][i] = dp[j][i];
			else fr[j][i] = min(fr[j][i + 1], dp[j][i]);
	}
	ans += dp[v - 1][n];
	cout<<ans<<endl;
	return 0;
} 
/*
4
3 3 3 3
 
*/