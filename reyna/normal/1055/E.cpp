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

const int N = (int) 1550, mod = (int) 0;
int n, s, m, k;
int dp[N][N], cur[N], best[N], sum[N], a[N], odp[N][N], o[N], xl[N], xr[N], intervals[N][N];
int cmp(int x, int y) { return xl[x] == xl[y] ? xr[x] < xr[y] : xl[x] < xl[y]; }
int check(int lim) {
	for (int j = 0; j < n; ++j)
		sum[j + 1] = sum[j] + (a[j] <= lim);
	memset(dp, -63, sizeof dp);
	memset(cur, -63, sizeof cur);
	cur[0] = 0;
	int pt = 0;
	for (int i = 0; i < m; ++i) {
		int j = o[i];
		if (!best[j]) continue;
		dp[j][1] = sum[xr[j]] - sum[xl[j]];
		int id = -1;
		for (int p = 0; p < i; ++p) {
			int q = o[p];
			if (!best[q]) continue;
			if (xl[j] < xr[q]) {
				id = q;
				break;
			}
		}
		if (id != -1)
			for (int pick = 1; pick <= s; ++pick)
				dp[j][pick] = max(dp[j][pick], dp[id][pick - 1] + sum[xr[j]] - sum[xr[id]]);
		while (pt < i) {
			int c = o[pt];
			if (best[c] == 0) {
				++pt;
			} else {
				if (xr[c] <= xl[j]) {
					for (int pick = 0; pick <= s; ++pick)
						cur[pick] = max(cur[pick], dp[c][pick]);
				} else {
					break;
				}
				++pt;
			}
		}
		for (int pick = 1; pick <= s; ++pick)
			dp[j][pick] = max(dp[j][pick], cur[pick - 1] + sum[xr[j]] - sum[xl[j]]);
	}
	for (int j = 0; j < m; ++j)
		for (int pick = 0; pick <= s; ++pick)
			if (dp[j][pick] >= k)
				return 1;
	return 0;
}
int main() {
	cin >> n >> m >> s >> k;
	for (int j = 0; j < n; ++j)
		cin >> a[j];
	for (int j = 0; j < m; ++j)
		cin >> xl[j] >> xr[j], best[j] = 1, --xl[j], o[j] = j;
	sort(o, o + m, cmp);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j) if (i != j) {
			if (xl[i] == xl[j] && xr[i] == xr[j]) {
				if (i > j) continue;	
			}
			if (xl[i] <= xl[j] && xr[j] <= xr[i])
				best[j] = 0;
		}
	int bl = -1, br = 1e9 + 10;
	while (bl < br - 1) {
		int bm = bl + br >> 1;
		if (check(bm)) {
			br = bm;	
		} else {
			bl = bm;
		}
	}
	cout << (br > 1e9 + 2 ? -1 : br)  << endl;
}