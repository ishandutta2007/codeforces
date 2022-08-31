#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 3005
#define mod 1000000007
#define ll long long
using namespace std;

ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if(b & 1) ns = ns * a % mod;
	return ns;
}
struct edge
{
	int u, v;
	edge *next;
}p[maxn * 2], *h[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->next = h[u], h[u] = n1;
}
ll bk[maxn];
int size[maxn];
ll dp[maxn][maxn];
void dfs(int a)
{
	size[a] = 1;
	dp[a][0] = 0;	
	for(edge *p = h[a]; p; p = p->next)
		dfs(p->v), size[a] += size[p->v];
	for(int i = 1; i < maxn; i++)
	{
		dp[a][i] = dp[a][i - 1];
		ll ns = 1;
		for(edge *p = h[a]; p; p = p->next)
			ns = ns * dp[p->v][i] % mod;
		dp[a][i] += ns, dp[a][i] %= mod;
	}
}
ll jc[maxn], bjc[maxn];
ll c1(int a, int b)
{
	if(b > a) return 0;
	ll ans = jc[a] * bjc[b] % mod * bjc[a - b] % mod;
	return ans;
}
ll c(ll a, ll b)
{
	ll ns = 1;
	for(int i = 1; i <= b; i++)
		ns = ns * bk[i] % mod, 
		ns = ns * (a - i + 1) %  mod;
	return ns;
}
int n, d;
int main()
{
	scanf("%d%d", &n, &d);
	jc[0] = bjc[0] = 1;
	for(int i = 1; i <= n; i++)
		bk[i] = ksm(i, mod - 2), 
		jc[i] = jc[i - 1] * i % mod, 
		bjc[i] = bjc[i - 1] * bk[i] % mod;
		
	for(int i = 2; i <= n; i++)
	{
		int p;
		scanf("%d", &p);
		addedge(p, i);
	}
	dfs(1);
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i - 1; j++)
			dp[1][i] -= dp[1][j] * c1(i, j), 
			dp[1][i] %= mod;
	for(int i = 1; i <= n && i <= d; i++)
		ans = ans + c(d, i) * (dp[1][i]) % mod, ans %= mod;
	if(ans < 0) ans += mod;
	printf("%lld\n", ans);
	return 0;
}