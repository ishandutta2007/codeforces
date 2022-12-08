#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define pii pair<int, int>

int n;
vector<int> reds;
vector<int> ans; //store all of the answers
vector<pii> queries;

vector<vector<int>> adj(maxn);
int par[18][maxn]; //try to keep this down
int dep[maxn]; //depth of each node
int dist[maxn]; //current smallest depth

int walk(int u, int k) {
	for (int i = 17; i >= 0; i--) {
		if (k & (1 << i)) u = par[i][u];
	}
	return u;
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) return lca(v, u);
	int diff = dep[u]-dep[v];
	u = walk(u, diff);
	if (u == v) return u;
	for (int i = 17; i >= 0; i--) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u]; //have to go to next guy
}

int getdist(int u, int v) { //returns dist between u and v
	int lc = lca(u, v);
	int ans = dep[u]+dep[v] - 2*dep[lc]; //always should be fine
	return ans;
}

void predfs(int u, int p) {
	dep[u] = p == -1 ? 1 : dep[p]+1;
	par[0][u] = p; //get the first step done
	for (auto v : adj[u]) {
		if (v == p) continue;
		predfs(v, u);
	}
}

void recalcdist() { //redo all of the distances
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		dist[i] = n+1; //eliminates need for vis array
	}
	for (int i = 0; i < reds.size(); i++) {
		dist[reds[i]] = 0;
		q.push(reds[i]);
	}
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (auto nx : adj[v]) {
			if (dist[nx] > dist[v]+1) {
				dist[nx] = dist[v]+1;
				q.push(nx);
			}
		}
	}
	//should be good now

}

void process() { //do everything currently in the query vector (sqrt(n) at most)

	vector<int> cr; //current reds
	for (int i = 0; i < queries.size(); i++) {
		int tp = queries[i].first;
		int v = queries[i].second;
		if (tp == 1) {
			cr.push_back(v);
			reds.push_back(v); //put it in both 
		}
		else {
			int cans = dist[v];
			for (auto ov : cr) {
				cans = min(cans, getdist(v, ov));
			}
			ans.push_back(cans);
		}
	}

	recalcdist(); //this is the n root n dfs part
	queries.clear(); //dump it all
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	predfs(1, -1); //we can just root it
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			if (par[i-1][j] != -1) {
				par[i][j] = par[i-1][par[i-1][j]];
			}
			else {
				par[i][j] = -1;
			}
		}
	}
	int tp, v;
	reds.push_back(1);  //starting condition
	process(); //run at beginning to get it for the root
	for (int i = 0; i < m; i++) {
		cin >> tp >> v;
		queries.push_back(pii(tp, v));
		if (i > 0 && i % 317 == 0) {
			process();
		}
	}
	process();
	for (auto a : ans) {
		cout << a << endl; //'\n' would be faster
	}

	cin >> n; 
}