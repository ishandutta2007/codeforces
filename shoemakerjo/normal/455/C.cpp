#include <bits/stdc++.h>

using namespace std;
#define maxn 300001
int par[maxn];
int diam[maxn];
int depth[maxn];
bool visited[maxn];
vector<vector<int>> adj;
vector<int> curdfs;
vector<int> path;
int furthest;
int dist;
bool done;

void dfs(int u, int p, int d) {
	curdfs.push_back(u);
	if (d > dist) {
		dist = d;
		furthest = u;
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u, d+1);
	}
}
void dfspath(int u, int p, int goal) {
	if (done) return;

	path.push_back(u);
	if (u == goal) {
		done = true;
		return;
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfspath(v, u, goal);
		if (done) return;
	}
	if (done) return;
	path.pop_back();
}

int findset(int u) {
	if (par[u] == u) return u;
	par[u] = findset(par[u]);
	return par[u];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i <= n; i++) {
		visited[i] = false;
		vector<int> b;
		adj.push_back(b);
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		curdfs.clear();
		furthest = i;
		dist = 0;
		dfs(i, 0, 0);
		curdfs.clear();
		dist = 0;
		int t = furthest;
		dfs(furthest, 0, 0);
		done = false;
		path.clear();
		dfspath(t, 0, furthest);
		int d = dist+1;
		int center = path[d/2];
		// if (i == 1) cout << "center  " << center << endl;

		diam[center] = dist;
		depth[center] = max(d/2, d-d/2-1);
		// if (i == 1) {
		// 	cout << "path  ";
		// 	for (int j = 0; j < path.size(); j++) {
		// 		cout << path[j] << " ";
		// 	}
		// 	cout << endl;
		// }
		for (int j =  0; j < curdfs.size(); j++) {
			visited[curdfs[j]] = true;
			par[curdfs[j]] = center;
		}
	}
	int type, x, y;
	for (int i = 0; i < q; i++) {
		cin >> type >> x;
		if (type == 2) {
			cin >> y;
			int cx = findset(x);
			int cy = findset(y);
			if (cx == cy) continue;
			// cout << "c     " << cx << " " << cy << endl;
			// cout << "depth " << depth[cx] << " " << depth[cy] << endl;
			if (depth[cx] > depth[cy]) {

				par[cy] = cx;
				diam[cx] = max(diam[cx], diam[cy]);
				diam[cx] = max(diam[cx], depth[cx] + depth[cy] + 1);
				depth[cx] = max(depth[cx], depth[cy]+1);


			}
			else {
				par[cx] = cy;
				diam[cy] = max(diam[cy], diam[cx]);
				diam[cy] = max(diam[cy], depth[cx]+depth[cy]+1);
				depth[cy] = max(depth[cy], depth[cx]+1);
			}
			// cout << "here  " <<  findset(cx) <<  " " << diam[findset(cx)] << endl;
		}
		else {
			int cx = findset(x);
			cout << diam[cx] << '\n';
		}
	}
	// cin >> x;

}