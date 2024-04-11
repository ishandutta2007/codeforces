#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 400005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
ll ksm(ll a, ll b)
{
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if(b & 1) ns = ns * a % mod;
	return ns;
}
int fa[maxn];
int gfa(int a)
{
	if(fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n + m; i++)
		fa[i] = i;
	for(int i = 1; i <= q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		fa[gfa(y + n)] = gfa(x);
	}
	int tot = 0;
	for(int i = 1; i <= n + m; i++)
		if(fa[i] == i) tot++;
	printf("%d\n", tot - 1);
	return 0;
 }