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

const int N = (int) 2005, mod = (int) 1e9 + 7;
int n, m, dp[2][N], odp[2][N], lcp[2][N][N], revlcp[2][N][N];
string mat[2];
void sadd(int &x, int y) {
	x += y;
	while (x >= mod) x -= mod;
	while (x < 0   ) x += mod;
}
int solve(string pattern, int turn = 0) {
	memset(lcp, 0, sizeof lcp);
	memset(revlcp, 0, sizeof revlcp);
	for (int row = 0; row <= 1; ++row) {
		for (int x = n - 1; x >= 0; --x)
			for (int y = m - 1; y >= 0; --y)
				lcp[row][x][y] = (mat[row][x] == pattern[y] ? lcp[row][x + 1][y + 1] + 1 : 0);
		for (int x = n - 1; x >= 0; --x)
			for (int y = 0; y < m; ++y)
				revlcp[row][x][y] = (mat[row][x] == pattern[y] ? (y == 0 ? 0 : revlcp[row][x + 1][y - 1]) + 1 : 0);
	}
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	dp[1][0] = 1;
	int res = 0;
	for (int col = 0; col < n; ++col) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		dp[1][0] = 1;
		for (int k = 0; k <= 1; ++k) {
			for (int pos = 1; pos <= m; ++pos) {
				sadd(dp[k][pos], odp[k][pos - 1] * (pattern[pos - 1] == mat[k][col]));
				if (pos >= 2) {
					sadd(dp[k][pos], odp[k ^ 1][pos - 2] * (pattern[pos - 2] == mat[k ^ 1][col]) * (pattern[pos - 1] == mat[k][col]));
				}
			}
			for (int len = 2; len + len < m; ++len) {
				int last_col = col - len + 1;
				if (last_col >= 0) {
					int f0 = (revlcp[k ^ 1][last_col][len - 1] >= len);
					int f1 = (lcp[k][last_col][len] >= len);
					sadd(dp[k][len + len], f0 & f1);
				}
			}
		}
		for (int k = 0; k <= 1; ++k) {
			sadd(res, dp[k][m]);
			for (int len = 2; len + len <= m; ++len) {
				int nxt_col = col + len;
				if (nxt_col < n) {
					int f0 = (lcp[k][col + 1][m - len - len] >= len);
					int f1 = (revlcp[k ^ 1][col + 1][m - 1] >= len);
					sadd(res, f0 * f1 * dp[k][m - len - len]);
				}
			}
		}
	}
	
	if (m % 2 == 0) for (int k = 0; k <= 1; ++k) {
		int len = m / 2;	
		int col = -1;
		int nxt_col = col + len;
		if (nxt_col < n) {
			int f0 = (lcp[k][col + 1][m - len - len] >= len);
			int f1 = (revlcp[k ^ 1][col + 1][m - 1] >= len);
			sadd(res, f0 * f1);
		}
		
	}
	
	return res;
}

int main() {
	for (int j = 0; j <= 1; ++j)
		cin >> mat[j];
	n = (int) mat[0].size();
	string s;
	cin >> s;
	m = (int) s.size();
	if (m == 2) {
		int res = 0;
		for (int row = 0; row <= 1; ++row) {
			for (int j = 0; j + 1 < n; ++j) {
				if (mat[row][j] == s[0] && mat[row][j + 1] == s[1]) ++res;
				if (mat[row][j] == s[1] && mat[row][j + 1] == s[0]) ++res;
			}
		}
		for (int col = 0; col < n; ++col) {
			if (mat[0][col] == s[0] && mat[1][col] == s[1]) ++res;
			if (mat[1][col] == s[0] && mat[0][col] == s[1]) ++res;
		}
		cout << res << '\n';
		return 0;
	}
	if (m == 1) {
		int res = 0;
		for (int row = 0; row <= 1; ++row)
			for (int col = 0; col < n; ++col)
				res += (mat[row][col] == s[0]);
		cout << res << '\n';
		return 0;
	}
	int res = solve(s);
	for (int j = 0; j <= 1; ++j) reverse(mat[j].begin(), mat[j].end());
	res = (res + solve(s)) % mod;
	cout << res << '\n';
}