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
int INF = INT_MAX / 2;

template <class Monoid>
struct segtree {
	using T = typename Monoid::T;
	int N;
	T *a;
	segtree(int _N = 0) {
		if (!_N) return;
		N = _N;
		a = new T[N * 2];
		rep(i, N * 2) a[i] = Monoid::id();
	}
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

struct monoid {
	using T = double;
	static T id() { return 1; }
	static T op(const T &l, const T &r) { return l * r; }
};
typedef segtree<monoid> ST;

int main() {
	int Q; cin >> Q;
	vector<int> t(Q), u(Q);
	rep(k, Q) scanf("%d%d", &t[k], &u[k]), u[k]--;
	int N = 1;
	rep(k, Q) if (t[k] == 1) N++;
	vector<int> par(N); par[0] = -1;
	vector<int> id(N); id[0] = -1;
	vector<vector<int> > G(N);
	int v = 1;
	rep(k, Q) if (t[k] == 1) {
		par[v] = u[k];
		id[v] = G[u[k]].size();
		G[u[k]].pb(v);
		v++;
	}
	vector<int> d(N);
	rep(u, N) d[u] = G[u].size();
	vector<ST> st(N);
	rep(u, N) st[u] = ST(d[u] * 50);
	int v0 = 1;
	rep(k, Q) {
		if (t[k] == 1) {
			int v = v0;
			rep(h, 50) {
				int p = par[v], i = id[v];
				if (p == -1) break;
				if (!h) st[p].set(i, 0.5);
				else st[p].set(h * d[p] + i, 0.5 + 0.5 * st[v].get((h - 1) * d[v], h * d[v]));
				v = p;
			}
			v0++;
		}
		if (t[k] == 2) {
			int v = u[k];
			double ans = 0;
			rep(h, 49) {
				double p = st[v].get((h + 1) * d[v], (h + 2) * d[v]) - st[v].get(h * d[v], (h + 1) * d[v]);
				ans += p * (h + 1);
			}
			printf("%.10f\n", ans);
		}
	}
}