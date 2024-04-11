#include <bits/stdc++.h>

using namespace std;

const int N = 510;

struct Edge{
	int x, y, next;
}edge[N * N];

int tot = 0, du[N], a[N], q[N], son[N];

inline void add(int x, int y)
{
	edge[++tot].x = x; edge[tot].y = y; edge[tot].next = son[x]; son[x] = tot;
}

int check(int nown, int x, int n)
{
	int h = 0, l = 0;
	for(int i = 1; i <= n; i++)
		a[i] = du[i];
	a[x]--;
	q[++l] = x;
	while(h < l)
	{
		int v = q[++h];
		for(int i = son[v]; i; i = edge[i].next)
		{
			int y = edge[i].y;
			a[y]--;
			if(!a[y])q[++l] = y;
		}
	}
	if(l + nown == n)return 1;
	return 0;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		du[y]++;
	}
	int h = 0, l = 0;
	for(int i = 1; i <= n; i++)
		if(!du[i])q[++l] = i;
	while(h < l)
	{
		int v = q[++h];
		for(int i = son[v]; i; i = edge[i].next)
		{
			int y = edge[i].y;
			du[y]--;
			if(!du[y])q[++l] = y;
		}
	}
	if(l == n)
	{
		puts("YES");
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		if(du[i] != 1)continue;
		if(check(l, i, n))
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}