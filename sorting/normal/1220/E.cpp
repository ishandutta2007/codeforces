#include <bits/stdc++.h>
 
using namespace std;
 
const long long MAXM = 4e5 + 7;
const long long LOGM = 20;
 
vector<long long> adj[MAXM];
long long n, m, w[MAXM], s;
bool used[MAXM];

long long ans = 0;
 
bool dfs2(long long u, long long par = -1){
	used[u] = true;
	bool ok = false;
 
	for(long long to: adj[u]){
		if(to == par){
			continue;
		}
 
		long long curr;
		if(used[to])
			ok = true;
		else
			if(dfs2(to, u))
				ok = true;
	}
 
	if(ok){
		ans += w[u];
		w[u] = 0;
	}
 
	return ok;
}
 
long long solve(long long u, long long par = -1){
	used[u] = true;
 
	long long ans = 0;
	for(long long to: adj[u]){
		if(to == par || used[to]){
			continue;
		}
 
		ans = max(ans, solve(to, u));
	}
 
	ans += w[u];
 
	return ans;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> n >> m;
 
	for(long long i = 1; i <= n; ++i){
		cin >> w[i];
	}
 
	for(long long i = 0; i < m; ++i){
		long long u, v;
 
		cin >> u >> v;
 
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
 
	cin >> s;

	dfs2(s, -1);
	for(int i = 1; i <= n; ++i){
		used[i] = false;
	}
	ans += solve(s, -1);

	cout << ans << "\n";
 
	return 0;
}