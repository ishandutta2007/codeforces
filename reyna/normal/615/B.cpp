//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 2e5 + 5;

int read() { int x; cin >> x; return x; }

vector<int> adj[N];
ll dp[N], deg[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), m = read();
	for (int i = 0; i < m; ++i) {
		int u = read() - 1, v = read() - 1;
		deg[u]++, deg[v]++;
		if (u < v)
			swap(u, v);
		adj[u].push_back(v);	
	}
	ll res = 0;
	for (int v = 0; v < n; ++v) {
		for (int u : adj[v])
			dp[v] = max(dp[u], dp[v]);
		dp[v]++;
		res = max(res, dp[v] * 1LL * deg[v]);
	}
	cout << res << endl;
}