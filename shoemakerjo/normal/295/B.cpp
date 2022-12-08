#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	int n;
	cin >> n;
	ll adj[n][n];
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}
	vector<int> rem;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		rem.push_back(cur-1);
	}
	ll dist[n][n];
	for (int i = 0; i  < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = adj[i][j];
		}
	}
	vector<int> active;
	vector<ll> anses;
	for (int i = n-1; i >= 0; i--) {
		int v = rem[i];
		
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (dist[j][v] + dist[v][k] < dist[j][k]) {
					dist[j][k] = dist[j][v] + dist[v][k];
				}
			}
		}
		
		ll ans = 0;
		active.push_back(v);
		for (int j = 0; j < active.size(); j++) {
			for (int k = 0; k < active.size(); k++) {
				ans += dist[active[j]][active[k]];
				// cout << "d:  " << active[j] << " " << active[k] << " " 
				// 	<< dist[active[j]][active[k]] <<endl;
			}
		}
		anses.push_back(ans);
	}
	for (int i = anses.size()-1; i >= 0; i--) {
		cout << anses[i];
		if (i > 0) cout << " ";
		
	}
	cout << endl;
	// cin >> n;
}