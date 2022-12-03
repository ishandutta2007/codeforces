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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

#define rep(i, N) for (int i = 0; i < N; i++)

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

ll kruskal(int n, vector<edge>& E) {
	sort(E.begin(), E.end(), kr_cmp);
	union_find uf(n);
	ll res = 0;
	for (int i = 0; i < E.size(); i++) {
		edge e = E[i];
		if (uf.same(e.u, e.v)) continue;
		uf.unite(e.u, e.v);
		res += e.w;
	}
	return res;
}

int main() {
	int N, M; cin >> N >> M;
	vector<ll> w(M), c(M);
	rep(i, M) scanf("%lld", &w[i]);
	rep(i, M) scanf("%lld", &c[i]);
	vector<int> a(M), b(M);
	rep(i, M) {
		scanf("%d%d", &a[i], &b[i]);
		a[i]--; b[i]--;
	}
	ll S; cin >> S;
	vector<edge> E(M);
	rep(i, M) E[i] = edge{a[i], b[i], w[i]};
	ll ori = kruskal(N, E);
	vector<ll_i> unko(M);
	rep(i, M) unko[i] = ll_i(w[i], i);
	sort(unko.begin(), unko.end());
	vector<ll> lb(M, -1), ub(M, M - 1);
	rep(t, 20) {
		vector<int> mid(M);
		vector<vector<int> > v(M);
		rep(i, M) {
			mid[i] = (lb[i] + ub[i]) / 2;
			v[mid[i]].push_back(i);
		}
		union_find uf(N);
		rep(k, M) {
			int i = unko[k].second;
			uf.unite(a[i], b[i]);
			for (int i: v[k]) {
				if (uf.same(a[i], b[i])) ub[i] = mid[i];
				else lb[i] = mid[i];
			}
		}
	}
	vector<ll> ans(M);
	ll mi = LLONG_MAX;
	rep(i, M) {
		ans[i] = ori - unko[ub[i]].first + w[i];
		ans[i] -= S / c[i];
		mi = min(mi, ans[i]);
	}
	cout << mi << endl;
	rep(i, M) {
		if (ans[i] > mi) continue;
		union_find uf(N);
		rep(k, M) {
			int j = unko[k].second;
			if (uf.same(a[j], b[j])) continue;
			uf.unite(a[j], b[j]);
			if (j == unko[ub[i]].second)
				printf("%d %lld\n", i + 1, w[i] - S / c[i]);
			else
				printf("%d %lld\n", j + 1, w[j]);
		}
		break;
	}
}