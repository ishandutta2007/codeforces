/*
    Soheil Mohammadkhani
    Sos Goge Tabarok :)
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
 
const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 66;

vector<ll> ind[LOG], adj[MAXN];
ll vis[MAXN] = {0}, par[MAXN] = {0};

ll ans = INF, n;

void bfs(ll v) {
	queue<ll> q;
	q.push(v);
	fill(par, par + MAXN, -1);
	fill(vis, vis + MAXN, -1);

	vis[v] = 0;
	while (!q.empty()) {
		ll u = q.front();
		q.pop();
		for (ll e : adj[u]) {
			if (vis[e] < 0) {
				vis[e] = vis[u] + 1;
				par[e] = u;
				q.push(e);
			} else if (par[u] != e && par[e] != u) ans = min(ans, vis[e] + vis[u] + 1);
		}
	}

}

int main() {
	fast_io;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		ll j = 0;
		while (x > 0) {
			if (x & 1) ind[j].push_back(i);
			j++;
			x /= 2;
		}
	}

	for (int i = 0; i < LOG; i++) {
		if (ind[i].size() > 2) return cout << "3" << endl, 0;
		if (ind[i].size() == 2) {
			adj[ind[i][0]].push_back(ind[i][1]);
			adj[ind[i][1]].push_back(ind[i][0]);
		}
	}

//	for (int i = 0; i < n; i++) {for (ll e : adj[i]) cout << e << sep; cout << endl;}
	
	for (int i = 0; i < n; i++) if (adj[i].size() > 1) bfs(i);
	if (ans > n) ans = -1;
	cout << ans << endl;
	return 0;
}