#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pll;
 
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
const ll MOD = 998244353; // 1e9 + 9;

ll dist1[MAXN][30];
pll dist2[MAXN];
vector<int> adj[MAXN][2], adj2[MAXN];
int n, m;

void dijkstra1() {
	for (int i = 1; i < MAXN; i++) for (int j = 0; j < 30; j++) dist1[i][j] = INF;
	dist1[1][0] = 0;
	priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> q;
	q.push({0, {1, 0}});
	while (!q.empty()) {
		int v = q.top().Y.X;
		int p = q.top().Y.Y;
		ll d_v = q.top().X;
		q.pop();
		if (d_v != dist1[v][p]) continue;
		for (int u : adj[v][p & 1]) {
			if (u == v) {
				if (p + 1 < 30 && d_v < dist1[v][p + 1]) {
					dist1[v][p + 1] = d_v;
					q.push({d_v, {v, p + 1}});
				}
			} else {
				if (d_v + 1 < dist1[u][p]) {
					dist1[u][p] = d_v + 1;
					q.push({d_v + 1, {u, p}});
				}
			}
		}
	}
}

void dijkstra2() {
	for (int i = 1; i < MAXN; i++) dist2[i] = {INF, MAXN};
	dist2[1] = {0, 0};
	priority_queue<pair<pll, ll>, vector<pair<pll, ll>>, greater<pair<pll, ll>>> q;
	q.push({{0, 0}, 1});
	while (!q.empty()) {
		int v = q.top().Y;
		pll d_v = q.top().X;
		q.pop();
		if (d_v != dist2[v]) continue;
		for (int u : adj2[v]) {
			if (u == v) {
				if (u > n) u -= n;
				else u += n;
				pll len = d_v;
				len.X++;
				if (len < dist2[u]) {
					dist2[u] = len;
					q.push({len, u});
				}
			} else {
				pll len = d_v;
				len.Y++;
				if (len < dist2[u]) {
					dist2[u] = len;
					q.push({len, u});
				}	
			}
		}
	}
}

ll calc_dist(pll d) {
	ll ans = d.Y;
	for (int i = 0; i < d.X; i++) ans += poww(2, i, MOD), ans %= MOD;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) adj[i][0].push_back(i), adj[i][1].push_back(i);
	for (int i = 1; i <= 2 * n; i++) adj2[i].push_back(i);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u][0].push_back(v);
		adj[v][1].push_back(u);
		adj2[u].push_back(v);
		adj2[v + n].push_back(u + n);
	}

	dijkstra1();
	ll try1 = INF;
	for (int i = 0; i < 30; i++) {
		if (dist1[n][i] < INF) {
			ll tans = dist1[n][i];
			for (ll j = 0; j < i; j++) tans += (1ll << j);
			try1 = min(try1, tans);
		}
	}

	if (try1 < INF) return cout << try1 % MOD << endl, 0;
	dijkstra2();
	if (dist2[n] < dist2[2 * n]) return cout << calc_dist(dist2[n]) << endl, 0;
	cout << calc_dist(dist2[2 * n]) << endl;
	return 0;
}