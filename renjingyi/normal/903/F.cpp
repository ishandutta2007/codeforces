#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 1005;
const int oo = 1e9;
struct state
{
	int a, b, c, d;
	state(const int &a = 0, const int &b = 0, const int &c = 0, const int &d = 0) : a(a), b(b), c(c), d(d) {}
};
int encode(const int &a, const int &b, const int &c, const int &d)
{
	return a | b << 2 | c << 4 | d << 6;
}
state decode(const int &p)
{
	return state(p & 3, (p >> 2) & 3, (p >> 4) & 3, (p >> 6) & 3);
}
int dp[maxn][1 << 8];
char c[maxn][5];
int a[5], tmp[5], trans[5], con[5];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n >> a[1] >> a[2] >> a[3] >> a[4];
	for(int j = 1; j <= 4; j ++)
		for(int i = 1; i <= n; i ++)
			cin >> c[i][j];
	for(int i = 1; i <= n + 1; i ++)
		for(int j = 0; j < (1 << 8); j ++)
			dp[i][j] = oo;
	dp[1][0] = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j < (1 << 8); j ++)
			if(dp[i][j] < oo)
			{
				state now = decode(j);
				tmp[1] = now.a;
				tmp[2] = now.b;
				tmp[3] = now.c;
				tmp[4] = now.d;
				for(int k = 1; k <= 4; k ++)
					con[k] = c[i][k] == '*';
				if(tmp[1] >= con[1] && tmp[2] >= con[2] && tmp[3] >= con[3] && tmp[4] >= con[4])
				{
					int next = encode(max(tmp[1] - 1, 0), max(tmp[2] - 1, 0), max(tmp[3] - 1, 0), max(tmp[4] - 1, 0));
					dp[i + 1][next] = min(dp[i + 1][next], dp[i][j]);
					continue;
				}
				dp[i + 1][(1 << 8) - 1] = min(dp[i + 1][(1 << 8) - 1], dp[i][j] + a[4]);
				for(int k = 1; k <= 4; k ++)
				{
					for(int x = 1; x <= 4; x ++)
						trans[x] = tmp[x];
					for(int x = 1; x <= min(5 - k, 3); x ++)
					{
						for(int y = k; y < k + x; y ++)
							trans[y] = max(trans[y], x);
						int next = encode(trans[1], trans[2], trans[3], trans[4]);
						dp[i][next] = min(dp[i][next], dp[i][j] + a[x]);
					}
				}
			}
	int ans = oo;
	for(int i = 0; i < (1 << 8); i ++)
		ans = min(ans, dp[n + 1][i]);
	cout << ans << endl;
	
	return 0;
}