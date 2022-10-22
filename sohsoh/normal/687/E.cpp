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

const ll MAXN = 5000 + 10;

int n, m, col[MAXN], cmpid, dist[MAXN][MAXN];
bool sink[MAXN], vis[MAXN];
vector<int> adj[MAXN], cmp[MAXN], tadj[MAXN], adj_r[MAXN];
stack<int> order;
ll ans = 0;

void dfs(int v) {
	vis[v] = true;

	for (int u : adj[v])
		if (!vis[u])
			dfs(u);
	

	order.push(v);
}

void sfd(int v) {
	cmp[cmpid].push_back(v);
	col[v] = cmpid;

	for (int u : adj_r[v])
		if (!col[u])
			sfd(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_r[v].push_back(u);
	}

	for (int v = 1; v <= n; v++)
		if (!vis[v])
			dfs(v);

	while (!order.empty()) {
		int v = order.top();
		order.pop();
		if (!col[v]) {
			cmpid++;
			sink[cmpid] = true;
			sfd(v);
		}
	}

	for (int v = 1; v <= n; v++) {
		for (int u : adj[v]) {
			if (col[u] == col[v]) tadj[v].push_back(u);
			else sink[col[v]] = false;
		}
	}

	ans = n;
	for (int e = 1; e <= n; e++) {
		for (int u = 1; u <= n; u++)
			dist[e][u] = n + 5;
			
		dist[e][e] = 0;
		queue<int> q;
		q.push(e);

		while (!q.empty()) {
			int v = q.front();
			q.pop();

			for (int u : tadj[v]) {
				if (dist[e][u] > dist[e][v] + 1) {
					q.push(u);
					dist[e][u] = dist[e][v] + 1;
				}
			}
		}

	}	

	for (int i = 1; i <= cmpid; i++) {
		if (!sink[i] || cmp[i].size() == 1) continue;
		int cyc = n + 5;

		for (int v : cmp[i]) {
			for (int u : cmp[i]) {
				if (u == v) continue;
				cyc = min(cyc, dist[v][u] + dist[u][v]);
			}
		}

		ans += 998 * cyc + 1;
	}

	cout << ans << endl;
	return 0;
}