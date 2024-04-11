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

int n, par[MAXN], H[MAXN], S[MAXN];
ll pcnt, prv_pcnt, ans;
vector<int> adj[MAXN];
vector<pair<int, int>> vec;

inline ll C(ll n) {
	return n * (n - 1) / 2;
}
	
inline void make_set(int v) {
	par[v] = v;
	H[v] = 0;
	S[v] = 1;
}

int find_set(int v) {
	if (v == par[v]) return v;
	return find_set(par[v]);
}

inline void union_sets(int v, int u) {
	v = find_set(v);
	u = find_set(u);
	if (u == v) return;	
	if (H[v] > H[u]) swap(v, u);

	pcnt -= C(S[v]);
	pcnt -= C(S[u]);
	pcnt += C(S[v] + S[u]);
	S[u] += S[v];
	S[v] = 0;

	par[v] = u;
	if (H[v] == H[u]) H[u]++;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		vec.push_back({x, i});
	}	

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	sort(all(vec));
	for (auto e : vec) {
		int v = e.Y, a_v = e.X;

		prv_pcnt = pcnt;
		make_set(v);
		for (int u : adj[v])
			if (par[u] != 0) union_sets(u, v);
		ans += 1ll * a_v * (pcnt - prv_pcnt);
	}

	memset(par, 0, sizeof par);
	memset(S, 0, sizeof S);
	memset(H, 0, sizeof H);
	pcnt = 0;
	prv_pcnt = 0;
		
	reverse(all(vec));
	for (auto e : vec) {
		int v = e.Y, a_v = e.X;

		prv_pcnt = pcnt;
		make_set(v);
		for (int u : adj[v])
			if (par[u] != 0) union_sets(u, v);
		ans -= 1ll * a_v * (pcnt - prv_pcnt);
	}

	printf("%lld", ans);
	return 0;
}