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
const ll OVF = 1e13 + 3;

ll sum = 0, A[MAXN], W = 1, mx_cst = 0;
vector<int> adj[MAXN];
int n;

void boom() {
	cout << sum << endl;
	exit(0);
}

ll ovf_lcm(ll a, ll b) {
	if (a == OVF || b == OVF) return OVF;
	ll bg = b / __gcd(a, b);
	if (((1ull * a * bg) / a) != bg) return OVF;
	return a * bg;
}

void dfs(int v, int p, ll x) {
	if (x >= OVF) boom();
	if (adj[v].size() == 1 && p > 0) W = ovf_lcm(W, x);
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v, x * (ll(adj[v].size()) - ll(p > 0)));	
	}
}

void dfs2(int v, int p, ll x) {
	if (adj[v].size() == 1 && p > 0) {
		mx_cst = min(mx_cst, A[v] / (W / x));
		return;
	}

	for (int u : adj[v]) if (u != p) dfs2(u, v, x * (ll(adj[v].size()) - ll(p > 0)));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i], sum += A[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0, 1);
	if (W == OVF) boom();
	mx_cst = INF;
	dfs2(1, 0, 1);
	cout << sum - W * mx_cst << endl;
	return 0;
}