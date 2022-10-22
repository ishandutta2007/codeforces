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

int n, m, ans[MAXN], C[MAXN], sub_g[MAXN], q;
unordered_map<int, int> cnt[MAXN], mp[MAXN];
vector<pll> Q[MAXN];
vector<int> adj[MAXN];

inline void Push(int v, int c) {
	cnt[v][c]++;
	mp[v][cnt[v][c]]++;
}

void dfs(int v, int p) {
	sub_g[v] = 1;
	Push(v, C[v]);
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		if (sub_g[v] < sub_g[u]) {
			cnt[v].swap(cnt[u]);
			mp[v].swap(mp[u]);
		}

		for (pll e : cnt[u]) {
			while (e.Y) {
				e.Y--;
				Push(v, e.X);
			}
		}

		sub_g[v] += sub_g[u];
		mp[u].clear();
		cnt[u].clear();
	}

	for (pll e : Q[v]) ans[e.X] = mp[v][e.Y];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> C[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < q; i++) {
		int v, k;
		cin >> v >> k;
		Q[v].push_back({i, k});
	}

	dfs(1, 0);
	for (int i = 0; i < q; i++) cout << ans[i] << endl;
	return 0;
}