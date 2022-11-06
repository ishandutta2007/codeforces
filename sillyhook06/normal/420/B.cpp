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

int N, M, tot;
int a[100005], t[100005], cant[100005], ans[100005], id[100005], s[100005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), M = read();
	for (int i = 1; i <= N; ++ i)
	{
		a[i] = -1;
		t[i] = 0;
	}
	for (int i = 1; i <= M; ++ i)
	{
		char ch[10];
		scanf("%s", ch);
		int x = read();
		id[i] = x;
		if (ch[0] == '+')
		{
			if (a[x] == -1)	a[x] = 1;
			if (t[x] != i - 1)	cant[x] = 1;
			a[x] = 0;
			t[x] = i;
		}
		else
		{
			if (a[x] == -1)	a[x] = 0;
			s[t[x] + 1] ++, s[i] --;
			a[x] = 1;
			t[x] = i;
		}
	}
	for (int i = 1; i <= N; ++ i)
		if (a[i] == 1)
			if (t[i] != M)	cant[i] = 1; 
	for (int i = 1; i <= N; ++ i)
		if (a[i] == 0)
		{
			s[t[i] + 1] ++, s[M + 1] --;
		}
	for (int i = 1; i <= M; ++ i)	s[i] += s[i - 1];
	for (int i = 1; i <= M; ++ i)	if (s[i])
		cant[id[i]] = 1;
	int tot = 0;
	for (int i = 1; i <= N; ++ i)
		if (!cant[i])
			 ans[++ tot] = i;
	printf("%d\n", tot);
	for (int i = 1; i <= tot; ++ i)
		printf("%d%c", ans[i], i < tot ? ' ' : '\n');

	return 0;
}