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
int n, a[N], mn[N << 2], ch[N << 2];
void push(int v) {
	mn[v << 1 | 0] += ch[v];
	mn[v << 1 | 1] += ch[v];
	ch[v << 1 | 0] += ch[v];
	ch[v << 1 | 1] += ch[v];
	ch[v] = 0;
}
void update(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		mn[v] += x;
		ch[v] += x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	mn[v] = min(mn[l], mn[r]);
}
void build(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		mn[v] = a[b];
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	mn[v] = min(mn[l], mn[r]);
}
int find(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) return b;
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	if (mn[r] == mn[v]) return find(r, m, e);
	return find(l, b, m);
}
int res[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j];
	build();
	for (int turn = 0; turn < n; ++turn) {
		int cur = find();
		res[cur] = turn + 1;
		update(cur + 1, n, -turn - 1);
		update(cur, cur + 1, (long long) 1e18);
	}
	for (int j = 0; j < n; ++j) cout << res[j] << ' ';
	cout << endl;
}