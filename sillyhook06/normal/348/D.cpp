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

int N, M;
char	a[3005][3005];
int	f[3005][3005];

inline void	work(int sx, int sy)
{
	memset(f, 0, sizeof(f));
	if (a[sx][sy] == '#')	return;
	f[sx][sy] = 1;
	for (int i = sx; i <= N; ++ i)
		for (int j = sy; j <= M; ++ j)	if (i != sx || j != sy)
			if (a[i][j] == '.')
				f[i][j] = (f[i - 1][j] + f[i][j - 1]) % MOD;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), M = read();
	for (int i = 1; i <= N; ++ i)	scanf("%s", a[i] + 1);
	work(1, 2);
	LL	ans1 = f[N - 1][M], ans2 = f[N][M - 1];
	work(2, 1);
	cout << ((ans1 * (LL)f[N][M - 1] - ans2 * (LL)f[N - 1][M]) % MOD + MOD) % MOD << endl;

	return 0;
}