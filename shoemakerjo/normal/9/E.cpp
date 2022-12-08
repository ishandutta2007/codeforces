#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define maxn 52

vector<vector<int>> adj(maxn);
vector<pii> edges;
int par[maxn];

int findset(int x) {
	// cout << "x   " << x << endl;
	if (par[x] == x) return x;
	return par[x] = findset(par[x]);
}

void unionset(int x, int y) {
	// cout << "here  " << endl;
	x = findset(x);
	// cout << " x  " << x << " - " << y << endl;
	y = findset(y);
	// cout << y << endl;
	if (x != y) par[x] = y; //who cares about union by rank. it is so small anyway
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		unionset(x, y);
	}
	// for (int i = 1; i <= n; i++) { //this is just debuggin
	// 	cout << i << " " << findset(i) << endl;
	// }


	bool bad = false;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() > 2) bad = true;
	}
	if (bad) {
		cout << "NO" << endl;
		return 0;
	}
	
	bool fin = true;
	if (n != m) fin = false;
	for(int i = 2; i <= n; i++) {
		if (findset(i) != findset(1)) fin = false;
	}
	if (fin) {
		cout << "YES" << endl;
		cout << 0 << endl; //no work to be done
		return 0; //why not just exit
	}
	

	//time to check for cycle

	if(n == 1) {
		cout << "YES" << endl;
		cout << 1 << endl << 1 << " " << 1 << endl;
		return 0; //special case of self loop
	}
	multiset<int> pendants;
	vector<pii> ans;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			pendants.insert(i); //keep connecting pendants

		}
		if (adj[i].size() == 0) {
			pendants.insert(i);
			pendants.insert(i);
		}
	}
	while (pendants.size() > 0) {
		int u = *pendants.begin();
		pendants.erase(pendants.begin());
		if (pendants.size() == 1) {
			auto it = pendants.begin();
			int v = *it;
			pendants.erase(it);
			ans.push_back(pii(u, v));
			break;

		}
		auto it = pendants.begin();
		while (findset(u) == findset(*it)) {
			++it;
		}
		int v = *it;
		pendants.erase(it);
		// cout << "u   " << u << " " << v << endl;
		ans.push_back(pii(u, v));
		unionset(u, v);
	}
	bool ok = true;
	for (int i = 2; i <= n; i++) {
		if (findset(i) != findset(1)) ok = false;
	}
	if (!ok) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	cin >> n;

}