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

int n, m, A[MAXN];
vector<int> adj[MAXN], ans;
bool vis[MAXN];

void flip(int i) {
	 A[i] = 1 - A[i];
} 

void dfs(int v, int p) {
	vis[v] = true;	
	flip(v);
	ans.push_back(v);	
	if (p == 0 && adj[v].size() == 0) return;
	for (int u : adj[v]) if (!vis[u]) dfs(u, v), ans.push_back(v), flip(v);
	if (A[v] == 0) return;
	if (p > 0) {
		ans.push_back(p);
	       	flip(p);
		ans.push_back(v);
		flip(v);
		return;
	} else ans.pop_back(), flip(v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) cin >> A[i];

	if (find(A, A + MAXN, 1) == A + MAXN) return cout << 0 << endl, 0;
	int root = find(A, A + MAXN, 1) - A;
	dfs(root, 0);
	if (find(A, A + MAXN, 1) != A + MAXN) return cout << -1 << endl, 0;
	cout << ans.size() << endl;
	for (ll e : ans) cout << e << sep;
	cout << endl;
	return 0;
}