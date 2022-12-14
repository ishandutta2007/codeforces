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
const int N = (int) 1e6 + 6, mod = (int) 0;
int n, len, a[N], b[N], sum[N];
int check(int lim) {
	memset(sum, 0, sizeof sum);
	for (int j = 0; j < n; ++j) {
		int xl = a[j] + len - lim, xr = a[j] + len + lim + 1;
		xl = lower_bound(b, b + n + n + n, xl) - b;
		xr = lower_bound(b, b + n + n + n, xr) - b;
		xl -= j;
		xr -= j;
		xl += n;
		xr += n;
		xr = min(xr, xl + n);
		sum[xr]--;
		sum[xl]++;
	}
	for (int j = 1; j < N; ++j) sum[j] += sum[j - 1];
	for (int j = n; j < N; ++j)
		sum[j] += sum[j - n];
	for (int j = 0; j < N; ++j) {
		if (sum[j] > n) 
			assert(0);
	}
	for (int j = 0; j < N; ++j) {
		if (sum[j] == n) return 1;
	}
	return 0;
}
int32_t main() {
	cin >> n >> len;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int j = 0; j < n; ++j) cin >> b[j];
	sort(a, a + n);
	sort(b, b + n);
	for (int j = n; j < n + n + n; ++j) b[j] = b[j - n] + len;
	int bl = -1, br = len;
	while (bl < br - 1) {
		int bm = bl + br >> 1;
		if (check(bm)) {
			br = bm;
		} else {
			bl = bm;
		}
	}
	cout << br << endl;
}