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
const int N = (int) 1e6 + 6, mod = (int) 0;
int g[N], pos[N], ps[4][N], a[4][N], t[4], cnt[N], sum[N], cost[N];
pair<int, int> sr[N];
void fu(int m, int x, int *f) { ++m;
	while (m < N)
		f[m] += x, m += m & -m;
}
int fq(int m, int *f) { ++m;
	int res = 0;
	while (m > 0)
		res += f[m], m -= m & -m;
	return res;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int j = 0; j < n; ++j) {
		cin >> cost[j];
		sr[j] = mp(cost[j], j);
	}
	sort(sr, sr + n);
	for (int j = 0; j < n; ++j) pos[sr[j].second] = j;
	int ss;
	cin >> ss;
	for (int j = 0; j < ss; ++j) {
		int x;
		cin >> x;
		g[--x] |= 1;
	}
	int b;
	cin >> b;
	for (int j = 0; j < b; ++j) {
		int x;
		cin >> x;
		g[--x] |= 2;
	}
	for (int _ = 0; _ < n; ++_) {
		int j = sr[_].second;
		int gr = g[j];
		a[gr][t[gr]++] = j;
	}
	for (int j = 0; j < n; ++j) {
		int i = pos[j];
		fu(i, 1, cnt);
		fu(i, cost[j], sum);
	}
	for (int gr = 1; gr <= 2; ++gr) {
		for (int j = 0; j < min(k, t[gr]); ++j) {
			int p = a[gr][j];
			int i = pos[p];
			fu(i, -1, cnt);
			fu(i, -cost[p], sum);
		}
	}
	for (int gr = 0; gr < 4; ++gr) {
		for (int j = 0; j < t[gr]; ++j) {
			ps[gr][j + 1] = ps[gr][j] + cost[a[gr][j]];
		}
	}
	int res = 1e18, cursum = 0, pt1 = min(k, t[1]), pt2 = min(k, t[2]);
	for (int c3 = 0; c3 <= min(m, t[3]); ++c3) {
		int c1 = k - c3;
		int c2 = k - c3;
		while (pt1 > 0 && pt1 > c1) {
			int p = a[1][pt1 - 1];
			int i = pos[p];
			fu(i, 1, cnt);
			fu(i, cost[p], sum);
			--pt1;
		}
		while (pt2 > 0 && pt2 > c2) {
			int p = a[2][pt2 - 1];
			int i = pos[p];
			fu(i, 1, cnt);
			fu(i, cost[p], sum);
			--pt2;
		}
		int choose = pt1 + pt2 + c3;
		int flag = 0;
		if (c3 + pt1 < k || c3 + pt2 < k) flag = 1;
		if (choose > m) flag = 1;
		int rem = m - choose;
		int cur_cost = cursum + ps[1][pt1] + ps[2][pt2];
		int bl = -2, br = N - 1;
		if (fq(br, cnt) < rem) flag = 1;
		while (bl < br - 1) {
			int bm = bl + br >> 1;
			if (fq(bm, cnt) >= rem) {
				br = bm;
			} else {
				bl = bm;
			}
		}
		cur_cost += fq(br, sum);
		if (!flag && fq(br, cnt) == rem) res = min(res, cur_cost);
		cursum += cost[a[3][c3]];
		int i = pos[a[3][c3]];
		fu(i, -1, cnt);
		fu(i, -cost[a[3][c3]], sum);
	}
	cout << (res > 1e17 ? -1 : res) << endl;
	
}