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
const int N = (int) 55, S = N * 100, mod = (int) 0;
const double oo = 1e9;
double dp[N][S];
int n, tot, f[N], s[N], p[N];
bool check(double lim) {
	for (int j = 0; j < N; ++j)
		for (int used = 0; used < S; ++used)
			dp[j][used] = lim;
	dp[0][0] = oo;
	for (int used = 0; used <= tot; ++used) dp[n][used] = 0;
	for (int used = tot; used >= 0; --used) {
		for (int level = n - 1; level >= 0; --level) {
			if (used != 0 || level != 0) 
				dp[level][used] = min(dp[level][used], lim);
			double alter = 0;
			{
				alter += p[level] / (double) 100 * (f[level] + dp[level + 1][used + f[level]]);
				alter += (100 - p[level]) / (double) 100 * (s[level] + dp[level + 1][used + s[level]]);
			}
			dp[level][used] = min(dp[level][used], alter);
		}
	}
	if (dp[0][0] < lim) return 1;
	return 0;
}
int main() {
	cin >> n >> tot;
	for (int j = 0; j < n; ++j) {
		cin >> f[j] >> s[j] >> p[j];	
	}
	double bl = 0, br = 1e9;
	for (int j = 0; j < 100; ++j) {
		double bm = (bl + br) / 2;
		if (check(bm)) {
			br = bm;	
		} else {
			bl = bm;
		}
	}
	cout << setprecision(100) << fixed << bl << endl;
	
}