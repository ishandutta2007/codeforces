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

ll deg[MAXN] = {0};
queue<ll> lf;
vector<ll> adj[MAXN];
ll A[MAXN], ans = 0;

void dfs(ll v, ll p) {
	for (ll u : adj[v]) if (u != p) dfs(u, v);
	if (A[v] == v) {
		ans += 2;
		if (p) swap(A[v], A[p]);
		else swap(A[v], A[adj[v][0]]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 0; i <= n; i++) A[i] = i;
	for (int i = 1; i <= n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);

	cout << ans << endl;
	for (int i = 1; i <= n; i++) cout << A[i] << sep;
       	cout << endl;	
	return 0;
}