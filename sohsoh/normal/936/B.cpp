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

bool odd_vis[MAXN] = {false}, even_vis[MAXN] = {false}, cycle = false;
ll n, m, col[MAXN];
vector<ll> adj[MAXN], vec;

void win() {
	cout << "Win" << endl;
	for (ll e : vec) cout << e << sep;
	cout << endl;
	exit(0);
}

void dfs(ll v) {
	if (vec.size() % 2) odd_vis[v] = true;
	else even_vis[v] = true;
	vec.push_back(v);
	if (adj[v].empty() && vec.size() % 2 == 0) win();
	for (ll u : adj[v]) {
		if (vec.size() % 2 == 1 && !odd_vis[u]) dfs(u);
		if (vec.size() % 2 == 0 && !even_vis[u]) dfs(u);
	}

	vec.pop_back();
}

void dfs2(ll v) {
	col[v] = 1;
	for (ll u : adj[v]) {
		if (col[u] == 0) dfs2(u);
		else if (col[u] == 1) cycle = true;
	}

	col[v] = 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ll c;
		cin >> c;
		for (int j = 0; j < c; j++) {
			ll t;
			cin >> t;
			adj[i].push_back(t);
		}
	}

	ll s;
	cin >> s;
	dfs(s);
	dfs2(s);
	if (cycle) return cout << "Draw" << endl, 0;
	cout << "Lose" << endl;
	return 0;
}