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

int n, C = 0;
vector<int> adj[MAXN];
bool vis[MAXN];

bool is_lucky(ll n) {
	while (n > 0) {
		if (n % 10 != 7 && n % 10 != 4) return false;
		n /= 10;
	}

	return true;
}

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = true;
	C++;
	for (int u : adj[v]) dfs(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		if (!is_lucky(c)) adj[v].push_back(u), adj[u].push_back(v);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			C = 0;
		       	dfs(i);
			ans += ll(C) * ll(n - C) * ll(n - C - 1);
		}
	}

	cout << ans << endl;
	return 0;
}