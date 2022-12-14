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
int res[N], deg[N], p[N], sz[N], sum[N];
int a[N];
int main() {
	int n;
	cin >> n;
	for (int j = 1; j < n; ++j) {
		cin >> p[j];
		--p[j];
		++deg[p[j]];
	}
	for (int j = 0; j < n; ++j)
		if (deg[j] == 0) {
			sz[j] = 1;
		}
	for (int j = n - 1; j >= 0; --j) {
		if (j != 0) sz[p[j]] += sz[j];
	}
	sort(sz, sz + n);
	for (int v = 0; v < n; ++v) {
		cout << sz[v] << ' ';
	}
}