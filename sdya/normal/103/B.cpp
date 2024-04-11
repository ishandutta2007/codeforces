#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n, m;
int g[110][110];
int used[110];

void dfs(int v)
{
	if (used[v]) return ;
	used[v] = true;

	for (int i = 1; i <= n; i ++)
		if (g[v][i]) dfs(i);
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = true;
	}

	dfs(1);
	for (int i = 1; i <= n; i ++)
		if (!used[i])
		{
			printf("NO\n");
			return 0;
		}
	if (n != m)
		printf("NO\n"); else
		printf("FHTAGN!\n");

	return 0;
}