#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <vector<int>> gr;

int dd = 0, edges = 0;
vector <bool> used;

void dfs(int v) {
	if (used[v]) return;
	used[v] = true;
	edges += gr[v].size();
	++dd;
	for (int u : gr[v]) {
		dfs(u);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	gr.clear();
	gr.resize(n);

	int cnt = 0;

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		if (x == y) continue;
		gr[x].pb(y);
		gr[y].pb(x);
		++cnt;
	}

	used.assign(n, false);
	for (int i = 0; i < n; ++i) {
		if (used[i]) continue;
		dd = 0, edges = 0;
		dfs(i);
		//cout << dd << " " << edges << "\n";
		if (2 * dd == edges) {
			++cnt;
		}
	}
	
	cout << cnt << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}