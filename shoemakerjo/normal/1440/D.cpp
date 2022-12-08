#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

const int maxn = 100010;

int t, n, m, k;

vector<int> adj[maxn];
int deg[maxn];
int odeg[maxn];
bool marked[maxn];
bool isin[maxn];
set<int> ed[maxn];

// set<pii> ed;

void solve() {
	cin >> n >> m >> k;
	// vector<pii> edg;l
	// ed.clear();
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		deg[i] = 0;
		odeg[i] = 0;
		marked[i] = isin[i] = false;
		ed[i].clear();
	}
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++; deg[v]++;
		// ed.insert(pii(min(u, v), max(u, v)));
		ed[u].insert(v);
		ed[v].insert(u);
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		odeg[i] = deg[i];
		if (deg[i] < k) q.push(i);
	}
	while (q.size()) {
		u = q.front(); q.pop();
		// cout << "here " << u << endl;
		marked[u] = true;
		for (int vv : adj[u]) {
			deg[vv]--;
			if (deg[vv] == k-1) q.push(vv);
		}
	}
	vector<int> vals;
	for (int i = 1; i <= n; i++) {
		if (!marked[i]) vals.push_back(i);
	}
	if (vals.size() != 0) {
		cout << 1 << " " << vals.size() << endl;
		for (int vv : vals) cout << vv << " ";
		cout << endl;
		return;
	}

	if (k >= 500) { //just in case this makes it slow
		cout << -1 << endl;
		return;
	}

	//now, we need to do the clique thing
	for (int i = 1; i <= n; i++) {
		deg[i] = odeg[i]; //reset the degrees
		marked[i] = false;
		if (deg[i] < k-1) q.push(i);
	}
	while (q.size()) {
		u = q.front(); q.pop();
		marked[u] = true;
		for (int vv : adj[u]) {
			deg[vv]--;
			if (deg[vv] == k-2) q.push(vv);
		}
	}

	for (int i = 1; i <= n; i++) {
		// marked[i] = 
		if (deg[i] == k-1) q.push(i);
	}
	while (q.size()) {
		u = q.front(); q.pop();
		if (deg[u] == k-1) {
			//check the k it connects to that are in
			vector<int> cstuff;
			cstuff.push_back(u);
			for (int vv : adj[u]) {
				if (!marked[vv]) {
					cstuff.push_back(vv);
				}
			}
			//size of cstuff must be k
			// for (int vv : cstuff) {
			// 	isin[vv] = true;
			// }
			bool isok = true;
			for (int i = 0; i < cstuff.size(); i++) {
				if (!isok) break;
				for (int j = i+1; j < cstuff.size(); j++) {
					if (ed[cstuff[i]].count(cstuff[j]) == 0) {
						isok = false;
						break;
					}
				}
			}
			if (isok) {
				cout << 2 << endl;
				for (int vv : cstuff) cout << vv << " ";
				cout << endl;
				return;
			}
		}
		marked[u] = true;
		for (int vv : adj[u]) {
			deg[vv]--;
			if (deg[vv] == k-1) q.push(vv);
		}
	}
	cout << -1 << endl; //nothing found

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		solve();
	}
}