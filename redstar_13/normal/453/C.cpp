#include<bits/stdc++.h>

using namespace std;

#define NN 100010

vector<int> adj[NN];
int st[NN];
int root[NN];
vector<int> res;

int find_root(int u) {
	if(root[u] == u) return root[u];
	return root[u] = find_root(root[u]);
}

int dfs(int u, int fa = 0) {
	res.push_back(u);
	st[u] ^= 1;
	for(auto v : adj[u]) if(v != fa) {
		dfs(v, u);
		res.push_back(u);
		st[u] ^= 1;
		if(st[v]) {
			res.push_back(v), res.push_back(u);
			st[u] ^= 1, st[v] ^= 1;
		}
	}
	if(!fa and st[u]) {
		st[u] ^= 1;
		res.pop_back();
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n, m; scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) root[i] = i;
	
	for(int i=1, u, v; i<=m; i++) {
		scanf("%d %d", &u, &v);
		if(find_root(u) == find_root(v)) continue;
		adj[u].push_back(v);
		adj[v].push_back(u);
		root[root[u]] = root[v];
	}
	
	for(int i=1; i<=n; i++) scanf("%d", st+i);
	
	for(int i=1; i<=n; i++) if(st[i]) {
		dfs(i);
		for(int j=1; j<=n; j++) if(st[j]) {
			return puts("-1"), 0;
		}
		printf("%d\n", res.size());
		for(auto u : res) printf("%d ", u);
		return 0;
	}
	
	printf("%d\n", 0);
}