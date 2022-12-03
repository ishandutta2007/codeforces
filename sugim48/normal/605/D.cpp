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
	int n; vector<ll_i> v;
	segment_tree_max(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<ll_i>(n * 2 - 1, ll_i(LLONG_MIN, -1));
	}
	void set(int i, ll x, int index) {
		int k = i + n - 1;
		v[k] = ll_i(x, index);
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = max(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	ll_i _get(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return ll_i(LLONG_MIN, -1);
		if (i <= l && r <= j) return v[k];
		ll_i vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		ll_i vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	ll_i get(int i, int j) { return _get(i, j, 0, 0, n); }
};

int main() {
	int N; cin >> N;
	N++;
	vector<ll> a(N), b(N), c(N), d(N);
	vector<ll> v, w;
	for (int i = 0; i < N; i++) {
		if (i) scanf("%lld%lld%lld%lld", &a[i], &b[i], &c[i], &d[i]);
		a[i] = a[i] * N * 2 + i;
		c[i] = c[i] * N * 2 + N + i;
		v.push_back(a[i]); v.push_back(c[i]);
		w.push_back(b[i]); w.push_back(d[i]);
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	w.erase(unique(w.begin(), w.end()), w.end());
	int n = v.size(), m = w.size();
	for (int i = 0; i < N; i++) {
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		b[i] = lower_bound(w.begin(), w.end(), b[i]) - w.begin();
		c[i] = lower_bound(v.begin(), v.end(), c[i]) - v.begin();
		d[i] = lower_bound(w.begin(), w.end(), d[i]) - w.begin();
	}
	segment_tree_max st(n);
	for (int i = 0; i < N - 1; i++)
		st.set(c[i], d[i], i);
	queue<int> q;
	q.push(N - 1);
	vector<int> prev(N, -1);
	while (!q.empty()) {
		int i = q.front(); q.pop();
		for (;;) {
			ll_i p = st.get(a[i], n);
			if (p.first < b[i]) break;
			q.push(p.second);
			prev[p.second] = i;
			st.set(c[p.second], LLONG_MIN, -1);
		}
	}
	if (prev[0] == -1) cout << -1 << endl;
	else {
		vector<int> ans;
		int i = 0;
		for (; i != N - 1; i = prev[i])
			if (i)
				ans.push_back(i);
		ans.push_back(N - 1);
		cout << ans.size() << endl;
		for (int k = 0; k < ans.size(); k++)
			cout << ans[k] << ' ';
		cout << endl;
	}
}