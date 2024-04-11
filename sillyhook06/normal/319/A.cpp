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
#define next Next
#define elif else if

const int MOD = 1000000007;
int N;
char	a[1005];

LL	power(LL x, LL y)
{
	LL	ans = 1;
	for (int i = 1; i <= y; ++ i)
		ans = ans * x % MOD;
	return ans;
}

LL	work(int N)
{
	if (N == 0)	return 0;
	LL	ans = work(N - 1) * 2 % MOD;
	if (a[N] == '1')	ans = (ans + power(power(2, N - 1), 2)) % MOD;
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	scanf("%s", a + 1);
	N = strlen(a + 1);
	reverse(a + 1, a + N + 1);
	printf("%d\n", (int)work(N));

	return 0;
}