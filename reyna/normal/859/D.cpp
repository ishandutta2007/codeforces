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
#define double long double
const int N = (int) 1 << 12, M = 1 << 6, mod = (int) 0;
double dp[10][M], winner[10][N];
int prob[M][M];
int main() {
	int n;
	cin >> n;
	for (int x = 0; x < 1 << n; ++x)
		for (int y = 0; y < 1 << n; ++y)
			cin >> prob[x][y];
	for (int j = 0; j < 1 << n; ++j) winner[0][j] = 1, dp[0][j] = 0;
	for (int level = 0; level < n; ++level) {
		for (int start = 0; start < (1 << n); start += 1 << level + 1) {
			int m = start + (1 << level);
			for (int who = start; who < start + (1 << level + 1); ++who) {
				int st = start, ed = m;
				if (who < m) st += 1 << level, ed += 1 << level;
				for (int j = st; j < ed; ++j) {
					winner[level + 1][who] += winner[level][who] * winner[level][j] * prob[who][j] / 100;
				}
			}
			for (int who = start; who < start + (1 << level + 1); ++who) {
				int st = start, ed = m;
				if (who < m) st += 1 << level, ed += 1 << level;
				double most = 0;
				for (int j = st; j < ed; ++j) most = max(most, dp[level][j]);
				dp[level + 1][who] = dp[level][who] + winner[level + 1][who] * (1 << level) + most;
			}
			
		}
	}
	double most = 0;
	for (int j = 0; j < 1 << n; ++j)
		most = max(most, dp[n][j]);
	cout << setprecision(100) << fixed << most << endl;
}