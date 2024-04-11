//In the name of God

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }



const int N = 2e5 + 5;
const int mod = 0;
const int base = 1000 * 1000 + 3;
const int oo = 1e18 + 9;

int read() { int x; cin >> x; return x; }

int dis[N], vis[N], par[N];
set<pii> st;
vector<pii> adj[N];

void relax(int v) {
	vis[v] = 1;
	for (int i = 0; i < (int) adj[v].size(); ++i) if (!vis[adj[v][i].first]) {
		int u = adj[v][i].first, w = adj[v][i].second;	
		st.erase({dis[u], u});
		smin(dis[u], dis[v] + w);
		st.insert({dis[u], u});
		if (dis[u] == dis[v] + w)
			par[u] = v;
	}
}

void show(int v) {
	if (par[v] != -1)
		show(par[v]);
	cout << v + 1 << ' ';
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), m = read(), s = 0, t = n - 1;
	for (int i = 0; i < m; ++i) {
		int u = read() - 1, v = read() - 1, w = read();
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});	
	}
	fill(dis, dis + N, oo);
	memset(par, -1, sizeof (par));
	dis[s] = 0;
	st.insert({dis[s], s});
	while ((int) st.size()) {
		pii cur = *(st.begin());
		st.erase(cur);
		relax(cur.second);	
	}
//	cout << dis[t] << '\n';
	if (par[t] != -1)
		show(t);
	else
		cout << -1;
}