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

const int N = (int) 0, mod = (int) 0;
#define int long long
long long k, d, t;
int f(int bm) {

	long long tmp = bm / 2;
	long long cycle = (d + k - 1) / d * d;
	long long rem = cycle - k;
	long long take_each_cycle = k * 2 + rem;
	long long times = tmp / cycle;
	long long have = take_each_cycle * times;
	long long rembm = tmp - times * cycle;
	if (rembm <= k) {
		have += rembm * 2;
	} else {
		have += k * 2 + rembm - k;
	}
	if ((bm & 1) && rembm < k) {
		have++;
	}
	return have;
}
int32_t main() {
	cin >> k >> d >> t;
	long long bl = 0, br = 4e18 + 100;
	while (bl < br - 1) {
		long long bm = bl + br >> 1;
		int have = f(bm);
		if (have >= 2 * t) {
			br = bm;
		} else {
			bl = bm;
		}

	}
	if (br & 1) {
		cout << br / 2 << ".5\n";
	} else {
		cout << br / 2 << endl;
	}
}