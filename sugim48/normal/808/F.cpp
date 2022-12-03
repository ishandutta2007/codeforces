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
struct edge { int src, dst; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-9;
ll INF = LLONG_MAX / 2;

struct flow_network {
	int n;
	struct edge { int v; ll c; int rev; };
	vector< vector<edge> > G;
	flow_network(int _n) : n(_n), G(_n) {}
	void add_edge(int u, int v, ll c) {
		edge e = {v, c, G[v].size()}, _e = {u, 0, G[u].size()};
		G[u].push_back(e); G[v].push_back(_e);
	}
	ll dfs(int u, int t, ll f, vector<bool>& vis) {
		if (u == t) return f;
		vis[u] = true;
		for (int i = 0; i < G[u].size(); i++) {
			edge& e = G[u][i];
			if (vis[e.v] || e.c == 0) continue;
			ll d = min(e.c, dfs(e.v, t, min(f, e.c), vis));
			if (d == 0) continue;
			e.c -= d;
			G[e.v][e.rev].c += d;
			return d;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		ll res = 0;
		for (;;) {
			vector<bool> vis(n);
			ll f = dfs(s, t, LLONG_MAX, vis);
			if (f == 0) return res;
			res += f;
		}
	}
};

int main() {
	vector<bool> prime(200001, true);
	for (int x = 2; x <= 200000; x++)
		if (prime[x])
			for (int y = x * 2; y <= 200000; y += x)
				prime[y] = false;
	int N, P; cin >> N >> P;
	vector<int> p(N), c(N), l(N);
	rep(i, N) cin >> p[i] >> c[i] >> l[i];
	vector<int> ve, vo;
	rep(i, N) {
		if (c[i] % 2 == 0) ve.pb(i);
		else vo.pb(i);
	}
	int E = ve.size(), O = vo.size();
	vector<vector<bool> > a(E, vector<bool>(O));
	rep(ie, E) rep(io, O) {
		int x = c[ve[ie]] + c[vo[io]];
		a[ie][io] = prime[x];
	}
	int i1 = -1;
	rep(i, N) if (c[i] == 1)
		if (i1 == -1 || p[i] > p[i1]) i1 = i;
	rep(i, N) if (c[i] == 1)
		if (i != i1) p[i] = 0;
	int lb = 0, ub = N + 1;
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		int _P = 0;
		flow_network fn(E + O + 2);
		int s = E + O, t = E + O + 1;
		rep(ie, E) {
			int i = ve[ie];
			if (l[i] <= mid) {
				_P += p[i];
				fn.add_edge(s, ie, p[i]);
			}
		}
		rep(io, O) {
			int i = vo[io];
			if (l[i] <= mid) {
				_P += p[i];
				fn.add_edge(E + io, t, p[i]);
			}
		}
		rep(ie, E) rep(io, O) if (a[ie][io])
			fn.add_edge(ie, E + io, INT_MAX);
		ll f = fn.max_flow(s, t);
		if (_P - f >= P) ub = mid;
		else lb = mid;
	}
	int ans = ub;
	if (ans == N + 1) ans = -1;
	cout << ans << endl;
}