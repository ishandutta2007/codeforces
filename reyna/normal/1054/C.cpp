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
int a[N], b[N], res[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j)
		cin >> a[j];
	for (int j = 0; j < n; ++j)
		cin >> b[j];
	for (int j = 0; j < n; ++j) {
		res[j] = n - a[j] - b[j];
		if (res[j] < 0) {
			cout << "NO\n";
			return 0;
		}
	}
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < x; ++y) if (res[x] < res[y]) --a[x];
		for (int y = x + 1; y < n; ++y) if (res[x] < res[y]) --b[x];
		if (a[x] || b[x]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (int x = 0; x < n; ++x)
		cout << res[x] << ' ';
}