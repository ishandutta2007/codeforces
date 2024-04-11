#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

multiset<int> st[MAXN][2];
pll E[MAXN], par[MAXN];
int ans[MAXN], n, m, q;

vector<pll> adj[MAXN];
bool vis[MAXN], e_vis[MAXN];

inline bool S(int ind, int v) {
	return v == E[ind].X;
}

inline int O(int ind, int v) {
	return (v == E[ind].X ? E[ind].Y : E[ind].X);
}


// :sad:
void dfs(int v) {
	vis[v] = true;
	for (pll e : adj[v]) {
		int u = e.X, ind = e.Y;
		if (!e_vis[ind]) {
			ans[ind] = S(ind, u);
			e_vis[ind] = true;
			dfs(u);
		}
	}

}

inline void add(int v, int ind) {
	if (O(ind, v) == v) return;
	adj[v].push_back({O(ind, v), ind});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	q = m;

	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		w--;

		E[i] = {u, v};
		st[v][w].insert(i);
		st[u][w].insert(i);
	}

	int tans = 0;
	for (int i = 1; i <= n; i++) {
		if (st[i][0].size() & 1) tans++;
		
		for (int j = 0; j < 2; j++) {
			while (st[i][j].size() > 1) {
				int e1 = *st[i][j].begin();
				st[i][j].erase(st[i][j].begin());
				int e2 = *st[i][j].begin();
				st[i][j].erase(st[i][j].begin());
			
				int u = O(e1, i), v = O(e2, i);
				st[u][j].erase(e1);
				st[v][j].erase(e2);

				E[++m] = {u, v};
				par[e1] = {m, int(S(e1, i))};
				par[e2] = {m, int(S(e2, v))};

				if (u == v) continue;
				st[u][j].insert(m);
				st[v][j].insert(m);
				
			}
		}
	}

	for (int v = 1; v <= n; v++) {
		if (!st[v][0].empty()) add(v, *st[v][0].begin());
		if (!st[v][1].empty()) add(v, *st[v][1].begin());
	}

	for (int v = 1; v <= n; v++)
		if (!vis[v] && adj[v].size() == 1)
			dfs(v);

	for (int v = 1; v <= n; v++)
		if (!vis[v])
			dfs(v);


	for (int i = m; i > 0; i--) {
		if (par[i].X) {
			ans[i] = (ans[par[i].X] ^ par[i].Y);
		}

	}

	cout << tans << endl;
	for (int i = 1; i <= q; i++) cout << ans[i] + 1;
	cout << endl;
	return 0;
}