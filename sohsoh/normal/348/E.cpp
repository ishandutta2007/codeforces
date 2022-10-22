#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const int MAXN = 1e5 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const int LOG = 22;

int n, m, par[MAXN][LOG], v_ind[MAXN], T[MAXN], H[MAXN], D[MAXN];
bool C[MAXN];
vector<pll> adj[MAXN];
pll dp_down[MAXN], dp_up[MAXN];
vector<pll> dp[MAXN][2];

void dfs(int v, int p) {
	par[v][0] = p;
	int ind = 0;

	for (pll e : adj[v]) {
		int u = e.X, w = e.Y;
		if (u == p) continue;

		H[u] = H[v] + 1;
		dfs(u, v);
		int val = dp_down[u].X + w;
		if (val > dp_down[v].X) {
			dp_down[v].X = val;
			dp_down[v].Y = dp_down[u].Y;
		} else if (val == dp_down[v].X) dp_down[v].Y = v;
	
		dp[v][0].push_back({0, 0});
		dp[v][1].push_back({0, 0});
		if (ind == 0) dp[v][0][0] = {val, dp_down[u].Y};
		else {
			dp[v][0][ind] = dp[v][0][ind - 1];
			if (val > dp[v][0][ind].X) {
				dp[v][0][ind].X = val;
				dp[v][0][ind].Y = dp_down[u].Y;
			} else if (val == dp[v][0][ind].X) dp[v][0][ind].Y = v;
		}

		v_ind[u] = ind;
		ind++;
	}
	
	ind--;
	for (int i = adj[v].size() - 1; i >= 0; i--) {
		int u = adj[v][i].X, w = adj[v][i].Y;
		if (u == p) continue;

		int val = dp_down[u].X + w;
		if (ind == dp[v][0].size() - 1) dp[v][1][ind] = {val, dp_down[u].Y};
		else {
			
			dp[v][1][ind] = dp[v][1][ind + 1];
			if (val > dp[v][1][ind].X) {
				dp[v][1][ind].X = val;
				dp[v][1][ind].Y = dp_down[u].Y;
			} else if (val == dp[v][1][ind].X) dp[v][1][ind].Y = v;
		}

		ind--;
	}

}

void dfs_up(int v, int p, int w) {
	if (p) {
		int ind = v_ind[v];
		dp_up[v] = max(make_pair(w + dp_up[p].X, dp_up[p].Y), dp_up[v]);
		if (ind) {
			if (dp[p][0][ind - 1].X + w > dp_up[v].X) {
				dp_up[v].X = dp[p][0][ind - 1].X + w;
				dp_up[v].Y = dp[p][0][ind - 1].Y;
			} else if (dp[p][0][ind - 1].X + w == dp_up[v].X) dp_up[v].Y = p;
		}

		if (ind < dp[p][1].size() - 1) {	
			if (dp[p][1][ind + 1].X + w > dp_up[v].X) {
				dp_up[v].X = dp[p][1][ind + 1].X + w;
				dp_up[v].Y = dp[p][1][ind + 1].Y;
			} else if (dp[p][1][ind + 1].X + w == dp_up[v].X) dp_up[v].Y = p;	
		}
	}

	if (dp_down[v].X > dp_up[v].X) T[v] = dp_down[v].Y;
	else if (dp_down[v].X < dp_up[v].X) T[v] = dp_up[v].Y;
	else T[v] = v;

	for (pll e : adj[v])
		if (e.X != p)
			dfs_up(e.X, v, e.Y);
}

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			v = par[v][i];
	
	return v;
}

inline int LCA(int v, int u) {
	if (H[v] < H[u]) swap(u, v);
	v = Par(v, H[v] - H[u]);
	if (v == u) return v;

	for (int i = LOG - 1; i >= 0; i--)
		if (par[v][i] != par[u][i])
		       v = par[v][i], u = par[u][i];
	return par[v][0];	
}

void MajikalDfs(int v, int p) {
	for (pll e : adj[v]) {
		int u = e.X;
		if (u == p) continue;
		MajikalDfs(u, v);
		D[v] += D[u];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	fill(dp_down, dp_down + MAXN, make_pair(-INF, -1));
	fill(dp_up, dp_up + MAXN, make_pair(-INF, -1));

	for (int i = 1; i <= m; i++) {
		int v;
		cin >> v;
		C[v] = true;
		dp_down[v] = dp_up[v] = {0, v};
	}	

	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}


	dfs(1, 0);
	dfs_up(1, 0, 0);

	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	for (int i = 1; i <= n; i++) {
		if (C[i]) {
			int u = i, v = T[i], lca = LCA(u, v);
			D[u]++;
			D[v]++;
			D[lca]--;
			D[par[lca][0]]--;
		}
	}
	
	MajikalDfs(1, 0);
	int mx = -1, mx_cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (C[i]) continue;
		if (D[i] > mx) mx = D[i], mx_cnt = 1;
		else if (D[i] == mx) mx_cnt++;
	}

	cout << mx << sep << mx_cnt << endl;
	return 0;
}