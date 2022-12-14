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
#define int long long
const int N = (int) 0, mod = (int) 0;

int32_t main() {
	int n;
	cin >> n;
	int res = -1e18, mx0 = -1e18, mx1 = 0;
	int last = 0;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		int tmp = x;
		x = abs(last - x);
		last = tmp;
		if (j == 0) continue;
		tmp = mx0;
		mx0 = mx1 + x;
		mx1 = tmp - x;
		res = max(mx0, res);
		res = max(mx1, res);
		mx1 = max(mx1, 0LL);
	}
	cout << res << endl;
}