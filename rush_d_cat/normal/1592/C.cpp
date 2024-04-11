#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 10;
vector<int> g[N];
int n, k, xorsum, a[N];
int sum[N], s1[N];

void dfs(int u, int p) {
	sum[u] = a[u];
	s1[u] = 0;
	for (auto v: g[u]) {
		if (v == p) continue;
		dfs(v, u);
		sum[u] ^= sum[v];
		s1[u] += s1[v];
	}	
	if (sum[u] == xorsum) s1[u] ++;
}
int root[N];
void dfs2(int u, int p) {
	for (auto v: g[u]) {
		if (v == p) continue;
		root[v] = root[u] + (sum[v]==xorsum);
		dfs2(v, u);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		cin >> n >> k;
		for (int i = 1; i <= n; i ++) 
			g[i].clear();
		
		xorsum = 0;
		for (int i = 1; i <= n; i ++) cin >> a[i], xorsum ^= a[i];

		for (int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 1);
		root[1] = 1;
		dfs2(1, 1);

		bool ok = 0;
		if (xorsum == 0) ok = 1;
		if (xorsum > 0 && k >= 3) {
			for (int i = 2; i <= n; i ++) {
				if (sum[i] == xorsum && root[i] + s1[i] - 1 != s1[1]) ok = 1;
				if (sum[i] == 0 && s1[i] > 0) ok = 1;
			}
		}
		cout << (ok?"YES":"NO") << "\n";
	}

}