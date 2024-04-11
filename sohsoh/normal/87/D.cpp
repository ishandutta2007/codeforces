#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define print(x)		    cout << "! " << #x << ": " << x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int C[MAXN], UC[MAXN], dp[MAXN], par[MAXN], par_p[MAXN], n, H[MAXN], ht[MAXN], tot;
bool vis[MAXN], in[MAXN];
vector<int> C_adj[MAXN], D[MAXN], moved_el, st;
vector<pll> vec;
vector<pair<ll, ll>> ans;
vector<pair<int, pll>> edges;
map<pll, int> mp;

void dfs(int v, int p) {
	vis[v] = true;
	dp[v] = C[v];
	ht[v] = 1;
	for (int u : C_adj[v]) {
		if (u != p) {
			dfs(u, v);
			dp[v] += dp[u];
			ht[v] = max(ht[v], ht[u] + 1);
		}
	}	
}

inline void Add(int v) {
	dp[v] = 1;
	C[v] = UC[v] = 1;
	par[v] = par_p[v] = v;
	D[v].push_back(v);	
}

inline void Union(int v, int u) {
	int tv = v, tu = u;
	v = par[v];
	u = par[u];
	if (D[v].size() > D[u].size()) swap(u, v), swap(tv, tu);	
	vec.push_back({par_p[tv], par_p[tu]});
	UC[u] += UC[v];
       	C_adj[par_p[tv]].push_back(par_p[tu]);	
       	C_adj[par_p[tu]].push_back(par_p[tv]);	
	st.push_back(par_p[tv]);
	st.push_back(par_p[tu]);

	for (int e : D[v]) {
		par[e] = u;
		D[u].push_back(e);
		moved_el.push_back(e);
	}

	D[v].clear();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) Add(i);

	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, {u, v}});
		mp[make_pair(u, v)] = i;
		mp[make_pair(v, u)] = i;
	}
	
	sort(all(edges));
	for (int i = 0; i < n - 1; i++) {
		Union(edges[i].Y.X, edges[i].Y.Y);
		if (i == n - 2 || edges[i].X != edges[i + 1].X) {
			for (int ind : st) {
				if (!vis[ind]) {
					dfs(ind, 0);
				}
			}

			for (int j = 0; j < vec.size(); j++) {
				int tind = i - vec.size() + j + 1;
				int ind = mp[make_pair(edges[tind].Y.X, edges[tind].Y.Y)];
				int u = vec[j].X, v = vec[j].Y;	
				if (ht[u] < ht[v]) swap(v, u);	
				ll tans = 1ll * dp[v] * (UC[par[edges[tind].Y.Y]] - dp[v]);	
				ans.push_back({tans, ind});
			}	

			vec.clear();
			for (int e : st) {
				C_adj[e].clear();
				C[e] = UC[e];
				vis[e] = false;
			}

			for (int e : moved_el) {
				par_p[e] = par[e];
			}

			moved_el.clear();
			st.clear();
		}
	}

	sort(all(ans));
	reverse(all(ans));
	while (ans.front().X != ans.back().X) ans.pop_back();
	cout << 2 * ans.front().X << sep << ans.size() << endl;
	reverse(all(ans));
	for (auto e : ans) cout << e.Y << sep;
	cout << endl;
	return 0;
}