#include <bits/stdc++.h>

using namespace std;

int n, q;
const int maxn = 100010;

const int mod = 1000000007;
using ll = long long;
#define pii pair<int, int>

int dp[305]; //just store dp values
vector<int> adj[maxn];

int par[18][maxn];
int dep[maxn];
int st[maxn];
int en[maxn]; //dfs order nodes
vector<int> preorder;

int BIT[maxn];

void dfs(int u, int p = -1) {
	// cout << "dfs: " << u << endl;
	par[0][u] = p;
	dep[u] = p == -1 ? 1 : dep[p]+1;
	st[u] = preorder.size();
	preorder.push_back(u);

	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
	en[u] = preorder.size()-1;
}

void upd(int spot, int diff) {
	while (spot <= n) {
		BIT[spot] += diff;
		spot += spot & (-spot);
	}
}

void update(int us, int ue) {
	upd(us, 1);
	upd(ue+1, -1); 
}

void uneg(int us, int ue) {
	upd(us, -1);
	upd(ue+1, 1);
}

int query(int spot) {
	int res = 0;
	while (spot > 0) {
		res += BIT[spot];
		spot -= spot & (-spot);
	}
	return res;
}

int walk(int u, int k) {
	for (int i = 17; i >= 0; i--) {
		if (k & (1 << i)) {
			u = par[i][u];
		}
	}
	return u;
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	u = walk(u, dep[u]-dep[v]);
	if (u == v) return u;
	for (int i = 17; i >= 0; i--) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u];
}

bool isin[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin  >> n >> q;
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	preorder.push_back(-1);
	dfs(1);

	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			if (par[i-1][j] != -1) {
				par[i][j] = par[i-1][par[i-1][j]];
			}
			else par[i][j] = -1;
		}
	}

	int k, m, r;
	vector<int> vals;
	vector<pii> stuff;
	while (q--) {
		cin >> k >> m >> r;
		vals.clear();
		stuff.clear();
		int cur;

		// cout << "PRE: " << query(st[r]) << endl;
		for (int i = 0; i < k; i++) {
			cin >> cur;
			isin[cur] = true;
			vals.push_back(cur);
			update(st[cur], en[cur]);
		}
		for (int vv : vals) {
			int lc = lca(vv, r);
			// cout << "   " << vv << " " << r << " :: " << lc << endl;

			int ch = query(st[vv]) + query(st[r]) - 2*query(st[lc]) 
					+ isin[lc] - 1;
			stuff.push_back(pii(ch, vv));

			// cout << " ---- " << vv << " " << 
			// 	query(st[vv]) << " " << query(st[r]) << endl;
			// cout << "    " << vv << " : "  << ch << endl;
		}
		sort(stuff.begin(), stuff.end());
		dp[0] = 1;
		for (int i = 1; i <= m; i++) {
			dp[i] = 0;
		}
		for (pii vp : stuff) {
			cur = vp.second;
			int ch = vp.first;

			// cout << " " << ch << endl;
			for (int i = m; i >= 0; i--) {
				int odp = dp[i];
				dp[i] = 0;
				if (i - ch >= 0) {
					dp[i] = (dp[i] + odp*1LL*(i-ch)%mod )%mod;

				}
				if (i > 0) {
					dp[i] = (dp[i] + dp[i-1])%mod;
				}
				// cout << "    " << i << " "  << dp[i] << endl;
			}
		}
		int ans = 0;
		for (int i = 0; i <= m; i++) {
			ans = (ans + dp[i])%mod;
		}
		// cout << "    ";
		cout << ans << '\n';

		//clear out everything
		for (int vv : vals) {
			isin[vv] = false;
			uneg(st[vv], en[vv]);
		}
	}
	cout.flush();
}