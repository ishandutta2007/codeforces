#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;

struct edge { int u, v, w; };

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

ll kruskal(int N, vector<edge> E) {
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

int naive(int N) {
	vector<edge> E;
	rep(u, N) for (int v = u + 1; v < N; v++)
		E.pb({u, v, u ^ v});
	return kruskal(N, E);
}

ll solve(ll N) {
	ll ans = 0;
	for (ll x = 1; N > 1; N = (N + 1) / 2, x *= 2) ans += N / 2 * x;
	return ans;
}

int main() {
	/*
	for (int N = 1; ; N++) {
		cout << N << endl;
		if (solve(N) != naive(N)) {
			cout << "ERR" << endl;
			return 0;
		}
	}
	*/
	ll N; cin >> N;
	cout << solve(N) << endl;
}