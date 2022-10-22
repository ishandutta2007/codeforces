#include <bits/stdc++.h>
using namespace std;
#define all(x)			(x).begin(),(x).end()
const int N = 1e6;
set<int> st[N];
int f[N], n, ans, A[N];
bool B[N];
vector<int> adj[N];

void dfs(int v, int p)  {
	f[v] ^= (f[p] ^ A[v]);
	st[v].insert(f[v]);
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		if (!B[u]) {
			if (st[u].size() > st[v].size()) st[u].swap(st[v]);
			for (int x : st[u])
				B[v] |= st[v].count(x ^ A[v]);
			st[v].insert(all(st[u]));
		}
	}
	ans += B[v];
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}