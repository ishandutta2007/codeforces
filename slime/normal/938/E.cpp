#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 1000005
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
int a[maxn];
int ed[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; )
	{
		int j = i;
		while(j <= n && a[j] == a[i])
			j++;
		for(int k = i; k < j; k++)
			ed[k] = n - i + 1;
		i = j;
	}
	ll ans = 0;
	ll jc = 1;
	ll bjc = 1;
	for(int i = 1; i <= n; i++)
		jc = jc * i % mod;
	bjc = jc * ksm(n, mod - 2) % mod;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == a[n]) continue;
		ll nans = a[i] * ksm(ed[i], mod - 2) % mod;
	//	cout<<i<<" "<<ed[i]<<" "<<a[i]<<" "<<nans<<endl;
		ans = (ans + nans) % mod;
	}	
	ans = ans * jc % mod;

//	ans = (ans + mod) % mod;
	printf("%I64d\n", ans);
	return 0; 
}