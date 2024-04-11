#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll OVF = 1e9 + 10;
const ll MOD = 998244353;

int n, m;
ll f[MAXN];
vector<int> adj[MAXN], ord;
bool vis[MAXN];

void dfs(int v) {
	vis[v] = true;
	for (int u : adj[v])
		if (!vis[u])
			dfs(u);

	ord.push_back(v);
}

inline int solve() {
	ord.clear();
	for (int i = 0; i < n + 10; i++) {
		adj[i].clear();
		vis[i] = false;
		f[i] = 0; 
	}

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> f[i];

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);
	
	ll t = 0;
	while (t <= n + 10) {
		bool flag = false;
		for (int v : ord) {
			if (f[v]) {
				f[v]--;
				for (int u : adj[v])
					f[u]++;
				
				flag = true;
			}
		}

		if (!flag) return cout << t << endl, 0;
		t++;
	}

	reverse(all(ord));
	for (int v : ord) {
		for (int u : adj[v])
			f[u] = (f[u] + f[v]) % MOD;
	}

	cout << (f[ord.back()] + t) % MOD << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}