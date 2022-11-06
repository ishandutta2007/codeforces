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

int N, M, K;
char	a[105], b[105], c[105], d[105];
int next[105][26];
pair<int, int>	f[105][105][105];

inline void	update(pair<int, int> &a, int b, int c)
{
	if (b > a.first)	a = make_pair(b, c);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	scanf("%s", a + 1), N = strlen(a + 1);
	scanf("%s", b + 1), M = strlen(b + 1);
	scanf("%s", c + 1), K = strlen(c + 1);
	for (int i = 0; i < K; ++ i)
		for (int ch = 0; ch < 26; ++ ch)
		{
			memcpy(d, c, sizeof(d));
			d[i + 1] = ch + 'A';
			for (int j = i + 1; j >= 0; -- j)
				if (string(c + 1, c + j + 1) == string(d + i + 2 - j, d + i + 2))
				{
					next[i][ch] = j;
					break;
				}
		}
	for (int i = 1; i <= N; ++ i)
		for (int j = 1; j <= M; ++ j)
			for (int k = 0; k < K; ++ k)
			{
				update(f[i][j][k], f[i - 1][j][k].first, 0);
				update(f[i][j][k], f[i][j - 1][k].first, 1);
				if (a[i] == b[j])
					update(f[i][j][next[k][a[i] - 'A']], f[i - 1][j - 1][k].first + 1, k + 2);
			}
	int p = 0;
	for (int k = 1; k < K; ++ k)
		if (f[N][M][k].first > f[N][M][p].first)
			p = k;
	string ans = "";
	for (int i = N, j = M, k = p; f[i][j][k].first; )
	{
		if (f[i][j][k].second == 0)	i --;
		elif (f[i][j][k].second == 1)	j --;
		else
		{
			ans += a[i];
			k = f[i][j][k].second - 2;
			i --, j--;
		}
	}
	reverse(ans.begin(), ans.end());
	if (ans.size() == 0)	cout << 0 << endl;
	else	cout << ans << endl;

	return 0;
}