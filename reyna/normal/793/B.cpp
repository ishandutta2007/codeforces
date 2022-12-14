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

const int N = (int) 1e3 + 3, mod = (int) 0;

int dp[N][N], odp[N][N], ndp[N][N];
string mat[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) {
		cin >> mat[j];
	}
	memset(dp, 63, sizeof dp);
	for (int a = 0; a < n; ++a)
		for (int b = 0; b < m; ++b)
			if (mat[a][b] == 'S')
				dp[a][b] = 0;
	for (int turn = 0; turn < 3; ++turn) {
		memcpy(odp, dp, sizeof dp);
		memset(ndp, 63, sizeof ndp);
		memcpy(dp, odp, sizeof dp);
		for (int a = 1; a < n; ++a) {
			for (int b = 0; b < m; ++b) {
				if (mat[a][b] != '*') {
					dp[a][b] = min(dp[a][b], dp[a - 1][b]);
				}
			}
		}
		for (int a = 0; a < n; ++a)
			for (int b = 0; b < m; ++b)
				smin(ndp[a][b], dp[a][b]);
		memcpy(dp, odp, sizeof dp);
		for (int a = 0; a < n; ++a) {
			for (int b = 1; b < m; ++b) {
				if (mat[a][b] != '*') {
					dp[a][b] = min(dp[a][b], dp[a][b - 1]);
				}
			}
		}
		for (int a = 0; a < n; ++a)
			for (int b = 0; b < m; ++b)
				smin(ndp[a][b], dp[a][b]);
		memcpy(dp, odp, sizeof dp);
		for (int a = n - 2; a >= 0; --a) {
			for (int b = m - 1; b >= 0; --b) {
				if (mat[a][b] != '*') {
					dp[a][b] = min(dp[a][b], dp[a + 1][b]);
				}
			}
		}
		for (int a = 0; a < n; ++a)
			for (int b = 0; b < m; ++b)
				smin(ndp[a][b], dp[a][b]);
		memcpy(dp, odp, sizeof dp);
		for (int a = n - 1; a >= 0; --a) {
			for (int b = m - 2; b >= 0; --b) {
				if (mat[a][b] != '*') {
					dp[a][b] = min(dp[a][b], dp[a][b + 1]);
				}
			}
		}
		for (int a = 0; a < n; ++a)
			for (int b = 0; b < m; ++b)
				smin(ndp[a][b], dp[a][b]);
		memcpy(dp, ndp, sizeof dp);
	}
	for (int a = 0; a < n; ++a)
		for (int b = 0; b < m; ++b)
			if (mat[a][b] == 'T') {
				if (!dp[a][b]) {
					cout << "YES\n";
				} else {
					cout << "NO\n";
				}
				return 0;
			}
}