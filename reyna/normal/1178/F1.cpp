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

const int N = (int) 505, M = 505, mod = (int) 998244353;
int dp[N][N], c[M];
int solve(int l, int r) {
	if (r - l <= 1) return 1;
	if (dp[l][r] != -1) return dp[l][r];
	int &res = dp[l][r];
	res = 0;
	int mnid = l;
	for (int j = l; j < r; ++j)
		if (c[j] < c[mnid])
			mnid = j;
	int suml = 0, sumr = 0;
	for (int nl = mnid; nl >= l; --nl) {
		suml = (suml + (LL) solve(nl, mnid) * solve(l, nl)) % mod;
	}
	for (int nr = mnid + 1; nr <= r; ++nr) {
		sumr = (sumr + (LL) solve(mnid + 1, nr) * solve(nr, r)) % mod;	
	}
	res = (res + (LL) suml * sumr) % mod;
	return res;
}
int main() {
	memset(dp, -1, sizeof dp);
	int n, m;
	cin >> n >> m;
	int res = 1;
	for (int j = 0; j < m; ++j) cin >> c[j];
	cout << solve(0, m) << endl;
}