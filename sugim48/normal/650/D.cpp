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

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

struct bit {
	vector<ll> w;
	bit(int n) : w(n + 1, 0) {}
	ll maxi(int i) {
		ll res = 0;
		for (; i > 0; i -= i & -i) res = max(res, w[i]);
		return res;
	}
	void update(int i, ll x) {
		for (i++; i < w.size(); i += i & -i)
			w[i] = max(w[i], x);
	}
};

struct segment_tree_max {
	int n; vector<ll> v;
	segment_tree_max(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<ll>(n * 2 - 1, LLONG_MIN);
	}
	void set(int i, ll x) {
		int k = i + n - 1;
		v[k] = max(v[k], x);
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = max(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	ll _get(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return LLONG_MIN;
		if (i <= l && r <= j) return v[k];
		ll vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		ll vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	ll get(int i, int j) { return _get(i, j, 0, 0, n); }
};

int main() {
	int N, Q; cin >> N >> Q;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	vector<int> index(Q), b(Q);
	for (int j = 0; j < Q; j++) {
		scanf("%d%d", &index[j], &b[j]);
		index[j]--;
	}
	vector<int> w;
	for (int i = 0; i < N; i++)
		w.push_back(a[i]);
	for (int j = 0; j < Q; j++)
		w.push_back(b[j]);
	sort(w.begin(), w.end());
	w.erase(unique(w.begin(), w.end()), w.end());
	int M = w.size();
	for (int i = 0; i < N; i++)
		a[i] = lower_bound(w.begin(), w.end(), a[i]) - w.begin();
	for (int j = 0; j < Q; j++)
		b[j] = lower_bound(w.begin(), w.end(), b[j]) - w.begin();
	bit bt(M + 1);
	vector<int> dp(N);
	for (int i = 0; i < N; i++) {
		dp[i] = bt.maxi(a[i]) + 1;
		bt.update(a[i], dp[i]);
	}
	int L = bt.maxi(M + 1);
	vector<int> v(L + 2);
	v[L + 1] = INT_MAX;
	vector<bool> f(N);
	vector<int> g(L + 1);
	for (int i = N - 1; i >= 0; i--) {
		int j = dp[i];
		if (a[i] < v[j + 1]) {
			v[j] = max(v[j], a[i]);
			f[i] = true;
			g[j]++;
		}
	}
	vector<bool> subete(N);
	for (int i = 0; i < N; i++)
		if (f[i]) {
			int j = dp[i];
			if (g[j] == 1) subete[i] = true;
		}
	vector<vector<int> > query(N);
	for (int j = 0; j < Q; j++)
		query[index[j]].push_back(j);
	vector<int> left(Q), right(Q);
	segment_tree_max st1(M), st2(M);
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < query[i].size(); k++) {
			int j = query[i][k];
			left[j] = st1.get(0, b[j]);
		}
		st1.set(a[i], st1.get(0, a[i]) + 1);
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int k = 0; k < query[i].size(); k++) {
			int j = query[i][k];
			right[j] = st2.get(b[j] + 1, M);
		}
		st2.set(a[i], st2.get(a[i] + 1, M) + 1);
	}
	int lis = st1.get(0, M);
	for (int j = 0; j < Q; j++) {
		int ans = (subete[index[j]] ? lis - 1 : lis);
		ans = max(ans, left[j] + 1 + right[j]);
		printf("%d\n", ans);
	}
}