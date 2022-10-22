//: // ////: ///  / : //// / :
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

const ll MAXN = 1e6 + 10;
ll MOD;

pll exgcd(ll a, ll b) {
	if (b == 0) return {1, 0};
	pll p = exgcd(b, a % b);
	return {p.Y, p.X - p.Y * (a / b)}; // f
}

inline ll mod_inv(ll a) {
	ll x = exgcd(a, MOD).X;
	return (x % MOD + MOD) % MOD;
}

int n, sz[MAXN];
bool R[MAXN];
ll ans, pw[MAXN];
vector<int> tmp;
vector<pll> adj[MAXN];
map<int, int> mp;

int sub_dfs(int v, int p) {
	sz[v] = 1;
	for (pll e : adj[v]) {
		int u = e.X;
		if (!R[u] && u != p)
			sz[v] += sub_dfs(u, v);
	}
	return sz[v];
}

int find(int v, int p, int s) {
	for (pll e : adj[v]) {
		int u = e.X;
		if (!R[u] && u != p && sz[u] * 2 > s)
			return find(u, v, s);
	}

	return v;
}

void dfs(int v, int p, ll r, ll r2, int h) {
	for (pll e : adj[v]) {
		int u = e.X;
		if (!R[u] && u != p)
			dfs(u, v, (r * 10 + e.Y) % MOD, (r2 + e.Y * pw[h]) % MOD, h + 1);
	}

	ll t = (MOD - r) * mod_inv(pw[h]) % MOD;	
	ans += mp[t];
	tmp.push_back(r2);

}

void centroid(int v) {
	v = find(v, 0, sub_dfs(v, 0));
	R[v] = true;

	mp[0]++;
	for (pll e : adj[v]) {
		int u = e.X;
		if (!R[u]) {
			dfs(u, v, e.Y, e.Y, 1);
			for (int e : tmp) mp[e]++;
			tmp.clear();
		}
	}
	mp.clear();

	reverse(all(adj[v]));
	for (pll e : adj[v]) {
		int u = e.X;
		if (!R[u]) {
			dfs(u, v, e.Y, e.Y, 1);
			for (int e : tmp) mp[e]++;
			tmp.clear();
		}
	}

	ans += mp[0];
	mp.clear();

	for (pll e : adj[v])
		if (!R[e.X])
			centroid(e.X);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> MOD;
	pw[0] = 1;
	for (int i = 1; i < MAXN; i++) pw[i] = pw[i - 1] * 10 % MOD;

	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		c = c % MOD;
		u++, v++;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}

	centroid(1);
	cout << ans << endl;
	return 0;
}