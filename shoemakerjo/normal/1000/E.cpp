#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

#define maxn 300010
//only bridges connect components

int n, m;
vector<vector<int>> adj(maxn);
vector<pii> bridgelinks; //parent node to child node
int dfs_num[maxn];
bool vis[maxn];
int dfs_low[maxn];
int comp[maxn]; //which component i am in
int compct = 0;
int dfsnumbercounter = 0;
stack<int> s; //used for vertices

void dfs(int u, int p) {
	dfs_num[u] = dfs_low[u] = dfsnumbercounter++;
	s.push(u);
	vis[u] = true;
	for (int v : adj[u]) {
		if (v == p) continue; //can't just travel back up
		if (vis[v]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
		else {
			dfs(v, u);
			if (dfs_low[v] > dfs_num[u]) {
				bridgelinks.push_back(pii(u, v));
				//can't get back up to me
				compct++;
				while (s.top() != v) {
					comp[s.top()] = compct;
					s.pop();
				}
				s.pop();
				comp[v] = compct;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}

}

int dist[maxn];
int maxd;
int farnode;
vector<vector<int>> adj2(maxn); //for each component

void dfs2(int u, int p) {
	//this is now a tree --> find the diameter
	for (int v : adj2[u]) {
		if (v == p) continue;
		dist[v] = dist[u]+1;
		if (dist[v] > maxd) { //new furthest node
			maxd = dist[v];
			farnode = v;
		}
		dfs2(v, u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int x, y;
	while (m--) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, -1);
	if (s.size()) {
		compct++;
		while (s.size()) {
			comp[s.top()] = compct;
			s.pop();
		}
	}

	for (pii vp : bridgelinks) {
		int c1 = comp[vp.first]; //extract the doubly-edge connected components
		int c2 = comp[vp.second];
		// cout << c1 << " is linked to " << c2 << endl;
		adj2[c1].push_back(c2);
		adj2[c2].push_back(c1);
	}
	farnode = 1;
	maxd = 0;
	dist[1] = 0; //set the node of 1 to have distance 0
	dfs2(1, -1);
	// cout << "max distance from 1: " << maxd << " - " << farnode << endl;
	maxd = 0;
	dist[farnode] = 0; //this reset is important
	dfs2(farnode, -1);
	cout << maxd << endl;
	// cout << "number of components: " << compct << endl;
}