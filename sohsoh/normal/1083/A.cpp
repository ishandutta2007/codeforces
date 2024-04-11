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

vector<pll> adj[MAXN];
ll A[MAXN] = {0}, S[MAXN] = {0}, ans = 0;

void dfs(ll v, ll par = -1) {
	S[v] = A[v];
	ans = max(ans, A[v]);
	for (pll p : adj[v]) {
		ll u = p.X, c = p.Y;
		if (u == par) continue;
		dfs(u, v);
		ans = max(ans, S[v] + S[u] - c);
		S[v] = max(S[v], S[u] + A[v] - c);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 0; i < n - 1; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	
	dfs(1);
	cout << ans << endl;
	return 0;
}