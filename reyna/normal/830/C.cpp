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
const int N = (int) 105, mod = (int) 0;
int a[N];
vector<int> v;
int32_t main() {
	int n, k, sum = 0;
	cin >> n >> k;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		sum += a[j];
		for (int d = 1; d * d <= a[j]; ++d) {
			v.pb(d);
			v.pb(d + 1);
		}
		for (int p = 1; p * p <= a[j]; ++p) {
			v.pb((a[j] + p - 1) / p);
			v.pb((a[j] + p) / (p + 1));
		}
		
	}
	v.pb(1);
	v.pb(k + (int) 1e9 + 10);
	sort(ALL(v));
	v.resize(unique(ALL(v)) - v.begin());
	long long res = 0;
	for (int j = 0; j < (int) v.size() - 1; ++j) {
		int dl = v[j], dr = v[j + 1];
		int cnt = 0;
		for (int i = 0; i < n; ++i) cnt += (a[i] + dl - 1) / dl;
		// cnt * d - sum <= k
		// cnt * d <= sum + k
		int d = (sum + k) / cnt;
		d = min(d, dr - 1);
		if (d < dl) continue;
		res = max(res, d);
	}
	cout << res << endl;
}