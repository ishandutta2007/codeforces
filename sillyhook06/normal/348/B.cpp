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

int N;
LL	f[100005], g[100005], a[100005], sum;
int E, link[100005 << 1], next[100005 << 1], list[100005];

void	DFS(int x, int fa)
{
	f[x] = 1ll << 60, g[x] = 1;
	LL tot = 0;
	for (int i = list[x]; i; i = next[i])
	{
		int y = link[i];
		if (y == fa)	continue;
		DFS(y, x);
		if (g[x] / __gcd(g[x], g[y]) > sum / g[y])
		{
			cout << sum << endl;
			exit(0);
		}
		g[x] = g[x] / __gcd(g[x], g[y]) * g[y];
		f[x] = min(f[x], f[y]);
		++ tot;
	}
	if (!tot)	f[x] = a[x];
	else	f[x] = (f[x] / g[x] * g[x]) * tot, g[x] *= tot;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read();
	sum = 0;
	for (int i = 1; i <= N; ++ i)	a[i] = read(), sum += a[i];
	E = 1, memset(list, 0, sizeof(list));
	for (int i = 1; i < N; ++ i)
	{
		int x = read(), y = read();
		link[++ E] = y, next[E] = list[x], list[x] = E;
		link[++ E] = x, next[E] = list[y], list[y] = E;
	}
	DFS(1, 0);
	cout << sum - f[1] << endl;

	return 0;
}