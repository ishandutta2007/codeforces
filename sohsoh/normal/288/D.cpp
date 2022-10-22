#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<int> adj[MAXN];
ll sub_g[MAXN], n, ans = 0;

inline ll C(ll n) {
	return n * (n - 1) / 2ll;
}

void dfs(int v, int p) {
	sub_g[v] = 1;
	ll P = 0;
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		sub_g[v] += sub_g[u];
		P -= C(sub_g[u]);
	}

	P += C(sub_g[v]);
	ans -= P * (P - 1);
	ans -= 2 * P * (sub_g[v] * (n - sub_g[v]));	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ans = C(n) * (C(n) - 1);
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}