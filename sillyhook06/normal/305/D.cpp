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

const int MOD = 1000000007;
int N, M, K;
bool	a[1000006];
int power[1000006];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	power[0] = 1;
	for (int i = 1; i <= 1000000; ++ i)	power[i] = power[i - 1] * 2 % MOD;
	N = read(), M = read(), K = read();
	int mi = N + 1, ma = 0, tot = 0;
	for (int i = 1; i <= M; ++ i)
	{
		int x = read(), y = read();
		if (y - x == 1)	continue;
		if (y - x != K + 1)	return printf("0\n"), 0;
		mi = min(x, mi);
		ma = max(x, ma);
		tot ++;
	}
	if (ma >= mi + K + 1)
		return printf("0\n"), 0;
	if (mi == N + 1)
	{
		int ans = 1;
		for (int i = 1; i + K + 1 <= N; ++ i)
			ans = (ans + power[min(K, N - i - K - 1)]) % MOD;
		cout << ans << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i < mi; ++ i)	if (i + K + 1 > ma)
		ans = (ans + power[min(K, N - i - K - 1) - tot]) % MOD;
	ans = (ans + power[min(K, N - mi - K - 1) - tot + 1]) % MOD;
	cout << ans << endl;

	return 0;
}