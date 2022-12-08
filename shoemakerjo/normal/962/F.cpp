#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define maxn 100010
stack<int> cs; //current stack of edge ids
int dfs_num[maxn];
int dfs_low[maxn];
int dfs_counter;
bool vis[maxn];
int par[maxn];
vector<vector<pii>> adj(maxn);
vector<int> ans;
int n1[maxn], n2[maxn]; //map edges to nodes


void clearstack(int eid) {
	// cout << "clear stack: " << cs.size() << "  stopping at " << eid << endl;
	vector<int> cur;
	while (!cs.empty() && cs.top() != eid ) {
		// cout << "adding  " << cs.top() << endl;
		if (cs.top() == -1) cout << "WEIRD WEIRD WEIRD" << endl;
		cur.push_back(cs.top()); cs.pop();
	}
	if (cs.size() > 0) {
		cur.push_back(cs.top()); cs.pop();
	}
	set<int> seen; //seen nodes
	// cout << "popping stuff " << endl;
	for (int ec : cur) {
		// cout << ec << endl;
		seen.insert(n1[ec]);
		seen.insert(n2[ec]);
	}
	if (seen.size() == cur.size()) {
		for (int ec : cur) {
			ans.push_back(ec);
		}
	}
	if (eid == -1) {
		assert(cs.size() == 0);
	}
}

void dfs(int u, int p) {
	// cout << "here  " << u << " - " << p << endl;
	dfs_num[u] = dfs_low[u] = dfs_counter++;
	// cout << "u num:  " << dfs_num[u] << endl;
	vis[u] = true;
	int ch = 0;
	for (auto vp : adj[u]) {
		int v = vp.first;
		int eid = vp.second;
		// cout << "going  " << u << " to " << v << endl;
		// cout << "    " << dfs_low[u] << "   " << dfs_num[v] << endl;
		if (eid == p) continue; //came here via this edge
		if (!vis[v]) {
			// cout << "added normally " << u << " to " << v << endl;
			cs.push(eid);
			ch++;
			par[v] = u;
			dfs(v, eid);
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
			if (par[u] !=  -1 && dfs_low[v] >= dfs_num[u] || 
				par[u] == -1 && ch > 1) { //need multiple children to clear if top
				// cout << "here for " << u << " to " << v << "   with id: " << eid << endl;
				// cout << "   " << dfs_low[v] << " " << dfs_num[u] << endl;
				// cout << "stopping at " << eid << endl;
				clearstack(eid);
			}
		}
		else  if (dfs_num[v] < dfs_num[u]) { //changed this a bit
			// cout << "made this : " << u << " to " << v <<  "  id: " << eid << endl;
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
			cs.push(eid);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	dfs_counter = 0;

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(pii(v, i));
		adj[v].push_back(pii(u, i));
		n1[i] = u;
		n2[i] = v;
	}
	fill(par, par+maxn, -1);
	fill(vis, vis+maxn, false);
	// for (int i = 1; i <= n; i++) { //assumes we are sort dependent
	// 	//must sort my adjacency list stuff
	// 	sort(adj[i].begin(), adj[i].end());
	// }
	for (int i = 1; i <= n; i++) {
		// cout << "starting at " << i << endl;
		if (!vis[i]) {
			assert(cs.size() == 0); //let if fly and see what happens
			par[i] = -1; //i think this is what i want
			dfs(i, -1);
			clearstack(-1);
		}
	}
	sort(ans.begin(), ans.end());
	// cout << "starting ans  " << endl;
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i]+1 << " ";

	}
	cout << endl;
	cin >> n;
}