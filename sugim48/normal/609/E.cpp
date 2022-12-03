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
#include <random>
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
struct edge { int u, v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (-v[x] < -v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
	}
	bool root(int x) { return v[x] < 0; }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

bool kr_cmp(const edge& l, const edge& r) { return l.w < r.w; }

ll kruskal(int N, vector<edge>& E) {
	sort(E.begin(), E.end(), kr_cmp);
	union_find uf(N);
	ll sum = 0;
	for (edge e: E)
		if (!uf.same(e.u, e.v)) {
			uf.unite(e.u, e.v);
			sum += e.w;
		}
	return sum;
}

int main() {
	int N, M; cin >> N >> M;
	vector<edge> E(M);
	for (int i = 0; i < M; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		E[i] = edge{u - 1, v - 1, w};
	}
	vector<edge> _E = E;
	ll x = kruskal(N, _E);
	vector<int> lb(M, 0), ub(M, M);
	for (int t = 0; t < 20; t++) {
		vector<i_i> p(M);
		for (int i = 0; i < M; i++) {
			int mid = (lb[i] + ub[i]) / 2;
			p[i] = i_i(mid, i);
		}
		sort(p.begin(), p.end());
		int k = 0;
		union_find uf(N);
		for (int i = 0; i < M; i++) {
			for (; k < M && p[k].first <= i; k++) {
				int j = p[k].second;
				if (uf.same(E[j].u, E[j].v)) ub[j] = i;
				else lb[j] = i;
			}
			uf.unite(_E[i].u, _E[i].v);
		}
	}
	for (int i = 0; i < M; i++)
		printf("%lld\n", x + E[i].w - _E[lb[i]].w);
}