/*
* Problem: 
* Author: Leo Yu
* Time: 
* State: SOLVED
* Memo: 
*/
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

int N, K;
int a[105], b[105], s[105];

int t[105];
inline void	trans_one(int p[])
{
	for (int i = 1; i <= N; ++ i)	t[i] = p[a[i]];
	for (int i = 1; i <= N; ++ i)	p[i] = t[i];
}
inline void	trans_two(int p[])
{
	for (int i = 1; i <= N; ++ i)	t[a[i]] = p[i];
	for (int i = 1; i <= N; ++ i)	p[i] = t[i];
}
inline bool	equal(int a[], int b[])
{
	for (int i = 1; i <= N; ++ i)
		if (a[i] != b[i])
			return 0;
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), K = read();
	for (int i = 1; i <= N; ++ i)	a[i] = read();
	for (int i = 1; i <= N; ++ i)	s[i] = read();
	for (int i = 1; i <= N; ++ i)	b[i] = i;
	if (equal(b, s))	return printf("NO\n"), 0;
	int l = 1 << 30, r = 1 << 30;
	for (int i = 1; i <= K + 1; ++ i)
	{
		trans_one(b);
		if (equal(b, s))
		{
			r = i;
			break;
		}
	}
	for (int i = 1; i <= N; ++ i)	b[i] = i;
	for (int i = 1; i <= K + 1; ++ i)
	{
		trans_two(b);
		if (equal(b, s))
		{
			l = i;
			break;
		}
	}
	if (l % 2 == K % 2 && K >= l)
	{
		if (l > 1 || r > 1 || K - l == 0)	return printf("YES\n"), 0;
	}
	if (r % 2 == K % 2 && K >= r)
	{
		if (r > 1 || l > 1 || K - r == 0)	return printf("YES\n"), 0;
	}
	printf("NO\n");

	return 0;
}