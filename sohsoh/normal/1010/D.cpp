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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

string A[MAXN];
ll T[MAXN];
ll val[MAXN], n;
vector<ll> adj[MAXN];
vector<ll> ans_rev;

ll dfs1(ll v) {
	if (A[v] == "AND") return val[v] = dfs1(adj[v][0]) & dfs1(adj[v][1]);
	else if (A[v] == "OR") return val[v] = dfs1(adj[v][0]) | dfs1(adj[v][1]);
	else if (A[v] == "XOR") return val[v] = dfs1(adj[v][0]) ^ dfs1(adj[v][1]);
	else if (A[v] == "NOT") return val[v] = 1 - dfs1(adj[v][0]);
	return val[v];
}

void dfs(ll v) {
	if (A[v] == "IN") {
		ans_rev.push_back(T[v]);
		return;
	}

	if (A[v] == "AND") {
		ll a1 = adj[v][0], a2 = adj[v][1];
		ll v1 = val[a1], v2 = val[a2];
		if (v1 == 0 && v2 == 0) return;
		if (v1 == 1 && v2 == 1) {
			dfs(a1);
			dfs(a2);
			return;
		}

		if (v1 == 0) {
			dfs(a1);
			return;
		}

		dfs(a2);
		return;
	} 

	if (A[v] == "NOT") {
		dfs(adj[v][0]);
		return;
	}

	if (A[v] == "OR") {
		ll a1 = adj[v][0], a2 = adj[v][1];
		ll v1 = val[a1], v2 = val[a2];
		if (v1 == 1 && v2 == 1) return;
		if (v1 == 0 && v2 == 0) {
			dfs(a1);
			dfs(a2);
			return;
		} 

	       	if (v1) {
			dfs(a1);
			return;
		}

		dfs(a2);
		return;
	} 

	if (A[v] == "XOR") {
		ll a1 = adj[v][0], a2 = adj[v][1];
		dfs(a1);
		dfs(a2);
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	ll ind = 0;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (A[i] == "AND" || A[i] == "XOR" || A[i] == "OR") {
			ll u, v;
			cin >> u >> v;
			adj[i].push_back(u);
			adj[i].push_back(v);
		} else if (A[i] == "NOT") {
			ll u;
			cin >> u;
			adj[i].push_back(u);
		} else {
			cin >> val[i];
			T[i] = ind;
			ind++;
		}
	}


	ll ans = dfs1(1);
	dfs(1);
	vector<ll> v;
	for (int i = 0; i < ind; i++) v.push_back(ans);
	for (ll e : ans_rev) {
		v[e] = 1 - v[e];
	}

	for (ll e : v) cout << e;
	cout << endl;
	return 0;
}