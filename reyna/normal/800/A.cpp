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
const int N = (int) 1e6 + 6, mod = (int) 0;
int n, p, a[N], b[N];
bool check(double lim) {
	double use = 0;
	for (int j = 0; j < n; ++j) {
		double cur_use = a[j] * lim - b[j];
		if (cur_use > 0) {
			use += cur_use;
		}
	}
	return use <= lim * p;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> p;
	for (int j = 0; j < n; ++j)
		cin >> a[j] >> b[j];
	double bl = 0, br = 1e12;
	for (int j = 0; j < 200; ++j) {
		double bm = (bl + br) / 2;
		if (check(bm)) {
			bl = bm;
		} else {
			br = bm;
		}
	}
	if (br > 1e11) {
		cout << -1 << endl;
		return 0;
	}
	cout << setprecision(10) << fixed << bl << endl;
}