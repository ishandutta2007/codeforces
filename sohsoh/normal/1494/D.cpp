#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

int depth[MAXN], W[MAXN], t = 1, M[510][510], n, par[MAXN];
vector<int> path[MAXN], path_v[MAXN], V;
vector<pll> edges;

inline void Majik(vector<int>& v) {
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	reverse(all(v));
}

inline void AddEdge(int u, int v) {
	edges.push_back({v, u});
	par[v] = u;
	depth[v] = depth[u] + 1;
}

inline int Vert(int v) {
	return find(all(V), v) - V.begin() + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			cin >> M[i][j];
	for (int j = 1; j <= n; j++) path[1].push_back(M[1][j]);
	Majik(path[1]);
	depth[1] = 1;

	for (int e : path[1]) {
		W[t] = e;
		if (!path_v[1].empty()) AddEdge(path_v[1].back(), t);
		path_v[1].push_back(t);
		t++;
	}
	
	for (int v = 2; v <= n; v++) {
		int u = path_v[1].front();
		for (int i = 1; i < v; i++) {
			int ind = find(all(path[i]), M[i][v]) - path[i].begin();
			if (depth[path_v[i][ind]] > depth[u]) u = path_v[i][ind];
		}

		int u_w = W[u];
		for (int i = 1; i <= n; i++) path[v].push_back(M[v][i]);
		Majik(path[v]);
		int ind = find(all(path[v]), u_w) - path[v].begin();
		
		int t_u = u;
		while (true) {
			path_v[v].push_back(t_u);
			if (t_u == 1) break;
			t_u = par[t_u];
		}

		reverse(all(path_v[v]));
		for (int i = ind + 1; i < path[v].size(); i++) {
			int e = path[v][i];
			W[t] = e;
			AddEdge(path_v[v].back(), t);
			path_v[v].push_back(t);
			t++;
		}
	}


	for (int i = 1; i <= n; i++) V.push_back(path_v[i].back());
	for (int i = 1; i < t; i++) if (find(all(V), i) == V.end()) V.push_back(i);

	cout << t - 1 << endl;
	for (int i = 1; i < t; i++) cout << W[V[i - 1]] << sep;
	cout << endl;
	cout << Vert(1) << endl;
	for (pll e : edges) cout << Vert(e.X) << sep << Vert(e.Y) << endl;
	return 0;
}