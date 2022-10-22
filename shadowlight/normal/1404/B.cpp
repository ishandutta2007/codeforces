#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <vector <int> > gr;

int dfs(int v, int t, int p) {
	if (v == t) return 0;
	for (int u : gr[v]) {
		if (u == p) continue;
		int x = dfs(u, t, v);
		if (x != -1) {
			return x + 1; 
		}
	}
	return -1;
}

int res = 0, t = -1;

int get_diam(int v, int p, int h) {
	if (h > res) {
		res = h;
		t = v;
	}
	for (int u : gr[v]) {
		if (u == p) continue;
		get_diam(u, v, h + 1);
	}
}

void solve() {
	int n;
	cin >> n;
	int a, b, da, db;
	cin >> a >> b >> da >> db;
	--a, --b;
	gr.assign(n, {});
	for (int i = 1; i < n; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		gr[v].pb(u);
		gr[u].pb(v);
	}
	res = -1, t = -1;
	get_diam(a, -1, 0);
	res = -1;
	get_diam(t, -1, 0);
	if (2 * da >= db || dfs(a, b, -1) <= da || res <= 2 * da) {
		cout << "Alice\n";
		return;
	}
	cout << "Bob\n";
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
	for (int i = 0; i < t; ++i) {
		solve();
	}

}