//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 3e5 + 5;

int read() { int x; cin >> x; return x; }

int deg[N], par[N];
vector<int> adj[N];

int find(int v) { return v == par[v]? v: par[v] = find(par[v]); }
void unite(int u, int v) { par[find(u)] = find(v); }

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), m = read(), k = read();
	rep(i, m) {
		int u = read() - 1, v = read() - 1;
		deg[u]++;
		deg[v]++;
		if (v)
			adj[u].push_back(v);
		if (u)
			adj[v].push_back(u);
	}
	rep(i, n)
		sort(adj[i].begin(), adj[i].end()), par[i] = i;
	int ind = 1;
	for (int i = 2; i < n; ++i) if (deg[i] < deg[ind])
		ind = i;
	int p = 0;
	for (int i = 1; i < n; ++i)
		if (p == adj[ind].size() || adj[ind][p] != i)
			unite(i, ind);
		else
			p++;
	for (int v = 1; v < n; ++v) if (find(v) != find(ind)) {
		int pt = 0;
		for (int u = 1; u < n; ++u)
			if (pt == adj[v].size() || adj[v][pt] != u)
				unite(u, v);
			else
				pt++; 
	}
	vector<int> incident;
	p = 0;
	ind = 0;
	int cnt = 0;
	memset(deg, 0, sizeof deg);
	for (int i = 1; i < n; ++i)
		deg[find(i)]++, cnt += (deg[find(i)] == 1);
	if (cnt > k) {
		cout << "impossible" << endl;
		return 0;
	}
	for (int i = 1; i < n; ++i)
		if (p == adj[ind].size() || adj[ind][p] != i) {
			incident.push_back(find(i));
		} else
			p++;
	sort(incident.begin(), incident.end());
	incident.resize(unique(incident.begin(), incident.end()) - incident.begin());
	if (incident.size() != cnt) {
		cout << "impossible" << endl;
		return 0;
	}
	int d = n - adj[ind].size() - 1;
	if (d < k) {
		cout << "impossible" << endl;
		return 0;
	}
	cout << "possible";
}