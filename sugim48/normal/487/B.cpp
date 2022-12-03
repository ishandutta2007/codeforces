#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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
double EPS = 1e-9;

struct segment_tree_min {
	int n; vector<int> v;
	segment_tree_min(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<int>(n * 2 - 1, INT_MAX);
	}
	void set(int i, int x) {
		int k = i + n - 1;
		v[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = min(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	int _get(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return INT_MAX;
		if (i <= l && r <= j) return v[k];
		int vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		int vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr);
	}
	int get(int i, int j) { return _get(i, j, 0, 0, n); }
};

struct segment_tree_max {
	int n; vector<int> v;
	segment_tree_max(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<int>(n * 2 - 1, INT_MIN);
	}
	void set(int i, int x) {
		int k = i + n - 1;
		v[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = max(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	int _get(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return INT_MIN;
		if (i <= l && r <= j) return v[k];
		int vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		int vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	int get(int i, int j) { return _get(i, j, 0, 0, n); }
};

int main() {
	int n, s, l; cin >> n >> s >> l;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	segment_tree_min stm(n);
	segment_tree_max stM(n);
	for (int i = 0; i < n; i++) {
		stm.set(i, a[i]);
		stM.set(i, a[i]);
	}
	vector<int> dp(n + 1, INT_MAX);
	segment_tree_min stdp(n + 1);
	dp[0] = 0;
	stdp.set(0, 0);
	for (int i = l; i <= n; i++) {
		int lb = -1, ub = i;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			ll mini = stm.get(mid, i);
			ll maxi = stM.get(mid, i);
			if (maxi - mini <= s) ub = mid;
			else lb = mid;
		}
		if (ub >= i - l + 1) continue;
		int x = stdp.get(ub, i - l + 1);
		if (x < INT_MAX) {
			dp[i] = x + 1;
			stdp.set(i, x + 1);
		}
	}
	cout << (dp[n] < INT_MAX ? dp[n] : -1) << endl;
}