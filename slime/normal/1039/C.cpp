#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#define maxn 500005
#define ll long long
#define mod 1000000007
using namespace std;
ll pw[maxn];
int fa[maxn];
int gfa(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = gfa(fa[x]);
}
int ns[maxn], top = 0;
struct eg
{
	int u, v;
	ll t;
	bool operator < (const eg &x)const
	{
		return t < x.t;
	}
}p[maxn];
ll c[maxn];
int main()
{
	pw[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw[i] = pw[i - 1] * 2 % mod;
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	for(int i = 1; i <= n; i++)
		scanf("%lld", &c[i]);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &p[i].u, &p[i].v);
		p[i].t = c[p[i].u] ^ c[p[i].v];
	}
	sort(p + 1, p + m + 1);
	int tot = 0;
	ll ans = 0;
	for(int i = 1; i <= m; )
	{
		
		tot++;
		int j = i;
		while(j <= m && p[j].t == p[i].t) j++;
		int ncnt = n;
		for(int k = i; k < j; k++)
		{
			int ufa = gfa(p[k].u), vfa = gfa(p[k].v);
			if(ufa == vfa) continue;
			else
			{
				ncnt--;
				ns[top++] = ufa;
				fa[ufa] = vfa;
			}
		}
		for(int k = 0; k < top; k++)
		{
			fa[ns[k]] = ns[k];
		}
		top = 0;
		ans += pw[ncnt];
	//	cout<<p[i].t<<" "<<ncnt<<endl;
		ans %= mod;
		i = j;
	}
	ans += pw[n] * (pw[k] - tot) % mod;
	ans %= mod;
	if(ans < 0) ans += mod;
	printf("%lld\n", ans);
	return 0;
}