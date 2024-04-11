#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <cassert> //
#pragma GCC optimize("O3,no-stack-protector,unroll-loops,fast-math")

using namespace std;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const int MAXN = 1e5 + 10;
const int MAXD = 50;

int n, m, d, C[MAXN * MAXD], T, dp_val[MAXN * MAXD], dp[MAXN * MAXD], k;
bool O[MAXN * MAXD], vis[MAXN * MAXD], tmp[MAXN];
vector<int> adj[MAXN * MAXD], adj_r[MAXN * MAXD], order, need_rem;

void dfs1(int v) {
	vis[v] = true;
	for (int u : adj[v]) if (!vis[u]) dfs1(u);
	order.push_back(v);
}

void dfs2(int v) {
	k = v / MAXD;
	if (!tmp[k] && O[v]) {
		dp_val[T]++;
		need_rem.push_back(k);
		tmp[k] = true;
	}

	C[v] = T;
	for (int u : adj_r[v]) if (C[u] == 0) dfs2(u);
}

void dp_dfs(int v) {
	dp[v] = dp_val[v];
	vis[v] = true;
	for (int u : adj_r[v]) {
		if (!vis[u]) dp_dfs(u);
		dp[v] = max(dp[v], dp_val[v] + dp[u]);
	}
}

inline void SSC() {
	for (int i = 0; i < MAXN * MAXD; i++) if (!vis[i]) dfs1(i);		
	reverse(all(order));	
	for (int i : order) {
		if (C[i] == 0) {
			T++;
			dfs2(i);
			for (int e : need_rem) tmp[e] = false;
			need_rem.clear();
		}
	}

	order.clear();
	for (int i = 0; i < MAXN * MAXD; i++) adj_r[i].clear(), adj_r[i].shrink_to_fit();
		
	for (int i = 0; i < MAXN * MAXD; i++) {
		for (int e : adj[i]) {
			if (C[i] != C[e]) adj_r[C[i]].push_back(C[e]);
		}
	}

	memset(vis, false, sizeof vis);

}

int main() {
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		for (int j = 0; j < d; j++) {
			adj[u * MAXD + j].push_back(v * MAXD + ((j + 1) % d));
			adj_r[v * MAXD + ((j + 1) % d)].push_back(u * MAXD + j);
		}		
	}

	for (int i = 1; i <= n; i++) {	
		getchar();
		for (int j = 0; j < d; j++) {
			char c = getchar();
			O[i * MAXD + j] = (c == '1');
		}
	}

	SSC();

	int v = C[MAXD];
	dp_dfs(v);
	printf("%d", dp[v]);
	return 0;
}