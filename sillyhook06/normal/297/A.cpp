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

int N, M;
char	a[1005], b[1005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	scanf("%s", a + 1);
	scanf("%s", b + 1);
	N = strlen(a + 1);
	M = strlen(b + 1);
	int cnt = 0;
	for (int i = 1; i <= N; ++ i)	cnt += a[i] == '1';
	int cnt2 = 0;
	for (int i = 1; i <= M; ++ i)	cnt2 += b[i] == '1';
	if (cnt & 1)	cnt ++;
	if (cnt >= cnt2)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}