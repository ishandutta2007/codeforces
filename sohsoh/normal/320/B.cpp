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

vector<ll> adj[MAXN];
bool vis[MAXN];
vector<pll> v;

void dfs(ll v) {
	if (vis[v]) return;
	vis[v] = true;
	for (ll u : adj[v]) dfs(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll c, a, b;
		cin >> c >> a >> b;
		if (c == 1) {
			for (int i = 0; i < v.size(); i++) {
				int c = v[i].X, d = v[i].Y;
				if ((c < a && a < d) || (c < b && b < d)) adj[v.size()].push_back(i);
				if ((a < c && c < b) || (a < d && d < b)) adj[i].push_back(v.size());  
			}

			v.push_back({a, b});
		} else {
			memset(vis, false, sizeof vis);
			dfs(a - 1);
			if (vis[b - 1]) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}