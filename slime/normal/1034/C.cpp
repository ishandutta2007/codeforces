#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define ll long long
#define ld double
#define mod 1000000007
using namespace std;
struct edge
{
	int u, v;
	edge *next;
}egp[maxn], *h[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
	edge *n1 = &egp[egcnt++];
	n1->u = u, n1->v = v, n1->next = h[u], h[u] = n1;
}
ll sz[maxn];
int p[maxn]; 
int dp[maxn];
bool fl[maxn];
void dfs(int a)
{
	sz[a] = p[a];
	for(edge *p = h[a]; p; p = p->next)
	{
		dfs(p->v);
		sz[a] += sz[p->v];
	}
}
ll lst[maxn];
int f[maxn];	
int n;
int check(int i)
{
	ll x = sz[1] / i;
	for(int i = 1; i <= n; i++)
		lst[i] = 0;
	for(int i = n; i >= 1; i--)
	{
		lst[i] += p[i];
		if(lst[i] > x) return 0;
		if(lst[i] < x) lst[f[i]] += lst[i];
	}
	return 1;
}

int main()
{

	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for(int i = 2; i <= n; i++)
	{
		scanf("%d", &f[i]);
		addedge(f[i], i);
	}
	dfs(1);	
	for(int i = 1; i <= n; i++)
	{
		if(sz[1] % sz[i]) continue;
		if(sz[1] / sz[i] <= n) fl[sz[1] / sz[i]] = 1; 
	} 
	for(int i = n; i >= 1; i--)
		if(!fl[i]) continue;
		else
		{
			if(check(i)) dp[i] = 1;
		}
	for(int i = n; i >= 1; i--)
		if(dp[i])
			for(int j = 2 * i; j <= n; j += i)
				dp[i] = (dp[i] + dp[j]) % mod;
	printf("%d\n", dp[1]);
	return 0;
}