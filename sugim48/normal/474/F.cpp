#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
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

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

struct segtree {
	int n; vector<int> v;
	segtree(int _n) {
		for (n = 1; n < _n; n *= 2);
		v.assign(n * 2 - 1, 0);
	}
	void update(int i, int x) {
		int k = n - 1 + i;
		v[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = gcd(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	int _query(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return 0;
		if (i <= l && r <= j) return v[k];
		int vl = _query(i, j, k * 2 + 1, l, (l + r) / 2);
		int vr = _query(i, j, k * 2 + 2, (l + r) / 2, r);
		return gcd(vl, vr);
	}
	int query(int i, int j) {
		return _query(i, j, 0, 0, n);
	}
};

struct min_num {
	int min, num;
	min_num(int _min, int _num)
		: min(_min), num(_num) {}
};

min_num calc(min_num& a, min_num& b) {
	int m, n;
	m = min(a.min, b.min);
	if (a.min < b.min) n = a.num;
	else if (a.min > b.min) n = b.num;
	else n = a.num + b.num;
	return min_num(m, n);
}

struct segtree2 {
	int n; vector<min_num> v;
	segtree2(int _n) {
		for (n = 1; n < _n; n *= 2);
		v.assign(n * 2 - 1, min_num(INT_MAX, 0));
	}
	void update(int i, int x) {
		int k = n - 1 + i;
		v[k] = min_num(x, 1);
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = calc(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	min_num _query(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return min_num(INT_MAX, 0);
		if (i <= l && r <= j) return v[k];
		min_num vl = _query(i, j, k * 2 + 1, l, (l + r) / 2);
		min_num vr = _query(i, j, k * 2 + 2, (l + r) / 2, r);
		return calc(vl, vr);
	}
	min_num query(int i, int j) {
		return _query(i, j, 0, 0, n);
	}
};

int main() {
	int n; cin >> n;
	vector<int> s(n);
	segtree st(n);
	segtree2 st2(n);
	for (int i = 0; i < n; i++) {
		int s; cin >> s;
		st.update(i, s);
		st2.update(i, s);
	}
	int t; cin >> t;
	while (t--) {
		int l, r; cin >> l >> r; l--;
		int d = st.query(l, r);
		min_num x = st2.query(l, r);
		int num = (x.min == d ? x.num : 0);
		cout << r - l - num << endl;
	}
}