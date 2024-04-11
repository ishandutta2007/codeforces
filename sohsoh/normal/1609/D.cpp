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

const ll MAXN = 1e3 + 10;

int n, d, sz;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int v) {
	sz++;
	vis[v] = true;

	for (int u : adj[v])
		if (!vis[u])
			dfs(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> d;
	for (int c = 1; c <= d; c++) {
		memset(vis, false, sizeof vis);
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);

		vector<int> vec;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				sz = 0;
				dfs(i);
				vec.push_back(sz);
			}
		}

		int t = int(vec.size()) - (n - c);
		sort(all(vec), greater<int>());
		int ans = 0;

		for (int i = 0; i < min(int(vec.size()), t + 1); i++) ans += vec[i];
		cout << ans - 1 << endl;
	}
	return 0;
}