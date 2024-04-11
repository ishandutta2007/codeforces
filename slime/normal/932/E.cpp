#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 5005
using namespace std;
const ll mod = 1000000007;
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if(b & 1) ns = ns * a % mod;
	return ns;
}
int n, k;
int nnum[maxn][maxn];
ll ns[maxn];
ll tms[maxn];
ll bjc[maxn], jc[maxn];
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i <= k; i++)
	{
		if(!i) bjc[i] = jc[i] = 1;
		else 
			bjc[i] = bjc[i - 1] * ksm(i, mod - 2) % mod, 
			jc[i] = jc[i - 1] * i % mod;
	
	}
	if(n <= k)
	{
		ll ans = 0;
		for(int i = 1; i <= n; i++)
		{
			ll n1 = ksm(i, k);
			n1 = n1 * jc[n] % mod * bjc[i] % mod * bjc[n - i] % mod;
			ans = (ans + n1) % mod;
		}
		printf("%I64d\n", ans);
		return 0;
	}
	for(int i = 0; i <= k; i++)
	{
		if(!i) bjc[i] = 1;
		else bjc[i] = bjc[i - 1] * ksm(i, mod - 2) % mod;
		if(i == 0) nnum[i][0] = 1;
		else
		{
			ll nbk = ksm(i, mod - 2);
			for(int j = 1; j <= i; j++)
			{
				ll ns1 = nnum[i - 1][j] * (ll)(1 - i) + nnum[i - 1][j - 1];
				ns1 = ns1 % mod * nbk % mod;
				nnum[i][j] = ns1;
			}
		}
	}
	ns[k] = 1;
	ll ans = 0;
	for(int i = k; i >= 0; i--)
	{
		ll nbk = ksm(nnum[i][i], mod - 2) * ns[i] % mod;
		for(int j = i; j >= 0; j--)
			ns[j] = (ns[j] - nbk * nnum[i][j]) % mod;
		tms[i] = nbk;
	//	cout<<tms[i]<<" ";
		ll nans = ksm(2, n - i) * tms[i] % mod;
		for(int j = n; j >= n - i + 1; j--)
			nans = nans * j % mod;
		nans = nans * bjc[i] % mod;
		ans = (ans + nans) % mod;
	}
	if(ans < 0) ans += mod;
	printf("%I64d\n", ans);
	return 0; 
}