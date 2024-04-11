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

int cnt = 0;

template<typename T, int MAXN, int MAXM>
struct Flow { // O(n^2 * m)
	int m = 0, dist[MAXN], from[MAXM << 1], to[MAXM << 1], ptr[MAXN];
	T cap[MAXM << 1], delta = 0, max_edge = 0;
	vector<int> adj[MAXN];

	Flow() {}
	
	inline void add_edge(int u, int v, T c) {
		adj[u].push_back(m);
		from[m] = u;
		to[m] = v;
		cap[m++] = c;

		adj[v].push_back(m);
		from[m] = v;
		to[m] = u;
		cap[m++] = 0;

		max_edge = max(max_edge, c);
	}

	inline bool BFS(int source, int sink) {	
		cnt++;
		memset(dist, 63, sizeof dist);
		memset(ptr, 0, sizeof ptr);
		dist[source] = 0;
		
		queue<int> q;
		q.push(source);
		while (!q.empty()) {
			int v = q.front();
			q.pop();

			int d = dist[v] + 1;
			for (int id : adj[v]) {
				int u = to[id];
				if (cap[id] >= delta && dist[u] > d) {
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
		for (; ptr[v] < int(adj[v].size()) && flow; ptr[v]++) {
			int id = adj[v][ptr[v]], u = to[id];
			if (dist[u] == dist[v] + 1 && cap[id] >= delta) {
				T flow_e = dfs(u, sink, min(flow - ans, cap[id]));
				ans += flow_e;
				cap[id] -= flow_e;
				cap[id ^ 1] += flow_e;
			}
		}

		return ans;
	}	

	T max_flow(int source, int sink) {
		T ans = 0;
		delta = 1;
		while (delta < max_edge) delta = delta * 2;
		while (delta) {
			while (BFS(source, sink))
				ans += dfs(source, sink, 1e6);	
			delta /= 2;
		}

		return ans;
	}
};

const ll MAXN = 60 + 3;
const ll INF = 1e6;

Flow<int, 5 * MAXN * MAXN , MAXN * MAXN * 5> flow; //
int n, h, m, S[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int s = 0, t = 5 * MAXN * MAXN - 1;

	cin >> n >> h >> m;
	int ans = h * h * n;
	
	for (int i = 1; i <= n; i++) {
		S[i] = (i == 1 ? 1 : S[i - 1] + h + 1);
		flow.add_edge(s, S[i], INF);

		for (int j = 0; j < h; j++) {
			int v = S[i] + j;
			flow.add_edge(v + 1, v, INF);
			flow.add_edge(v, v + 1, h * h - j * j);
		}
	}

	int v = S[n] + h + 1;
	while (m--) {
		int l, r, x, c;
		cin >> l >> r >> x >> c;
		if (x == h) continue;

		x++;
		for (int i = l; i <= r; i++) 
			flow.add_edge(S[i] + x, v, INF);


		flow.add_edge(v, t, c);
		v++;
	}

	cout << ans - flow.max_flow(s, t) << endl;
	return 0;
}