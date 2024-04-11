#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define maxn 1000005
#define ll long long
#define ld double
#define mod 998244353
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
int main()
{
	jc[0] = bjc[0] = 1;
	for(int i = 1; i < maxn; i++)
		jc[i] = jc[i - 1] * i % mod, 
		bjc[i] = ksm(jc[i], mod - 2);
	ll ans = 0;
	int n;
	scanf("%d", &n);
	ans = jc[n] * n % mod;
	for(int i = 1; i <= n; i++)
		ans -= jc[n] * bjc[i], 
		ans %= mod;
	ans++;
	ans %= mod;
	if(ans < 0) ans += mod;
	printf("%lld\n", ans); 
	return 0;
} 
/*
2 1 1 5

 
*/