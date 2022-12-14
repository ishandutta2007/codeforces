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
int a[N][N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 2; ++i) for (int x = 0; x < n; ++x)
		for (int y = 0; y < m; ++y) {
			int p;
			cin >> p;
			a[x][y] ^= p;
		}
	for (int row = 0; row < n; ++row) {
		int c = 0;
		for (int j = 0; j < m; ++j)
			c ^= a[row][j];
		if (c) {
			cout << "No\n";
			return 0;
		}
	}
	for (int col = 0; col < m; ++col) {
		int c = 0;
		for (int row = 0; row < n; ++row)
			c ^= a[row][col];
		if (c) {
			cout << "No\n";
			return 0;
		}
		
	}
	cout << "Yes\n";
}