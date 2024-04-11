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
const int N = (int) 5005, mod = (int) 0;
int a[N], pos[N], p[N], c[N];
long long sum[N];
pair<int, int> sr[N];
long long get(int hole, int l, int r) {
	int m = pos[hole];
	if (l < m && m < r) {
		return get(hole, l, m) + get(hole, m, r);
	}
	if (r <= m) {
		return (r - l) * (long long) p[hole] - (sum[r] - sum[l]);
	} else if (l >= m) {
		return sum[r] - sum[l] - (r - l) * (long long) p[hole];
	}
	assert(0);

}
long long odp[N], dp[N];
int dq[N];
void solve(int hole, int ul, int ur, int optl, int optr) {
	if (ur - ul <= 0) return;
	int h = 0;
	int t = 0;
	dp[0] = 0;
	dq[t++] = 0;
	for (int j = 1; j <= ur; ++j) {
		while (t - h > 0 && j - dq[h] > c[hole]) ++h;
		while (t - h > 0 && odp[j] <= odp[dq[t - 1]] + get(hole, dq[t - 1], j)) --t;
		dq[t++] = j;
		dp[j] = odp[dq[h]] + get(hole, dq[h], j);
		//best = min(odp[j + 1], best + abs(p[hole] - a[j]));
	}
/*	int m = ul + ur >> 1;
	int opt = optl;
	dp[m] = 1e18;
	for (int j = optl; j <= min(optr, m); ++j) {
		if (m - j > c[hole]) continue;
		long long nwcost = odp[j] + get(hole, j, m);
		if (nwcost <= dp[m]) {
			dp[m] = nwcost;
			opt = j;
		}
	}
	solve(hole, ul, m, optl, opt);
	solve(hole, m + 1, ur, opt, optr); */
}
int32_t main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
	}
	sort(a, a + n);
	for (int j = 0; j < n; ++j)
		sum[j + 1] = sum[j] + a[j];
	int ss = 0;
	for (int j = 0; j < m; ++j) {
		cin >> sr[j].first >> sr[j].second;
		ss += sr[j].second;
	}
	sort(sr, sr + m);
	for (int j = 0; j < m; ++j) {
		p[j] = sr[j].first, c[j] = sr[j].second;
		int &pt = pos[j];
		while (a[pt] <= p[j]) ++pt;
	}
	if (ss < n) {
		cout << -1 << endl;
		return 0;
	}
	memset(dp, 63, sizeof dp);
	dp[0] = 0;
	for (int j = 0; j < m; ++j) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		solve(j, 0, n + 1, 0, n);
	}
	cout << dp[n] << endl;
}