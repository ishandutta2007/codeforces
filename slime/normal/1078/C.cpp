#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define mod 998244353
#define maxn 300005
#define ll long long
using namespace std;
struct edge
{
	int u, v;
	edge *next;
}p[maxn << 1], *h[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->next = h[u], h[u] = n1;
}
ll dp[maxn][2];
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if(b & 1) ns = ns * a % mod;
	return ns;
}
void dfs(int a, int fa)
{
	dp[a][1] = 1;
	ll ns = 1;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa) continue;
		dfs(p->v, a);
		ns = ns * (dp[p->v][0] * 2 + dp[p->v][1]) % mod;
		dp[a][1] = dp[a][1] * (dp[p->v][0] + dp[p->v][1]) % mod; 
	}
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->v == fa) continue;
		ll nans = ns;
		nans = nans * ksm((dp[p->v][0] * 2 + dp[p->v][1]) % mod, mod - 2) % mod;
		for(edge *q = h[p->v]; q; q = q->next)
		{
			if(q->v == a) continue;
			nans = nans * (dp[q->v][0] + dp[q->v][1] + dp[q->v][0]) % mod;
		}
		dp[a][0] += nans;
		dp[a][0] %= mod;
	}
//	cout<<a<<" "<<fa<<" "<<dp[a][0]<<" "<<dp[a][1]<<endl;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v), addedge(v, u);
	}
	dfs(1, 0);
	printf("%lld\n", (dp[1][0] + dp[1][1]) % mod);
	return 0;
}