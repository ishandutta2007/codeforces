/*
    Soheil Mohammadkhani
    Test contest on vim :)
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

vector<pll> adj[MAXN];
ll n = 0, S, sum = 0;
priority_queue<pair<ll, pll>> Q;

ll dfs(ll v, ll p = -1) {
	ll lev = 0;
	for (pll u : adj[v]) {
		if (u.X == p) continue;
		ll k = dfs(u.X, v);
		lev += k;
		sum += u.Y * k;
		Q.push({ceil(u.Y / ld(2)) * k, {u.Y, k}});
				
	}

	if (lev == 0) return 1;
	return lev;
}

ll solve() {
	sum = 0;
	while (!Q.empty()) Q.pop();
	for (int i = 0; i < n + 10; i++) adj[i].clear();
	cin >> n >> S;
	//debug("Here")
	for (int i = 0; i < n - 1; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	//debug("bef")
	dfs(1);
	ll ans = 0;
	//debug("riched here");
	while (sum > S) {
		pair<ll, pll> e = Q.top();
		Q.pop();
		sum -= e.X;
		ans++;
		e.Y.X /= 2;
		e.X = ceil(e.Y.X / ld(2)) * e.Y.Y;
		Q.push(e);	
	}

	cout << ans << endl;
	return 0;
}

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) solve();
}

// Save your code before compile and sumbit :)