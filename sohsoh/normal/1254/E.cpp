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
const ll MOD = 1e9 + 7;

int n, tin[MAXN], tout[MAXN], t, tot = 0, 
    par[MAXN], S[MAXN], E[MAXN], in[MAXN], out[MAXN], v_cnt;
ll fact[MAXN];
vector<int> adj[MAXN];
vector<pll> edges[MAXN];
bool vis[MAXN];

void dfs(int v, int p) {
	par[v] = p;
	tin[v] = ++t;

	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
	tout[v] = t;
}

inline bool Par(int v, int u) {
	return tin[v] <= tin[u] && tout[v] >= tout[u];
}

inline vector<int> path(int u, int v) {
	vector<int> ans = {u};
	while (!Par(u, v)) {
		u = par[u];
		ans.push_back(u);
	}

	vector<int> ans2;
	while (u != v) {
		ans2.push_back(v);
		v = par[v];
	}

	reverse(all(ans2));
	ans.insert(ans.end(), all(ans2));
	
	tot += ans.size();
	if (tot > MAXN * 3) cout << 0 << endl, exit(0);

	return ans;
}

bool dfs2(int v) {
	bool ans = (out[v] == 0);
	vis[v] = true;	
	v_cnt++;

	if (in[v] && !vis[in[v]]) ans |= dfs2(in[v]);
	if (out[v] && !vis[out[v]]) ans |= dfs2(out[v]);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	fact[0] = 1;

	for (int v = 1; v <= n; v++) {
		fact[v] = fact[v - 1] * v % MOD;
		int u;
		cin >> u;
		if (!u) continue;
		if (v == u) return cout << 0 << endl, 0;
		
		vector<int> vec = path(v, u);
		S[v] = vec[1];
		E[u] = vec[int(vec.size()) - 2];

		for (int i = 1; i < int(vec.size()) - 1; i++)
			edges[vec[i]].push_back({vec[i - 1], vec[i + 1]});
	}

	ll ans = 1;
	for (int v = 1; v <= n; v++) {
		for (pll e : edges[v]) {
			int a = e.X, b = e.Y;
			if (in[b] || out[a]) return cout << 0 << endl, 0;
			out[a] = b;
			in[b] = a;
		}

		int cnt = 0;
		for (int u : adj[v]) {
			if (!vis[u] && !in[v]) {
				bool a = vis[S[v]], b = vis[E[v]];
				int t_cnt = v_cnt;
				if (!dfs2(u)) return cout << 0 << endl, 0;
				cnt++;
		
				if (vis[S[v]] != a && vis[E[v]] != b && (t_cnt || v_cnt != int(adj[v].size())))
					return cout << 0 << endl, 0;
				if ((a ^ vis[S[v]]) || (b ^ vis[E[v]])) cnt--;
			}
		}

		for (int u : adj[v]) {
			if (!vis[u])
				return cout << 0 << endl, 0;
		
			vis[u] = false;
			in[u] = out[u] = 0;
		}

		ans = ans * fact[cnt] % MOD;
		cnt = 0;
		v_cnt = 0;
	}

	cout << ans << endl;
	return 0;
}