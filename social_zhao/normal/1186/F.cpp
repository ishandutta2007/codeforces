#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, m, deg[N], rem[N], _x[N], _y[N], vis[N];
vector<int> adj[N];
priority_queue<pair<int, int>> q;
map<pair<int, int>, int> del;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	n = get(), m = get();
	for(int i = 1, u, v; i <= m; i++) 
		u = get(), v = get(), adj[u].push_back(v), adj[v].push_back(u), ++deg[u], ++deg[v], _x[i] = u, _y[i] = v;
	for(int i = 1; i <= n; i++) 
		rem[i] = deg[i] - (deg[i] + 1) / 2, q.push({-rem[i], i});
	int shit = m - (n + m + 1) / 2;
	while(shit > 0 && q.size()) {
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		sort(adj[u].begin(), adj[u].end(), [](int a, int b) { return rem[a] > rem[b]; });
		for(auto v : adj[u]) {
			if(!rem[u] || !shit) break;
			if(vis[v]) continue;
			--rem[u], --shit;
			del[{u, v}] = del[{v, u}] = 1;
			rem[v]--, q.push({-rem[v], v});
		}
	}
	int ans = 0;
	for(int i = 1; i <= m; i++) if(!del[{_x[i], _y[i]}]) ++ans;
	cout << ans << endl;
	for(int i = 1; i <= m; i++) if(!del[{_x[i], _y[i]}]) cout << _x[i] << " " << _y[i] << "\n";
	cout << endl;
	return 0;
}