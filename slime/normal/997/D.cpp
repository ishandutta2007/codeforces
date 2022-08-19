#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue> 
#define ll long long
#define maxn 4005
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
ll dp[maxn][80], adp[maxn][80];
struct edge
{
	int u, v;
	ll dp[80], adp[80]; // dp:  adp:  
	edge *next;
	edge *rev;
}p[maxn * 4], *h[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->next = h[u], h[u] = n1;
	edge *n2 = &p[egcnt++];
	n2->u = v, n2->v = u, n2->next = h[v], h[v] = n2;
	n1->rev = n2, n2->rev = n1;
}

ll jc[maxn], bjc[maxn];
ll ns[2][maxn];
ll c(int a, int b)
{
	ll ans = jc[a] * bjc[b] % mod * bjc[a - b] % mod;
	return ans;
}
int main()
{
	jc[0] = bjc[0] = 1;
	for(int i = 1; i < maxn; i++)
		jc[i] = jc[i - 1] * i % mod, 
		bjc[i] = bjc[i - 1] * ksm(i, mod - 2) % mod;
	int n[2], k;
	scanf("%d%d%d", &n[0], &n[1], &k);
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < maxn; j++)
			h[j] = NULL;
		egcnt = 0;
		for(int j = 0; j < n[i] - 1; j++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			addedge(u, v);
		}
		for(int j = 1; j <= n[i]; j++)
		{
			for(edge *p = h[j]; p; p = p->next)
				p->adp[0] = p->dp[0] = 1;
			dp[j][0] = adp[j][0] = 1;
		}
		ns[i][0] += n[i];
		for(int nk = 2; nk <= k; nk += 2)
		{
		//	cout<<"CAL"<<nk<<endl;
			ns[i][nk] = 0;
			for(int j = 1; j <= n[i]; j++)
			{
				dp[j][nk] = adp[j][nk] = 0;
				for(edge *p = h[j]; p; p = p->next)
					dp[j][nk] += p->adp[nk - 2], 
					dp[j][nk] %= mod;
				for(int s = 0; s <= nk - 1; s++)
					adp[j][nk] += adp[j][s] * dp[j][nk - s], 
					adp[j][nk] %= mod; 
			//	cout<<j<<" "<<dp[j][nk]<<" "<<adp[j][nk]<<endl;
				ns[i][nk] += adp[j][nk], 
				ns[i][nk] %= mod;
			}
			for(int j = 1; j <= n[i]; j++)
				for(edge *p = h[j]; p; p = p->next)
				{
					int nv = p->v;
					p->dp[nk] = p->adp[nk] = 0;
					p->dp[nk] = dp[nv][nk] - p->rev->adp[nk - 2];
					if(p->dp[nk] < 0) p->dp[nk] += mod;
					for(int s = 0; s <= nk - 1; s++)
						p->adp[nk] += p->adp[s] * p->dp[nk - s], 
						p->adp[nk] %= mod;
			//		cout<<p->u<<" "<<p->v<<" "<<p->dp[nk]<<" "<<p->adp[nk]<<endl;
				}
		
		}
	}
	ll ans = 0;
	for(int i = 0; i <= k; i++)
	{
		ll nans = ns[0][i] * ns[1][k - i] % mod;
		nans *= c(k, i), nans %= mod;
		ans += nans, ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}