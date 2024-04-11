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

const int N = (int) 3e5 + 5, mod = (int) 0;
int ok[N], req[N], bl[N], br[N], bm[N], xcs[N], o[N], rev[N], xl[N], xr[N], xc[N], seg[N << 2], alone[N], val[N], ans[N], eo[N];
pair<int, int> event[N * 4];
bool by_req(int a, int b) { return req[a] < req[b]; }
bool by_xc(int a, int b) { return xc[a] < xc[b]; }
void update(int pos, int x, int v = 1, int b = 0, int e = N) {
	if (b + 1 == e) {
		seg[v] = max(seg[v], x);
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	if (pos < m) {
		update(pos, x, l, b, m);
	} else {
		update(pos, x, r, m, e);
	}
	seg[v] = max(seg[l], seg[r]);
}
int query(int i, int j, int v = 1, int b = 0, int e = N) {
	if (i >= e || b >= j) return 0;
	if (i <= b && e <= j) return seg[v];
	int m = b + e >> 1, l = v << 1, r = l | 1;
	return max(query(i, j, l, b, m), query(i, j, r, m, e));
}

int main() {
	ios_base::sync_with_stdio(0);
	int n, bud;
	cin >> n >> bud;
	for (int j = 0; j < n; ++j) {
		cin >> xl[j] >> xr[j] >> xc[j];	
		o[j] = j;
		xcs[j] = xc[j];
	}
	int q;
	cin >> q;
	for (int j = 0; j < q; ++j) cin >> req[j], bl[j] = 0, br[j] = 2e9 + 1, eo[j] = j;
	sort(xcs, xcs + n);
	sort(o, o + n, by_xc);
	sort(eo, eo + q, by_req);
	int pt = 0;
	for (int j = 0; j < n; ++j) rev[o[j]] = j;
	memset(ok, 0, sizeof ok);
	memset(seg, 0, sizeof seg);
	memset(alone, 0, sizeof alone);
	memset(val, 0, sizeof val);
	int sz = 0, c = 0;
/*	for (int j = 0; j < q; ++j) {
					if (br[j] != bl[j] + 1) {
					bm[j] = ((long long) bl[j] + br[j]) >> 1;
					event[sz++] = mp(bm[j], -j - 1);
					++c;
					}
					} 
					if (!c) break; */
		for (int j = 0; j < n; ++j) {
			event[sz++] = mp(xl[j], j << 2 | 0);
			event[sz++] = mp(xr[j], j << 2 | 1);
		}
		event[sz++] = mp((int) 2e9 + 1, 2);
	set<int> op;
	map<pair<int, int>, int> share;
	sort(event, event + sz);
	int last = 0;
	int res = 0, add = 0;
	for (int j = 0; j < sz; ++j) {
		int pos = event[j].first, t = event[j].second;
		/*			if (t < 0) {
					t *= -1;
					--t;
					t <<= 2;
					t |= 2;
					} */
		if ((int) op.size() == 1) {
			int o = *(op.begin());
			if (xc[o] <= bud) {
				val[o] += pos - last;
				alone[o] += pos - last;
				res = max(res, add + val[o]);
				res = max(res, alone[o] + add);
				int p = rev[o];
				update(p, alone[o]);
				int allow_r = upper_bound(xcs, xcs + n, bud - xc[o]) - xcs;
				if (p < allow_r) {
					res = max(res, alone[o] + max(query(0, p), query(p + 1, allow_r)) + add);	
				} else {
					res = max(res, alone[o] + query(0, allow_r) + add);
				}
			}
		} else if ((int) op.size() == 2) {
			auto it = op.begin();
			int x = *it, y = *(++it);
			if (xc[x] + xc[y] <= bud) {
				share[mp(x, y)] += pos - last;
				int g = share[mp(x, y)] + alone[x] + alone[y];
				res = max(res, add + g);
				val[x] = max(val[x], g);
				val[y] = max(val[y], g);
			}
		} else if ((int) op.size() == 0) {
			add += pos - last;	
			res += pos - last;
		}
		while (pt < q && res >= req[eo[pt]]) {
			ans[eo[pt]] = pos - (res - req[eo[pt]]);
			++pt;
		}
		if ((t & 3) == 0) {
			op.insert(t >> 2);
		} else if ((t & 3) == 1) {
			op.erase(t >> 2);
		} else if ((t & 3) == 2) {
			int id = t >> 2;
			if (req[id] <= res) {
				ok[id] = 1;	
			} else {
				ok[id] = 0;
			}
			--c;
			if (!c) break;
		} else {
			assert(0);
		}
		last = pos;
	}
	for (int j = 0; j < q; ++j)
		cout << ans[j] << '\n';
}