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
#define left Left
#define right Right

const int MaxN = 500005;
int N, dfn, E = 1, link[MaxN << 1], next[MaxN << 1], list[MaxN], fa[MaxN], left[MaxN], right[MaxN];
int T1[MaxN << 2], T[MaxN << 2];

void	modify1(int t, int l, int r, int x)
{
	if (l == r)
	{
		T1[t] = 1;
		return;
	}
	int mid = l + r >> 1;
	if (x <= mid)	modify1(t << 1, l, mid, x);
	else	modify1((t << 1) ^ 1, mid + 1, r, x);
	T1[t] = T1[t << 1] || T1[(t << 1) ^ 1];
}
bool	query1(int t, int l, int r, int ll, int rr)
{
	if (l == ll && r == rr)	return T1[t];
	int mid = l + r >> 1;
	if (rr <= mid)	return query1(t << 1, l, mid, ll, rr);
	if (ll > mid)	return query1((t << 1) ^ 1, mid + 1, r, ll, rr);
	return query1(t << 1, l, mid, ll, mid) || query1((t << 1) ^ 1, mid + 1, r, mid + 1, rr);
}
void	clear1(int t, int l, int r, int ll, int rr)
{
	if (l == ll && r == rr)
	{
		if (T1[t] && l < r)
		{
			int mid = l + r >> 1;
			clear1(t << 1, l, mid, ll, mid);
			clear1((t << 1) ^ 1, mid + 1, r, mid + 1, rr);
		}
		T1[t] = 0;
		return;
	}
	int mid = l + r >> 1;
	if (rr <= mid)	clear1(t << 1, l, mid, ll, rr);	else
	if (ll > mid)	clear1((t << 1) ^ 1, mid + 1, r, ll, rr);	else
	clear1(t << 1, l, mid, ll, mid), clear1((t << 1) ^ 1, mid + 1, r, mid + 1, rr);
}

void	modify(int t, int l, int r, int ll, int rr)
{
	if (l == ll && r == rr)
	{
		T[t] = 1;
		return;
	}
	int mid = l + r >> 1;
	if (rr <= mid)	modify(t << 1, l, mid, ll, rr); else
	if (ll > mid)	modify((t << 1) ^ 1, mid + 1, r, ll, rr); else
	modify(t << 1, l, mid, ll, mid), modify((t << 1) ^ 1, mid + 1, r, mid + 1, rr);
}
bool	query(int t, int l, int r, int x)
{
	if (T[t])	return 1;
	if (l == r)	return 0;
	int mid = l + r >> 1;
	if (x <= mid)	return query(t << 1, l, mid, x);
	return query((t << 1) ^ 1, mid + 1, r, x);
}

void	DFS(int x)
{
	left[x] = ++ dfn;
	for (int i = list[x]; i; i = next[i])
	{
		int y = link[i];
		if (y == fa[x])	continue;
		fa[y] = x;
		DFS(y);
	}
	right[x] = dfn;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read();
	for (int i = 1; i < N; ++ i)
	{
		int x = read(), y = read();
		link[++ E] = y, next[E] = list[x], list[x] = E;
		link[++ E] = x, next[E] = list[y], list[y] = E;
	}
	fa[1] = 0;
	dfn = 0;
	DFS(1);
	int Q = read();
	while (Q --)
	{
		int c = read(), x = read();
		if (c == 1)
		{
			if (query1(1, 1, N, left[x], right[x]))
			{
				clear1(1, 1, N, left[x], right[x]);
				if (fa[x])	modify1(1, 1, N, left[fa[x]]);
			}
			modify(1, 1, N, left[x], right[x]);
		}
		elif (c == 2)
			modify1(1, 1, N, left[x]);
		else
		{
			if (query1(1, 1, N, left[x], right[x]))	printf("0\n");
			elif (query(1, 1, N, left[x]))	printf("1\n");
			else printf("0\n");
		}
	}

	return 0;
}