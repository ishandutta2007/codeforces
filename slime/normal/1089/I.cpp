#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 405
#define ll long long
using namespace std;
ll p;
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % p;
	if(b & 1) ns = ns * a % p;
	return ns;
}
ll jc[maxn], bjc[maxn];
//ll ans[maxn][maxn][maxn]; // yong >= k ping j jiechengfang daoshujizhihe
ll ans[maxn][maxn];
ll dp[maxn];
ll ns[maxn];
int main()
{
	int t;
	scanf("%d%lld", &t, &p);
	jc[0] = bjc[0] = 1;
	for(int i = 1; i < maxn; i++)
		jc[i] = jc[i - 1] * i % p, 
		bjc[i] = ksm(jc[i], p - 2);
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
		{
			if(i == 0)
				if(j == 0) ans[i][j] = 1;
				else ans[i][j] = 0;
			else
			{
				for(int k = 1; k <= i; k++)
					ans[i][j] = (ans[i][j] + jc[k] * ans[i - k][j - 1]) % p;
			}
		}
	ns[1] = 1;
	for(int i = 2; i < maxn; i++)
	{
		ns[i] = jc[i];
		for(int j = 1; j < i; j++)	
			ns[i] -= ns[j] * jc[i - j], 
			ns[i] %= p;
	//	if(i <= 4) cout<<i<<" "<<ns[i]<<endl;
	}
	dp[1] = 1;
	for(int i = 2; i < maxn; i++)
	{
		dp[i] = jc[i];
		for(int x = 2; x < i; x++)
		{
			ll nans = -1;
			if(x >= 3)
			{
				nans *= ans[i][x], nans %= p;
				nans *= dp[x], nans %= p;
			}
			else
				nans *= 2 * (jc[i] - ns[i]);		
			dp[i] += nans;
			dp[i] %= p;
		//	cout<<nans<<endl;
		//	if(i == 3) cout<<x<<" "<<nans<<" "<<dp[i]<<" "<<dp[x]<<endl;
		}
		if(dp[i] < 0) dp[i] += p;
	}
	for(int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}