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
	int n, m; cin >> n >> m;
	vector<int> a(n), b(n);
	int A = 0, B = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		A += a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		B += b[i];
	}
	if (A != B) {
		cout << "NO" << endl;
		return 0;
	}
	flow_network fn(n * 2 + 2);
	int s = n * 2, t = n * 2 + 1;
	for (int i = 0; i < n; i++) {
		fn.add_edge(s, i, a[i]);
		fn.add_edge(i, n + i, 100);
		fn.add_edge(n + i, t, b[i]);
	}
	while (m--) {
		int u, v; cin >> u >> v;
		u--; v--;
		fn.add_edge(u, n + v, 100);
		fn.add_edge(v, n + u, 100);
	}
	int f = fn.max_flow(s, t);
	if (f < B) {
		cout << "NO" << endl;
		return 0;
	}
	vector<vector<int> > c(n, vector<int>(n));
	for (int u = 0; u < n; u++)
		for (int k = 0; k < fn.G[u].size(); k++) {
			flow_network::edge e = fn.G[u][k];
			int v = e.v - n;
			if (0 <= v && v < n)
				c[u][v] += 100 - e.c;
		}
	cout << "YES" << endl;
	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++)
			cout << c[u][v] << ' ';
		cout << endl;
	}
}