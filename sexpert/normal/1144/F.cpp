#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int MAXN= 2e5 + 5;
vector<ii> edges;
vector<int> adj[MAXN];
int col[MAXN];
bool bad = false;

void dfs(int s, int c = 0) {
	if(c == 1 - col[s])
		bad = true;
	col[s] = c;
	for(auto v : adj[s]) {
		if(col[v] == c)
			bad = true;
		if(col[v] == -1)
			dfs(v, 1 - c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while(m--){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back({u, v});
	}
	fill(col, col + MAXN, - 1);
	for(int i = 1; i <= n; i++)
		if(col[i] == -1) dfs(i);
	if(bad) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(auto e : edges) {
		if(col[e.first] == 0)
			cout << "0";
		else
			cout << "1";
	}
	cout << '\n';
}