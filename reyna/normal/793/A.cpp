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
#define int long long
typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
int a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	int res = 0, mn = 1e18;
	for (int j = 0; j < n; ++j)
		cin >> a[j], mn = min(mn, a[j]);
	for (int j = 0; j < n; ++j) {
		if (mn % k != a[j] % k) {
			cout << -1 << endl;
			return 0;
		}
		res += (a[j] - mn) / k;
	}
	cout << res << endl;
}