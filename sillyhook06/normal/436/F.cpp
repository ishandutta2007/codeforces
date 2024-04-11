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

int N, M, L, S;
LL	W;
LL	f[200005];
int	cover[100005];
vector< pair<long double, int> >	stack[100005];
pair<int, int>	a[100005];

inline void	Insert(int s)
{
	int x = s / S;
	for (int i = x * S; i < x * S + S; ++ i)
	{
		f[i] += LL(cover[x]) * LL(i);
		if (i <= s)	f[i] += i;
	}
	cover[x] = 0;
	stack[x].clear();
	stack[x].push_back(make_pair(- 1e99, x * S));
	int n = 1;
	for (int i = x * S; i < x * S + S; ++ i)
	{
		while (n > 1)
		{
			int j = stack[x][n - 1].second, k = stack[x][n - 2].second;
			if ((f[j] - f[k]) * (i - k) - (f[i] - f[k]) * (j - k) <= 0)	-- n, stack[x].pop_back();
			else	break;
		}
		++ n;
		int j = stack[x][n - 2].second;
		stack[x].push_back(make_pair(- (long double)(f[i] - f[j]) / (long double)(i - j), i));
	}
	
	for (int i = 0; i < x; ++ i)	cover[i] ++;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read();
	W = read();
	int maxb = 0;
	for (int i = 0; i < N; ++ i)
	{
		int x = read(), y = read();
		a[i] = make_pair(y, x);
		maxb = max(maxb, y);
	}
	sort(a, a + N);
	L = 100000;
	S = 320;
	M = L / S;
	memset(f, 0, sizeof(f));
	for (int i = 0; i <= M; ++ i)
	{
		stack[i].clear();
		stack[i].push_back(make_pair(- 1e99, i * S));
		stack[i].push_back(make_pair(0, i * S + S - 1));
	}
	for (int c = 0, i = 0; c <= maxb + 1; ++ c)
	{
		for ( ; i < N && a[i].first < c; ++ i)
			Insert(a[i].second);
		LL ans = -1;
		int	p = -1;
		for (int j = 0; j <= M; ++ j)
		{
			pair< long double, int > tmp(cover[j], 0);
			int x = stack[j][lower_bound(stack[j].begin(), stack[j].end(), tmp) - stack[j].begin() - 1].second;
			LL y = f[x] + LL(x) * LL(cover[j]);
			if (y > ans)	ans = y, p = x;
		}
		printf("%I64d %d\n", ans + LL(W) * LL(c) * LL(N - i), p);
	}

	return 0;
}