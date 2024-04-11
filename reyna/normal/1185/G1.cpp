
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 55, mod = (int) 1e9 + 7;
int dp[7050][N * N], ways[N][N][N][3], f[N], cnt[3], t[N], g[N];
int main() {
	f[0] = 1;
	for (int j = 1; j < N; ++j) f[j] = (LL) f[j - 1] * j % mod;
	int n, T;
	cin >> n >> T;
	for (int j = 0; j < n; ++j) cin >> t[j] >> g[j], --g[j], cnt[g[j]]++;
	++cnt[0];
	++cnt[1];
	++cnt[2];
	int m = cnt[0] * cnt[1] * cnt[2];
	dp[0][0] = 1;
	for (int use = 0; use < n; ++use) {
		for (int last = m - 1; last >= 0; --last) {
			int incr = (g[use] == 0 ? 1 : (g[use] == 1 ? cnt[0] : cnt[0] * cnt[1]));
			for (int t_use = t[use]; t_use <= T; ++t_use) {
				dp[last + incr][t_use] = (dp[last + incr][t_use] + dp[last][t_use - t[use]]);
				if (dp[last + incr][t_use] >= mod)
					dp[last + incr][t_use] -= mod;
			}
		}
	}
	ways[0][0][1][2] = 1;
	ways[0][1][0][1] = 1;
	ways[1][0][0][0] = 1;
	for (int sum = 2; sum < N; ++sum) {
		for (int i = 0; i <= sum; ++i)
			for (int j = 0; i + j <= sum; ++j) {
				int k = sum - i - j;
				for (int last = 0; last <= 2; ++last) {
					for (int cur = 0; cur <= 2; ++cur) if (cur != last) {
						if (cur == 0 && !i) continue;
						if (cur == 1 && !j) continue;
						if (cur == 2 && !k) continue;
						if (cur == 0) {
							ways[i][j][k][cur] = (ways[i][j][k][cur] + ways[i - 1][j][k][last]) % mod;	
						}
						if (cur == 1) {
							ways[i][j][k][cur] = (ways[i][j][k][cur] + ways[i][j - 1][k][last]) % mod;	
						}
						if (cur == 2) {
							ways[i][j][k][cur] = (ways[i][j][k][cur] + ways[i][j][k - 1][last]) % mod;	
						}
					}
				}
			}
	}
	int res = 0;
	for (int last = 0; last < m; ++last) {
		int way = dp[last][T];
		int c0 = last % cnt[0];
		int c1 = (last / cnt[0]) % cnt[1];
		int c2 = last / (cnt[0] * cnt[1]);
		way = (LL) way * (ways[c0][c1][c2][0] + (LL) ways[c0][c1][c2][1] + ways[c0][c1][c2][2]) % mod;
		way = (LL) way * f[c0] % mod;
		way = (LL) way * f[c1] % mod;
		way = (LL) way * f[c2] % mod;
		res = (res + way) % mod;
	}
	cout << res << endl;
}