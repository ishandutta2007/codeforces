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
const int N = (int) 1e6 + 6, mod = (int) 0;
int value[N], increase[N], p[N];
void add_query(int l, int r, int x, int d) {
	assert(r >= l);
	value[l] += x;
	value[r] -= x + (r - l - 1) * d;
//	if (l + 1 <= r) {
		increase[l + 1] += d;
		increase[r] -= d;
//	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> p[j];
		--p[j];
	}
	for (int j = 0; j < n; ++j) {
		if (p[j] >= j) {
			add_query(0, p[j] - j, p[j] - j, -1);
			add_query(p[j] - j, n - j, 0, 1);
			add_query(n - j, n, p[j], -1);
		} else if (j > p[j]) {
			add_query(0, n - j, j - p[j], 1);
			add_query(n - j, n - j + p[j], p[j], -1);
			add_query(n - j + p[j], n, 0, 1);
		}
	}
	int cur_val = 0, cur_incr = 0;
	for (int j = 0; j < n; ++j) {
		cur_val += value[j];
		cur_incr += increase[j];
		cur_val += cur_incr;
		value[j] = cur_val;
	}
	int least = 1e18;
	for (int j = 0; j < n; ++j) {
		least = min(least, value[j]);
	}
	cout << least << ' ';
	for (int j = 0; j < n; ++j)
		if (value[j] == least) {
			cout << j << endl;
			return 0;
		}
}