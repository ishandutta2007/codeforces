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

ll n, k, center = 1;
vector<ll> adj[MAXN], diam;
ll dist[MAXN] = {0};

void dfs(ll v, ll p, ll d) {
	dist[v] = d;
	for (ll u : adj[v]) if (u != p) dfs(u, v, d + 1);
}

void kill_no() {
	cout << "No" << endl;
	exit(0);
}

void final_dfs(ll v, ll p, ll d) {
	if (adj[v].size() == 1) {
		if (d == k) return;
		kill_no();
	}
	
	if (d == 0 && adj[v].size() < 3) kill_no();
	if (d > 0 && adj[v].size() < 4) kill_no();
	
	for (ll u : adj[v]) if (u != p) final_dfs(u, v, d + 1);	
}

void print_ans() {
	center = diam[diam.size() / 2];
	final_dfs(center, 0, 0);
	cout << "Yes" << endl;
	exit(0);
}

void diam_dfs(ll v, ll p, ll tar) {
	diam.push_back(v);

	if (v == tar) print_ans();
	for (ll u : adj[v]) if (u != p) diam_dfs(u, v, tar);
	diam.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1, 0, 0);
	ll v = max_element(dist + 1, dist + n + 1) - dist;
	dfs(v, 0, 0);
	ll u = max_element(dist + 1, dist + n + 1) - dist;
	diam_dfs(v, 0, u);
	cout << "No" << endl;
	return 0;
}