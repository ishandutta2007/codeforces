#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool vis[MAXN];
int cnt[MAXN], C = 0, n, m, dp[2][MAXN];
vector<pll> V;
vector<int> adj[MAXN];

void dfs(int v) {
	vis[v] = true;
	C++;
	for (int u : adj[v]) {
		if (vis[u]) continue;
		dfs(u);
	}
}

bool Lucky(int n) {
	while (n) {
		if (n % 10 != 4 && n % 10 != 7) return false;
		n = n / 10;
	}

	return true;
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

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i), cnt[C]++, C = 0;
	
	for (int i = 0; i <= n; i++) {
		int r = 1;
		while (cnt[i]) {
			int t = (min(r, cnt[i]));
			V.push_back({t * i, t});
			cnt[i] -= t;
			r <<= 1;
		}
	} 

	fill(dp[1], dp[1] + MAXN, MAXN);
	dp[1][0] = 0;
	for (int i = 0; i < V.size(); i++) {
		int x = V[i].X, w = V[i].Y, t = i & 1;
		for (int j = n; j >= 0; j--) {
			dp[t][j] = dp[t ^ 1][j];
			if (j >= x) dp[t][j] = min(dp[t][j], dp[t ^ 1][j - x] + w);
		}
	}

	int ans = MAXN;
	for (int i = 1; i <= n; i++)
		if (Lucky(i))
			ans = min(ans, dp[(V.size() - 1) & 1][i]);
	cout << (ans <= n ? ans - 1 : -1) << endl;
	return 0;
}