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

const int N = (int) 1e6 + 6, mod = (int) 1e9 + 7;
int sz;
struct segtree {
	int n;
	vector<int> sum, ch, cnt;
	segtree(int _n = 0) { n = _n;
		sum.resize(n << 2);
		ch.resize(n << 2);
		cnt.resize(n << 2);
	}
	void apply(int v, int x) {
		sum[v] = (sum[v] + x * cnt[v]) % mod;
		ch[v] = (ch[v] + x) % mod;
	}
	void pull(int v) {
		sum[v] = (sum[v << 1 | 0] + sum[v << 1 | 1]) % mod;
		cnt[v] = cnt[v << 1 | 0] + cnt[v << 1 | 1];
	}
	void push(int v) {
		apply(v << 1 | 0, ch[v]);
		apply(v << 1 | 1, ch[v]);
		ch[v] = 0;
	}
	void update_seg(int i, int j, int x, int v = 1, int b = 0, int e = sz) {
		if (i >= e || b >= j) return;
		if (i <= b && e <= j) {
			apply(v, x);
			return;
		}
		int m = b + e >> 1, l = v << 1, r = l | 1;
		push(v);
		update_seg(i, j, x, l, b, m);
		update_seg(i, j, x, r, m, e);
		pull(v);
	}
	int query(int i, int j, int v = 1, int b = 0, int e = sz) {
		if (i >= e || b >= j) return 0;
		if (i <= b && e <= j) return sum[v];
		int m = b + e >> 1, l = v << 1, r = l | 1;
		push(v);
		return (query(i, j, l, b, m) + query(i, j, r, m, e)) % mod;
	}
	void update_sing(int pos, int x, int c, int v = 1, int b = 0, int e = sz) {
		if (b + 1 == e) {
			cnt[v] = c;
			sum[v] = (c * x) % mod;
			return;
		}
		int m = b + e >> 1, l = v << 1, r = l | 1;
		push(v);
		if (pos < m) {
			update_sing(pos, x, c, l, b, m);
		} else {
			update_sing(pos, x, c, r, m, e);
		}
		pull(v);
	}
} l1, r1, l2, r2;
int f[N];
vector<int> p[N];
vector<pair<int, pair<int, int>>> qry[N];
int lv[N], rv[N], _lv[N], _rv[N];
void fu(int m, int x) { m++;
	while (m < N) {
		f[m] += x;
		m += m & -m;
	}
}
int fq(int m, int res = 0) { m++;
	while (m > 0) {
		res += f[m];
		m -= m & -m;
	}
	return res;
}
#define sign siiign
int cur_res, a[N], res[N];
void add(int pos, int c) {
	int sign = (c == 0 ? -1 : 1);
	l1.update_sing(pos, lv[pos], c);
	r1.update_sing(pos, rv[pos], c);
	l2.update_sing(pos, l1.query(0, pos), c);
	r2.update_sing(pos, r1.query(pos + 1, r1.n), c);
	l2.update_seg(pos + 1, l2.n, (mod + sign * lv[pos]) % mod);
	r2.update_seg(0, pos, (mod + sign * rv[pos]) % mod);
	cur_res = (cur_res + sign * (l1.query(0, pos) * r1.query(pos + 1, r1.n) % mod) + mod) % mod;
	cur_res = (cur_res + sign * (lv[pos] * r2.query(pos + 1, r2.n) % mod) + mod) % mod;
	cur_res = (cur_res + sign * (rv[pos] * l2.query(0, pos) % mod) + mod) % mod;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> all;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		all.pb(a[j]);
	}
	sort(ALL(all));
	all.resize(unique(ALL(all)) - all.begin());
	int m = (int) all.size();
	for (int j = 0; j < n; ++j) {
		a[j] = lower_bound(ALL(all), a[j]) - all.begin();
		p[a[j]].push_back(j);
	}
	for (int j = 0; j < n; ++j) {
		_lv[j] = fq(a[j]);
		fu(a[j], 1);
	}
	memset(f, 0, sizeof f);
	for (int j = n - 1; j >= 0; --j) {
		_rv[j] = fq(a[j]);
		fu(a[j], 1);
	}
	int q;
	cin >> q;
	for (int j = 0; j < q; ++j) {
		int t, x;
		cin >> t >> x;
		--t, --x;
		qry[a[x]].push_back(mp(t, mp(lower_bound(ALL(p[a[x]]), x) - p[a[x]].begin(), j)));
	}
	for (int cur_num = 0; cur_num < m; ++cur_num) {
		cur_res = 0;
		sz = (int) p[cur_num].size();
		l1 = l2 = r1 = r2 = segtree(sz);
		for (int j = 0; j < sz; ++j) {
			lv[j] = _lv[p[cur_num][j]];
			rv[j] = _rv[p[cur_num][j]];
		}
		for (int j = 0; j < sz; ++j) add(j, 1);
		res[0] = (res[0] + cur_res) % mod;
		int last = cur_res;
		for (auto qv : qry[cur_num]) {
			int c = qv.x;
			int pos = qv.y.x;
			int add_after = qv.y.y + 1;
			res[add_after] = (res[add_after] + mod - last) % mod;
			add(pos, c);
			last = cur_res;
			res[add_after] = (res[add_after] + cur_res) % mod;
		}
	}
	for (int j = 1; j <= q; ++j) {
		res[j] = (res[j] + res[j - 1]) % mod;
		cout << res[j] << '\n';
	}
}