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

const int N = (int) 505, mod = (int) 0;
int b[N][N], a[N][N], row[N], col[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int x = 0; x < n; ++x)
		for (int y = 0; y < m; ++y) {
			cin >> a[x][y];	
			b[x][y] = a[x][y];
		}
	int mn = 1e9, px = -1, py = -1;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (a[x][y] < mn) {
				mn = a[x][y];
				px = x;
				py = y;
			}
		}
	}
	if (n < m) {
		for (int j = 0; j < n; ++j) row[j] += mn;	
	} else {
		for (int j = 0; j < m; ++j) col[j] += mn;
	}
	for (int x = 0; x < n; ++x)
		for (int y = 0; y < m; ++y)
			a[x][y] -= mn;
	for (int x = 0; x < n; ++x) {
		row[x] += (a[x][py] - a[px][py]);
	}
	for (int y = 0; y < m; ++y) {
		col[y] += (a[px][y] - a[px][py]);
	}
	for (int x = 0; x < n; ++x)
		for (int y = 0; y < m; ++y)
			if (row[x] + col[y] != b[x][y]) {
				cout << -1 << endl;
				return 0;
			}
	int all = 0;
	for (int x = 0; x < n; ++x) all += row[x];
	for (int y = 0; y < m; ++y) all += col[y];
	cout << all << endl;
	for (int x = 0; x < n; ++x) {
		while (row[x]--) {
			cout << "row " << x + 1 << '\n';
		}
	}
	for (int y = 0; y < m; ++y) {
		while (col[y]--) {
			cout << "col " << y + 1 << '\n';	
		}
	}
	
	
}