
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
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int n, m, k, q, b[N], dp[2], odp[2], pos[2], xl[N], xr[N];
int get_dist(int px, int py, int qx, int qy) {
	if (px == qx) return abs(py - qy);
	int pos = lower_bound(b, b + q, py) - b;
	int res = 1e18;
	for (int j = 0; j >= -1; --j) {
		int p = pos + j;
		if (p >= 0 && p < q) {
			int dist = abs(py - b[p]) + abs(b[p] - qy);	
			res = min(res, dist);
		}
	}
	return res + abs(px - qx);
}
int32_t main() {
	cin >> n >> m >> k >> q;
	memset(xl, 63, sizeof xl);
	memset(xr, -63, sizeof xr);
	for (int j = 0; j < k; ++j) {
		int r, c;
		cin >> r >> c;
		--r, --c;
		xl[r] = min(xl[r], c);
		xr[r] = max(xr[r], c);
	}
	for (int j = 0; j < q; ++j) {
		cin >> b[j];
		--b[j];
	}
	sort(b, b + q);
	int lastrow = 0;
	pos[0] = pos[1] = 0;
	dp[0] = dp[1] = 0;
	for (int row = 0; row < n; ++row) {
		if (xl[row] < N) {
			memcpy(odp, dp, sizeof dp);
			memset(dp, 63, sizeof dp);
			for (int last_pos = 0; last_pos <= 1; ++last_pos) {
				for (int cur_pos = 0; cur_pos <= 1; ++cur_pos) {
					dp[cur_pos] = min(dp[cur_pos], odp[last_pos] + 
							get_dist(lastrow, pos[last_pos], row, (cur_pos == 0 ? xr[row] : xl[row])) +
							get_dist(row, (cur_pos == 0 ? xr[row] : xl[row]), row, (cur_pos == 0 ? xl[row] : xr[row])));
				}
			}
			lastrow = row;
			pos[0] = xl[row];
			pos[1] = xr[row];
		}
	}
	cout << min(dp[0], dp[1]) << endl;
	
}