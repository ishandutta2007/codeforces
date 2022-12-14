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

const int N = (int) 55, mod = (int) 0;
string s[N];
int cntrow[N][N], cntcol[N][N], a[N][N], dp[N][N][N][N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> s[j];
		for (int i = 0; i < n; ++i)
			a[j][i] = (s[j][i] == '#');
	}
	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < n; ++col)
			cntrow[row][col + 1] = cntrow[row][col] + a[row][col];
	}
	for (int col = 0; col < n; ++col)
		for (int row = 0; row < n; ++row)
			cntcol[col][row + 1] = cntcol[col][row] + a[row][col];
	for (int xl = n - 1; xl >= 0; --xl)
		for (int xr = xl + 1; xr <= n; ++xr)
			for (int yl = n - 1; yl >= 0; --yl)
				for (int yr = yl + 1; yr <= n; ++yr) {
					dp[xl][xr][yl][yr] = max(yr - yl, xr - xl);
					for (int row = xl; row < xr; ++row) {
						if (cntrow[row][yr] - cntrow[row][yl] == 0) {
							if (dp[xl][xr][yl][yr] > dp[xl][row][yl][yr] + dp[row+1][xr][yl][yr]) {
								dp[xl][xr][yl][yr] = dp[xl][row][yl][yr] + dp[row+1][xr][yl][yr];
							}
						}
					}
					for (int col = yl; col < yr; ++col) {
						if (cntcol[col][xr] - cntcol[col][xl] == 0) {
							if (dp[xl][xr][yl][yr] > dp[xl][xr][yl][col] + dp[xl][xr][col+1][yr]) {
								dp[xl][xr][yl][yr] = dp[xl][xr][yl][col] + dp[xl][xr][col+1][yr];
							}
						}
					}
				}
	cout << dp[0][n][0][n] << endl;
}