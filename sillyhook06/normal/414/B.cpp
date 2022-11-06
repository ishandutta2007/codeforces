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

int N, K;
const int MOD = 1000000007;
LL	f[2004][2005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), K = read();
	f[0][1] = 1;
	for (int i = 1; i <= K; ++ i)
	{
		for (int j = 1; j <= N; ++ j)	if (f[i - 1][j])
		{
			for (int k = j; k <= N; k += j)
				f[i][k] = (f[i][k] + f[i - 1][j]) % MOD;
		}
	}
	LL	ans = 0;
	for (int i = 1; i <= N; ++ i)
		ans = (ans + f[K][i]) % MOD;
	cout << ans << endl;

	return 0;
}