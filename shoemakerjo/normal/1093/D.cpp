#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define ll long long
#define maxn 300010
const int mod = 998244353;
vector<pii> comps;

vector<int> adj[maxn];
int n, m;

int col[maxn];

ll pows[maxn];

bool ok;
int num1, num2;

void dfs(int u) {
	if (col[u] == 1) num1++;
	else num2++;

	for (int v : adj[u]) {
		if (col[v] == 0) {
			if (col[u] == 1) col[v] = 2;
			else col[v] = 1;
			dfs(v);
		}
		if (col[v] == col[u]) ok = false;
	}
}

void solve() {
	comps.clear();
	ok = true;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		col[i] = 0;
	}

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		
		if (col[i] == 0) {
			num2 = 0;
			num1 = 0;
			col[i] = 1;
			dfs(i);
			// cout << "thing: " << num1 << " " << num2 << endl;
			comps.push_back(pii(num1, num2));
		}
	}

	ll ans = 0LL;
	if (!ok) {
		// cout << "HERE" << endl;
		cout << ans << endl;
		return;
	}

	ans = 1LL;
	for (pii vp : comps) {
		ll a = vp.first;
		ll b = vp.second;

		ll numop = (pows[a] + pows[b]) %mod;


		ans = (ans * numop)%mod;

	}


	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pows[0] = 1LL;
	for (int i = 1; i < maxn; i++) {
		pows[i] = (pows[i-1]*2LL) %mod;
	}

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}