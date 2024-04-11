#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;

int n, m, s;
vector<int> g[N];
int vis[N], par[N], tag[N];

void dfs(int u, int t) {
	vis[u] = 1; tag[u] = t;

	for (auto v: g[u]) {
		if (vis[v] == 0) {
			par[v] = u;
			//cout <<"!" << u << " " << v << "\n";
			//vis[v] = 1;
			dfs(v, t==0?v:t);
		} else if (vis[v] == 2 && tag[u] != tag[v]){		
			// s->u->v
			// s->v
			vector<int> p1, p2;
			int v_cp = v;
			//cout << u << " " << v << "\n";
			while (v != s) {
				p2.push_back(v); v = par[v];
			}
			while (u != s) {
				p1.push_back(u); u = par[u];
			}
			p1.push_back(s); p2.push_back(s);

			reverse(p1.begin(), p1.end());
			reverse(p2.begin(), p2.end());
			p1.push_back(v_cp);
			cout << "Possible" << "\n";
			cout << p1.size() << "\n";
			for (auto x: p1) cout << x << " "; cout << "\n";
			cout << p2.size() << "\n";
 			for (auto x: p2) cout << x << " ";
			exit(0);
		} else {
			continue;
		}
	}
	vis[u] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i ++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	dfs(s, 0);

	cout << "Impossible" << "\n";
}