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
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll CST = 1e5;

int n, m, k, dist[MAXN];
map<pll, int> mp;
vector<pll> adj[MAXN];

inline int D(pll e) {
	return dist[mp[e]];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	cin >> n >> m >> k;
	fill(dist, dist + MAXN, INF);

	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		mp[make_pair(x, y)] = i;
		adj[CST + x].push_back({i, 0});
		adj[CST + x + 1].push_back({i, 0});
		adj[CST + x - 1].push_back({i, 0});
		adj[2 * CST + y].push_back({i, 0});
		adj[2 * CST + y + 1].push_back({i, 0});
		adj[2 * CST + y - 1].push_back({i, 0});
		adj[i].push_back({CST + x, 1});
		adj[i].push_back({CST + x + 1, 1});
		adj[i].push_back({CST + x - 1, 1});
		adj[i].push_back({2 * CST + y + 1, 1});
		adj[i].push_back({2 * CST + y - 1, 1});
		adj[i].push_back({2 * CST + y, 1});
	}

	for (auto e : mp) {
		int x = e.X.X, y = e.X.Y;
		if (mp.find(make_pair(x + 1, y)) != mp.end()) adj[e.Y].push_back({mp[make_pair(x + 1, y)], 0});
		if (mp.find(make_pair(x - 1, y)) != mp.end()) adj[e.Y].push_back({mp[make_pair(x - 1, y)], 0});
		if (mp.find(make_pair(x, y + 1)) != mp.end()) adj[e.Y].push_back({mp[make_pair(x, y + 1)], 0});
		if (mp.find(make_pair(x, y - 1)) != mp.end()) adj[e.Y].push_back({mp[make_pair(x, y - 1)], 0});
	}

	deque<int> q = {mp[make_pair(1, 1)]};
	dist[q.front()] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		for (pll e : adj[v]) {
			if (e.Y == 1) {
				if (dist[e.X] > dist[v] + 1) {
					q.push_back(e.X);
					dist[e.X] = dist[v] + 1;
				}
			} else {
				if (dist[e.X] > dist[v]) {
					q.push_front(e.X);
					dist[e.X] = dist[v];
				}
			}
		}
	}
		
	int ans = INF;
	if (mp.find(make_pair(n, m)) != mp.end()) ans = min(ans, dist[mp[make_pair(n, m)]]);
       	ans = min(ans, dist[CST + n]);
       	ans = min(ans, dist[2 * CST + m]);
	if (ans > MAXN) ans = -1;
	cout << ans << endl;
	return 0;
}