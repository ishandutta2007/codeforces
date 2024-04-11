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
int sum[N], cnt0, a[N], cnt1;
int32_t main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];	
		a[j] = __builtin_popcountll(a[j]);
		sum[j + 1] = sum[j] ^ (a[j] & 1);
	}
	for (int j = 0; j <= n; ++j) {
		if (sum[j] == 0) {
			cnt0++;
		} else {
			cnt1++;
		}
	}
	int res = cnt0 * (cnt0 - 1) / 2 + cnt1 * (cnt1 - 1) / 2;
	for (int r = 0; r <= n; ++r) {
		int sum = 0, mx = 0;
		for (int l = r - 1; l >= max(0LL, r - 70); --l) {
			mx = max(mx, a[l]);
			sum += a[l];
			if (sum < mx + mx && ::sum[r] == ::sum[l]) {
				res--;	
			}
		}
	}
	cout << res << endl;
}