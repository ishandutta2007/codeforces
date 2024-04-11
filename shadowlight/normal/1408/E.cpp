	#include <bits/stdc++.h>
	#define ll long long
	#define db long double
	#define x first
	#define y second
	#define mp make_pair
	#define pb push_back
	#define all(a) a.begin(), a.end()

	using namespace std;

	struct DSU {
		int n;
		vector <int> r, p;
		DSU(int n) : r(n, 0), p(n) {
			iota(all(p), 0);
		}
		int get(int v) {
			return (p[v] == v ? v : p[v] = get(p[v]));
		}
		bool uni(int v, int u) {
			v = get(v);
			u = get(u);
			if (v == u) {
				return false;
			}
			if (r[v] == r[u]) ++r[u];
			if (r[v] > r[u]) swap(v, u);
			p[v] = u;
			return true;
		}
	};

	int main(){
	#ifdef LOCAL
		freopen("E_input.txt", "r", stdin);
		//freopen("E_output.txt", "w", stdout);
	#endif
		ios_base::sync_with_stdio(0);
		cin.tie(0);

		int m, n;
		cin >> m >> n;

		vector <int> a(m), b(n);

		for (int i = 0; i < m; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}

		ll sum = 0;

		vector <pair <int, pair <int, int>>> edges;

		for (int i = 0; i < m; ++i) {
			int s;
			cin >> s;
			for (int j = 0; j < s; ++j) {
				int x;
				cin >> x;
				--x;
				sum += a[i] + b[x];
				edges.pb({a[i] + b[x], {i, m + x}});
			}
		}

		DSU dsu(n + m);

		sort(all(edges));
		reverse(all(edges));

		for (auto e : edges) {
			int v = e.y.x, u = e.y.y;
			//cout << v << " " << u << endl;
			if (dsu.uni(v, u)) {
				sum -= a[v] + b[u - m];
				//cout << v << " " << u << endl;
				//cout << a[v] << " " << b[u - n] << "\n";
			}
		}
		cout << sum << "\n";
	}