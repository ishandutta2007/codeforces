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
#include <random>
#include <unordered_map>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-12;
int INF = INT_MAX / 10;

template <class Monoid>
struct segtree {
	using T = typename Monoid::T;
	int N;
	vector<T> a;
	segtree(const vector<T> &a0) {
		for (N = 1; N < a0.size(); N<<=1);
		a.resize(N<<1);
		copy(a0.begin(), a0.end(), a.begin() + N);
		for (int i = N - 1; i; i--)
			a[i] = Monoid::op(a[i<<1], a[i<<1 | 1]);
	}
	segtree(int N, const T &x = Monoid::id()) :
		segtree(vector<T>(N, x)) {}
	T get(int l, int r) {
		T xl = Monoid::id(), xr = Monoid::id();
		for (l += N, r += N; l < r; l>>=1, r>>=1) {
			if (l & 1) xl = Monoid::op(xl, a[l++]);
			if (r & 1) xr = Monoid::op(a[--r], xr);
		}
		return Monoid::op(xl, xr);
	}
	void set(int i, const T &x) {
		a[i += N] = x;
		while (i>>=1) a[i] = Monoid::op(a[i<<1], a[i<<1 | 1]);
	}
};

struct Unko {
	using T = ll;
	static T id() { return 0; }
	static T op(const T &l, const T &r) { return l + r; }
};

struct bit {
	vector<ll> v;
	bit(int n) : v(n + 1) {}
	ll sum(int i) {
		ll res = 0;
		for (; i > 0; i -= i & -i) res += v[i];
		return res;
	}
	void add(int i, ll x) {
		for (i++; i < v.size(); i += i & -i) v[i] += x;
	}
	int lower_bound(ll x) {
		if (x <= 0) return 0;
		int res = 0;
		for (int i = 1 << 24; i > 0; i >>= 1)
			if (res + i < v.size() && v[res + i] < x) {
				res += i; x -= v[res];
			}
		return res + 1;
	}
};

vector<ll> calc_sum(vector<int> a) {
	int N = a.size();
	vector<ll> sum(N + 1);
	rep(i, N) sum[i + 1] = sum[i] + a[i];
	return sum;
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	vector<bool> b1(N), b2(N);
	int N1; cin >> N1;
	rep(t, N1) {
		int i; scanf("%d", &i); i--;
		b1[i] = true;
	}
	int N2; cin >> N2;
	rep(t, N2) {
		int i; scanf("%d", &i); i--;
		b2[i] = true;
	}
	if (N1 < K || N2 < K) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> a00, a01, a10, a11;
	rep(i, N) {
		if (!b1[i] && !b2[i]) a00.pb(a[i]);
		if (!b1[i] && b2[i]) a01.pb(a[i]);
		if (b1[i] && !b2[i]) a10.pb(a[i]);
		if (b1[i] && b2[i]) a11.pb(a[i]);
	}
	sort(a00.begin(), a00.end());
	sort(a01.begin(), a01.end());
	sort(a10.begin(), a10.end());
	sort(a11.begin(), a11.end());
	vector<ll> sum01 = calc_sum(a01);
	vector<ll> sum10 = calc_sum(a10);
	vector<ll> sum11 = calc_sum(a11);
	vector<int> A = a;
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	int L = A.size();
	bit b(L), c(L);
	rep(i, a00.size()) {
		int x = a00[i];
		int j = lower_bound(A.begin(), A.end(), x) - A.begin();
		b.add(j, 1);
		c.add(j, x);
	}
	int i01 = a01.size(), i10 = a10.size();
	ll mi = LLONG_MAX;
	for (int k = 0; k <= a11.size(); k++) {
		int d = max(0, K - k);
		while (i01 > d) {
			i01--;
			int x = a01[i01];
			int j = lower_bound(A.begin(), A.end(), x) - A.begin();
			b.add(j, 1);
			c.add(j, x);
		}
		while (i10 > d) {
			i10--;
			int x = a10[i10];
			int j = lower_bound(A.begin(), A.end(), x) - A.begin();
			b.add(j, 1);
			c.add(j, x);
		}
		if (d <= a01.size() && d <= a10.size()) {
			ll ans = sum11[k] + sum01[d] + sum10[d];
			int m = M - k - d * 2;
			if (0 <= m && m <= b.sum(L)) {
				int j = b.lower_bound(m);
				ans += c.sum(j);
				if (j) ans -= (b.sum(j) - m) * A[j - 1];
				mi = min(mi, ans);
			}
		}
	}
	if (mi == LLONG_MAX) mi = -1;
	cout << mi << endl;
}