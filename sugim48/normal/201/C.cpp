#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
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
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

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
	int N; cin >> N;
	N--;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	vector<ll> sum(N + 1);
	rep(i, N) sum[i + 1] = sum[i] + 1 + (a[i] - 1) / 2 * 2;
	vector<ll> unko(N + 1);
	for (int i = N - 1; i >= 0; i--) {
		unko[i] = unko[i + 1] + a[i] / 2 * 2;
		if (a[i] == 1) unko[i] = 0;
	}
	segment_tree_max st(N + 1);
	for (int i = 0; i <= N; i++) st.set(i, sum[i] + unko[i]);
	vector<ll> hoge(N + 1);
	for (int i = 1; i <= N; i++) {
		hoge[i] = hoge[i - 1] + a[i - 1] / 2 * 2;
		if (a[i - 1] == 1) hoge[i] = 0;
	}
	ll ans = 0;
	rep(i, N + 1) ans = max(ans, hoge[i] + st.get(i, N + 1) - sum[i]);
	cout << ans << endl;
}