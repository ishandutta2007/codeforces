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
double EPS = 1e-10;

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

int b = 300;

int main() {
	int n; cin >> n;
	vector<int> p(n), l(n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &p[i], &l[i]);
	vector<int> dp(n);
	segment_tree_max st(n);
	for (int i = n - 1; i >= 0; i--) {
		int j = upper_bound(p.begin(), p.end(), p[i] + l[i]) - p.begin();
		dp[i] = max(p[i] + l[i], st.get(i + 1, j));
		st.set(i, dp[i]);
	}
	vector<int> to(n), c(n);
	for (int i = 0; i < n; i++) {
		int j = upper_bound(p.begin(), p.end(), dp[i]) - p.begin();
		to[i] = j;
		if (j < n) c[i] = p[j] - dp[i];
	}
	vector<int> skip_to(n), skip_c(n);
	for (int i = 0; i < n; i++) {
		int j;
		for (j = i; j < n && j < i + b;) {
			skip_c[i] += c[j];
			j = to[j];
		}
		skip_to[i] = j;
	}
	int q; cin >> q;
	while (q--) {
		int x, y; scanf("%d%d", &x, &y);
		x--; y--;
		int ans = 0;
		while (to[x] <= y) {
			if (skip_to[x] <= y) {
				ans += skip_c[x];
				x = skip_to[x];
			}
			else {
				ans += c[x];
				x = to[x];
			}
		}
		printf("%d\n", ans);
	}
}