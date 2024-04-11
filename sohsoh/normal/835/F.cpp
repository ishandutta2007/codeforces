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
const ll MOD = 1e9 + 7; // 998244353;

vector<pll> adj[MAXN];
vector<int> cyc;
int H[MAXN], low[MAXN], deg[MAXN], sz;
ll W[MAXN], mx_dist, mx_dist_v, diam[MAXN], mx_diam, pref_dist[MAXN], pref_w[MAXN], pref_w2[MAXN], suff_w[MAXN], suff_w2[MAXN], CN = 0;
bool vis[MAXN];

void dfs1(int v, int p) {
	low[v] = H[v];
	vis[v] = true;
	for (pll e : adj[v]) {
		int u = e.X;
		if (u == p) continue;
		if (vis[u]) {
			low[v] = min(low[v], H[u]);
			deg[v]++;
		} else {
			H[u] = H[v] + 1;
			dfs1(u, v);
			low[v] = min(low[v], low[u]);
		}
	}

	if (low[v] < H[v]) deg[v]++, deg[p]++;
}

void dfs2(int v, ll d = 0) {
	vis[v] = true;
	pref_dist[sz++] = d;
	cyc.push_back(v);
	for (pll e : adj[v])
		if (deg[e.X] > 1 && !vis[e.X])
			dfs2(e.X, d + e.Y);
}

void dfs3(int v, int p, ll d) {
	if (d > mx_dist) {
		mx_dist = d;
		mx_dist_v = v;
	}

	for (pll e : adj[v]) {
		int u = e.X, w = e.Y;
		if (u != p && deg[u] < 2) dfs3(u, v, d + w);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	dfs1(1, 0);

	memset(vis, 0, sizeof vis);
	int v = 1;
	for (int i = 1; i <= n; i++) if (deg[i] >= 2) v = i;
       	dfs2(v);	
	for (int i = 0; i < sz; i++) {
		int v = cyc[i];
		deg[v] = 1;
		mx_dist = 0, mx_dist_v = v;
		dfs3(v, 0, 0);
		W[i] = mx_dist;
		dfs3(mx_dist_v, 0, 0);
		diam[i] = mx_dist;
		mx_diam = max(mx_diam, diam[i]);
		deg[v] = 2;
	}

	for (pll e : adj[cyc.front()]) 
		if (e.X == cyc.back())
			CN = e.Y;

	ll mx_open = 0;
	for (int i = 0; i < sz; i++) {
		pref_w[i] = W[i] + pref_dist[i];
		if (i) {
			pref_w[i] = max(pref_w[i], pref_w[i - 1]);
			mx_open += pref_dist[i] - pref_dist[i - 1];
			pref_w2[i] = max(pref_w2[i - 1], mx_open + W[i]);
		}

		mx_open = max(mx_open, W[i]);
	}


	mx_open = 0;
	for (int i = sz - 1; i >= 0; i--) {
		suff_w[i] = W[i] + pref_dist[sz - 1] - pref_dist[i];
		if (i < sz - 1) {
			suff_w[i] = max(suff_w[i], suff_w[i + 1]);
			mx_open += pref_dist[i + 1] - pref_dist[i];
			suff_w2[i] = max(suff_w2[i + 1], mx_open + W[i]);
		}

		mx_open = max(mx_open, W[i]);
	}


	ll ans = INF;
	for (int i = 0; i < sz - 1; i++) {
		ll tans = mx_diam;
		tans = max(tans, pref_w2[i]);
		tans = max(tans, suff_w2[i + 1]);
		tans = max(tans, pref_w[i] + CN + suff_w[i + 1]);
		ans = min(ans, tans);
	}

	ans = min(ans, max(mx_diam, pref_w2[sz - 1]));
	cout << ans << endl;
	return 0;
}