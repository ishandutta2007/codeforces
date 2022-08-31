#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue> 
#define maxn 1000005
#define ll long long
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
int cal(int a)
{
	if(a & 1) return -1;
	return 1;
}
ll mt[maxn];
ll c[maxn];
ll jc[maxn], bjc[maxn];
int main()
{
	ll n;
	scanf("%lld", &n);
	jc[0] = bjc[0] = 1;
	for(int i = 1; i <= n; i++)
		jc[i] = jc[i - 1] * i % mod, bjc[i] = bjc[i - 1] * ksm(i, mod - 2) % mod;
	for(int i = 0; i <= n; i++)
		c[i] = jc[n] * bjc[i] % mod * bjc[n - i] % mod;
	mt[0] = 1;
	for(int i = 1; i <= n; i++)
		mt[i] = mt[i - 1] * 3 % mod;
	ll ans = 0;
	for(int i = 0; i <= n; i++)
	{
		ll nans = cal(i) * mt[i] % mod * ksm(mt[n - i], n) % mod;
		nans = nans * c[i] % mod;
	//	cout<<i<<" "<<nans<<endl;
		if(i == 0) ans += nans;
		else ans += 2 * nans;
		ans %= mod;
	}
//	cout<<ans<<endl;
	for(int i = 1; i <= n; i++)
	{
		ll fr = cal(i) * 3;
		ll nm = mt[n - i];
		fr *= cal(n);
		fr = fr * c[i] % mod;
		ll nans = ksm(-nm + 1, n) - ksm(-nm, n);
		ans += nans * fr;
		ans %= mod;
	}
	ans = ksm(3, n * n) - ans;
	ans %= mod; 
	if(ans < 0) ans += mod;
	printf("%lld\n", ans); 
	return 0;
}