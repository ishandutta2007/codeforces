#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, f[N], g[N], l[N], r[N];
vector<int> adj[N];

void dfs(int u) {
	f[u] = g[u] = 0;
	for(auto v : adj[u]) {
		dfs(v);
		f[u] += f[v], g[u] += g[v];
	}
	if(f[u] < l[u]) ++g[u], f[u] = r[u];
	f[u] = min(f[u], r[u]);
}

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) adj[i].clear();
	for(int i = 2, f; i <= n; i++) f = get(), adj[f].emplace_back(i);
	for(int i = 1; i <= n; i++) l[i] = get(), r[i] = get();
	dfs(1);
	cout << g[1] << endl;
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
4
1 2 1
6 9
5 6
4 5
2 4
*/