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
#define int long long
const int N = (int) 55, mod = (int) 0;
int n, p[N], q[N], o[N], dp[N][N], odp[N][N];
int cmp(int x, int y) { return p[x] < p[y]; }
int check(int lim) {
	memset(dp, 63, sizeof dp);
	dp[0][0] = 0;
	int last = -1;
	for (int j = n - 1; j >= 0; --j) {
		int i = o[j];
		if (p[i] != last) {		
			memcpy(odp, dp, sizeof dp);
			memset(dp, 63, sizeof dp);
			for (int x = 0; x < N; ++x)
				for (int y = 0; x + y < N; ++y)
					dp[x + y][0] = min(dp[x + y][0], odp[x][y]);
			last = p[i];
		}
		memcpy(odp, dp, sizeof dp);
		memset(dp, 63, sizeof dp);
		int val = p[i] - q[i] * lim;
		for (int p0 = 0; p0 <= n; ++p0) {
			for (int p1 = 0; p1 <= n; ++p1) {
				dp[p0][p1 + 1] = min(dp[p0][p1 + 1], odp[p0][p1] + val);
			}
		}
		for (int p0 = 1; p0 <= n; ++p0) {
			for (int p1 = 0; p1 <= n; ++p1) {
				dp[p0 - 1][p1] = min(dp[p0 - 1][p1], odp[p0][p1]);
			}
		}
	}
	for (int j = 0; j < N; ++j)
		for (int i = 0; i < N; ++i)
			if (dp[j][i] <= 0)
				return 1;
	return 0;
}
int32_t main() {
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> p[j], p[j] *= 1000, o[j] = j;
	for (int j = 0; j < n; ++j) cin >> q[j];
	sort(o, o + n, cmp);
	int bl = -1, br = 1e13;
	while (bl < br - 1) {
		int bm = bl + br >> 1;
		if (check(bm)) {
			br = bm;
		} else {
			bl = bm;
		}
	}
	cout << br << endl;
}