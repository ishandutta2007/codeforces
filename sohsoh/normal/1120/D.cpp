#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

ll dp[MAXN][2], diff[MAXN], mx[MAXN], F[MAXN], cnt[MAXN];
int n, C[MAXN];
vector<int> adj[MAXN], ans;

void dfs(int v, int p) {
	mx[v] = -1;
	if (adj[v].size() == 1 && p) {
		dp[v][0] = C[v];
		diff[v] = C[v];
		return;
	}

	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		dp[v][0] += dp[u][0];
		
		if (diff[u] > mx[v]) mx[v] = diff[u], cnt[v] = 1;
		else if (diff[u] == mx[v]) cnt[v]++;
	}

	F[v] = dp[v][0];
	dp[v][1] = dp[v][0] - mx[v];
	dp[v][0] = min(F[v], dp[v][1] + C[v]);
	diff[v] = dp[v][0] - dp[v][1];
}

void dfs2(int v, int p, int state) {
	if (adj[v].size() == 1 && p) {
		if (state & 1) ans.push_back(v);
		return;
	}

	if (state & 1) {
		if (F[v] != dp[v][0]) state = 2;
		if (dp[v][1] + C[v] == dp[v][0]) {
			ans.push_back(v);
			state |= 2;
		}
	}

	for (int u : adj[v]) {
		if (u == p) continue;
		int tstate = 0;

		if (state & 2) {
			if (diff[u] == mx[v]) {
				if (cnt[v] > 1) tstate |= 3;
				else tstate |= 2;
			} else tstate |= 1;
		}

		if (state & 1) tstate |= 1;
		dfs2(u, v, tstate);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> C[i];

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	dfs2(1, 0, 1);

	cout << dp[1][0] << sep << ans.size() << endl;
	sort(all(ans));
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}