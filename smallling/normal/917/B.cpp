#include <bits/stdc++.h>

using namespace std;

const int N = 110;

struct Edge{
	int x, y, kind, next;
}edge[N * N];

bool vis[N][N][26], f[N][N][26];
int tot, son[N];

inline void add(int x, int y, int kind)
{
	edge[++tot].x = x; edge[tot].y = y; edge[tot].kind = kind;
	edge[tot].next = son[x]; son[x] = tot;
}

bool dfs(int x, int y, int kind)
{
	if(vis[x][y][kind])return f[x][y][kind];
	vis[x][y][kind] = 1;
	bool &now = f[x][y][kind];
	now = 1;
	for(int i = son[x]; i; i = edge[i].next)
		if(edge[i].kind >= kind)now &= dfs(y, edge[i].y, edge[i].kind);
	now ^= 1;
	return now;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		char s[2];
		scanf("%d%d%s", &x, &y, s);
		add(x, y, s[0] - 'a');
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int flag = 0;
			for(int k = 0; k < 26; k++)
			{
				flag |= dfs(i, j, k);
			}
			if(flag)putchar('A');
			else putchar('B');
		}
		puts("");
	}
}