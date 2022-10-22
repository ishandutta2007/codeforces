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

int V[MAXN], n, L, cnt;
map<int, int> mp;
vector<pair<pll, int>> adj[MAXN];
ll dist[MAXN];
bool vis[MAXN];
pll P[MAXN];

inline void Add_Node(int val) {
	if (mp[val]) return;
	cnt++;
	mp[val] = cnt;
	V[cnt] = val;
}	

inline void Dijkstra(int s) {
	memset(dist, 63, sizeof dist);
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	dist[s] = 0;
	pq.push({0, s});
	
	while (!pq.empty()) {
		ll v = pq.top().Y, d_v = pq.top().X;
		pq.pop();
		if (d_v != dist[v]) continue;

		for (auto e : adj[v]) {
			int u = e.X.X, w = e.X.Y, ind = e.Y;
			if (dist[u] > dist[v] + w) {
				dist[u] = dist[v] + w;
				P[u] = {v, ind};
				pq.push({dist[u], u});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> L;
	Add_Node(0);
	Add_Node(L);
	for (int i = 0; i < n; i++) {
		int x, d, t, p;
		cin >> x >> d >> t >> p;
			
		if (x - p >= 0) {
			Add_Node(x);
			Add_Node(x + d);
			Add_Node(x - p);
			adj[mp[x - p]].push_back({{mp[x + d], t + p}, i + 1});
		}
	}

	auto it = mp.begin();
	while (true) {
		auto it2 = next(it);
		if (it2 == mp.end()) break;
		adj[it -> Y].push_back({{it2 -> Y, (it2 -> X) - (it -> X)}, 0});
		adj[it2 -> Y].push_back({{it -> Y, (it2 -> X) - (it -> X)}, 0});
		it = it2;
	}
	
	Dijkstra(mp[0]);
	
	vector<int> ans;
	int v = mp[L];
	while (P[v].X) {
		if (P[v].Y) ans.push_back(P[v].Y);
		v = P[v].X;
	}

	cout << dist[mp[L]] << endl << ans.size() << endl;
	reverse(all(ans));
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}