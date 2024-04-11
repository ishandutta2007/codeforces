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
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll w; };

int inf = INT_MAX / 10;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-9;

struct segment_tree_max {
	int n; vector<ll> v;
	segment_tree_max(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<ll>(n * 2 - 1, LLONG_MIN);
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
		if (r <= i || j <= l) return LLONG_MIN;
		if (i <= l && r <= j) return v[k];
		ll vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		ll vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	ll get(int i, int j) { return _get(i, j, 0, 0, n); }
};

int main() {
	int n, d; cin >> n >> d;
	vector<int> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	vector<bool> dp(500001);
	dp[0] = true;
	for (int i = 0; i < n; i++)
		for (int x = 500000; x - c[i] >= 0; x--)
			if (dp[x - c[i]])
				dp[x] = true;
	segment_tree_max st(600001);
	for (int x = 0; x <= 500000; x++)
		if (dp[x])
			st.set(x, x);
	int x = 0, t;
	for (t = 0; ; t++) {
		ll _x = st.get(x + 1, x + d + 1);
		if (_x == LLONG_MIN) break;
		x = _x;
	}
	cout << x << ' ' << t << endl;
}