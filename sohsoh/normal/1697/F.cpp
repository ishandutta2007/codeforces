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

const ll MAXN = 1e6 + 10;

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
		for (int i = 0; i <= 2 * n; i++) {
			adj[i].clear();
			adj_r[i].clear();
			vis[i] = false;
			col[i] = 0;
			ans[i] = false;
		}

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

int n, m, k;

inline int solve() {
	cin >> n >> m >> k;
	sat.init();
	sat.n = k * n;

	for (int i = 0; i < n; i++) {
		sat.add((k * i) << 1, (k * i) << 1);
		for (int j = 1; j < k; j++)
			sat.add((k * i + j - 1) << 1, (k * i + j) << 1 | 1);
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < k; j++)
			sat.add((k * i + j) << 1 | 1, (k * (i + 1) + j) << 1);

	while (m--) {
		int c;
		cin >> c;
		if (c == 1) {
			int i, x;
			cin >> i >> x;
			i--, x--;

			int v = i * k + x;
			if (x == k - 1) sat.add(v << 1 | 1, v << 1 | 1);
			else sat.add(v << 1 | 1, (v + 1) << 1);
		} else if (c == 2) {
			int i, j, x;
			cin >> i >> j >> x;
			i--, j--, x -= 2;

			if (x + 1 < k) {
				sat.add((i * k + x + 1) << 1 | 1, (i * k + x + 1) << 1 | 1);
				sat.add((j * k + x + 1) << 1 | 1, (j * k + x + 1) << 1 | 1);
			}

			for (int xi = 0; xi < k; xi++) {
				if (xi > x) sat.add((i * k + xi) << 1 | 1, (i * k + xi) << 1 | 1);
				else if (x + 1 - xi < k) sat.add((i * k + xi) << 1 | 1, (j * k + (x + 1 - xi)) << 1 | 1);
			}
		} else {
			int i, j, x;
			cin >> i >> j >> x;
			i--, j--, x -= 2;

			if (x == 2 * k - 2) {
				sat.add((i * k + k - 1) << 1, (i * k + k - 1) << 1);
				sat.add((j * k + k - 1) << 1, (j * k + k - 1) << 1);
			}

			for (int xi = 0; xi < min(k, x + 1); xi++) {
				if (x - xi + 1 < k) sat.add((i * k + xi) << 1, (j * k + (x - xi + 1)) << 1);
				else sat.add((i * k + xi) << 1, (i * k + xi) << 1);
			}
		}
	}

	if (!sat.solve()) return cout << -1 << endl, 0;
	for (int i = 0; i < n; i++) {
		int mx = 0;
		while (mx < k - 1 && sat.ans[i * k + mx + 1]) mx++;
		cout << mx + 1 << sep;
	}

	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}