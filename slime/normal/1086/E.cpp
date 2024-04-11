#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
struct bit
{
	int d[maxn];
	bit()
	{
		memset(d, 0, sizeof(d));
	}
	void clear()
	{
		memset(d, 0, sizeof(d));
	}
	int lb(int x)
	{
		return x & (-x);
	}
	void ch(int pl, int num)
	{
		if(pl == 0) return ;
		while(pl < maxn)
			d[pl] += num, 
			pl += lb(pl);
	}
	int q(int pl)
	{
		if(pl < 0) return 0;
		int ans = 0;
		while(pl)
			ans += d[pl], 
			pl -= lb(pl);
		return ans;
	}
}th[2];	
int a[maxn][maxn];
ll dp[maxn][maxn];
int fl[maxn][2];
int main()
{
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
		{
			if(i == 0)
				if(j == 0) dp[i][j] = 1;
				else dp[i][j] = dp[i][j - 1] * j % mod;
			else
			{
				dp[i][j] = j * dp[i - 1][j] % mod;
				if(i >= 2) 
					dp[i][j] += (i - 1) * dp[i - 2][j + 1] % mod, 
					dp[i][j] %= mod;
			}
		}
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ll n1 = 1;
		for(int t = 0; t < n - i; t++)
			n1 = n1 * dp[n][0] % mod;
		memset(fl, 0, sizeof(fl));
		th[0].clear(), //  
		th[1].clear(); //  
		for(int i = 1; i <= n; i++)
			th[0].ch(i, 1);
		int cnt = 0;
		// cnt :  
		for(int j = 1; j <= n; j++)
		{
			fl[a[i - 1][j]][0] = 1;
			if(fl[a[i - 1][j]][1]) cnt--; 
			else
				th[0].ch(a[i - 1][j], -1), 
				th[1].ch(a[i - 1][j], 1);
			
			int t2 = th[1].q(a[i][j] - 1);
			int t1 = th[0].q(a[i][j] - 1);
			if(a[i - 1][j] < a[i][j] && !fl[a[i - 1][j]][1])
				t2--; 
			//t1 : cnt + 1
			//t2 : cnt 
			ll nans = 0;
			if(i != 1)
			{
				if(n - j - cnt - 1 >= 0) 
					nans += dp[n - j - (cnt + 1)][cnt + 1] * t1, 
					nans %= mod;
				if(n - j - cnt >= 0) 
					nans += dp[n - j - cnt][cnt] * t2, 
					nans %= mod;
				nans %= mod;
			}
			else
				nans = th[0].q(a[i][j] - 1) * dp[0][n - j] % mod;	
			
			ans += nans * n1, 
		//	cout<<"WORK"<<i<<" "<<j<<" "<<nans<<" "<<n1<<endl;
			ans %= mod;
			
			fl[a[i][j]][1] = 1;
			if(!fl[a[i][j]][0]) 
			{
				cnt++;
				th[0].ch(a[i][j], -1);
			}
			else
				th[1].ch(a[i][j], -1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}