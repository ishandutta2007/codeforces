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

const int N = (int) 2e5 + 5, mod = (int) 0;
int n, cur[N], mx[N << 2], mn[N << 2], mnmx[N << 2], mxmn[N << 2], ch[N << 2];
void apply(int v, int x) {
	ch[v] += x;
	mx[v] += x;
	mn[v] += x;
	mnmx[v] -= x;
	mxmn[v] -= x;
}
void push(int v) {
	if (!ch[v]) return;
	apply(v << 1 | 0, ch[v]);
	apply(v << 1 | 1, ch[v]);
	ch[v] = 0;
}
void pull(int v) {
	int l = v << 1, r = l | 1;
	mx[v] = max(mx[l], mx[r]);
	mn[v] = min(mn[l], mn[r]);
	mnmx[v] = max(mnmx[l], mnmx[r]);
	mnmx[v] = max(-2 * mn[l] + mx[r], mnmx[v]);
	mxmn[v] = max(mxmn[l], mxmn[r]);
	mxmn[v] = max(-2 * mn[r] + mx[l], mxmn[v]);
}
void build(int v = 1, int b = 0, int e = 2 * n - 2) {
	if (b + 1 == e) {
		mn[v] = cur[b];
		mx[v] = cur[b];
		mnmx[v] = mxmn[v] = -cur[b];
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	pull(v);
}
int find_max(int v = 1, int b = 0, int e = 2 * n - 2) {
	if (b + 1 == e) return b;
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	if (mx[l] > mx[r]) return find_max(l, b, m);
	return find_max(r, m, e);
}
void update(int i, int j, int x, int v = 1, int b = 0, int e = 2 * n - 2) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		apply(v, x);
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	pull(v);
}
pair<int, pair<int, int>> find_mnmx(int i, int j, int v = 1, int b = 0, int e = 2 * n - 2) {
	if (i >= e || b >= j) return mp(-1e9, mp(-1, -1));
	if (i <= b && e <= j) {
		return mp(mnmx[v], mp(mn[v], mx[v]));	
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	auto xl = find_mnmx(i, j, l, b, m);
	auto xr = find_mnmx(i, j, r, m, e);
	if (xl.second.first == -1) return xr;
	if (xr.second.first == -1) return xl;
	int cur_mnmx = max(xl.first, xr.first);
	cur_mnmx = max(cur_mnmx, -2 * xl.second.first + xr.second.second);
	int cmn = min(xl.second.first, xr.second.first);
	int cmx = max(xl.second.second, xr.second.second);
	return mp(cur_mnmx, mp(cmn, cmx));
}

pair<int, pair<int, int>> find_mxmn(int i, int j, int v = 1, int b = 0, int e = 2 * n - 2) {
	if (i >= e || b >= j) return mp(-1e9, mp(-1, -1));
	if (i <= b && e <= j) {
		return mp(mxmn[v], mp(mn[v], mx[v]));	
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	auto xl = find_mxmn(i, j, l, b, m);
	auto xr = find_mxmn(i, j, r, m, e);
	if (xl.second.first == -1) return xr;
	if (xr.second.first == -1) return xl;
	int cur_mxmn = max(xl.first, xr.first);
	cur_mxmn = max(cur_mxmn, -2 * xr.second.first + xl.second.second);
	int cmn = min(xl.second.first, xr.second.first);
	int cmx = max(xl.second.second, xr.second.second);
	return mp(cur_mxmn, mp(cmn, cmx));
}
int b[N];
void give_out() {

	int pos = find_max();
	int h = mx[1];
	int res = h + find_mnmx(pos + 1, 2 * n - 2).first;
	res = max(res, h + find_mxmn(0, pos).first);
	res = max(res, h);
	cout << res << '\n';
}
int main() {
	ios_base::sync_with_stdio(0);
	int q;
	cin >> n >> q;
	string s;
	cin >> s;
	for (int j = 0; j < 2 * (n - 1); ++j) b[j] = (s[j] == '(' ? 1 : -1);
	for (int j = 0; j < 2 * (n - 1); ++j) {
		if (j) cur[j] += cur[j - 1];
		cur[j] += b[j];
	}
	build();
	give_out();
	while (q--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		if (b[u] != b[v]) {
			update(u, 2 * n - 2, -b[u]);
			update(v, 2 * n - 2, +b[u]);
			update(u, 2 * n - 2, +b[v]);
			update(v, 2 * n - 2, -b[v]);
			swap(b[u], b[v]);
		}
		give_out();


	}
}