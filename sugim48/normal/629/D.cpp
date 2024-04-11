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
	int N; cin >> N;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) {
		int r, h; scanf("%d%d", &r, &h);
		a[i] = (ll)r * r * h;
	}
	vector<ll> A = a;
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	int M = A.size();
	for (int i = 0; i < N; i++)
		a[i] = lower_bound(A.begin(), A.end(), a[i]) - A.begin();
	segment_tree_max st(M);
	for (int i = 0; i < N; i++)
		st.set(a[i], max(0LL, st.get(0, a[i])) + A[a[i]]);
	printf("%.10f\n", st.get(0, M) * M_PI);
}