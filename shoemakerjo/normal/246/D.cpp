#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<set<int>> adj;
	bool seen[100001];
	for (int i = 0; i <= 100000; i++) {
		set<int> b;
		adj.push_back(b);
		seen[i] = false;
	}
	int colors[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> colors[i];
		seen[colors[i]] = true;
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (colors[a] == colors[b]) continue;
		adj[colors[a]].insert(colors[b]);
		adj[colors[b]].insert(colors[a]);
	}
	int ans = -1;
	int most = -1;
	for (int i = 1; i <= 100000; i++) {
		if (!seen[i]) continue;
		// cout << "i:   " << i << endl;
		int si = adj[i].size();
		if (si > most) {
			most = si;
			ans = i;
		}
		// cout << si<<  " " << most << endl;
	}
	cout << ans << endl;
	cin >> ans;
}