#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

struct Edge{
	int x, y, next;
}edge[N];

int n, root, tot;
int size[N], son[N], fa[N], du[N], q[N];
vector<int> g[N];

inline void add(int x, int y)
{
	edge[++tot].x = x; edge[tot].y = y; edge[tot].next = son[x]; son[x] = tot;
}

void dfs(int x)
{
	size[x] = 1;
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		dfs(y);
		size[x] += size[y];
	}
}

int dfs(int x, int flag)
{
	int nowf = 1, cnt = 0;
	for(int i = son[x]; i; i = edge[i].next)
	{
		int y = edge[i].y;
		if(size[y] & 1)nowf &= dfs(y, 1), cnt++, g[x].push_back(y), du[y]++;
		else nowf &= dfs(y, 0), g[y].push_back(x), du[x]++;;
	}
	cnt += flag ^ 1;
	if(cnt & 1)return 0;
	return 1;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &fa[i]);
		if(fa[i])add(fa[i], i);
		else root = i;
	}
	dfs(root);
	if(!dfs(root, 1))
	{
		puts("NO");
		return 0;
	}
	else
	{
		int h = 0, l = 0;
		puts("YES");
		for(int i = 1; i <= n; i++)
		{
			if(!du[i])q[++l] = i;
		}
		while(h < l)
		{
			int v = q[++h];
			printf("%d\n", v);
			for(int i = 0; i < g[v].size(); i++)
			{
				int y = g[v][i];
				du[y]--;
				if(!du[y])q[++l] = y;
			}
		}
	}
}