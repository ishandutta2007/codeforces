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

const int N = (int) 1105, M = 1e6 + 6, mod = (int) 998244353;
int dp[N][N], c[M];
vector<int> appear[N];
int solve(int l, int r) {
	if (r - l < 0) return 0;
	if (r - l == 0) return 1;
	if (r - l == 1) {
		int id = c[l];
		if (appear[id].size() == 1) return 1;
		return 0;
	}
	if (dp[l][r] != -1) return dp[l][r];
	int &res = dp[l][r];
	res = 0;
	int mn = 1e9;
	for (int j = l; j < r; ++j)
		mn = min(mn, c[j]);
	int mnl = appear[mn][0], mnr = appear[mn].back();
	if (l > mnl || r <= mnr) {
		res = 0;
		return res;
	}
	int suml = 0, sumr = 0, summ = 1;
	for (int j = 0; j < (int) appear[mn].size() - 1; ++j) {
		summ = (LL) summ * solve(appear[mn][j] + 1, appear[mn][j + 1]) % mod;
	}
	for (int nl = mnl; nl >= l; --nl) {
		suml = (suml + (LL) solve(nl, mnl) * solve(l, nl)) % mod;
	}
	for (int nr = mnr; nr <= r; ++nr) {
		sumr = (sumr + (LL) solve(mnr + 1, nr) * solve(nr, r)) % mod;	
	}
	res = (res + (LL) suml * sumr % mod * summ % mod) % mod;
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	memset(dp, -1, sizeof dp);
	int n, m;
	cin >> n >> m;
	int res = 1;
	vector<int> all;
	for (int j = 0; j < m; ++j) {
		cin >> c[j];
		if ((int) all.size() == 0 || c[j] != all.back()) {
			all.pb(c[j]);
		}
	}
	m = (int) all.size();
	for (int j = 0; j < m; ++j) {
		c[j] = all[j];
		appear[c[j]].pb(j);	
	}
	if (m >= N) {
		cout << 0 << endl;
		return 0;
	}
	cout << solve(0, m) << endl;
}