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

int n, root, P[MAXN], vis[MAXN], ans = 0;
vector<ll> adj[MAXN];

void build_graph() {
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i <= n; i++) if (i != P[i]) adj[P[i]].push_back(i);
}

void smth(int v) {
	vis[v] = 1;
	for (ll u : adj[v]) {
		if (vis[u] == 0) smth(u);
		else if (vis[u] == 1) root = u;
	}

	vis[v] = 2;
}

void dfs(int v) {
	vis[v] = 1;
	for (ll u : adj[v]) {
		if (vis[u] == 0) dfs(u);
		else if (vis[u] == 1) P[u] = root, ans++;
	}

	vis[v] = 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> P[i];
		if (P[i] == i) {
			if (root) P[i] = root, ans++;
			else root = P[i];
		}
	}

	if (root == 0) {
		root = 1;
		build_graph();
		for (int i = 1; i <= n; i++) if (!vis[i]) smth(i);
		ans++;
		P[root] = root;
	}

	build_graph();
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
	cout << ans << endl;
	for (int i = 1; i <= n; i++) cout << P[i] << sep;
	cout << endl;
	return 0;
}