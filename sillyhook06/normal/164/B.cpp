/*
* Problem:
* Author: Leo Yu
* Time:
* State:
* Memo:
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
inline int   read()
{
	int x = 0;	char ch = getchar();	bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())  if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())    x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link
#define next Next

int N, M, a[2000006], pos[2000006];

bool	in_segment(int l, int r, int x)
{
	if (l <= r)	return x >= l && x <= r;
	return x >= l || x <= r;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), M = read();
	for (int i = 1; i <= N; ++ i)	a[i] = a[i + N] = read();
	for (int j = 1; j <= M; ++ j)	pos[read()] = j;
	int l = 0, r = 0;
	int ans = 0;
	for (int i = 1, j = 1; i <= N; ++ i)	if (pos[a[i]])
	{
		l = pos[a[i]];
		if (j <= i)	j = i + 1, r = pos[a[i]];
		while (j < i + N && pos[a[j]] && !in_segment(l, r, pos[a[j]]))
			r = pos[a[j ++]];
		ans = max(ans, j - i);
	}
	cout << ans << endl;

	return 0;
}