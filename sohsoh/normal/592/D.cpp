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
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int tot_cnt[MAXN], dp_down[MAXN], dp_down_sec[MAXN], dp_up[MAXN], tdp_down[MAXN], tdp_up[MAXN], is_down[MAXN], n, m;
vector<int> adj[MAXN];
bool B[MAXN];

void dfs(int v, int p) {
	if (B[v]) tot_cnt[v] = 1, dp_down[v] = dp_down_sec[v] = dp_up[v] = 0, is_down[v] = true;
	for (int u : adj[v]) {
		if (u != p) {
			dfs(u, v);
			if (dp_down[u] + 1 > dp_down_sec[v]) dp_down_sec[v] = dp_down[u] + 1;
			if (dp_down_sec[v] > dp_down[v]) swap(dp_down[v], dp_down_sec[v]);
			is_down[v] |= is_down[u];
			tot_cnt[v] += tot_cnt[u];
			if (is_down[u]) tdp_down[v] += 2 + tdp_down[u];
		}
	}
}

void dfs2(int v, int p) {
	if (p) {
		dp_up[v] = max(dp_up[v], dp_up[p] + 1);
		if (dp_down[p] == dp_down[v] + 1) dp_up[v] = max(dp_up[v], dp_down_sec[p] + 1);
		else dp_up[v] = max(dp_up[v], dp_down[p] + 1);
		if (tot_cnt[v] < m) tdp_up[v] += tdp_up[p] + tdp_down[p] - tdp_down[v] + 2 - 2 * int(is_down[v] == true);
	}

	for (int u : adj[v]) if (u != p) dfs2(u, v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	fill(dp_down, dp_down + MAXN, -INF);
	fill(dp_down_sec, dp_down_sec + MAXN, -INF);
	fill(dp_up, dp_up + MAXN, -INF);

	for (int i = 0; i + 1 < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < m; i++) {
		int v;
		cin >> v;
		B[v] = true;
	}
	
	dfs(1, 0);
	dfs2(1, 0);
	
	int ans = int(1e9), ans2 = 1;
	for (int i = 1; i <= n; i++) {
		int val = tdp_up[i] + tdp_down[i] - max(dp_down[i], dp_up[i]); 
		if (val < ans) ans = val, ans2 = i;
	}
	
	cout << ans2 << endl << ans << endl;
	return 0;
}