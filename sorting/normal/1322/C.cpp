#include <bits/stdc++.h>

using namespace std;

const int kN = 5e5 + 7;

long long c[kN];
vector<int> adj[kN];

map<vector<int>, long long> mp;

void solve(){
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
		adj[i].clear();
	mp.clear();

	for(int i = 1; i <= n; ++i)
		cin >> c[i];

	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;

		adj[v].push_back(u);
	}

	for(int i = 1; i <= n; ++i)
		sort(adj[i].begin(), adj[i].end());

	for(int i = 1; i <= n; ++i)
		mp[adj[i]] += c[i];

	long long ans = 0;
	for(auto it: mp){
		if(it.first.empty())
			continue;

		ans = __gcd(ans, it.second);
	}

	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}