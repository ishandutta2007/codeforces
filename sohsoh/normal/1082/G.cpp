#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 1e18;

template<typename T, int MAXN, int MAXM>
struct Flow { // O(n^2 * m)
	int m = 0, dist[MAXN], from[MAXM << 1], to[MAXM << 1];
	T cap[MAXM << 1];
	vector<int> adj[MAXN];

	Flow() {}
	
	inline void addEdge(int u, int v, T c) {
		adj[u].push_back(m);
		from[m] = u;
		to[m] = v;
		cap[m++] = c;

		adj[v].push_back(m);
		from[m] = v;
		to[m] = u;
		cap[m++] = 0;
	}

	inline bool BFS(int source, int sink) {	
		memset(dist, 63, sizeof dist);
		dist[source] = 0;
		
		queue<int> q;
		q.push(source);
		while (!q.empty()) {
			int v = q.front();
			q.pop();

			int d = dist[v] + 1;
			for (int id : adj[v]) {
				int u = to[id];
				if (cap[id] && dist[u] > d) {
					dist[u] = d;
					q.push(u);
				}
			}
		}

		return dist[sink] < MAXN;
	}

	T dfs(int v, int sink, T flow) {
		if (!flow || v == sink) return flow;

		T ans = 0;
		for (int id : adj[v]) {
			int u = to[id];
			if (dist[u] == dist[v] + 1 && cap[id]) {
				T flow_e = dfs(u, sink, min(flow - ans, cap[id]));
				ans += flow_e;
				cap[id] -= flow_e;
				cap[id ^ 1] += flow_e;
			}
		}

		return ans;
	}	

	T flow(int source, int sink) {
		T ans = 0;
		while (BFS(source, sink))
			ans += dfs(source, sink, INF);	
		
		return ans;
	}
};

Flow<ll, 1003, 5003> f;
int n, m;
ll S[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		f.addEdge(i, n + 1, 2 * x);	
	}

	ll ans = 0;
	for (int  i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		ans += 2 * w;

		f.addEdge(u, v, w);
		f.addEdge(v, u, w);
		S[v] += w;
		S[u] += w;
	}

	for (int i = 1; i <= n; i++)
		f.addEdge(0, i, S[i]);

	ans -= f.flow(0, n + 1);
	cout << ans / 2 << endl;
	return 0;
}