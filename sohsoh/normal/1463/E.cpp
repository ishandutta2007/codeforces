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

int n, k, P_par[MAXN], P_ind[MAXN], tmp = 1, prv[MAXN], nxt[MAXN], vis[MAXN];
vector<int> t_adj[MAXN], P[MAXN], adj[MAXN], ans;
bool vis2[MAXN];

// check for cycle in final graph
// check for inversion in paths

inline void kill() {
	cout << 0 << endl;
	exit(0);
}

inline void TRV(int v) {
	P[tmp].push_back(v);
	P_ind[v] = 1;
	vis2[v] = true;
	P_par[v] = tmp;
	int ind = 1;
	while (nxt[v]) {
		ind++;
		if (vis2[nxt[v]]) kill();
		v = nxt[v];
		vis2[v] = true;
		P_par[v] = tmp;
		P_ind[v] = ind;
		P[tmp].push_back(v);
	}
	tmp++;
}

inline void Merge(int v, int t) {
	for (int u : t_adj[v]) {
		if (P_par[u] == t) {
			if (P_ind[u] < P_ind[v]) kill();
			continue;
		}

		adj[t].push_back(P_par[u]);
	}
}

void dfs(int v) {
	vis[v] = 1;
	for (int u : adj[v]) {
		if (vis[u] == 1) kill();
		if (vis[u] == 0) dfs(u);
	}

	vis[v] = 2;	
	ans.push_back(v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		t_adj[p].push_back(i);
	}

	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		prv[v] = u;
		nxt[u] = v;
	}

	for (int i = 1; i <= n; i++)
		if (prv[i] == 0) TRV(i);
	for (int i = 1; i <= n; i++) {
		if (!vis2[i]) kill();
		Merge(i, P_par[i]);
	}

	for (int i = 1; i <= tmp; i++) if (!vis[i]) dfs(i);
	reverse(all(ans));
	for (int e : ans)
		for (int v : P[e]) cout << v << sep;
	cout << endl;
	return 0;
}