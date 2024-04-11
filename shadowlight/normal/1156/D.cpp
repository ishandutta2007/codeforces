#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct DSU {
	int n;
	vector <int> p, r;

	DSU(int n) : n(n), p(n, 0), r(n, 0) {
		iota(p.begin(), p.end(), 0);
	}

	int get(int v) {
		return (p[v] == v ? v : p[v] = get(p[v]));
	}

	void uni(int v, int u) {
		v = get(v);
		u = get(u);
		if (v == u) return;
		if (r[v] == r[u]) r[u]++;
		if (r[v] > r[u]) swap(v, u);
		p[v] = u;
	}
};

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	DSU a(n), b(n);
	for (int i = 1; i < n; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		v--, u--;
		if (w) {
			b.uni(v, u);
		} else {
			a.uni(v, u);
		}
	}
	map <int, vector <int> > sa;
	map <int, vector <int> > sb;

	for (int i = 0; i < n; i++) {
		sa[a.get(i)].push_back(i);
		sb[b.get(i)].push_back(i);
	}

	ll res = 0;
	for (auto t : sa) {
		auto &mas = t.second;
		ll sza = mas.size();
		ll now = 0;
		for (int v : mas) {
			now += sb[b.get(v)].size() - 1;
		}
		res += sza * (sza - 1);
		res += sza * now;
	}
	cout << res << "\n";
}