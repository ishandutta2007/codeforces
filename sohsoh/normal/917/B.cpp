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
 
const ll MAXN = 1e2 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<pll> adj[MAXN];
ll mem[MAXN][MAXN][26] = {0};

ll calc(ll u, ll v, ll c) { 
	if (mem[u][v][c] > 0) return mem[u][v][c];
	mem[u][v][c] = 2;
	for (pll e : adj[u]) if (e.Y >= c && calc(v, e.X, e.Y) == 2) mem[u][v][c] = 1;
	return mem[u][v][c];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll u, v;
		char c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c - 'a'});
	}

	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			ll x = calc(u, v, 0);
			if (x == 1) cout << 'A';
			else cout << 'B';
		}

		cout << endl;
	}
	return 0;
}