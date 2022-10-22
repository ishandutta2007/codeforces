#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Rollback {
	int v;
	int p;
	int r;
	int c;
};

vector<Rollback> rb;

struct DSU {
	int n;
	vector <int> p, r;
	vector <int> c;
	
	DSU(int n) : n(n), p(n), r(n, 0), c(n, 0) {
		iota(all(p), 0);
	}

	int get(int v, int &cn) {
		if (cn != -1) {
			cn ^= c[v];
			if (c[v] == -1) {
				cn = -1;
			}
		}
		return (p[v] == v ? v : get(p[v], cn));
	}

	void uni(int v, int u) {
		int cv = 0, cu = 0;
		v = get(v, cv);
		u = get(u, cu);

		rb.pb({v, p[v], r[v], c[v]});
		rb.pb({u, p[u], r[u], c[u]});
		
		if (v == u) {
			if (cv == -1 || cu == -1 || cv == cu) {
				c[u] = -1;
			}
			return;
		}

		//cout << cv << " " << cu << "\n";

		if (r[v] == r[u]) ++r[u];
		if (r[v] > r[u]) swap(v, u);
		p[v] = u;
		if (cv == cu && c[v] != -1) {
			c[v] ^= 1;		
		}
		if (cv == -1 || cu == -1) {
			c[u] = -1;
		}
	}
};

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector <int> c(n);
	set <int> groups;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		--c[i];
	}

	DSU dsu(n);

	map <pair <int, int>, vector<pair<int, int>>> edges;

	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		if (c[v] == c[u]) {
			dsu.uni(v, u);
		} else {
			if (c[v] > c[u]) {
				swap(v, u);
			}
			edges[{c[v], c[u]}].pb({v, u});
		}
	}
	rb.clear();
	
	vector <bool> good(k, true);
	for (int i = 0; i < n; ++i) {
		int ci = 0;
		dsu.get(i, ci);
		if (ci == -1) {
			good[c[i]] = false;
		}
	}

	int good_cnt = 0;
	for (int i = 0; i < k; ++i) {
		good_cnt += good[i];
	}

	ll cnt = good_cnt * (ll) (good_cnt - 1) / 2;
	//cout << good_cnt << "\n";

	for (auto &t : edges) {
		int c1 = t.x.x, c2 = t.x.y;
		//cout << c1 << " " << c2 << "\n";
		if (good[c1] && good[c2]) {
			--cnt;
		} else {
			continue;
		}
		int c = 0;
		int p = -1;
		for (auto e : t.y) {
			//cout << "EDGE: " << e.x << " " << e.y << "\n";
			dsu.uni(e.x, e.y);

			int cc = 0;
			dsu.get(e.x, cc);
			if (cc == -1) {
				c = -1;
			}
			p = e.x;
		}
		if (c != -1) {
			//cout << "GOOD\n";
			++cnt;
		}
		while (rb.size()) {
			auto t = rb.back();
			rb.pop_back();
			dsu.p[t.v] = t.p;
			dsu.r[t.v] = t.r;
			dsu.c[t.v] = t.c;
		}
	}

	cout << cnt << "\n";
}