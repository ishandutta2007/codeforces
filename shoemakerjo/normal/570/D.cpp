#include <bits/stdc++.h>

using namespace std;
#define maxn 500010
#define pii pair<int, int>
#define endl '\n'

int n, m;
string lets;

int dep[maxn];
int subsize[maxn];
bool ans[maxn];
vector<vector<int>> adj(maxn);
vector<vector<pii>> quers(maxn); //store the queries here as pairs (depth by index of query)

int predfs(int u, int p) { 
	dep[u] = p == -1 ? 1 : dep[p]+1;
	subsize[u] = 1;
	for (auto v : adj[u]) {
		predfs(v, u);
		subsize[u] += subsize[v];
	}
}

void dfs(int u, int p, map<int, int>& cm) { //this is the main thing
	int mx = -1, bigChild = -1;
	for (auto v : adj[u]) {
		if (subsize[v] > mx) {
			mx = subsize[v];
			bigChild = v;
		}
	}
	if (mx != -1) {
		dfs(bigChild, u, cm);
	}
	for (auto v : adj[u]) {
		if (v != bigChild) {
			map<int, int> tempo;
			dfs(v, u, tempo);
			for (map<int, int>::iterator it = tempo.begin(); it != tempo.end(); ++it) {
				int dep = it->first;
				int val = it->second;
				if (cm.count(dep) == 0) cm[dep] = val;
				else cm[dep] = cm[dep] ^ val; //only care about parity, this is fast
			}
		}
	}
	cm[dep[u]] = (1 << (lets[u]-'a'));
	for (int i = 0; i < quers[u].size(); i++) {
		int cd = quers[u][i].first;
		int ind = quers[u][i].second;
		if (cm.count(cd) == 0) {
			ans[ind] = true;
			continue;
		}
		int val = cm[cd];
		int oc = 0;
		for (int i = 0; i < 27; i++) {
			if (val & (1 << i)) {
				oc++;
			}
		}
		ans[ind] = oc <= 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m; //n is nodes, m is queries
	int p;
	for (int i = 2; i <= n; i++) {
		cin >> p;
		adj[p].push_back(i);
	}

	cin >> lets;
	lets = " " + lets;

	int v, h;
	for (int i = 0; i < m; i++) {
		cin >> v >> h;
		quers[v].push_back(pii(h, i)); //stored as depth and then query index
	}

	predfs(1 ,-1);
	//time to do the work
	map<int, int> cm;
	dfs(1, -1, cm);

	for (int i = 0; i < m; i++) {
		if (ans[i]) {
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
	cin >> n;

}