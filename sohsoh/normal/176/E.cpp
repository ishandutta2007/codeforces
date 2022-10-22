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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 20;

int n, q, tin[MAXN], t;
vector<pll> adj[MAXN];
int par[MAXN][LOG], H[MAXN];
ll W[MAXN][LOG];

void dfs(int v, int p, int p_w) {
	par[v][0] = p;
	W[v][0] = p_w;
	H[v] = H[p] + 1;
	tin[v] = t++;
	
	for (pll e : adj[v]) 
		if (e.X != p)
			dfs(e.X, v, e.Y);
}

pll Par(int v, int k) {
	ll ans = 0;
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			ans += W[v][i], v = par[v][i];
	return {v, ans};
}

ll Path(int u, int v) {
	if (H[v] < H[u]) swap(u, v);
	pll e = Par(v, H[v] - H[u]);
	v = e.X;
	ll ans = e.Y;
	if (v == u) return ans;

	for (int i = LOG - 1; i >= 0; i--) {
		if (par[v][i] != par[u][i]) {
			ans += W[v][i];
			ans += W[u][i];
			v = par[v][i];
			u = par[u][i];
		}
	}

	return ans + W[v][0] + W[u][0];
}

struct cmp {
	bool operator() (int a, int b) const {
		return tin[a] < tin[b];
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	dfs(1, 0, 0);
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1], W[v][i] = W[v][i - 1] + W[par[v][i - 1]][i - 1];
	
	set<int, cmp> st;
	ll ans = 0;
	cin >> q;

	while (q--) {
		char c;
		cin >> c;
		if (c == '?') cout << ans / 2 << endl;
		else if (c == '+') {
			int v;
			cin >> v;
			auto it = st.insert(v).X;	
			
			pll p;
			if (it == st.begin()) p.X = *st.rbegin();
			else p.X = *prev(it);
			if (next(it) == st.end()) p.Y = *st.begin();
			else p.Y = *next(it);
			
			ans += Path(v, p.X);
			ans += Path(v, p.Y);
			ans -= Path(p.X, p.Y);
		} else {
			int v;
			cin >> v;
			auto it = st.find(v);	
			
			pll p;
			if (it == st.begin()) p.X = *st.rbegin();
			else p.X = *prev(it);
			if (next(it) == st.end()) p.Y = *st.begin();
			else p.Y = *next(it);
			
			ans -= Path(v, p.X);
			ans -= Path(v, p.Y);
			ans += Path(p.X, p.Y);
			st.erase(v);			
		}
	}
	return 0;
}