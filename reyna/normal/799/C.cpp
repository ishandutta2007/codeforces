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

const int N = (int) 1e5 + 5, mod = (int) 0;
pair<int, int> a[2][N];
int t[2], best[N];
int solve(int money, pair<int, int> a[N], int n) {
	memset(best, 0, sizeof best);
	sort(a, a + n);
	int res = 0;
	for (int j = 0; j < n; ++j) {
		int x = a[j].second, y = a[j].first;
		if (y <= money) {
			int ot = money - y;
			int pos = lower_bound(a, a + j, mp(ot, (int) 1e9)) - a;
			if (best[pos] != 0) {
				res = max(res, x + best[pos]);
			}
		}
		best[j + 1] = max(best[j], x);
	}
	return res;
}
int main() {
	int n, c, d;
	cin >> n >> c >> d;
	int mx0 = -1e9, mx1 = -1e9;
	for (int j = 0; j < n; ++j) {
		int x, y;
		char ch;
		cin >> x >> y >> ch;
		int g = (ch != 'C');
		if (g == 0) {
			if (y <= c) mx0 = max(mx0, x);
		} else {
			if (y <= d) mx1 = max(mx1, x);
		}
		a[g][t[g]++] = mp(y, x);
	}
	int res = max(0, mx0 + mx1);
	res = max(res, solve(c, a[0], t[0]));
	res = max(res, solve(d, a[1], t[1]));
	cout << res << endl;
}