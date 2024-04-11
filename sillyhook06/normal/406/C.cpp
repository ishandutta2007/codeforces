#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if

int N, M, tot, size[200005];
int E = 1, link[200005], next[200005], list[200005], flag[200005];
bool	visit[200005];

vector<int>	edge[200005];

void	DFS(int x)
{
	visit[x] = 1;
	for (int i = list[x]; i; i = next[i])	if (flag[i])
	{
		++ tot;
		flag[i ^ 1] = 0;
		int y = link[i];
		if (visit[y])	edge[y].push_back(x), flag[i] = 0;
		else	DFS(y);
	}
}

void	calc(int x)
{
	visit[x] = 1;
	size[x] = edge[x].size();
	for (int i = list[x]; i; i = next[i])	if (flag[i])
	{
		int y = link[i];
		calc(y);
		size[x] += size[y] + 1;
	}
}

void	print(int x, int y)
{
	visit[x] = 1;
	if (y)	edge[x].push_back(y);
	for (int i = list[x]; i; i = next[i])	if (flag[i])
	{
		int y = link[i];
		if (size[y] % 2 == 0)	edge[x].push_back(y);
	}
	int n = edge[x].size();
	for (int i = 0; i < n / 2; ++ i)
		printf("%d %d %d\n", edge[x][i * 2], x, edge[x][i * 2 + 1]);
	for (int i = list[x]; i; i = next[i])	if (flag[i])
	{
		int y = link[i];
		if (size[y] % 2 == 0)	print(y, 0);
		else	print(y, x);
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), M = read();
	
	for (int i = 1; i <= M; ++ i)
	{
		int x = read(), y = read();
		link[++ E] = y, next[E] = list[x], list[x] = E, flag[E] = 1;
		link[++ E] = x, next[E] = list[y], list[y] = E, flag[E] = 1;
	}
	
	for (int i = 1; i <= N; ++ i)
		if (!visit[i])
		{
			tot = 0;
			DFS(i);
			if (tot & 1)
			{
				printf("No solution\n");
				return 0;
			}
		}
	
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= N; ++ i)
		if (!visit[i])
			calc(i);
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= N; ++ i)
		if (!visit[i])
			print(i, 0);
	
	return 0;
}