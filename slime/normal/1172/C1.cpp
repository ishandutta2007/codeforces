#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define maxn 300005
#define ll long long
#define ld double
#define mod 998244353
#define maxm 3005
using namespace std;
int n, m; 
int a[maxn], w[maxn];
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if(b & 1) ns = ns * a % mod;
	return ns;
}
ll dp[maxm][maxm];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ll S[2] = {0, 0};
	for(int i = 1; i <= n; i++)
		scanf("%d", &w[i]), 
		S[a[i]] += w[i], 
		S[a[i]] %= mod;
	ll f[2] = {S[0], S[1]};
	dp[1][0] = 1;
	for(int i = 1; i <= m; i++)
		for(int j = 0; j <= i; j++)
		{
			ll n1 = S[1] + j, n2 = S[0] - (i - 1 - j);
			if(!dp[i][j]) continue;
			ll bk = ksm((n1 + n2) % mod, mod - 2);
			n1 = n1 * bk % mod, 
			n2 = n2 * bk % mod;
			dp[i + 1][j] += n2 * dp[i][j], dp[i + 1][j] %= mod;
			dp[i + 1][j + 1] += n1 * dp[i][j], dp[i + 1][j + 1] %= mod;
		}
	for(int j = 0; j <= m + 1; j++)
		f[1] += dp[m + 1][j] * j, f[1] %= mod, 
		f[0] -= dp[m + 1][j] * (m - j), f[0] %= mod;
	S[0] = ksm(S[0], mod - 2);
	S[1] = ksm(S[1], mod - 2);
	for(int i = 1; i <= n; i++)
	{
		ll ns = f[a[i]] * S[a[i]] % mod * w[i] % mod;
		if(ns < 0) ns += mod;
		printf("%lld\n", ns);
	}
	return 0;
}