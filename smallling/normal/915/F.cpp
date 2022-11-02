#include <bits/stdc++.h>

using namespace std;

const int N = 1000010; 

struct Edge{
	int x, y, next;
}edge[N << 1];

struct lhy{
	int v, id;
}a[N];

int n, tot;
int f[N], sz[N], son[N]; 

inline void add(int x, int y)
{
	edge[++tot].x = x; edge[tot].y = y; edge[tot].next = son[x]; son[x] = tot;
}

inline int cmp1(const lhy &a, const lhy &b)
{
	return a.v < b.v;
}

inline int cmp2(const lhy &a, const lhy &b)
{
	return a.v > b.v;
}

int getf(int u)
{
	if(u == f[u])return u;
	return f[u] = getf(f[u]); 
}

void Union(int x, int y)
{
	int u = getf(x), v = getf(y);
	f[v] = u;
	sz[u] += sz[v];
}

void work(long long &ans, int o)
{
	for(int i = 1; i <= n; i++)
		f[i] = i, sz[i] = 0;
	for(int i = 1; i <= n; i++)
	{
		int x = a[i].id, nowsz = 0;
		sz[x]++;
		for(int j = son[x]; j; j = edge[j].next) 
		{
			int y = getf(edge[j].y), szy = sz[y];
			if(!szy)continue;
			ans += 1ll * o * a[i].v * (1ll * szy * nowsz + szy);
			nowsz += szy;
			Union(x, y);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i].v), a[i].id = i;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	sort(a + 1, a + 1 + n, cmp1);
	long long ans = 0;
	work(ans, 1);
	sort(a + 1, a + 1 + n, cmp2);
	work(ans, -1);
	printf("%I64d\n", ans);
}