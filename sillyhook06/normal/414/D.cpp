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

int N, K, P, M = - 1;
int E = 1, link[200005], next[200005], list[200005];
int a[200005];
LL	s[200005];

inline void	DFS(int x, int f, int d)
{
	a[++ M] = d;
	for (int i = list[x]; i; i = next[i])
	{
		int y = link[i];
		if (y != f)
			DFS(y, x, d + 1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), K = read(), P = read();
	for (int i = 1; i < N; ++ i)
	{
		int x = read(), y = read();
		link[++ E] = y, next[E] = list[x], list[x] = E;
		link[++ E] = x, next[E] = list[y], list[y] = E;
	}
	DFS(1, 0, 0);
	N --;
	sort(a + 1, a + N + 1);
	for (int i = 1; i <= N; ++ i)	s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= N; ++ i)
	{
		int l = 0, r = min(K + 1, i + 1);
		while (l + 1 < r)
		{
			int mid = l + r >> 1;
			if (LL(mid) * LL(a[i]) - (s[i] - s[i - mid]) <= P)	l = mid;
			else	r = mid;
		}
		ans = max(ans, l);
	}
	cout << ans << endl;

	return 0;
}