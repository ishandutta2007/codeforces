#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 3e5 + 10;

struct _2SAT {
	vector<int> adj[MAXN << 1], adj_r[MAXN << 1];
	bool vis[MAXN << 1], ans[MAXN];
	int col[MAXN << 1], n = -1, C;
	stack<int> order;

	void dfs(int v) {
		vis[v] = true;
		for (int u : adj[v])
			if (!vis[u])
				dfs(u);

		order.push(v);
	}

	void sfd(int v) {
		col[v] = C;
		for (int u : adj_r[v])
			if (!col[u])
				sfd(u);
	}

	void add(int u, int v) {
		adj[u ^ 1].push_back(v);
		adj[v ^ 1].push_back(u);	
		adj_r[u].push_back(v ^ 1);
		adj_r[v].push_back(u ^ 1);
	}

	void add_pairwise(vector<int>& vec) {
		if (vec.empty()) return;
		add(vec.front(), ++n << 1);
		for (int i = 1; i < int(vec.size()); i++) {
			add(vec[i], n << 1 ^ 1);
			add(n << 1 ^ 1, (n + 1) << 1);
			n++;
			add(vec[i], n << 1);
		}
	}

	void init() {
		memset(vis, false, sizeof vis);
		memset(col, 0, sizeof col);
		memset(ans, false, sizeof ans);
		C = 0;
		n = -1;
	}

	bool solve() {
		for (int v = 0; v <= 2 * n; v++)
			if (!vis[v])
				dfs(v);

		while (!order.empty()) {
			int v = order.top();
			order.pop();
			if (!col[v])
				C++, sfd(v);
		}

		for (int i = 0; i <= n; i++) {
			if (col[i << 1] == col[i << 1 | 1])
				return false;
			ans[i] = col[i << 1] > col[i << 1 | 1];
		}

		return true;
	}
} sat;

int n, m;
vector<int> adj[MAXN], lst;
map<int, vector<int>> cadj[MAXN];
vector<pair<pll, pll>> edges;

inline void init() {
	sat.n = m;
	for (int v = 1; v <= n; v++) {
		vector<int> vec;
		for (int i : adj[v])
			vec.push_back(i << 1 | 1);
		sat.add_pairwise(vec);
	
		for (auto& e : cadj[v]) {
			for (int& i : e.Y)
				i <<= 1;
		
			sat.add_pairwise(e.Y);
		}
	}
}

inline bool check(int lim) {
	sat.init();
	sat.n = m;

	for (int e : lst) {
		sat.adj[e << 1].pop_back();
		sat.adj[e << 1].pop_back();
		sat.adj_r[e << 1 ^ 1].pop_back();
		sat.adj_r[e << 1 ^ 1].pop_back();
	}

	lst.clear();
	for (int i = 0; i < m; i++) {
		if (edges[i].Y.X > lim) {
			lst.push_back(i);
			sat.add(i << 1 ^ 1, i << 1 ^ 1);
		}
	}

	return sat.solve();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c, w;
		cin >> u >> v >> c >> w;
		edges.push_back({{u, v}, {w, c}});

		adj[u].push_back(i);
		adj[v].push_back(i);
		cadj[u][c].push_back(i);
		cadj[v][c].push_back(i);
	}

	init();
	int l = 0, r = int(1e9);
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	if (!check(l)) return cout << "No" << endl, 0;
	cout << "Yes" << endl;
	vector<int> ans;
	
	for (int i = 0; i < m; i++)
		if (sat.ans[i])
			ans.push_back(i);

	cout << l << sep << ans.size() << endl;
	for (int e : ans) cout << e + 1 << sep;
	cout << endl;
	return 0;
}