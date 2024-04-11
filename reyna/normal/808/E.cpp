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
const int N = (int) 4e5 + 5, mod = (int) 0;
int dp[N], odp[N];
vector<int> all[4], sum[4];
void solve(int w, int st, int l, int r, int optl, int optr) {
	if (r - l <= 0) return;
	int m = l + r >> 1, optm = optl;
	int f = 0;
	for (int j = optl; j <= optr; ++j) {
		int ind = m * w + st, jid = j * w + st;
		if (m >= j && (m - j) < (int) sum[w].size()) {
			if (f == 0 || dp[ind] < odp[jid] + sum[w][m - j]) {
			    f = 1;
				dp[ind] = odp[jid] + sum[w][m - j];
				optm = j;
			}
		}
	}
	solve(w, st, l, m, optl, optm);
	solve(w, st, m + 1, r, optm, optr);
}
int32_t main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) {
		int w, c;
		cin >> w >> c;
		all[w].push_back(c);
	}
	for (int w = 1; w <= 3; ++w) {
		sort(ALL(all[w]));
		reverse(ALL(all[w]));
		sum[w].resize(all[w].size() + 1);
		for (int j = 0; j < (int) all[w].size(); ++j)
			sum[w][j + 1] = sum[w][j] + all[w][j];
	}
	memset(dp, -63, sizeof dp);
	dp[0] = 0;
	for (int w = 1; w <= 3; ++w) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, -63, sizeof dp);	
		for (int st = 0; st < w; ++st) {
			solve(w, st, 0, (m + 2 * w) / w, 0, (m + 2 * w) / w);	
		}
	}
	int res = 0;
	for (int j = 0; j <= m; ++j) res = max(res, dp[j]);
	cout << res << endl;
}