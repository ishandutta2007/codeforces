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

const int N = (int) 1005, mod = (int) 0;
double a[N], b[N];
int n, init;
int check(double lim) {
	lim += init;
	for (int j = 0; j < n; ++j) {
		int cur = j;
		int nxt = (j + 1) % n;
		lim -= lim / a[cur];
		lim -= lim / b[nxt];
	}
	if (lim < init) {
		return 0;
	}
	return 1;
}
int main() {
	cin >> n >> init;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		if (x == 1) {
			cout << -1 << endl;
			return 0;
		}
		a[j] = x;
	}
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		if (x == 1) {
			cout << -1 << endl;
			return 0;
		}
		b[j] = x;
	}
	double bl = 0, br = 2e9;
	for (int j = 0; j < 200; ++j) {
		double bm = (bl + br) / 2;
		if (check(bm)) {
			br = bm;
		} else {
			bl = bm;
		}
	}
	cout << setprecision(20) << fixed << br << endl;	
}