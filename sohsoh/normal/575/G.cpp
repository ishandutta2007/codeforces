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
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, dist[MAXN], par[MAXN];
vector<pll> adj[MAXN];
map<pll, int> mp;
vector<int> vec, vec2;
bool final_vis[MAXN];

bool cmp(int v1, int v2) {
	return dist[v1] < dist[v2];
}

inline void source_find() {
	queue<int> tq;
	tq.push(n - 1);
	dist[n - 1] = 0;
	vec.push_back(n - 1);
	while (!tq.empty()) {
		int v = tq.front();
		tq.pop();
		for (pll e : adj[v]) {
			if (e.Y > 0) continue;
			if (dist[e.X] == INF) {
				dist[e.X] = 0;
				vec.push_back(e.X);
				tq.push(e.X);
				par[e.X] = v;
			}
		}
	}
}

inline void level_fillup() {
	vec2.clear();
	int T = 0, Tp = 0;
	for (int e : vec) final_vis[e] = true;
	for (int i = 0; i < vec.size(); i++) {
		if (i > 0 && dist[vec[i]] == dist[vec[i - 1]]) T = Tp;
		else ++T, Tp = T;
		int v = vec[i];
		for (pll e : adj[v]) {
			int u = e.X, w = e.Y;
			if (dist[u] == INF) {
				dist[u] = T + w;
				par[u] = v;
				vec2.push_back(u);
			} else if (!final_vis[u] && T + w < dist[u]) {
				dist[u] = T + w;
				par[u] = v;
			}
		}
		T += 12;
	}

	vec.clear();
	for (int e : vec2) vec.push_back(e);
	sort(all(vec), cmp);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		mp[make_pair(u, v)] = w;
		mp[make_pair(v, u)] = w;
	}

	fill(dist, dist + MAXN, INF);
	fill(par, par + MAXN, INF);
	source_find();
	while (!vec.empty()) level_fillup();	
	string ans;
	queue<int> st;
	int v = 0;
	while (par[v] != INF) {
		ans.push_back(char(mp[make_pair(v, par[v])] + '0'));
		st.push(v);
		v = par[v];
	}

	st.push(n - 1);

	if (ans.empty()) ans = "0";
	while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
	reverse(all(ans));
	cout << ans << endl;
	cout << st.size() << endl;
	while (!st.empty()) cout << st.front() << sep, st.pop();
	cout << endl;
	return 0;
}