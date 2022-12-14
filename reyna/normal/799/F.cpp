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
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }
typedef long long LL;
struct data {
	int cnt;
	long long sum;
	int t;
	data(int a = 0, int b = 0, int c = 0) { cnt = a, sum = b, t = c; }
};
data merge(data x, data y) {
	data res;
	res.cnt = max(x.cnt, y.cnt);
	res.sum = ((x.cnt == res.cnt) ? x.sum : 0) + ((y.cnt == res.cnt) ? y.sum : 0);
	res.t = ((x.cnt == res.cnt) ? x.t : 0) + ((y.cnt == res.cnt) ? y.t : 0);
	return res;
}
#define x first
#define y second
const int N = (int) 2e5 + 6, mod = (int) 0;
int ch[N << 2], sz;
data seg[N << 2];
void update(int i, int j, int x, int v = 1, int b = 0, int e = sz) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		seg[v].cnt += x;
		ch[v] += x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	seg[v] = merge(seg[l], seg[r]);
	seg[v].cnt += ch[v];
}
int ps[N];
void build(int p, int v = 1, int b = 0, int e = sz) {
	if (b + 1 == e) {
		if ((b & 1) == p) {
			seg[v] = data(-1, b, 1);
		} else {
			seg[v] = data(-1e9, 0, 1);
		}
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(p, l, b, m);
	build(p, r, m, e);
	seg[v] = merge(seg[l], seg[r]);
	seg[v].cnt += ch[v];
}
vector<pair<pair<int, int>, int>> queries[N];
int ql[N], qr[N];
pair<int, int> sr[N];
vector<int> op[N], cl[N];
void revert(int id) {
	for (auto s : queries[id]) {
		int l = s.x.x, r = s.x.y, x = s.y;
		update(l, r, -x);
	}
	queries[id].clear();
}
void add(int id, int l, int r, int x) {
	update(l, r, x);
	queries[id].push_back(mp(mp(l, r), x));
}
int32_t main() {
	int n, m;
	cin >> n >> m;
//	m += 10; 
	sz = m;
	for (int j = 0; j < n; ++j) {
		cin >> ql[j] >> qr[j];	
//		ql[j] += 5;
//		qr[j] += 5;
		--ql[j];
		--qr[j];
		sr[j] = mp(qr[j], ql[j]);
	}
	sort(sr, sr + n);
	for (int j = 0; j < n; ++j) {
		ql[j] = sr[j].second, qr[j] = sr[j].first;
		op[ql[j]].push_back(j);
		cl[qr[j] + 1].push_back(j);
	}
	long long res = 0;
	for (int rp = 0; rp <= 1; ++rp) {
		for (int lp = 0; lp <= 1; ++lp) {
			for (int j = 0; j < n; ++j) {
				queries[j].clear();
				add(j, 0, m, 1);
			}
			memset(ch, 0, sizeof ch);
			build(lp);
			int pt = 0;
			for (int r = rp; r < m; r += 2) {
//				cout << " hmmm " << r << ' ' << seg[1].t << endl;
				for (int j = max(0, r - 1); j <= r; ++j) {
					if ((j & 1) == lp) update(j, j + 1, n + 1);
//					cout << " what " << r << ' ' << seg[1].cnt << endl;
					for (int x : op[j]) {
						revert(x);
						add(x, ql[x], m, (lp == rp) ? 1 : -1);
						add(x, 0, ql[x], ((r - ql[x] + 1) % 2 == 1) ? 1 : -1);
					}
//					cout << " after " << r << ' ' << seg[1].t << endl;
					for (int x : cl[j]) {
						revert(x);
						if ((qr[x] - ql[x] + 1) % 2 == 0) {
							add(x, 0, ql[x], -1);
						} else {
							add(x, 0, ql[x], 1);
						}
						if ((lp & 1) == (qr[x] & 1)) {
							add(x, ql[x], qr[x] + 1, 1);
						} else {
							add(x, ql[x], qr[x] + 1, -1);
						}
						add(x, qr[x] + 1, m, 1);
					}
				}
				res += (seg[1].cnt == n ? ((long long) seg[1].t * (r + 1) - seg[1].sum) : 0);
			}
		}
	}
	for (int j = 0; j < n; ++j) {
		ps[qr[j] + 1]--;
		ps[ql[j]]++;
	}
	cerr << res << endl;
	long long sl = 0;
	int ss = 0;
	for (int j = 0; j < m; ++j) {
		ps[j] += (j >= 1 ? ps[j - 1] : 0);
		if (ps[j] >= 1) {
			sl = 0;
			ss = 0;
		} else {
			sl += j;
			ss++;
		}
		res -= (long long) (j + 1) * ss - sl;
	}
	cout << res << endl;
}