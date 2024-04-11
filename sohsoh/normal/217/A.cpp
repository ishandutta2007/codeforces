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

vector<pll> v;
vector<ll> adj[MAXN];
bool vis[MAXN];

void dfs(ll v) {
	if (vis[v]) return;
	vis[v] = true;
	for (ll u : adj[v]) dfs(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		pll e;
		cin >> e.X >> e.Y;
		for (int j = 0; j < v.size(); j++) if (v[j].X == e.X || v[j].Y == e.Y) adj[j].push_back(v.size()), adj[v.size()].push_back(j);
		v.push_back(e);
	}


	ll ans = -1;
	for (int i = 0; i < n; i++) if (!vis[i]) ans++, dfs(i);
	cout << ans << endl;
	return 0;
}