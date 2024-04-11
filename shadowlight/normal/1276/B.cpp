#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <vector <int> > gr;
int n, m, a, b;
vector <int> ea, eb;

vector <int> c;
vector <int> sz;

void dfs(int v, int cnow) {
	if (c[v]) return;
	c[v] = cnow;
	sz.back()++;
	for (int u : gr[v]) {
		dfs(u, cnow);
	}
}

void solve() {
	cin >> n >> m >> a >> b;
	a--, b--;
	gr.clear();
	gr.resize(n);
	ea.clear();
	eb.clear();
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		bool bad = false;
		if (v == a || u == a) {
			ea.push_back(v + u - a);
			bad = true;
		}
		if (v == b || u == b) {
			eb.push_back(v + u - b);
			bad = true;
		}
		if (!bad) {
			gr[v].push_back(u);
			gr[u].push_back(v);
		}
	}
	c.assign(n, 0);
	sz.clear();
	int now = 1;
	for (int v = 0; v < n; v++) {
		if (c[v] || v == a || v == b) continue;
		sz.push_back(0);
		dfs(v, now++);
	}
	vector <bool> cana(now, 0), canb(now, 0);
	for (int v : ea) {
		cana[c[v]] = true;
	}
	for (int v : eb) {
		canb[c[v]] = true;
	}
	int cnta = 0, cntb = 0;
	for (int i = 1; i < now; i++) {
		if (cana[i] && canb[i]) continue;
		if (cana[i]) {
			cnta += sz[i - 1];
		}
		if (canb[i]) {
			cntb += sz[i - 1];
		}
	}
	cout << cnta * (ll) cntb << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

}