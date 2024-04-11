#include <bits/stdc++.h>

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
const ll MOD = 998244353;
const ll SQ = 700;
const ll LOG = 20;

inline void mkay(int& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

int ans[MAXN], F[MAXN], n, q, s[MAXN], t,
    tin[MAXN], tout[MAXN], sz[MAXN], par[MAXN][LOG], H[MAXN];
ll inv;
vector<int> adj[MAXN];
vector<pll> Q;

void dfs(int v, int p) {
	par[v][0] = p;
	sz[v] = 1;
	tin[v] = ++t;
	H[v] = H[p] + 1;

	for (int u : adj[v]) {
		if (u != p) {
			dfs(u, v);
			sz[v] += sz[u];
		}
	}

	tout[v] = t;
}

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			v = par[v][i];
	return v;
}

void push_dfs(int v, int p, int f) {
	mkay(f += s[v]);
	mkay(ans[v] += f);

	for (int u : adj[v]) {
		if (u == p) continue;
		push_dfs(u, v, (f + 1ll * F[v] * (n - sz[u]) % MOD * inv) % MOD);
	}

	F[v] = s[v] = 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	inv = poww(n, MOD - 2);

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			ll v, d;
			cin >> v >> d;
			Q.push_back({v, d});

			if (v != 1) {
				int k = d * sz[v] % MOD * inv % MOD;
				mkay(s[1] += k);
				mkay(s[v] -= k);
			}

			mkay(F[v] += d);
			mkay(ans[v] += d);
		} else {
			int v;
			cin >> v;
			ll fans = ans[v];

			for (auto e : Q) {
				int u = e.X;
				ll d = e.Y;
				if (u == v) continue;
				
				if (tin[u] <= tin[v] && tout[u] >= tout[v]) {
					fans = (fans + d * (n - sz[Par(v, H[v] - H[u] - 1)]) % MOD * inv) % MOD;		
				} else {
					fans = (fans + d * sz[u] % MOD * inv) % MOD;
				}
			}

			cout << fans << endl;
		}

		if (Q.size() >= SQ) {
			push_dfs(1, 0, 0);
			Q.clear();
		}
	}
	return 0;
}