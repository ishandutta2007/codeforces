#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define maxn 1000005
#define ll long long
#define ld double
#define mod 1000000007 
using namespace std;
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if(b & 1) ns = ns * a % mod;
	return ns;
} 
ll jc[maxn], bjc[maxn]; 
ll c(int a, int b)
{
	return jc[a] * bjc[b] % mod * bjc[a - b] % mod;
}
int main()
{
	jc[0] = bjc[0] = 1;
	for(int i = 1; i < maxn; i++)
		jc[i] = jc[i - 1] * i % mod, 
		bjc[i] = bjc[i - 1] * ksm(i, mod - 2) % mod;
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	ll ans = 0;
	for(int j = 1; j <= min(n - 1, m); j++)
	{
		ll nans = 1;
		nans *= c(m - 1, j - 1);
		if(j != n - 1) nans *= (j + 1) * ksm(n, n - 2 - j) % mod, nans %= mod;
		nans *= c(n - 2, j - 1), nans %= mod;
		nans *= jc[j - 1], nans %= mod;
		nans %= mod;
		nans *= ksm(m, n - 1 - j), nans %= mod;
		ans += nans;
	} 
	ans %= mod;
	printf("%lld\n", ans);
	return 0;
} 
/*
2 1 1 5

 
*/