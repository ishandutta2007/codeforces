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

int N, ans[1000006];
pair<int, int>	a[1000006];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read();
	for (int i = 1; i <= N; ++ i)	a[i].first = read(), a[i].second = i;
	sort(a + 1, a + N + 1);
	int last = 0;
	for (int i = 1; i <= N; ++ i)
	{
		last ++;
		if (a[i].first > last)	last = a[i].first;
		ans[a[i].second] = last;
	}
	for (int i = 1; i <= N; ++ i)	printf("%d%c", ans[i], i < N ? ' ' : '\n');

	return 0;
}