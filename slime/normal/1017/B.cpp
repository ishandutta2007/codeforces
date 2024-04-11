#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define maxn 200005
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
char inp[2][maxn];
ll cnt[2][2];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 2; i++)
		scanf("%s", inp[i] + 1);
	for(int i = 1; i <= n; i++)
		cnt[inp[0][i] - '0'][inp[1][i] - '0']++;
	ll ans = cnt[0][0] * cnt[1][0] + cnt[0][1] * cnt[1][0] + cnt[0][0] * cnt[1][1];
	printf("%lld\n", ans);
	return 0;
}