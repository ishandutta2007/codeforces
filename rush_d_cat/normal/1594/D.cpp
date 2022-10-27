#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200000 + 10;
int par[N], sz[N], col[N];
vector<int> g[N];
int find(int x) {
	return par[x] == x ? x : par[x] = find(par[x]);
}

int ss[2] = {0}, gg = 0;
void dfs(int u) {
	for (auto v: g[u]) {
		if (col[v] == -1) {
			col[v] = 1 - col[u];
			ss[col[v]] += sz[find(v)];
			dfs(v);
		} else {
			if (col[v] == col[u]) gg = 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i ++)
			par[i] = i, sz[i] = 1, g[i].clear(), col[i] = -1;

		vector<int> u(m), v(m);
		vector<string> s(m);
		
		for (int i = 0; i < m; i ++) {
			cin >> u[i] >> v[i] >> s[i];
			if (s[i] == "crewmate") {
				if (find(u[i]) != find(v[i])) {
					sz[find(v[i])] += sz[find(u[i])];
					par[find(u[i])] = find(v[i]);
				}
			} 
		}
		for (int i = 0; i < m; i ++) {
			if (s[i] != "crewmate") {
				g[find(u[i])].push_back(find(v[i]));
				g[find(v[i])].push_back(find(u[i]));
			}
		}

		int ans = 0, ggg = 0;
		for (int i = 1; i <= n; i ++) {
			if (find(i) == i && col[i] == -1) {
				ss[0] = ss[1] = gg = 0;
				col[i] = 0; ss[0] += sz[i];
				dfs(i);
				if (gg) ggg = 1;
				ans += max(ss[0], ss[1]);
			}
		}
		if (ggg) cout << -1 << "\n"; else cout << ans << "\n";
	}
}