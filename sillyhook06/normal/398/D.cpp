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

int N, M, Q, O;
bool	state[50005];
int	sum[50005], tmp[150005][2], degree[50005], u[250005], v[250005];
char	op[250005][10];
map< pair<int, int>, int >	Map;
vector< pair<int, int>	>	edge[50005];

inline bool	cmp(int x, int y)
{
	return degree[x] < degree[y] || degree[x] == degree[y] && x < y;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), M = read(), Q = read();
	O = read();
	for (int i = 1; i <= O; ++ i)	state[read()] = 1;
	for (int i = 1; i <= M; ++ i)
	{
		int x = read(), y = read();
		tmp[i][0] = x, tmp[i][1] = y;
		degree[x] ++, degree[y] ++;
	}
	for (int i = 1; i <= Q; ++ i)
	{
		scanf("%s", op[i]);
		u[i] = read();
		if (op[i][0] == 'A' || op[i][0] == 'D')
		{
			v[i] = read();
			degree[u[i]] ++;
			degree[v[i]] ++;
		}
	}
	for (int i = 1; i <= M; ++ i)
	{
		int x = tmp[i][0], y = tmp[i][1];
		if (!cmp(x, y))	swap(x, y);
		Map[make_pair(x, y)] = edge[x].size();
		edge[x].push_back(make_pair(y, 1));
	}
	for (int x = 1; x <= N; ++ x)	if (state[x])
	{
		for (int j = 0; j < edge[x].size(); ++ j)
			if (edge[x][j].second)
				sum[edge[x][j].first] ++;
	}
	
	for (int i = 1; i <= Q; ++ i)
	{
		int x = u[i];
		if (op[i][0] == 'O')
		{
			state[x] = 1;
			for (int j = 0; j < edge[x].size(); ++ j)
				if (edge[x][j].second)
					sum[edge[x][j].first] ++;
		}
		elif (op[i][0] == 'F')
		{
			state[x] = 0;
			for (int j = 0; j < edge[x].size(); ++ j)
				if (edge[x][j].second)
					sum[edge[x][j].first] --;
		}
		elif (op[i][0] == 'A')
		{
			int y = v[i];
			if (!cmp(x, y))	swap(x, y);
			if (!Map.count(make_pair(x, y)))	Map[make_pair(x, y)] = edge[x].size(), edge[x].push_back(make_pair(y, 1));
			int j = Map[make_pair(x, y)];
			edge[x][j].second = 1;
			sum[y] += state[x];
		}
		elif (op[i][0] == 'D')
		{
			int y = v[i];
			if (!cmp(x, y))	swap(x, y);
			int j = Map[make_pair(x, y)];
			edge[x][j].second = 0;
			sum[y] -= state[x];
		}
		else
		{
			int ans = sum[x];
			for (int j = 0; j < edge[x].size(); ++ j)
				if (edge[x][j].second)
					ans += state[edge[x][j].first];
			printf("%d\n", ans);
		}
	}

	return 0;
}