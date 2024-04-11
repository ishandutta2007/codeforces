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
const ll LOG = 22;

vector<ll> dfs_time, adj[MAXN], D[MAXN], roots;
int n, m, tin[MAXN], tout[MAXN], depth[MAXN];
int par[LOG][MAXN];

void dfs(int v, int p, int d) {
	dfs_time.push_back(v);
	tin[v] = dfs_time.size() - 1;
	depth[v] = d;
	D[d].push_back(tin[v]);
	for (int u : adj[v]) if (u != p) dfs(u, v, d + 1);
	dfs_time.push_back(v);
	tout[v] = dfs_time.size();
}

int i_th_ancestor(int v, int i) {
	int j = 0;
	while (i > 0) {
		if (i & 1) v = par[j][v];
		j++;
		i >>= 1;
	}

	return v;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x == 0) roots.push_back(i);
		else {
			adj[x].push_back(i);
			par[0][i] = x;
		}
	}

	for (int i = 1; i <= n; i++) for (int j = 1; j < LOG; j++) par[j][i] = par[j - 1][par[j - 1][i]];
	
	for (int e : roots) dfs(e, 0, 0);

	cin >> m;
	while (m--) {
		int v, p;
		cin >> v >> p;
		int anc = i_th_ancestor(v, p);
		if (anc <= 0) {
			cout << 0 << sep;
			continue;
		}

		cout << upper_bound(all(D[depth[v]]), tout[anc]) - lower_bound(all(D[depth[v]]), tin[anc]) - 1 << sep;
	} 

	cout << endl;
	return 0;
}