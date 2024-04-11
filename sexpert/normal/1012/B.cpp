#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 5;
vector<int> adj[MAXN];
int vis[MAXN];

void dfs(int s) {
	vis[s] = 1;
	for(auto v : adj[s])
		if(!vis[v]) dfs(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;

	for(int i = 0; i < q; i++) {
		int r, c;
		cin >> r >> c;
		adj[r].push_back(n + c);
		adj[n + c].push_back(r);
	}
	int ans = -1;
	for(int i = 1; i <= m + n; i++)
		if(!vis[i]) {
			dfs(i);
			ans++;
		}

	cout << ans << '\n';
}