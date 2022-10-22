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

const ll MAXN = 2e5 + 10;
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

vector<int> adj[MAXN];
ll ans = 0, fact[MAXN], inv[MAXN], n, k, sz[MAXN];

inline ll C(ll k, ll n) {
	if (k < 0 || k > n) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

void dfs(int v, int p) {
	sz[v] = 1;
	ans = (ans + C(k, n) * n) % MOD;
	ll S = 0;

	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		sz[v] += sz[u];	
		S = (S + C(k, sz[u])) % MOD;
	}

	ans = (ans - (n - sz[v]) * sz[v] % MOD * S % MOD + MOD) % MOD;
	S += C(k, n - sz[v]);
	ans = (ans - n * S % MOD + MOD) % MOD;
	ans = (ans + (n - sz[v]) * sz[v] % MOD * C(k, sz[v]));
	
	for (int u : adj[v]) {
		if (u == p) continue;
		ans = (ans + sz[u] * (n - sz[u]) % MOD * C(k, n - sz[u])) % MOD;
		ans = (ans - sz[u] * (n - sz[u]) % MOD * ((S - C(k, sz[u]) + MOD) % MOD) % MOD + MOD) % MOD;	
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = poww(fact[i], MOD - 2);
	}	

	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	cout << ans << endl;
	return 0;
}