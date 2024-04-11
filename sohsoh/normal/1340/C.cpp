#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

using namespace std;
 
typedef int ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
 
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
 
const ll MAXN = 1e4 + 10;
const ll MAXG = 1e3 + 10;
const ll INF = 2139062143;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, g, r, adj_sz;
pair<pll, ll> adj[2];
vector<ll> v;
ll val[MAXN], dist[MAXN][MAXG];

void adj_comp(ll i, ll j) {	
	adj_sz = 0;
	if (i < m - 1) {
		ll x = j - (val[i + 1] - val[i]);
		if (x >= 0) adj[adj_sz] = {{i + 1, x}, 0}, adj_sz++; 
		if (j == 0 && val[i + 1] - val[i] <= g) adj[adj_sz] = {{i + 1, g - (val[i + 1] - val[i])}, g + r}, adj_sz++;
	}

	if (i > 0) {
		ll x = j - (val[i] - val[i - 1]);
		if (x >= 0) adj[adj_sz] = {{i - 1, x}, 0}, adj_sz++;
		if (j == 0 && val[i] - val[i - 1] <= g) adj[adj_sz] = {{i - 1, g - (val[i] - val[i - 1])}, g + r}, adj_sz++;
	}
}

void bfs01() {
	dist[0][g] = 0;
	deque<pll> q;
	q.push_back({0, g});
	while (!q.empty()) {
		pll v = q.front();
		q.pop_front();
		adj_comp(v.X, v.Y);
		for (int i = 0; i < adj_sz; i++) {
			pair<pll, ll> u = adj[i];
			if (dist[v.X][v.Y] + u.Y < dist[u.X.X][u.X.Y]) {
				dist[u.X.X][u.X.Y] = dist[v.X][v.Y] + u.Y;
				if (u.Y == 0) q.push_front({u.X.X, u.X.Y});
				else q.push_back({u.X.X, u.X.Y});			
			}
		}	
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}

	cin >> g >> r;
	
	sort(all(v));
	for (int i = 0; i < m; i++) val[i] = v[i]; 
	for (int i = 0; i < m; i++) {
		memset(dist[i], INF, sizeof dist[i]);
	}
	

	bfs01();
	ll ans = INF;
	for (int i = 0; i <= g; i++) ans = min(ans, dist[m - 1][i] + g - i);	
	if (ans >= INF) ans = -1;
	cout << ans << endl;
	//for (auto u : adj[1][8]) cout << u.X.X << sep << u.X.Y << sep << u.Y << endl;
	//debug(dist[0][0]);
	return 0;
}