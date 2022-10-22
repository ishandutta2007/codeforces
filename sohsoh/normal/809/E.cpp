#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define int			ll
#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 5e5 + 10;
const ll LOG = 20;
const ll MOD = 1e9 + 7;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

int ind[MAXN], n, tin[MAXN], tout[MAXN], inv[MAXN],
    par[MAXN][LOG], H[MAXN], t, C[MAXN], phi[MAXN], A[MAXN];
vector<int> adj[MAXN], tadj[MAXN];
ll ans = 0;

void dfs(int v, int p) {
	par[v][0] = p;
	H[v] = H[p] + 1;
	tin[v] = ++t;

	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
	tout[v] = t;
}

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			v = par[v][i];
	return v;
}

inline int LCA(int u, int v) {
	if (H[u] > H[v]) swap(u, v);
	v = Par(v, H[v] - H[u]);
	if (v == u) return v;

	for (int i = LOG - 1; i >= 0; i--)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];

	return par[v][0];
}

inline void prep_phi() {
	phi[0] = 0, phi[1] = inv[1] = 1;
	for (int i = 2; i <= n; i++)
		phi[i] = i - 1, inv[i] = poww(i, MOD - 2);

	for (int i = 2; i <= n; i++)
		for (int j = i + i; j <= n; j += i)
			phi[j] -= phi[i];
}

inline int build_virt_tree(vector<int> vec) {
	sort(all(vec), [] (int u, int v) {
		return tin[u] < tin[v];
	});

	int m = vec.size();
	for (int i = 1; i < m; i++)
		vec.push_back(LCA(vec[i - 1], vec[i]));

	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
	sort(all(vec), [] (int u, int v) {
		return tin[u] < tin[v];
	});

	for (int v : vec)
		tadj[v].clear();

	vector<int> tvec;
	for (int v : vec) {
		while (!tvec.empty() && tout[tvec.back()] < tout[v]) tvec.pop_back();
		if (!tvec.empty()) tadj[tvec.back()].push_back(v);
		tvec.push_back(v);
	}

	return vec.front();
}

ll tdfs(int v, int d) {
	ll res = (A[v] % d ? 0 : phi[A[v]]);
	for (int u : tadj[v]) {
		ll a = tdfs(u, d);
		ans = (ans + MOD - a * res % MOD * H[v] * 2 % MOD) % MOD;
		res = (res + a) % MOD;
	}

	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		ind[A[i]] = i;
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	prep_phi();
	dfs(1, 0);
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	ll fans = 0;
	for (int d = 1; d <= n; d++) {
		vector<int> vec;
		ll c = (d * inv[phi[d]] - C[d] + MOD) % MOD;

		for (int i = d; i <= n; i += d) {
			vec.push_back(ind[i]);
			C[i] = (C[i] + c) % MOD;	
		}

		int root = build_virt_tree(vec);

		ll a = 0, b = 0;
		ans = 0;
		for (int e : vec) {
			a = (a + phi[A[e]]) % MOD;
			b = (b + phi[A[e]] * H[e]) % MOD;
			ans = (ans + phi[A[e]] * phi[A[e]] % MOD * H[e]) % MOD;
		}

		ans = (a * b + MOD - ans) % MOD;
		tdfs(root, d);

		fans = (fans + ans * c) % MOD;
	//	debug(fans)
	}

	cout << fans * inv[n] % MOD * inv[n - 1] * 2 % MOD << endl;
	return 0;
}