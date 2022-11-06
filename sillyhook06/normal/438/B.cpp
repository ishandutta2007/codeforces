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

int N, M, a[100005];
vector<int>	edge[100005];
int f[100005], size[100005], tmp[100005];

bool	cmp(const int x, const int y)
{
	return a[x] > a[y];
}

int	findSet(int x)
{
	if (f[x] == x)	return x;
	f[x] = findSet(f[x]);
	return f[x];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), M = read();
	for (int i = 1; i <= N; ++ i)	a[i] = read(), tmp[i] = i, f[i] = i, size[i] = 1;
	sort(tmp + 1, tmp + N + 1, cmp);
	for (int i = 1; i <= M; ++ i)
	{
		int x = read(), y = read();
		if (a[y] > a[x])
			edge[x].push_back(y);
		else
			edge[y].push_back(x);
	}
	double	ans = 0;
	for (int i = 1; i <= N; ++ i)
	{
		int x = tmp[i];
		for (int j = 0; j < edge[x].size(); ++ j)
		{
			int y = edge[x][j];
			int A = findSet(x), B = findSet(y);
			if (A == B)	continue;
			ans += LL(size[A]) * LL(size[B]) * LL(a[x]) * 2ll;
			size[A] += size[B];
			f[B] = A;
		}
	}
	printf("%.10lf\n", ans / N / (N - 1));

	return 0;
}