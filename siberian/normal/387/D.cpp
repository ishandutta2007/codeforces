#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

const int MAXN = 510;
int n, m;
vector<pair<int, int>> edges;

vector<int> g[MAXN];

int mt[MAXN];
int used[MAXN];

bool dfs(int v, int c) {
	if (used[v] == c) return false;
	used[v] = c;
	for (auto i : g[v]) {
		if (mt[i] == -1 || dfs(mt[i], c)) {
			mt[i] = v;
			return true;
		}
	}
	return false;
} 

int solve(int v) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		g[i].clear();
		mt[i] = -1;
		used[i] = 0;
	}
	for (auto [i, j] : edges) {
		ans += i == v || j == v;
		if (i == v) continue;
		if (j == v) continue;
		g[i].push_back(j);
	}
	for (int i = 0; i < n; i++) {
		if (i == v) continue;
		dfs(i, i + 1);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += mt[i] != -1;
	}
	int needEdges = 1 + 2 * (n - 1) - ans;
	int delEdges = m - (ans + cnt);
	int addEdges = n - 1 - cnt;
	return needEdges + delEdges + addEdges;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		edges.push_back({u, v});
	}
	int ans = 1e9 + 10;
	for (int i = 0; i < n; i++) {
		ans = min(ans, solve(i));
	}
	cout << ans << endl;
	return 0;
}