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

int N, M, a[405][405];
int f[405][405], tmp[405][405];
unsigned short g[405][160005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), M = read();
	for (int i = 1; i <= N; ++ i)
	for (int j = 1; j <= M; ++ j)
		a[i][j] = read();
	
	int ans = 0;
	for (int i = 1; i <= N; ++ i)
	{
		for (int l = M; l; -- l)
		for (int r = l; r <= M; ++ r)
		{
			if (l == r)	tmp[l][r] = g[l][a[i][l]];
			else
			{
				tmp[l][r] = max(tmp[l][r - 1], tmp[l + 1][r]);
				tmp[l][r] = max(tmp[l][r], (int)g[r][a[i][l]]);
				tmp[l][r] = max(tmp[l][r], (int)g[l][a[i][r]]);
				if (a[i][l] == a[i][r])	tmp[l][r] = i;
			}
			f[l][r] = max(f[l][r], tmp[l][r]);
			ans = max(ans, (r - l + 1) * (i - f[l][r]));
		}
		
		for (int j = 1; j <= M; ++ j)	g[j][a[i][j]] = i;
	}
	cout << ans << endl;

	return 0;
}