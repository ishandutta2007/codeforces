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

const int N = (int) 505, lg = 61, mod = (int) 0;
int n, m;
bitset<N> mat[lg][2][N], cur[N], nx[N], bt[N];
void mul(bitset<N> a[N], bitset<N> b[N], bitset<N> c[N]) {
	for (int x = 0; x < n; ++x)
		for (int y = 0; y < n; ++y)
			bt[y][x] = b[x][y];
	for (int x = 0; x < n; ++x)
		for (int y = 0; y < n; ++y) {
			//cout << " : ) " << x << ' ' << y << ' ' << a[x][0] << ' ' << a[x][1] << ' ' << bt[y][0] << ' ' << bt[y][1] << endl;
			
			c[x][y] = ((a[x] & bt[y]) != 0);
			//cout << " hi " << x << ' ' << y << ' ' << c[x][y] << endl;
		}
}
bool is_zero(bitset<N> a[N]) {
	for (int j = 0; j < n; ++j)
		if (a[j] != 0)
			return 0;
	return 1;
}

int main() {
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int u, v, t;
		cin >> u >> v >> t;
		--u, --v;
		mat[0][t][u][v] = 1;
	}
	cur[0][0] = 1;
	for (int j = 1; j < lg; ++j) {
		for (int k = 0; k < 2; ++k) {
			mul(mat[j - 1][k], mat[j - 1][k ^ 1], mat[j][k]);
		}
	}
	long long can = 0;
	int cnt = 0;
	for (int j = lg - 1; j >= 0; --j) {
		mul(cur, mat[j][cnt], nx);
		if (!is_zero(nx)) {
			cnt ^= 1;
			can += 1ll << j;
			for (int x = 0; x < n; ++x)
				cur[x] = nx[x];
		}
	}
	cout << (can > (long long) 1e18 ? -1 : can) << '\n';

}