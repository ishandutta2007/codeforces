#include <bits/stdc++.h>
using namespace std;

vector<int> to[300*1000 + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> v;
	set<int> cur;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		to[u].push_back(v);
	}
	for(int i = n - 2; i >= 0; i--) {
		int x = v[i];
		int good = 0;
		for(auto u : to[x]) {
			if(cur.count(u) || u == v[n - 1])
				good++;
		}
		if(good == cur.size() + 1)
			continue;
		cur.insert(x);
	}
	cout << n - 1 - cur.size() << '\n';
}