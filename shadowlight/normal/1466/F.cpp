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
	vector <int> good;
	DSU(int n) : n(n), r(n, 0), p(n, 0), good(n, 0) {
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
		if (good[v] && good[u]) {
			return false;
		}
		if (r[v] == r[u]) ++r[u];
		if (r[v] > r[u]) swap(v, u);
		p[v] = u;
		good[u] = max(good[v], good[u]);
		return true;
	}
};

const int MOD = 1e9 + 7;

int power(int a, int k) {
	if (!k) {
		return 1;
	}
	int b = power(a, k / 2);
	b = b * (ll) b % MOD;
	if (k % 2) {
		return a * (ll) b % MOD;
	} else {
		return b;
	}
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	DSU dsu(m);
	vector <int> res;

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (k == 1) {
			int x;
			cin >> x;
			--x;
			if (dsu.good[dsu.get(x)]) {
				continue;
			}
			res.pb(i);
			dsu.good[dsu.get(x)] = 1;
		} else {
			int x, y;
			cin >> x >> y;
			--x, --y;
			//cout << x << " " << y << endl;
			if (!dsu.uni(x, y)) continue;
			res.pb(i);
		}
	}

	map <int, int> sizes;
	for (int i = 0; i < m; ++i) {
		int v = dsu.get(i);
		++sizes[v];
	}

	int resq = 1;

	for (int i = 0; i < m; ++i) {
		if (sizes.count(i)) {
			int good = dsu.good[i];
			resq = resq* (ll) power(2, sizes[i] - (!good)) % MOD;
		}
	}

	cout << resq << " " << res.size() << "\n";
	for (int x : res) {
		cout << x + 1 << " ";
	}
	cout << "\n";
}