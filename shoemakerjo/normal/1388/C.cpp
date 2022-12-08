#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

const int maxn = 100010;

int n, m;
vector<int> adj[maxn];
int p[maxn];
int h[maxn];
int totp[maxn];
bool ok;

pii dfs(int u, int par = -1) {
	totp[u] = p[u];
	int sumu = 0;
	int sumh = 0;
	for (int v : adj[u]) {
		if (v == par) continue;
		pii tmp = dfs(v, u);
		totp[u] += totp[v];
		sumu += tmp.second;
		sumh += tmp.first;
	}
	int a = (totp[u] + h[u])/2;
	int b = totp[u] - a;
	
	if (a + b != totp[u] || a - b != h[u] || a < 0 || b < 0) {
		ok = false;
	}

	if (a < sumh) {
		//number happy increased
		ok = false;
	}
	if (totp[u] - sumh < sumu) {
		ok = false;
	}
	return pii(a, b);

}

void solve() {
	cin >> n >> m;
	ok = true;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		adj[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}