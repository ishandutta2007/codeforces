#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXN = 1e6 + 10;

int n, A[MAXN];
ll F[MAXN], G[MAXN], D[MAXN], dp[MAXN][3][3], ans, ans_t[MAXN][3][3];
vector<int> adj[MAXN];

void dfs(int v, int p, ll s) {
	F[v] = G[v] = A[v];
	for (int u : adj[v]) {
		if (u != p) {
			dfs(u, v, s + A[v]);
			for (int i = 2; i >= 0; i--) {
				for (int j = 2; j >= 0; j--) {
					if (j) {
						dp[v][i][j] = max(dp[v][i][j], dp[v][i][j - 1] + G[u]);
						ans_t[v][i][j] = max(ans_t[v][i][j], D[u] + ans_t[v][i][j - 1]);	
					}

					if (i) {
						dp[v][i][j] = max(dp[v][i][j], dp[v][i - 1][j] + F[u]);	
						ans_t[v][i][j] = max(ans_t[v][i][j], F[u] + ans_t[v][i - 1][j]);	
					}


					
				}
			}

			D[v] = max(D[v], D[u] + A[v]);
		}
	}

	F[v] = max(F[v], dp[v][1][0] + A[v]);
	G[v] = max({F[v], dp[v][2][0] + A[v], dp[v][0][1]});
	
	D[v] = max({D[v], dp[v][1][1] + A[v], dp[v][0][1] + A[v]});
	ans = max({ans, D[v], dp[v][0][2], dp[v][2][1] + A[v], ans_t[v][1][1] + A[v]});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}