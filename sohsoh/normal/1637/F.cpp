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

ll n, mx_down[MAXN], cost_down[MAXN], mx_up[MAXN], cost_up[MAXN], H[MAXN];
vector<int> adj[MAXN];

void dfs_down(int v, int p) {
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs_down(u, v);
		mx_down[v] = max(mx_down[v], mx_down[u]);
		cost_down[v] += cost_down[u];
	}

	cost_down[v] += max(0ll, H[v] - mx_down[v]);
	mx_down[v] = max(mx_down[v], H[v]);
}

int par[MAXN];

void dfs_up(int v, int p) {
	multiset<ll> st;
	st.insert(mx_up[v]);
	ll sum = cost_up[v];
	par[v] = p;

	for (int u : adj[v]) {
		if (u == p) continue;
		st.insert(mx_down[u]);
		sum += cost_down[u];
	}

	for (int u : adj[v]) {
		if (u == p) continue;
		st.erase(st.find(mx_down[u]));
	

		mx_up[u] = *st.rbegin();
		cost_up[u] += sum - cost_down[u];
		cost_up[u] += max(0ll, H[v] - mx_up[u]);
		mx_up[u] = max(mx_up[u], H[v]);
		st.insert(mx_down[u]);
		dfs_up(u, v);
	}
}

const ll INF = 8e18;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	ll fuck = 0;
	for (int i = 1; i <= n; i++) {
		cin >> H[i];
		if (H[i] > fuck)
			fuck = H[i];
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs_down(1, 0);
	dfs_up(1, 0);

	ll ans = INF;
	for (int v = 1; v <= n; v++) {

		ll tans = cost_up[v], tc = mx_up[v];
		for (int u : adj[v])
			if (u != par[v])
				tans += cost_down[u], tc = max(tc, mx_down[u]);
		ans = min(ans, tans + fuck + max(0ll, H[v] - tc));
	}

	cout << ans << endl;
	return 0;
}