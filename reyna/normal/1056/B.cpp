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
#define int long long
typedef long long LL;

const int N = (int) 1005, mod = (int) 0;
int32_t main() {
	int n, m, res = 0;
	cin >> n >> m;
	for (int x = 1; x <= m; ++x) {
		for (int y = 1; y <= m; ++y) {
			int nx = (n - x + 1 + m - 1) / m;
			int ny = (n - y + 1 + m - 1) / m;
			if (nx < 0) nx = 0;
			if (ny < 0) ny = 0;
			if ((x * x + y * y) % m == 0)
				res += nx * ny;
		}
	}
	cout << res << endl;
}