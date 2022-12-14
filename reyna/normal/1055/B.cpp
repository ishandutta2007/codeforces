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
const int N = (int) 1e6 + 5, mod = (int) 0;
int par[N], a[N];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
int unite(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return 0;
	par[find(u)] = find(v);	
	return 1;
}
int32_t main() {
	for (int j = 0; j < N; ++j) par[j] = j;
	int n, m, l;
	cin >> n >> m >> l;
	++l;
	int res = 0;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		if (a[j] >= l) {
			++res;
			if (j - 1 >= 0 && a[j - 1] >= l) res -= unite(j - 1, j);
		}
	}
	while (m--) {
		int c;
		cin >> c;
		if (c == 0) {
			cout << res << '\n';
		} else {
			int pos, d;
			cin >> pos >> d;
			--pos;
			if (a[pos] < l && a[pos] + d >= l) {
				++res;
				if (pos - 1 >= 0 && a[pos - 1] >= l) res -= unite(pos - 1, pos);
				if (pos + 1 <  n && a[pos + 1] >= l) res -= unite(pos, pos + 1);
			}
			a[pos] += d;
		}
	}
	
}