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
const int N = (int) 2e6 + 6, mod = (int) 0;
pair<int, int> ans[N];
int cur_t = 0, a[N];
int32_t main() {
	int n, q, mx = 0;
	cin >> n >> q;
	for (int j = 0; j < n; ++j) cin >> a[j], mx = max(mx, a[j]);
	int h = 0, t = n;
	while (a[h] != mx) {
		ans[cur_t] = mp(a[h], a[h + 1]);
		++cur_t;
		int fs = max(a[h], a[h + 1]);
		int sc = min(a[h], a[h + 1]);
		a[t++] = sc;
		a[++h] = fs;
	}
	while (q--) {
		int k;
		cin >> k;
		if (k <= cur_t) {
			cout << ans[k - 1].first << ' ' << ans[k - 1].second << '\n';
			continue;
		}
		k -= cur_t;
		--k;
		int rem = k % (n - 1);
		cout << a[h] << ' ' << a[h + 1 + rem] << '\n';
	}	
	
}