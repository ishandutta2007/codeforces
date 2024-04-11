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
const int N = (int) 1e5 + 5, mod = (int) 0;
int t[N], a[N], added[N], sum[N];
int32_t main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int j = 0; j < n; ++j) cin >> t[j + 1], t[j + 1] += t[j];
	for (int j = 0; j < n; ++j) {
		int pos = upper_bound(t, t + n + 1, t[j] + a[j]) - t;
		added[pos - 1] += t[j] + a[j] - t[pos - 1];
		sum[j]++;
		sum[pos - 1]--;
	}
	for (int j = 0; j < n; ++j) {
		if (j) sum[j] += sum[j - 1];
		cout << added[j] + sum[j] * (t[j + 1] - t[j]) << ' ';
	}
	
}