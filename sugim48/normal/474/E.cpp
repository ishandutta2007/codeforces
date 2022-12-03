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

struct segtree {
	int n; vector<i_i> v;
	segtree(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<i_i>(n * 2 - 1, i_i(0, -1));
	}
	void set(int i, i_i x) {
		int k = i + n - 1;
		v[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = max(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	i_i _maxi(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return i_i(0, -1);
		if (i <= l && r <= j) return v[k];
		i_i vl = _maxi(i, j, k * 2 + 1, l, (l + r) / 2);
		i_i vr = _maxi(i, j, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	i_i maxi(int i, int j) { return _maxi(i, j, 0, 0, n); }
};

int main() {
	int n, d; cin >> n >> d;
	vector<ll> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	vector<ll> _h = h;
	sort(_h.begin(), _h.end());
	segtree st(n);
	vector<int> prev(n);
	for (int i = 0; i < n; i++) {
		int l = upper_bound(_h.begin(), _h.end(), h[i] - d) - _h.begin();
		int r = lower_bound(_h.begin(), _h.end(), h[i] + d) - _h.begin();
		i_i x = max(st.maxi(0, l), st.maxi(r, n));
		int j = lower_bound(_h.begin(), _h.end(), h[i]) - _h.begin();
		st.set(j, i_i(x.first + 1, i));
		prev[i] = x.second;
	}
	i_i x = st.maxi(0, n);
	cout << x.first << endl;
	vector<int> v;
	for (int i = x.second; i != -1; i = prev[i])
		v.push_back(i);
	for (int k = v.size() - 1; k >= 0; k--)
		cout << v[k] + 1 << ' ';
	cout << endl;
}