// Sohsoh84 O_o //
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, A[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = true;
	for (int u : adj[v]) dfs(u);
}

inline int solve() {
	for (int i = 0; i < n + 10; i++) adj[i].clear(), vis[i] = false;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];	
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		adj[v].push_back(A[i]);
		adj[A[i]].push_back(v);
	}

	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			ans = ans * 2 % MOD;
		}
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}