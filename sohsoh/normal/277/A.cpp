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

vector<ll> lang[MAXN], adj[MAXN];
ll n, m;
bool vis[MAXN];

void dfs(ll v) {
	if (vis[v]) return;
	vis[v] = true;
	for (ll u : adj[v]) dfs(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	ll nz = 0;
	for (int i = 1; i <= n; i++) {
		ll s;
		cin >> s;
		while (s--) {
			ll x;
			cin >> x;
			lang[x].push_back(i);
			nz++;
		}
	}

	if (nz == 0) return cout << n << endl, 0;

	for (int i = 1; i <= m; i++)
		for (ll u : lang[i]) for (ll v : lang[i]) adj[u].push_back(v), adj[v].push_back(u); 
	ll C = -1;
	for (int i = 1; i <= n; i++) if (!vis[i]) C++, dfs(i);
	cout << C << endl;
	return 0;
}