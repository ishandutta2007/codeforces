#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int C[MAXN], par[MAXN], sz[MAXN], opt[MAXN], n, m, q, shit;
stack<pll> hist;
pll E[MAXN];
bool flag;

inline pll find(int v) {
	pll ans = {v, 0};
	while (ans.X != par[ans.X]) {
		ans.Y ^= C[ans.X];
		ans.X = par[ans.X];
	}

	return ans;
}

inline int unite(int ind) {
	int u = E[ind].X, v = E[ind].Y;
	int cu, cv;
	tie(u, cu) = find(u);
	tie(v, cv) = find(v);

	if (v == u) {
		if (cv != cu) {
			hist.push({-2, -2});
			return 2;
		} else { 
			hist.push({-1, -1});
			shit++;
			return 1;
		}
	}

	if (sz[u] < sz[v]) swap(v, u);
	par[v] = u;
	sz[u] += sz[v];
	C[v] = cv ^ cu ^ 1;
	hist.push({v, u});
	return 0;
}

inline void rollback(int cnt) {
	while (cnt > 0 && !hist.empty()) {
		int v = hist.top().X, u = hist.top().Y;
		cnt--;

		hist.pop();
		if (v == -1) shit--;
		if (v < 0) continue;

		par[v] = v;
		sz[u] -= sz[v];
		C[v] = 0;
	}
}

void solve(int l = 1, int r = m) {
	if (r < l) return;
	
	if (l == r) {
		if (shit > 0) opt[l] = l + 5;
		else opt[l] = l;
	} else {
		int mid = (l + r) >> 1;
		for (int i = l; i <= mid; i++) unite(i);
		solve(mid + 1, r);
		rollback(mid - l + 1);

		for (int i = mid + 1; i <= r; i++) unite(i);
		solve(l, mid);
		rollback(r - mid);
	}
}

vector<pll> adj[MAXN];
int col[MAXN];
bool idkflag = false;

void dfs(int v, int ind) {
	for (auto [u, x] : adj[v]) {
		if (x == ind) continue;
		if (!col[u]) {
			col[u] = 3 - col[v];
			dfs(u, ind);
		}

		idkflag |= (col[v] == col[u]);
	}
}

inline int wtf() {	
	cin >> n >> m;
	for (int i = 0; i < m + 5; i++) {
		par[i] = i;
		sz[i] = 1;
	}

	for (int i = 1; i <= m; i++) {
		cin >> E[i].X >> E[i].Y;
		adj[E[i].X].push_back({E[i].Y, i});
		adj[E[i].Y].push_back({E[i].X, i});
	}

	E[m + 1] = {m + 5 - 1, m + 5 - 2};
	solve();

	col[1] = 1;
	dfs(1, -1);
	if (!idkflag) {
		cout << "YES" << endl;
		for (int i = 1; i <= n; i++)
			cout << col[i] - 1;
		cout << endl;
		return 0;
	}

	idkflag = false;
	for (int i = 0; i < n + 5; i++)
		col[i] = 0;

	for (int i = 1; i <= m; i++) {
		if (opt[i] <= i) {
			cout << "YES" << endl;
			col[E[i].X] = 2;
			dfs(E[i].X, i);
			for (int i = 1; i <= n; i++)
				cout << col[i] - 1;
			cout << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < m + 10; i++) {
			adj[i].clear();
			idkflag = false;
			col[i] = 0;
			C[i] = par[i] = sz[i] = opt[i] = 0;
			E[i] = {0, 0};
		}

		shit = 0;
		while (!hist.empty()) hist.pop();
		flag = false;
		n = m = q = 0;

		wtf();
	}
	return 0;
}