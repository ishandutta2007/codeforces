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

const int INF = 1e9;

template<typename T, int MAXN, int MAXM>
struct Flow { // O(n^2 * m)
	int m = 0, vis[MAXN], from[MAXM << 1], to[MAXM << 1];
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

	int x = 1;
	T flow(int v, int sink) {
		if (v == sink) return 1;

		vis[v] = x;
		for (int id : adj[v]) {
			int u = to[id];
			if (cap[id] && vis[u] != x && flow(u, sink)) {
				cap[id] -= 1;
				cap[id ^ 1] += 1;
				return 1;
			}
		}

		return 0;
	}
};


const ll MAXN = 2003;

Flow<int, MAXN * 2, MAXN * 3> f;
int n1, n2, m, deg[MAXN * 2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n1 >> n2 >> m;

	vector<int> vec_e, vec_s, vec_t;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		v += n1;
	
		f.add_edge(u, v, 1);
		vec_e.push_back(f.m - 2);
		
		deg[u]++;
		deg[v]++;
	}

	int s = 0, t = n1 + n2 + 1, delta = deg[1];
	for (int i = 1; i <= n1 + n2; i++) delta = min(delta, deg[i]);

	for (int i = 1; i <= n1; i++) {
		f.add_edge(s, i, deg[i] - delta);
		vec_s.push_back(f.m - 2);
	}

	for (int i = 1; i <= n2; i++) {
		f.add_edge(i + n1, t, deg[i + n1] - delta);
		vec_t.push_back(f.m - 2);
	}

	vector<vector<int>> ans;
	for (int i = 0; i <= delta; i++) {
		while (f.flow(s, t)) f.x++;
		f.x++;

		ans.push_back({});
		for (int i = 0; i < m; i++)
			if (f.cap[vec_e[i]])
				ans.back().push_back(i + 1);

		for (int e : vec_s)
			f.cap[e]++;
		for (int e : vec_t)
			f.cap[e]++;
	}

	reverse(all(ans));
	for (auto e : ans) {
		cout << e.size() << sep;
		for (int id : e)
			cout << id << sep;
		cout << endl;
	}
	return 0;
}