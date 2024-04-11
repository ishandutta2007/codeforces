#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, m;
vector <vector<int>> gr;

void solve() {
	gr.clear();
	cin >> n >> m;
	gr.resize(n);
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		gr[v].pb(u);
		gr[u].pb(v);
	}

	vector <bool> ban(n, false);
	vector <bool> used(n, false);
	queue <int> q;
	q.push(0);
	vector <int> res;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		bool was_banned = ban[v];
		if (!was_banned) {
			res.pb(v);
		}
		ban[v] = true;
		
		for (int u : gr[v]) {
			if (was_banned && !ban[u] && !used[u]) {
				used[u] = true;
				q.push(u);
			} else if (!was_banned) {
				ban[u] = true;
				if (!used[u]) {
					q.push(u);
					used[u] = true;
				}
			}
		}
	}
	bool good = true;
	for (int i = 0; i < n; ++i) {
		good &= (ban[i]);
	}
	if (!good) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << res.size() << "\n";
		sort(all(res));
		for (int x : res) {
			cout << x + 1 << " ";
		}
		cout << "\n";
	}
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}