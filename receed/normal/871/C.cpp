#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;
vector<int> g[200012];
int used[200012], cc;
long long p[200005];

int dfs(int v, int pp) {
	int ans = 1;
	used[v] = 1;
	for (int u : g[v]) {
		if (u != pp && used[u] == 1)
			cc = 1;
		if (!used[u])
			ans += dfs(u, v);
	}
	used[v] = 2;
	return ans;
}

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, a, b;
	cin >> n;
	map<int, int> x, y;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (!x.count(a))
			x[a] = x.size();
		a = x[a];
		if (!y.count(b))
			y[b] = y.size();
		b = 100001 + y[b];
		g[a].push_back(b);
		g[b].push_back(a);
	}
	p[0] = 1;
	for (int i = 0; i <= 200001; i++)
		p[i + 1] = p[i] * 2 % mod;
	int t;
	long long res = 1;
	for (int i = 1; i <= x.size(); i++) {
		if (used[i])
			continue;
		cc = 0;
		t = dfs(i, -1);
		if (cc)
			res = res * p[t] % mod;
		else
			res = res * (p[t] - 1) % mod;
	}
	cout << res << '\n';
}