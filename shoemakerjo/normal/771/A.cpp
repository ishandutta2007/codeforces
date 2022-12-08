#include <bits/stdc++.h>

using namespace std;
#define maxn 150010
#define ll long long
int n, m;
vector<vector<int>> adj(maxn);
vector<int> curvals;
bool seen[maxn];

void rec(int u) {
	seen[u] = true;
	curvals.push_back(u);
	for (auto v : adj[u]) {
		if (!seen[v]) rec(v);
	}
}

bool solve() { //want to be able to return quickly
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= n; i++) seen[i] = false;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (seen[i]) continue;
		curvals.clear();
		rec(i);
		ll sumpairs = 0LL;
		for (auto v : curvals) {
			sumpairs += adj[v].size()+0LL;
		}
		sumpairs /= 2LL;
		ll goal = ((curvals.size()+0LL)*(curvals.size()-1LL))/2LL;
		if (goal != sumpairs) return false;
	}
	return true;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (solve()) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;

	}
	cin >> n;
	
}