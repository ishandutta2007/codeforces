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
#include <unordered_map>
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

ll extgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = (a >= 0) ? 1 : -1;
		y = 0;
		return abs(a);
	}
	else {
		ll res = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return res;
	}
}

ll mod_inverse(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

vector<ll> dijkstra(int n, vector<vector<edge> >& G, int s) {
	vector<ll> d(n, LLONG_MAX / 10); d[s] = 0;
	priority_queue<ll_i, vector<ll_i>, greater<ll_i> > q;
	q.push(ll_i(0, s));
	while (!q.empty()) {
		ll_i p = q.top(); q.pop();
		int u = p.second;
		if (p.first > d[u]) continue;
		for (int i = 0; i < G[u].size(); i++) {
			edge e = G[u][i];
			if (d[e.v] > d[u] + e.w) {
				d[e.v] = d[u] + e.w;
				q.push(ll_i(d[e.v], e.v));
			}
		}
	}
	return d;
}

vector<ll> _dijkstra(int n, vector<vector<edge> >& G, int s) {
	vector<ll> d(n, LLONG_MAX / 10); d[s] = 0;
	vector<ll> x(n); x[s] = 1;
	priority_queue<ll_i, vector<ll_i>, greater<ll_i> > q;
	q.push(ll_i(0, s));
	while (!q.empty()) {
		ll_i p = q.top(); q.pop();
		int u = p.second;
		if (p.first > d[u]) continue;
		for (int i = 0; i < G[u].size(); i++) {
			edge e = G[u][i];
			if (d[e.v] > d[u] + e.w) {
				d[e.v] = d[u] + e.w;
				q.push(ll_i(d[e.v], e.v));
			}
			x[e.v] = (x[e.v] + x[u] * mod_inverse(G[u].size(), MOD)) % MOD;
		}
	}
	return x;
}

int main() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s--; t--;
	vector<int> a(m), b(m), l(m);
	vector<vector<edge> > G(n), _G(n);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a[i], &b[i], &l[i]);
		a[i]--; b[i]--;
		G[a[i]].push_back(edge{b[i], l[i]});
		_G[b[i]].push_back(edge{a[i], l[i]});
	}
	vector<ll> d = dijkstra(n, G, s), _d = dijkstra(n, _G, t);
	ll D = d[t];
	vector<vector<edge> > g(n);
	for (int i = 0; i < m; i++)
		if (d[a[i]] + _d[b[i]] + l[i] == D)
			g[a[i]].push_back(edge{b[i], l[i]});
	vector<ll> x = _dijkstra(n, g, s);
	for (int i = 0; i < m; i++)
		if (g[a[i]].size() == 1 && d[a[i]] + _d[b[i]] + l[i] == D && x[a[i]] == 1 && x[b[i]] == 1)
			printf("YES\n");
		else if (d[a[i]] + _d[b[i]] + 1 >= D)
			printf("NO\n");
		else
			printf("CAN %I64d\n", (d[a[i]] + _d[b[i]] + l[i]) - (D - 1));
}