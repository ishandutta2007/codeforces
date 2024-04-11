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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, S[MAXN] = {0}, N[MAXN] = {0}, A[MAXN] = {0};
vector<ll> adj[MAXN];

void dfs(ll v, ll p) {
	ll x = INF;
	for (ll u : adj[v]) if (u != p) dfs(u, v), x = min(x, S[u] - S[p]);
	if (x == INF) x = 0;
	if (S[v] < 0) A[v] = x;
}

void dfs2(ll v, ll p, ll s = 0) {
	if (S[v] >= 0) A[v] = S[v] - s;
	s += A[v];
	for (ll u : adj[v]) if (u != p) dfs2(u, v, s);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		ll u, v = i;
		cin >> u;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++) cin >> S[i];
	A[1] = S[1];
	dfs(1, 0);
	dfs2(1, 0);
	ll ans = 0;
	
	for (int i = 0; i <= n; i++) {
		if (A[i] < 0) return cout << -1 << endl, 0;
		ans += A[i];
	}

	cout << ans << endl;
	return 0;
}