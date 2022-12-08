#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int conn[n+1];
	for (int i = 0; i <= n; i++) {
		conn[i] = (1 << i);
	}
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--;
		v--;
		conn[u] |= (1 << v);
		conn[v] |= (1 << u);
	}
	int tot = (1 << n) - 1;
	bool isconn[tot+1];
	for (int i = 0; i < tot; i++) {
		isconn[i] = false;
	}
	for (int i = 0; i < n; i++) {
		isconn[1 << i] = true;
	}
	int ans = n;
	int cspot = tot;
	vector<int> va;
	for (int i = 0; i < n; i++) {
		va.push_back(i+1);
	}
	int neigh[tot];
	for (int i = 0; i < tot; i++) {
		neigh[i] = 0;
		if (!isconn[i]) {
			continue;
		}
		int ct = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				neigh[i] |= conn[j];
				ct++;
			}
		}
		for (int j = 0; j < n; j++) {
			if (neigh[i] & (1 << j)) {
				isconn[i | (1 << j)] = true;
			}
		}
		if (neigh[i] == tot) {
			if (ct < ans) {
				ans = ct;
				cspot = i;
				// cout << "SIZE  " << va.size() << endl;
			}
		}
	}
	// cout << "here   " << va.size() << endl;
	if (m == (n*(n-1))/2) {
		cout << 0 << endl;
	}
	else {
		cout << ans << endl;
		for (int i = 0; i < n; i++) {
			if (cspot & (1 << i)) {
				cout << i+1 << " ";
			}
		}
		cout << endl;
	}
	
	cin >> ans;
}