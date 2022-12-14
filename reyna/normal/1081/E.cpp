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
const int N = (int) 1e7 + 6, mod = (int) 0;
int a[N], res[N];
int is_sq(int x) {
	int y = sqrt(x);
	while (y * y < x) ++y;
	while (y * y > x) --y;
	return x == y * y;
}
int32_t main() {
	int n;
	cin >> n;
	for (int j = 0; j < n / 2; ++j) {
		cin >> a[j];
	}
	int cur = 0;
	for (int j = 0; j < n / 2; ++j) {
		int sum = cur * cur;
		while (cur < N && (cur * cur - sum <= a[j] || !is_sq(cur * cur - a[j]))) {
			++cur;
		}
		if (cur == N) {
			cout << "No\n";
			return 0;
		}
		res[j] = cur * cur - a[j] - sum;
	}
	cout << "Yes\n";
	for (int j = 0; j < n / 2; ++j) cout << res[j] << ' ' << a[j] << ' ';
	
}