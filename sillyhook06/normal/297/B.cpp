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

int N, M, K;
int a[100005], b[100005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), M = read(), K = read();
	for (int i = 1; i <= N; ++ i)	a[i] = read();
	for (int i = 1; i <= M; ++ i)	b[i] = read();
	sort(a + 1, a + N + 1);
	reverse(a + 1, a + N + 1);
	sort(b + 1, b + M + 1);
	reverse(b + 1, b + M + 1);
	if (N > M)	return printf("YES\n"), 0;
	for (int i = 1; i <= N; ++ i)
		if (b[i] < a[i])
			return printf("YES\n"), 0;
	printf("NO\n");

	return 0;
}