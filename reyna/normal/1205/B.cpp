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
const int N = (int) 1e5 + 5, K = 130, mod = (int) 0;
int a[N], d[K][K];
int32_t main() {
	int m, n = 0;
	cin >> m;
	for (int j = 0; j < m; ++j) {
		int x;
		cin >> x;
		if (x) a[n++] = x;
	}
	if (n >= K - 1) {
		cout << 3 << endl;
		return 0;
	}
	for (int x = 0; x < n; ++x)
		for (int y = 0; y < n; ++y) {
			d[x][y] = 1e9;
			if (x != y && (a[x] & a[y])) {
				d[x][y] = 1;
			}
		}
	int res = 1e9;
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < k; ++i)
			for (int j = 0; j < k; ++j)
				if (i != j) {
					res = min(res, d[i][j] + d[i][k] + d[j][k]);	
				}
		for (int i = 0; i <= k; ++i)
			for (int j = 0; j <= k; ++j)
				d[k][i] = d[i][k] = min(d[k][i], d[k][j] + d[j][i]);
		for (int i = 0; i <= k; ++i)
			for (int j = 0; j <= k; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}
	cout << (res > K ? -1 : res) << '\n';
				
	
}