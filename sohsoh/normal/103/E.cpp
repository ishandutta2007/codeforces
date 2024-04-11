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

template<typename T, int MAXN, int MAXM>
struct Flow {
	int m = 0, dist[MAXN], from[MAXM << 1], to[MAXM << 1];
	T cap[MAXM << 1];
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

	T max_flow(int source, int sink) {
		T ans = 0;
		while (BFS(source, sink))
			ans += dfs(source, sink, numeric_limits<T>::max());	
		
		return ans;
	}
};


const ll MAXN = 300 + 10;
const ll INF = 1e10; //

Flow<ll, MAXN * 2, MAXN * MAXN> f1, f2;
int n, mat[MAXN * 2];
vector<int> adj[MAXN * 2], E;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int e;
			cin >> e;	
			E.push_back(f1.m);
			adj[i].push_back(e);
			f1.add_edge(i, n + e, 1);
		}

		f1.add_edge(0, i, 1);
		f1.add_edge(n + i, 2 * n + 1, 1);
	}

	f1.max_flow(0, 2 * n + 1);
	for (int e : E) {
		if (!f1.cap[e]) {
			mat[f1.from[e]] = f1.to[e];
			mat[f1.to[e]] = f1.from[e];
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int u : adj[i])
			if (mat[i] != u + n)
				f2.add_edge(i, mat[u + n], INF), cerr << i << sep << mat[u + n] << endl;

		int c;
		cin >> c;
		if (c < 0) {
			ans += c;
			f2.add_edge(0, i, -c);
		} else f2.add_edge(i, n + 1, c);
	}

	cout << f2.max_flow(0, n + 1) + ans << endl;
	return 0;
}