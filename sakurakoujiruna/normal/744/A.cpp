#include <bits/stdc++.h>
using namespace std;

const int N = 1011;

struct DSU {
	int p[N];
	int sz[N];
	void init() {
		iota(p, p + N, 0);
		fill(sz, sz + N, 1);
	}
	int find(int x) {
		if(p[x] == x) return x;
		return p[x] = find(p[x]);
	}
	bool query(int a, int b) {
		return find(a) == find(b);
	}
	void merge(int a, int b) {
		int pa = find(a);
		int pb = find(b);
		p[pb] = pa;
		sz[pa] += sz[pb];
	}
}dsu;

int sp[N];

int main() {
	ios :: sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;
	for(int i = 1; i <= k; i ++)
		cin >> sp[i];

	dsu.init();
	for(int i = 1; i <= m; i ++) {
		int u, v; cin >> u >> v;
		if(!dsu.query(u, v))
			dsu.merge(u, v);
	}

	int ans = 0;
	int used = 0;
	int mx = 0;
	for(int i = 1; i <= k; i ++) {
		int s = dsu.sz[dsu.find(sp[i])];
		//cout << s << '\n';
		ans += s * (s - 1) / 2;
		mx = max(mx, s);
		used += s;
	}
	ans += (n - used) * (n - used - 1) / 2;
	ans += mx * (n - used);

	cout << ans - m << '\n';
	return 0;
}