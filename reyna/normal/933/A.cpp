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

const int N = (int) 2005, mod = (int) 0;
int pre[N][3], suf[N][3], dp[2], odp[2], a[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int j = 0; j < n; ++j) {
		pre[j + 1][0] = pre[j][0] + (a[j] == 1);
		pre[j + 1][1] = pre[j][1] + (a[j] == 2);
		pre[j + 1][2] = max(pre[j + 1][0], pre[j][2] + (a[j] == 2));
	}
	for (int j = n - 1; j >= 0; --j) {
		suf[j][0] = suf[j + 1][0] + (a[j] == 1);
		suf[j][1] = suf[j + 1][1] + (a[j] == 2);
		suf[j][2] = max(suf[j][0], suf[j + 1][2] + (a[j] == 2));
	}
	int res = 0;
	for (int l = 0; l < n; ++l) {
		memset(dp, 0, sizeof dp);
		int cnt0 = 0, cnt1 = 0;
		for (int r = l + 1; r <= n; ++r) {
			memcpy(odp, dp, sizeof dp);
			memset(dp, 0, sizeof dp);
			cnt0 += (a[r - 1] == 1);
			cnt1 += (a[r - 1] == 2);
			dp[1] = odp[1] + (a[r - 1] == 2);
			dp[0] = max(dp[1], odp[0] + (a[r - 1] == 1));
			res = max(res, pre[l][2] + cnt1 + suf[r][1]);
			res = max(res, pre[l][0] + dp[0] + suf[r][1]);
			res = max(res, pre[l][0] + cnt0 + suf[r][2]);
		}
	}
	cout << res << endl;
}