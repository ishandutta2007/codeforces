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

struct RMQ {
	using T = int;
	static T id() { return -INF; }
	static T op(const T &l, const T &r) { return max(l, r); }
};

int f(int ub, vector<int> a, vector<int> b) {
	int N = a.size();
	segtree<RMQ> st(100001);
	int ans = -INF;
	rep(i, N) {
		if (a[i] <= ub) ans = max(ans, b[i] + st.get(0, ub - a[i] + 1));
		int x = st.get(a[i], a[i] + 1);
		st.set(a[i], max(x, b[i]));
	}
	return ans;
}

int main() {
	int N, ub1, ub2; cin >> N >> ub1 >> ub2;
	vector<int> a1, b1, a2, b2;
	rep(i, N) {
		int x, y; char c;
		scanf("%d %d %c", &y, &x, &c);
		if (c == 'C') a1.pb(x), b1.pb(y);
		if (c == 'D') a2.pb(x), b2.pb(y);
	}
	int ans = 0;
	ans = max(ans, f(ub1, a1, b1));
	ans = max(ans, f(ub2, a2, b2));
	int ma1 = -INF, ma2 = -INF;
	rep(i, a1.size()) if (a1[i] <= ub1) ma1 = max(ma1, b1[i]);
	rep(i, a2.size()) if (a2[i] <= ub2) ma2 = max(ma2, b2[i]);
	ans = max(ans, ma1 + ma2);
	cout << ans << endl;
}