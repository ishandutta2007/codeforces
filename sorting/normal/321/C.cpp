#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5 + 7;

vector<int> adj[kN], adj_cen[kN];
int tr_sz[kN], cnt_vers, root, n;
bool used[kN];
char ans[kN];

void pre_dfs(int u, int pr = -1){
	tr_sz[u] = 1;

	for(int to: adj[u]){
		if(to == pr || used[to])
			continue;

		pre_dfs(to, u);
		tr_sz[u] += tr_sz[to];
	}
} 

int centroid(int u, int pr = -1){
	for(int to: adj[u]){
		if(to == pr || used[to])
			continue;

		if(tr_sz[to] > cnt_vers / 2)
			return centroid(to, u);
	}

	return u;
}

void decompose(int u, int pr = -1){
	pre_dfs(u);
	cnt_vers = tr_sz[u];
	int cen = centroid(u);
	if(pr != -1)
		adj_cen[pr].push_back(cen);
	else
		root = cen;

	used[cen] = true;
	for(int to: adj[cen])
		if(!used[to])
			decompose(to, cen);
	used[cen] = false;
}

int solve(int u, int curr = 0){ 
	for(int to: adj_cen[u])
		solve(to, curr + 1);

	ans[u] = curr + 'A';
	return curr;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	decompose(1);
	solve(root);

	for(int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
}