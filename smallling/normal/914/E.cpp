#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

struct Edge{
	int x, y, next;
}edge[N << 1];

int root, nowsize, tot, n;
int size[N], Max[N], son[N], flag[N], a[N], point[N], sum[1 << 20];
long long ans[N];
char s[N];

void GetRoot(int x, int fa)
{
	size[x] = 1;
	Max[x] = 0;
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		if(flag[y] || y == fa)continue;
		GetRoot(y, x);
		size[x] += size[y];
		Max[x] = max(Max[x], size[y]);
	}
	Max[x] = max(Max[x], nowsize - size[x]);
	if(Max[x] < Max[root])root = x;
}

void dfs(int x, int fa, int zt,int p)
{
	int nzt = zt ^ (1 << a[root]);
	long long lans = ans[x];
	ans[x] += sum[zt];
	for(int i = 0; i < 20; i++)
		ans[x] += sum[zt ^ (1 << i)];
	
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		if(y == fa || flag[y])continue;
		dfs(y, x, zt ^ (1 << a[y]),x);
	}
	ans[p] += ans[x] - lans;
}

void ad(int x, int fa, int zt)
{
	sum[zt ^ (1 << a[root])]++;
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		if(y == fa || flag[y])continue;
		ad(y, x, zt ^ (1 << a[y]));
	}
}

void clear(int x, int fa, int zt)
{
	sum[zt ^ (1 << a[root])]--;
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		if(y == fa || flag[y])continue;
		clear(y, x, zt ^ (1 << a[y]));
	}
}

void work(int x)
{
	sum[1<<a[x]]++;
	int nows = 0;
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		if(flag[y])continue;
		dfs(y, x, 1 << a[y],x);
		ad(y, x, 1 << a[y]);
		point[++nows] = y;
	}
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		if(flag[y])continue;
		clear(y, x, 1 << a[y]);
	}
	sum[1<<a[x]]--;
	for(int i = nows; i; i--)
	{
		int y = point[i];
		dfs(y, x, 1 << a[y],0);
		ad(y, x, 1 << a[y]);
	}
	for(int i = nows; i; i--)
	{
		int y = point[i];
		clear(y, x, 1 << a[y]);
	}
	ans[x]++;
}

void Divide(int x)
{
	flag[x] = 1;
	work(x);
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		if(flag[y])continue;
		root = 0;
		nowsize = size[y];
		GetRoot(y, 0);
		Divide(root);
	}
}

inline void add(int x, int y)
{
	edge[++tot].x = x; edge[tot].y = y; edge[tot].next = son[x]; son[x] = tot;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++)
		a[i] = s[i] - 'a'; 
	Max[0] = n + 1;
	root = 0;
	nowsize = n;
	GetRoot(1, 0);
	Divide(root);
	for(int i = 1; i <= n; i++)
		printf("%I64d%c", ans[i], i == n ? '\n':' '); 
}