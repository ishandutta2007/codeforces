#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN], path, ts;
int tin[MAXN], low[MAXN], comp[MAXN], col[MAXN], cur, ncomps;

void dfs(int s) {
	tin[s] = low[s] = ++cur;
	path.push_back(s);
	for(auto v : adj[s]) {
		if(!tin[v]) {
			dfs(v);
			low[s] = min(low[s], low[v]);
		}
		else if(!comp[v])
			low[s] = min(low[s], tin[v]);
	}
	if(low[s] == tin[s]) {
		ncomps++;
		int z;
		do {
			z = path.back();
			path.pop_back();
			comp[z] = ncomps;
		}while(z != s);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int p = 0; p < 2; p++) {
		for(int i = 0; i < n; i++)
			cin >> v[i];
		for(int i = 0; i < n - 1; i++)
			adj[v[i]].push_back(v[i + 1]);
	}
	for(int i = 1; i <= n; i++)
		if(!comp[i]) dfs(i);
	if(ncomps < k) {
		cout << "NO\n";
		return 0;
	}
	else {
		for(int i = 1; i <= ncomps; i++)
			col[i] = min(ncomps - i, 25);
	}
	cout << "YES\n";
	for(int i = 1; i <= n; i++)
		cout << (char)('a' + col[comp[i]]);
	cout << '\n';
}