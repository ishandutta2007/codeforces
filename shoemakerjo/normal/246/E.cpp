#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
#define maxn 100010
// #define endl '\n'
int n, m;

int subsize[maxn];
int dep[maxn];
string names[maxn];
int par[maxn];
int ans[maxn]; //store for easy printing later
vector<vector<int>> adj(maxn);
vector<vector<pii>> quers(maxn);

void getsubsize(int u, int p) {
	subsize[u] = 1;
	dep[u] = p == -1 ? 1 : dep[p]+1;
	for (auto v : adj[u]) {
		getsubsize(v, u);
		subsize[u] += subsize[v];
	}
}

void dfs(int u, int p, map<int, set<string>>& cm) { //might have to hash names
	int mx = -1, bigChild = -1;
	for (auto v : adj[u]) {
		if (subsize[v] > mx) {
			mx = subsize[v];
			bigChild = v;
		}
	}
	if (bigChild != -1) {
		dfs(bigChild, u, cm); //big boy
	}
	for (auto v : adj[u]) {
		// cout << "u   " << u << "  " << v << endl;
		if (v != bigChild) {
			map<int, set<string>> tempo;
			dfs(v, u, tempo); //m-m-m-m-meeeeeeeeerge
			for (auto it = tempo.begin(); it != tempo.end(); ++it) {
				int cd = it->first;
				set<string> cs = it->second; //current set
				// cout << "this guy's size:   " << cs.size() << endl;
				if (cm.count(cd) == 0) cm[cd] = cs;
				else cm[cd].insert(cs.begin(), cs.end()); //should just do everything
			}
		}
	}
	set<string> ns;
	ns.insert(names[u]);
	cm[dep[u]] = ns;

	// cout << "cm size  " << cm.size() << endl;

	for (int i = 0; i < quers[u].size(); i++) {
		// cout << "found a query  " << endl;
		int cd = quers[u][i].first;
		// cout << dep[u] << "  -   " << cd << endl;
		int ind = quers[u][i].second;
		if (cm.count(cd) == 0) {
			// cout << "never lucky" << endl;
			ans[ind] = 0;
		}
		else ans[ind] = cm[cd].size();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int p;
	for (int i = 1; i <= n; i++) {
		cin >> names[i];
		cin >> p;
		if (p == 0) p = -1;
		else adj[p].push_back(i);
		par[i] = p;
	}

	for (int i = 1; i <= n; i++) {
		if (par[i] == -1) getsubsize(i, -1);
	}
	cin >> m;
	int v, k;
	for (int i = 0; i < m; i++) {
		cin >> v >> k;
		quers[v].push_back(pii(dep[v]+k, i));
	}

	for (int i = 1; i <= n; i++) {
		if (par[i] == -1) {
			map<int, set<string>> cm;
			dfs(i, -1, cm);
		}
	}

	for (int i = 0; i < m; i++) {
		cout << ans[i] << endl;
	}
	cin >> n;
}

//HASH FOR SPEED BOOST
//endl boost could be there as well
//lol had a bug where i forgot the & on the map, SAD