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
int s[N], dis[N], sum[N];
int32_t main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> s[j];	
	}
	sort(s, s + n);
	s[n] = 2000LL * 1000 * 1000 * 1000 * 1000 * 1000 + 1;
	n += 1;
	for (int j = 1; j < n; ++j)
		dis[j - 1] = s[j] - s[j - 1];
	sort(dis, dis + n - 1);
	for (int j = 0; j < n - 1; ++j)
		sum[j + 1] = dis[j] + sum[j];
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l;
		int d = r - l;
		int pos = lower_bound(dis, dis + n - 1, d) - dis;
		int res = sum[pos] + (n - 1 - pos) * d;
		cout << res << ' ';
	}
	
	
}