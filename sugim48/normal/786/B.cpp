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
struct edge { int v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int n;
vector<edge> G[500000];

vector<ll> dijkstra(int N, vector<edge> G[], int s) {
	vector<ll> d(N, LLONG_MAX); d[s] = 0;
	priority_queue<ll_i, vector<ll_i>, greater<ll_i> > pq;
	pq.push(ll_i(0, s));
	while (pq.size()) {
		ll_i p = pq.top(); pq.pop();
		int u = p.second;
		if (p.first > d[u]) continue;
		for (edge e: G[u])
			if (d[e.v] > d[u] + e.w) {
				d[e.v] = d[u] + e.w;
				pq.push(ll_i(d[e.v], e.v));
			}
	}
	return d;
}

struct segtree {
	segtree *lch, *rch;
	int l, r, u, v;
	segtree(int _l, int _r) : l(_l), r(_r) {
		u = n++; v = n++;
		for (int x = l; x < r; x++) {
			G[u].pb(edge{x, 0});
			G[x].pb(edge{v, 0});
		}
		if (r - l == 1) return;
		int m = (l + r) / 2;
		lch = new segtree(l, m);
		rch = new segtree(m, r);
	}
	void add_edge(int q, int s, int w, int _l, int _r) {
		if (r <= _l || _r <= l) return;
		if (_l <= l && r <= _r) {
			if (q == 2) G[s].pb(edge{u, w});
			if (q == 3) G[v].pb(edge{s, w});
			return;
		}
		lch->add_edge(q, s, w, _l, _r);
		rch->add_edge(q, s, w, _l, _r);
	}
};

int main() {
	int N, M, s; cin >> N >> M >> s; s--;
	n = N;
	segtree* st = new segtree(0, N);
	while (M--) {
		int q; scanf("%d", &q);
		if (q == 1) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w); u--; v--;
			G[u].pb(edge{v, w});
		}
		if (q == 2 || q == 3) {
			int u, l, r, w; scanf("%d%d%d%d", &u, &l, &r, &w); u--; l--;
			st->add_edge(q, u, w, l, r);
		}
	}
	vector<ll> d = dijkstra(n, G, s);
	rep(u, N) printf("%lld ", d[u] < LLONG_MAX ? d[u] : -1);
	cout << endl;
}