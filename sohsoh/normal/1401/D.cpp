/*
    Soheil Mohammadkhani
    OK, im back :)
*/
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
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> adj[MAXN], sd[MAXN], poss;
ll n = 0;

ll dfs(ll v, ll par = 0) {
	ll sum = 0;
	for (ll u : adj[v]) if (u != par) sd[v].push_back(dfs(u, v)), sum += sd[v].back();
	return sum + 1;
}

void dfs2(ll v, ll par = 0, ll us = 0) {	
	ll pus = us, sm = 0;
	for (ll e : sd[v]) us += e, sm += e;
	poss.push_back(pus * (sm + 1));
	us++;
	ll ind = 0;
	for (ll u : adj[v]) if (u != par) dfs2(u, v, us - sd[v][ind]), ind++;
}

ll solve() {
	for (int i = 0; i < n + 10; i++) {
		adj[i].clear();
		sd[i].clear();
	}

	poss.clear();

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	ll m;
	cin >> m;
	vector<ll> v;
	for (int i = 0; i < m; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}	
	
	while (v.size() < n - 1) v.push_back(1);
	sort(all(v));
	while (v.size() > n - 1) {
		ll x = v.back();
		v.pop_back();
		x *= v.back();
		x %= MOD;
		v.pop_back();
		v.push_back(x);
	}

	
	ll tr = -1;
	for (int i = 1; i <= n; i++) if (adj[i].size() == 1) tr = i;
	dfs(tr);
	dfs2(tr);
	
	sort(all(poss));
	ll ans = 0;
	while (poss.size() > 1) {
		ans += (poss.back() % MOD) * v.back() % MOD;
		ans %= MOD;
		poss.pop_back();
		v.pop_back();
	}

	cout << ans << endl;

	return 0;	
}	

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) solve();	
	
	return 0;
}