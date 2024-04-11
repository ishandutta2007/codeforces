#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define int  			    ll

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n;
vector<int> adj[MAXN];
ll ans[MAXN], sub_g[MAXN], tin[MAXN], tout[MAXN], T;

void dfs(int v = 0, int p = 0) {
	sub_g[v] = 1;
	tin[v] = T++;

	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		sub_g[v] += sub_g[u];
	}

	if (v != 0 && p == 0) ans[0] -= sub_g[v] * (sub_g[v] - 1) / 2;
	tout[v] = T++;
}

bool subg(int v, int u) {
	return tin[v] <= tin[u] && tout[v] >= tout[u];
}

inline void solve() {
	for (int i = 0; i < n + 10; i++) {
		ans[i] = 0;
		adj[i].clear();
		tin[i] = tout[i] = sub_g[i] = T = 0;
	}

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ans[0] = n * (n - 1) / 2;	
	dfs();
	int L = 0, R = 0;

	ll X = 1, tpar = 0;
	for (int u : adj[0]) {
		if (subg(u, 1)) {
			tpar = u;
			continue;
		}
		X += sub_g[u];
	}

	for (int v = 1; v < n; v++) {
		if (subg(R, L)) swap(L, R);
		
		if (subg(R, v)) R = v;
		if (!subg(v, R)) {
			if (L == 0) {
				if (subg(tpar, v)) break;
				else L = v;
			} else {
				if (!subg(v, L)) {
					if (!subg(L, v)) break;
					else L = v;
				}
			}
		} 

			
		if (!subg(L, R)) ans[v] = sub_g[L] * sub_g[R];
		else ans[v] = sub_g[R] * X;
	}

	cout << n * (n - 1) / 2 - ans[0] << sep;
	for (int i = 0; i < n; i++)
		cout << ans[i] - ans[i + 1] << sep;
	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;

	while (t--) solve();
	return 0;
}