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

bool vis[MAXN] = {false};
vector<ll> order, temp;
vector<vector<ll>> cmp;
vector<ll> adj[MAXN], adj_rev[MAXN];
ll H[MAXN], col[MAXN] = {0}, c = 0;

void dfs1(ll v) {
	vis[v] = true;
	for (ll u : adj[v])
		if (!vis[u]) dfs1(u);
	order.push_back(v);
}

void dfs2(ll v) {
	col[v] = c;
	temp.push_back(v);
	for (ll u : adj_rev[v]) if (col[u] == 0) dfs2(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m, h;
	cin >> n >> m >> h;
	for (int i = 1; i <= n; i++) cin >> H[i];
	for (int i = 1; i <= m; i++) {
		ll a, b;
		cin >> a >> b;
		if ((H[a] + 1) % h == H[b]) adj[a].push_back(b), adj_rev[b].push_back(a);
		if ((H[b] + 1) % h == H[a]) adj[b].push_back(a), adj_rev[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) if (!vis[i]) dfs1(i);
	reverse(all(order));

	for (ll v : order) {
		if (col[v] == 0) {
			c++;
			dfs2(v);
			cmp.push_back(temp);
			temp.clear();
		}
	}

	ll b_ind = -1, b = INF;
	ll ind = 0;
	for (vector<ll> v : cmp) {
		ll x = col[v[0]];
		bool ok = true;
		for (ll u : v) {
			for (ll e : adj[u])
				if (col[e] != col[u]) ok = false;
	//		if (u == 5) debug(adj[u][0])
		}
		if (ok && v.size() < b) {
			b = v.size();
			b_ind = ind;
		}

		ind++;
	}

	//for (int i = 1; i <= n; i++) {
//		cout << i << ": ";
//		for (ll e : adj[i]) cout << e << sep; cout << endl;
//	}
	
	cout << b << endl;
	for (ll e : cmp[b_ind]) cout << e << sep;
	cout << endl;
	return 0;
}