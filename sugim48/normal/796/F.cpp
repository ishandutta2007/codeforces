#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <random>
#include <unordered_set>
#include <complex>
using namespace std;
 
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
// typedef complex<double> C;
 
int MOD;
const int _MOD = 1000000009;
ll INF = 1e18;
double EPS = 1e-10;
 
/*
struct segtree {
	segtree *lch, *rch;
	int l, r;
	ll x, dx, ma, dma;
	segtree(int _l, int _r) : l(_l), r(_r), x(0), dx(0), ma(0), dma(0) {
		if (r - l == 1) return;
		int m = (l + r) / 2;
		lch = new segtree(l, m);
		rch = new segtree(m, r);
	}
	void lazy(ll _dx, ll _dma) {
		dma = max(dma, dx + _dma);
		dx += _dx;
	}
	void denpan() { lch->lazy(dx, dma); rch->lazy(dx, dma); dx = dma = 0; }
	void merge() {
		x = max(lch->x + lch->dx, rch->x + rch->dx);
		ma = max(max(lch->ma, lch->x + lch->dma), max(rch->ma, rch->x + rch->dma));
	}
	ll mx(int _l, int _r) {
		if (r <= _l || _r <= l) return LLONG_MIN;
		if (_l <= l && r <= _r) return max(ma, x + dma);
		denpan(); merge();
		return max(lch->mx(_l, _r), rch->mx(_l, _r));
	}
	void add(int _l, int _r, ll _dx) {
		if (r <= _l || _r <= l) return;
		if (_l <= l && r <= _r) { dx += _dx; dma = max(dma, dx); return; }
		denpan();
		lch->add(_l, _r, _dx); rch->add(_l, _r, _dx);
		merge();
	}
};
*/
 
struct segtree {
	segtree *lch, *rch;
	int l, r;
	ll x, dx;
	segtree(int _l, int _r) : l(_l), r(_r), x(INF), dx(0) {
		if (r - l == 1) return;
		int m = (l + r) / 2;
		lch = new segtree(l, m);
		rch = new segtree(m, r);
	}
	void denpan() {
		lch->lazy(x, dx);
		rch->lazy(x, dx);
		x = INF; dx = 0;
	}
	void lazy(ll _x, ll _dx) {
		x = min(x, _x - dx);
		dx += _dx;
	}
	void update(int _l, int _r, ll _x, ll _dx) {
		if (r <= _l || _r <= l) return;
		if (_l <= l && r <= _r) { lazy(_x, _dx); return; }
		denpan();
		lch->update(_l, _r, _x, _dx);
		rch->update(_l, _r, _x, _dx);
	}
	ll get(int i) {
		if (r - l == 1) return x + dx;
		denpan();
		int m = (l + r) / 2;
		if (l <= i && i < m) return lch->get(i);
		if (m <= i && i < r) return rch->get(i);
	}
};
 
struct _segtree {
	_segtree *lch, *rch;
	int l, r;
	ll x, dx;
	_segtree(int _l, int _r) : l(_l), r(_r), x(-1), dx(0) {
		if (r - l == 1) return;
		int m = (l + r) / 2;
		lch = new _segtree(l, m);
		rch = new _segtree(m, r);
	}
	void denpan() { lch->lazy(dx); rch->lazy(dx); dx = 0; }
	void merge() { x = max(lch->x + lch->dx, rch->x + rch->dx); }
	void lazy(ll _dx) { dx += _dx; }
	void add(int _l, int _r, ll _dx) {
		if (r <= _l || _r <= l) return;
		if (_l <= l && r <= _r) { dx += _dx; return; }
		denpan();
		lch->add(_l, _r, _dx); rch->add(_l, _r, _dx);
		merge();
	}
	ll mx(int _l, int _r) {
		if (r <= _l || _r <= l) return -INF;
		if (_l <= l && r <= _r) return x + dx;
		denpan(); merge();
		return max(lch->mx(_l, _r), rch->mx(_l, _r));
	}
};
 
int main() {
	int N, Q; cin >> N >> Q;
	vector<int> t(Q), l(Q), r(Q), x(Q);
	rep(k, Q) {
		scanf("%d", &t[k]);
		if (t[k] == 1) scanf("%d%d%d", &l[k], &r[k], &x[k]);
		if (t[k] == 2) scanf("%d%d", &l[k], &x[k]);
		l[k]--;
	}
	segtree* st = new segtree(0, N);
	for (int k = Q - 1; k >= 0; k--) {
		if (t[k] == 1) st->update(l[k], r[k], x[k], 0);
		if (t[k] == 2) st->update(l[k], l[k] + 1, INF / 10, INT_MAX);
	}
	vector<ll> a(N);
	rep(i, N) a[i] = st->get(i);
	_segtree* _st = new _segtree(0, N);
	rep(i, N) _st->add(i, i + 1, a[i] + 1);
	vector<ll> a0 = a;
	rep(k, Q) {
		if (t[k] == 1) {
			if (_st->mx(l[k], r[k]) != x[k]) {
				cout << "NO" << endl;
				return 0;
			}
		}
		if (t[k] == 2) {
			int i = l[k];
			_st->add(i, i + 1, x[k] - a[i]);
			a[i] = x[k];
		}
	}
	set<ll> S;
	_segtree* _st2 = new _segtree(0, N);
	rep(i, N) a[i] = -1;
	rep(k, Q) {
		if (t[k] == 1) {
			if (_st2->mx(l[k], r[k]) != x[k])
				S.insert(x[k]);
		}
		if (t[k] == 2) {
			int i = l[k];
			_st2->add(i, i + 1, x[k] - a[i]);
			a[i] = x[k];
		}
	}
	rep(i, N) a0[i] = min(a0[i], (ll)1e9 + 1);
	priority_queue<i_i> pq;
	vector<ll> ans(N);
	ll cute = 0;
	rep(i, N) {
		if (S.count(a0[i])) {
			S.erase(a0[i]);
			ans[i] = a0[i];
			cute |= a0[i];
		}
		else if (a0[i]) pq.push(i_i(min(a0[i], (ll)1e9), i));
	}
	rep(i, N) a0[i] = min(a0[i], (ll)1e9);
	while (pq.size()) {
		int x = pq.top().first;
		int i = pq.top().second;
		pq.pop();
		int k;
		for (k = 30; k >= 0; k--)
			if (!(cute>>k & 1) && (x >= (1<<k)))
				break;
		if (k == -1) continue;
		cute |= 1<<k;
		pq.push(i_i(x - (1<<k), i));
		ans[i] += 1<<k;
	}
	cout << "YES" << endl;
	rep(i, N) printf("%d ", ans[i]);
	cout << endl;
}

/*
int main() {
	int N, Q; cin >> N >> Q;
	vector<int> l(Q), r(Q), dx(Q), x(Q);
	rep(k, Q) scanf("%d%d%d%d", &l[k], &r[k], &dx[k], &x[k]), l[k]--;
	segtree* st = new segtree(0, N);
	for (int k = Q - 1; k >= 0; k--)
		st->update(l[k], r[k], x[k], -dx[k]);
	vector<ll> a(N);
	rep(i, N) a[i] = st->get(i);
	_segtree* _st = new _segtree(0, N);
	rep(i, N) _st->add(i, i + 1, a[i]);
	rep(k, Q) {
		_st->add(l[k], r[k], dx[k]);
		if (_st->mx(l[k], r[k]) != x[k]) {
			cout << "NG" << endl;
			return 0;
		}
	}
	cout << "OK" << endl;
	rep(i, N) printf("%lld ", a[i]);
	cout << endl;
}
*/