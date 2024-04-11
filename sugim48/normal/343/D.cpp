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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

struct segment_tree_max {
	int n; vector<ll> v;
	segment_tree_max(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<ll>(n * 2 - 1, -1);
	}
	void set(int i, ll x) {
		int k = i + n - 1;
		v[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = max(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	ll _get(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return -1;
		if (i <= l && r <= j) return v[k];
		ll vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		ll vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	ll get(int i, int j) { return _get(i, j, 0, 0, n); }
};

struct _segment_tree_max {
	int n; vector<int> v;
	_segment_tree_max(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<int>(n * 2 - 1, -2);
	}
	void _set(int i, int j, int x, int k, int l, int r) {
		if (r <= i || j <= l) return;
		if (i <= l && r <= j) {
			v[k] = max(v[k], x);
			return;
		}
		_set(i, j, x, k * 2 + 1, l, (l + r) / 2);
		_set(i, j, x, k * 2 + 2, (l + r) / 2, r);
	}
	void set(int i, int j, int x) { return _set(i, j, x, 0, 0, n); }
	int get(int i) {
		int k = i + n - 1, maxi = -2;
		for (int k = i + n - 1; k >= 0; k = k ? (k - 1) / 2 : -1)
			maxi = max(maxi, v[k]);
		return maxi;
	}
};

void et(int u, int p, int& z, vector<vector<int> >& G, vector<int>& x, vector<int>& y) {
	x[u] = z++;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == p) continue;
		et(v, u, z, G, x, y);
	}
	y[u] = z++;
}

int main() {
	int n; cin >> n;
	vector<vector<int> > G(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d%d", &a, &b);
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> x(n), y(n);
	int z = 0;
	et(0, -1, z, G, x, y);
	segment_tree_max st(n * 2);
	_segment_tree_max _st(n * 2);
	int q; cin >> q;
	for (int t = 0; t < q; t++) {
		int c, v; scanf("%d%d", &c, &v);
		v--;
		if (c == 1)
			_st.set(x[v], y[v] + 1, t);
		if (c == 2)
			st.set(x[v], t);
		if (c == 3)
			printf("%d\n", st.get(x[v], y[v] + 1) < _st.get(x[v]));
	}
}