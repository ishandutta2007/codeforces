#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

constexpr ll MAXN = 5e5 + 10;
constexpr ll SIG = 22;

unordered_map<int, int> mp[MAXN];
int lz[MAXN], sz[MAXN], n, par_c[MAXN], H[MAXN], dp[MAXN];
vector<int> adj[MAXN];


inline int fast_find(unordered_map<int, int>& mp, int x) {
	auto it = mp.find(x);
	if (it == mp.end()) return -MAXN;
	return it -> Y;
}

int dfs_sz(int v) {
	sz[v] = 1;
	for (int u : adj[v])
		sz[v] += dfs_sz(u);
	return sz[v];
}

void dfs(int v) {
	mp[v].max_load_factor(0.4);
	
	if (!adj[v].empty()) {
		sort(all(adj[v]), [] (int u, int v) {
				return sz[u] > sz[v];
		});

		int u = adj[v][0];
		H[u] = H[v] + 1;
		dfs(u);

		lz[v] = lz[u];
		mp[v].swap(mp[u]);
		dp[v] = dp[u];

		for (int i = 1; i < int(adj[v].size()); i++) {
			u = adj[v][i];	
			H[u] = H[v] + 1;
			dfs(u);

			dp[v] = max(dp[v], dp[u]);
			for (pll e : mp[u]) {
				e.X ^= lz[u];
				dp[v] = max(dp[v], fast_find(mp[v], e.X ^ lz[v]) + e.Y - 2 * H[v]);

				for (int i = 0; i < SIG; i++)
					dp[v] = max(dp[v], fast_find(mp[v], e.X ^ lz[v] ^ (1 << i)) + e.Y - 2 * H[v]);
			}

			for (pll e : mp[u])
				mp[v][e.X ^ lz[u] ^ lz[v]] = max(mp[v][e.X ^ lz[u] ^ lz[v]], e.Y);
			mp[u].clear();
		}
	}

	dp[v] = max(dp[v], fast_find(mp[v], lz[v]) - H[v]);
	for (int i = 0; i < SIG; i++)
		dp[v] = max(dp[v], fast_find(mp[v], lz[v] ^ (1 << i)) - H[v]);

	mp[v][lz[v]] = max(mp[v][lz[v]], H[v]);
	
	lz[v] ^= (1 << par_c[v]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int p;
		char c;
		cin >> p >> c;
		adj[p].push_back(i);
		par_c[i] = int(c - 'a');
	}

	dfs_sz(1);
	dfs(1);
	for (int i = 1; i <= n; i++)
		cout << dp[i] << endl;
	return 0;
}