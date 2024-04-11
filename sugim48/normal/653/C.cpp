#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <complex>
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
struct edge { int v; ll w; };

int MOD = 1000000007;

struct segment_tree_max {
	int n; vector<ll> v;
	segment_tree_max(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<ll>(n * 2 - 1);
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
		if (r <= i || j <= l) return 0;
		if (i <= l && r <= j) return v[k];
		ll vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		ll vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	ll get(int i, int j) { return _get(i, j, 0, 0, n); }
};

bool check(int N, vector<int>& a, segment_tree_max& st, int i, int j) {
	if (i > j) swap(i, j);
	vector<int> v;
	if (i - 1 >= 0) v.push_back(i - 1);
	v.push_back(i);
	v.push_back(j - 1);
	if (j + 1 < N) v.push_back(j);
	swap(a[i], a[j]);
	for (int i: v) {
		int z = 1;
		if (i % 2 == 0 && a[i] < a[i + 1]) z = 0;
		if (i % 2 == 1 && a[i] > a[i + 1]) z = 0;
		st.set(i, z);
	}
	bool ok = (st.get(0, N) == 0);
	swap(a[i], a[j]);
	for (int i: v) {
		int z = 1;
		if (i % 2 == 0 && a[i] < a[i + 1]) z = 0;
		if (i % 2 == 1 && a[i] > a[i + 1]) z = 0;
		st.set(i, z);
	}
	return ok;
}

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	int x;
	segment_tree_max st(N - 1);
	for (int i = 0; i + 1 < N; i++) {
		if (i % 2 == 0 && a[i] < a[i + 1]) continue;
		if (i % 2 == 1 && a[i] > a[i + 1]) continue;
		x = i;
		st.set(i, 1);
	}
	int ans = 0;
	if (check(N, a, st, x, x + 1)) ans++;
	for (int i = 0; i < N; i++)
		if (i != x && i != x + 1) {
			if (check(N, a, st, x, i)) ans++;
			if (check(N, a, st, x + 1, i)) ans++;
		}
	cout << ans << endl;
}