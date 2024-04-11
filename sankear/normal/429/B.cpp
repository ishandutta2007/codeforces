#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define len(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define hash _hash
#define y0 yy0
#define y1 yy1
#define link _link

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 1010;

int a[N][N], d1[N][N], d2[N][N], d3[N][N], d4[N][N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d1[i][j] = a[i][j];
			if (i > 0) {
				d1[i][j] = max(d1[i][j], d1[i - 1][j] + a[i][j]);
			}
			if (j > 0) {
				d1[i][j] = max(d1[i][j], d1[i][j - 1] + a[i][j]);
			}
		}
	}	
	for (int i = 0; i < n; ++i) {
		for (int j = m - 1; j >= 0; --j) {
			d2[i][j] = a[i][j];
			if (i > 0) {
				d2[i][j] = max(d2[i][j], d2[i - 1][j] + a[i][j]);
			}
			if (j + 1 < m) {
				d2[i][j] = max(d2[i][j], d2[i][j + 1] + a[i][j]);
			}
		}	
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			d3[i][j] = a[i][j];
			if (i + 1 < n) {
				d3[i][j] = max(d3[i][j], d3[i + 1][j] + a[i][j]);
			}
			if (j > 0) {
				d3[i][j] = max(d3[i][j], d3[i][j - 1] + a[i][j]);
			}
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			d4[i][j] = a[i][j];
			if (i + 1 < n) {
				d4[i][j] = max(d4[i][j], d4[i + 1][j] + a[i][j]);
			}
			if (j + 1 < m) {
				d4[i][j] = max(d4[i][j], d4[i][j + 1] + a[i][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			ans = max(ans, d1[i - 1][j] + d4[i + 1][j] + d2[i][j + 1] + d3[i][j - 1]);
			ans = max(ans, d1[i][j - 1] + d4[i][j + 1] + d2[i - 1][j] + d3[i + 1][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}