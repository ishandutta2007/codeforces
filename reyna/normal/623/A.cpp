// In the name of God

/*
	........
*/


#include <bits/stdc++.h>

using namespace std;

inline int read() { int32_t x; scanf("%d", &x); return x; }

const int N = 1e5 + 5;

int mark[N], cnt, isb[N], ans[N], to = 'a';
vector<int> adj[N];

int dfs(int v) {
	if (mark[v]++)
		return 0;
	ans[v] = to;
	cnt++;
	int res = 0;
	for (int u : adj[v]) if (!isb[u]) {
		res += dfs(u);
		res++;
	}
	return res;
}

int main() {
	int n = read(), m = read();
	for (int i = 0; i < m; ++i) {
		int u = read() - 1, v = read() - 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int v = 0; v < n; ++v) if (adj[v].size() == n - 1) {
		isb[v] = 1;
		ans[v] = 'b';
	}
	int c = 0;
	for (int v = 0; v < n; ++v) if (!isb[v] && !mark[v]) {
		cnt = 0;
		c++;
		int x = dfs(v);
		if (x != cnt * (cnt - 1)) {
			cout << "No\n";
			return 0;
		}
		to = 'c';
	}
	if (c > 2) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	for (int v = 0; v < n; ++v)
		cout << char(ans[v]);
	
	
}