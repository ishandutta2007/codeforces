#include <iostream>
#include <vector>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

vector < int > g[60000];
int n, r1, r2;
bool used[60000];
int pr[60000];

void dfs(int v)
{
	if (used[v]) return ;
	used[v] = true;
	for (int i = 0; i < g[v].size(); i ++)
		if (!used[g[v][i]]) pr[g[v][i]] = v, dfs(g[v][i]);
}

int main()
{
	scanf("%d%d%d", &n, &r1, &r2);
	for (int i = 1; i <= n; i ++)
	{
		int a;
		if (i == r1) continue;
		scanf("%d", &a);
		g[a].push_back(i);
		g[i].push_back(a);
	}

	dfs(r2);
	for (int i = 1; i <= n; i ++)
		if (i != r2)
			printf("%d ", pr[i]);
	printf("\n");
	return 0;
}