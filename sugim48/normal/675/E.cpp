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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
typedef pair<int, ll> i_ll;
struct edge { int u, v; ll w; };

ll INF = LLONG_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

struct segment_tree_max {
	int n; vector<ll_i> v;
	segment_tree_max(int _n) {
		for (n = 1; n < _n; n *= 2);
		v = vector<ll_i>(n * 2 - 1, ll_i(LLONG_MIN, INT_MIN));
	}
	void set(int i, ll x) {
		int k = i + n - 1;
		v[k] = ll_i(x, i);
		while (k > 0) {
			k = (k - 1) / 2;
			v[k] = max(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	ll_i _get(int i, int j, int k, int l, int r) {
		if (r <= i || j <= l) return ll_i(LLONG_MIN, INT_MIN);
		if (i <= l && r <= j) return v[k];
		ll_i vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		ll_i vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	int get(int i, int j) { return _get(i, j, 0, 0, n).second; }
};

int main() {
	int N; cin >> N;
	vector<int> r(N);
	for (int i = 0; i < N - 1; i++)
		scanf("%d", &r[i]);
	r[N - 1] = N;
	segment_tree_max st(N);
	for (int i = 0; i < N; i++)
		st.set(i, r[i]);
	vector<ll> dp(N);
	for (int i = N - 2; i >= 0; i--) {
		int j = st.get(i + 1, r[i]);
		dp[i] = (j - i) + dp[j] + (N - r[i]);
	}
	ll sum = 0;
	for (int i = 0; i < N; i++)
		sum += dp[i];
	cout << sum << endl;
}