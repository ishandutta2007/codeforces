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

const int N = (int) 1 << 21, mod = (int) 0;
pair<int, int> most[N];
int a[N];
pair<int, int> add(pair<int, int> x, int y) {
	if (y == -1) return x;
	if (y == x.first || y == x.second) return x;
	if (x.second < y) {
		x.first = x.second;
		x.second = y;
	} else if (x.first < y) {
		x.first = y;	
	}
	return x;
}
pair<int, int> add(pair<int, int> x, pair<int, int> y) {
	x = add(x, y.first);
	x = add(x, y.second);
	return x;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < N; ++j) most[j] = make_pair(-1, -1);
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		most[a[j]] = add(most[a[j]], j);
	}
	for (int cur = 0; cur < 21; ++cur)
		for (int mask = 0; mask < 1 << 21; ++mask)
			if (mask >> cur & 1)
				most[mask ^ (1 << cur)] = add(most[mask ^ (1 << cur)], most[mask]);
	int res = 0;
	for (int bit = 20; bit >= 0; --bit) {
		res ^= 1 << bit;
		int can = 0;
		for (int cur = 0; cur < n; ++cur) {
			int s = a[cur];
			int see = res & (~s);
			if (most[see].first > cur && most[see].second > cur) {
				can = 1;
			}
		}
		if (!can) res ^= 1 << bit;
	}
	cout << res << endl;
}