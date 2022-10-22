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

vector<pll> adj[MAXN];
vector<pair<ll, pll>> v;
ll n, m, dist[MAXN];
pll S, F;

ll d_x_y(pll x, pll y) { return abs(x.X - y.X) + abs(x.Y - y.Y); }
ll d_x_or_y(pll x, pll y) { return min(abs(x.X - y.X), abs(x.Y - y.Y)); }

bool cmp1(pair<ll, pll> x, pair<ll, pll> y) { return x.Y.X < y.Y.X; }
bool cmp2(pair<ll, pll> x, pair<ll, pll> y) { return x.Y.Y < y.Y.Y; }

void dijkstra() {
	fill(dist, dist + MAXN, INF);
	dist[0] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		ll v = pq.top().Y, d_v = pq.top().X;
		pq.pop();
		if (d_v != dist[v]) continue;
		for (pll e : adj[v]) {
			ll u = e.X, len = e.Y;
			if (dist[v] + len < dist[u]) {
				dist[u] = dist[v] + len;
				pq.push({dist[u], u});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> S.X >> S.Y >> F.X >> F.Y;
	v.resize(m);
	for (int i = 0; i < m; i++) cin >> v[i].Y.X >> v[i].Y.Y, v[i].X = i + 1;
	sort(all(v), cmp1);
	for (int i = 0; i < m; i++) {
		if (i > 0) adj[v[i].X].push_back({v[i - 1].X, d_x_or_y(v[i].Y, v[i - 1].Y)});
		if (i < m - 1) adj[v[i].X].push_back({v[i + 1].X, d_x_or_y(v[i].Y, v[i + 1].Y)});
	}

	sort(all(v), cmp2);
	for (int i = 0; i < m; i++) {	
		adj[0].push_back({v[i].X, d_x_or_y(S, v[i].Y)});
		if (i > 0) adj[v[i].X].push_back({v[i - 1].X, d_x_or_y(v[i].Y, v[i - 1].Y)});
		if (i < m - 1) adj[v[i].X].push_back({v[i + 1].X, d_x_or_y(v[i].Y, v[i + 1].Y)});		
	}
	
	dijkstra();

	ll ans = d_x_y(S, F);
	sort(all(v));
	for (int i = 1; i <= m; i++) ans = min(ans, d_x_y(v[i - 1].Y, F) + dist[v[i - 1].X]);
	cout << ans << endl;
	
	return 0;
}