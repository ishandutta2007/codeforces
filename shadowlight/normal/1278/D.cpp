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
	vector <int> p, r;
	int n;
	DSU(int n) : p(n, 0), r(n, 0), n(n) {
		iota(p.begin(), p.end(), 0);
	}
	int get(int v) {
		return (p[v] == v ? v : p[v] = get(p[v]));
	}
	bool unite(int v, int u) {
		v = get(v);
		u = get(u);
		if (v == u) return false;
		if (r[v] > r[u]) swap(v, u);
		if (r[v] == r[u]) r[u]++;
		p[v] = u;
		return true;
	}
};

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> st;
	vector <bool> was(n, false);
	vector <pair <int, int> > a;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		a.push_back({l, i});
		a.push_back({r, i});
	}
	DSU dsu(n);
	int edges = 0;
	sort(a.begin(), a.end());
	for (auto t : a) {
		if (!was[t.second]) {
			st.push_back(t.second);
			was[t.second] = true; 
		} else {
			vector <int> pops;
			int v = t.second;
			while (st.back() != v) {
				int x = st.back();
				st.pop_back();
				//cout << v << " " << x << "\n";
				if (!dsu.unite(v, x)) {
					cout << "NO\n";
					return 0;
				}
				edges++;
				pops.push_back(x);
			}
			st.pop_back();
			while (pops.size()) {
				st.push_back(pops.back());
				pops.pop_back();
			}
		}
	}
	if (edges == n - 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}