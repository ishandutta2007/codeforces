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

int n, C[MAXN], ans[MAXN];
vector<int> adj[MAXN], A[2];

void dfs(int v, int p) {
	A[C[v]].push_back(v);
	for (int u : adj[v]) {
		if (u != p) {
			C[u] = C[v] ^ 1;
			dfs(u, v);
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	vector<vector<int>> vec;
	for (int i = 1; i <= n; i++) {
		if (i == 1 || __builtin_clz(i) != __builtin_clz(i - 1)) vec.push_back({});
		vec.back().push_back(i);
	}

	while (!vec.empty()) {
		if (A[0].size() < A[1].size()) A[0].swap(A[1]);
		for (int e : vec.back()) {
			ans[A[0].back()] = e;
			A[0].pop_back();
		}

		vec.pop_back();
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << sep;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
		A[0].clear();
		A[1].clear();
		for (int i = 0; i < n + 10; i++) adj[i].clear();
	}
	return 0;
}