// In the name of God

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

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 2005, M = 1 << 12, mod = (int) 0;
int n, m, dp[M], mx[N], odp[M], a[N][13], tmp[M], o[N];
int cmp(int x, int y) {
	return mx[x] > mx[y];	
}
int main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int j = 0; j < n; ++j)
			for (int i = 0; i < m; ++i)
				cin >> a[i][j];
		for (int i = 0; i < m; ++i) {
			o[i] = i;
			mx[i] = 0;
			for (int j = 0; j < n; ++j) mx[i] = max(mx[i], a[i][j]);
		}
		sort(o, o + m, cmp);
		memset(dp, -63, sizeof dp);
		dp[0] = 0;
		for (int col_ = 0; col_ < min(m, n + 1); ++col_) {
			int col = o[col_];
			for (int j = 0; j < (1 << n); ++j) tmp[j] = odp[j] = dp[j];
			for (int cyc = 0; cyc < n; ++cyc) {
				for (int mask = 0; mask < (1 << n); ++mask) {
					for (int j = 0; j < n; ++j) if (mask >> j & 1) {
						if (odp[mask] < odp[mask ^ (1 << j)] + a[col][(j + cyc) % n])
							odp[mask] = odp[mask ^ (1 << j)] + a[col][(j + cyc) % n];
					}
				}
				for (int j = 0; j < (1 << n); ++j) dp[j] = max(dp[j], odp[j]), odp[j] = tmp[j];
			}
		}
		cout << dp[(1 << n) - 1] << '\n';
	}
	
}