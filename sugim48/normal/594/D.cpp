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

ll extgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = (a >= 0) ? 1 : -1;
		y = 0;
		return abs(a);
	}
	else {
		ll res = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return res;
	}
}

ll mod_inverse(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

struct segment_tree {
	int n; vector<int> v;
	segment_tree(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<int>(n * 2 - 1, 1);
	}
	void set(int i, int x) {
		int k = i + n - 1;
		v[k] = (ll)v[k] * x % MOD;
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = (ll)v[k * 2 + 1] * v[k * 2 + 2] % MOD;
		}
	}
	int _get(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return 1;
		if (i <= l && r <= j) return v[k];
		int vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		int vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return (ll)vl * vr % MOD;
	}
	int get(int i, int j) { return _get(i, j, 0, 0, n); }
};

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	segment_tree st(n);
	for (int i = 0; i < n; i++)
		st.set(i, a[i]);
	vector<vector<int> > ps(n);
	vector<vector<int> > v(1000001);
	for (int i = 0; i < n; i++) {
		int x = a[i];
		for (int p = 2; p * p <= x; p++)
			if (x % p == 0) {
				ps[i].push_back(p);
				v[p].push_back(i);
				for (; x % p == 0; x /= p);
			}
		if (x > 1) {
			ps[i].push_back(x);
			v[x].push_back(i);
		}
	}
	vector<int> unko(1000001);
	for (int p = 1; p <= 1000000; p++) {
		if (v[p].empty()) continue;
		unko[p] = (ll)(p - 1) * mod_inverse(p, MOD) % MOD;
		st.set(v[p][0], unko[p]);
	}
	int q; cin >> q;
	vector<int> l(q), r(q);
	vector<vector<int> > qs(n);
	for (int j = 0; j < q; j++) {
		cin >> l[j] >> r[j];
		l[j]--;
		qs[l[j]].push_back(r[j]);
	}
	map<i_i, int> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < qs[i].size(); j++) {
			int l = i, r = qs[i][j];
			ans[i_i(l, r)] = (ll)st.get(l, r);
		}
		for (int k = 0; k < ps[i].size(); k++) {
			int p = ps[i][k];
			int x = upper_bound(v[p].begin(), v[p].end(), i) - v[p].begin();
			if (x < v[p].size()) st.set(v[p][x], unko[p]);
		}
	}
	for (int j = 0; j < q; j++)
		cout << ans[i_i(l[j], r[j])] << endl;
}