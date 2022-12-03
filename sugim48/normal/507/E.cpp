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
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

void dijkstra_deque(int n, vector< vector<edge> >& G, int s, vector<int>& d, vector<int>& prev) {
	vector<bool> vis(n, false);
	fill(d.begin(), d.end(), INT_MAX); d[s] = 0;
	deque<ll> deq; deq.push_back(s);
	while (!deq.empty()) {
		int u = deq.front(); deq.pop_front();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = 0; i < G[u].size(); i++) {
			edge e = G[u][i];
			if (d[e.v] > d[u] + e.w) {
				d[e.v] = d[u] + e.w;
				prev[e.v] = u;
				if (e.w == 0) deq.push_front(e.v);
				else deq.push_back(e.v);
			}
		}
	}
}

void add_edge(vector< vector<edge> >& G, int u, int v, int w) {
	edge e = {v, w};
	G[u].push_back(e);
}

int main() {
	int n, m; cin >> n >> m;
	vector< vector<edge> > G(n);
	vector<int> x(m), y(m), z(m);
	int sum = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
		x[i]--; y[i]--;
		add_edge(G, x[i], y[i], 1);
		add_edge(G, y[i], x[i], 1);
		sum += z[i];
	}
	vector<int> D(n), Prev(n);
	dijkstra_deque(n, G, 0, D, Prev);
	vector< vector<edge> > g(n);
	for (int i = 0; i < m; i++) {
		if (D[x[i]] - D[y[i]] == 1)
			add_edge(g, x[i], y[i], 1 - z[i]);
		if (D[y[i]] - D[x[i]] == 1)
			add_edge(g, y[i], x[i], 1 - z[i]);
	}
	vector<int> d(n), prev(n);
	dijkstra_deque(n, g, n - 1, d, prev);
	set<i_i> used;
	for (int u = 0; u != n - 1; u = prev[u]) {
		used.insert(i_i(u, prev[u]));
		used.insert(i_i(prev[u], u));
	}
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		int f = used.count(i_i(x[i], y[i]));
		if (z[i] ^ f) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (int j = 0; j < ans.size(); j++) {
		int i = ans[j];
		printf("%d %d %d\n", x[i] + 1, y[i] + 1, 1 - z[i]);
	}
}