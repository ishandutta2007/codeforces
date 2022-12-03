#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<double, int> d_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;

vector<int> dijkstra(int N, vector<vector<edge> >& G, int s) {
	vector<int> d(N, INF); d[s] = 0;
	priority_queue<ll_i, vector<ll_i>, greater<ll_i> > pq;
	pq.push(ll_i(0, s));
	while (pq.size()) {
		ll_i p = pq.top(); pq.pop();
		int u = p.second;
		if (p.first > d[u]) continue;
		for (edge e: G[u])
			if (d[e.v] > d[u] + e.w) {
				d[e.v] = d[u] + e.w;
				pq.push(ll_i(d[e.v], e.v));
			}
	}
	return d;
}

int main() {
	int N; cin >> N;
	vector<vector<edge> > G(N);
	rep(i, N - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		G[u].pb(edge{v, w});
		G[v].pb(edge{u, w});
	}
	vector<bool> leaf(N);
	rep(u, N) if (G[u].size() == 1) leaf[u] = true;
	vector<vector<int> > d(N);
	rep(s, N) d[s] = dijkstra(N, G, s);
	int s; cin >> s; s--;
	int M; cin >> M;
	vector<int> a(N);
	rep(j, M) {
		int u; cin >> u; u--;
		a[u]++;
	}
	vector<vector<int> > dp(M + 1, vector<int>(N));
	for (int m = 1; m <= M; m++) rep(s, N) if (leaf[s]) {
		vector<int> unko(m + 1);
		unko[0] = INF;
		rep(u, N) if (u != s && leaf[u])
			for (int j = m; j >= 0; j--) rep(dj, j + 1)
				unko[j] = max(unko[j], min(unko[j - dj], dp[m - dj][u] + d[s][u]));
		dp[m][s] = unko[m];
	}
	int mi = INF;
	for (edge e: G[s]) {
		int u0 = e.v;
		vector<int> V;
		rep(u, N) if (d[s][u0] + d[u0][u] == d[s][u]) V.pb(u);
		int m = 0;
		for (int u: V) m += a[u];
		if (!m) continue;
		vector<int> unko(m + 1);
		unko[0] = INF;
		for (int u: V) if (leaf[u])
			for (int j = m; j >= 0; j--) rep(dj, j + 1)
				unko[j] = max(unko[j], min(unko[j - dj], dp[M - dj][u] + d[s][u]));
		mi = min(mi, unko[m]);
	}
	cout << mi << endl;
}