#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 500005
#define inf 1000000007
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
char s[maxn], t[maxn];
int n, k; 
int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	scanf("%s", t);
	ll ans = 0;
	int dv = 0;
	for(int i = 0; i < n; i++)
	{
		dv *= 2;
		dv += t[i] - s[i];
		if(dv >= k) dv = max(k, 100);
		ans += min(dv + 1, k);
	}
	printf("%lld\n", ans);
	return 0;
 }