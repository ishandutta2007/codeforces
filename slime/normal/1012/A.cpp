#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int a[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= 2 * n; i++)
		scanf("%d", &a[i]);
	ll ans = 1000000007;
	ans *= ans;
	sort(a + 1, a + 2 * n + 1);
	for(int i = 2; i <= n; i++)
	{
		ll nans = (a[2 * n] - a[1]) * (ll)(a[i + n - 1] - a[i]);
		ans = min(ans, nans);
	}
	for(int i = n; i <= 2 * n - 1; i++)
	{
		ll ns = a[n];
		if(i == n) ns = a[n + 1];
		ll nans = (a[2 * n] - ns) * (ll)(a[i] - a[1]);
		ans = min(ans, nans);
	}
	printf("%lld\n", ans);
	return 0;
 }