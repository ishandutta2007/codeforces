#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
int N;
int par[maxn];
vector<vector<int>> adj(maxn);
int dist[maxn];
int mdist = 0;
int spot = 1;
int dep[maxn];
bool taken[maxn];
int deg[maxn];

void dfs(int u) {
	if (dist[u] > mdist) {
		mdist = dist[u];
		spot = u;
	}
	for (auto v : adj[u]) {
		if (dist[v] == -1) {
			dist[v] = dist[u]+1;
			dfs(v);
		}
	}
}

void godown(int u, int p) {
	dep[u] = p == -1 ? 1 : dep[p]+1;
	par[u] = p;
	for (auto v : adj[u]) {
		if (v == p) continue;
		godown(v, u);
	}
}


bool depcomp(const int& a, const int& b) {
	return dep[a] < dep[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int u, v;
	fill(deg, deg+maxn, 0);
	for (int i = 0; i < N-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	fill(dist, dist+maxn, -1);
	dist[1] = 0;
	dfs(1);
	// cout << "spot " << spot << endl;
	godown(spot, -1);


	vector<int> addons;
	vector<int> vals;
	for (int i = 1; i <= N; i++) {
		// cout << i << ":  " << dep[i] << endl;
		if (i == spot || deg[i] != 1) continue;
		vals.push_back(i);
	}
	sort(vals.begin(), vals.end(), depcomp);
	reverse(vals.begin(), vals.end());
	fill(taken, taken+maxn, false);
	for (int i = 0; i  < vals.size(); i++) {
		v = vals[i];
		// cout << "processing " << v << endl;
		int mycont = 1;
		taken[v] = true;
		int p = par[v];
		while (p != -1 && !taken[p]) {
			// cout << "updating " << p << endl;
			mycont++;
			taken[p] = true;
			p = par[p];
		}
		addons.push_back(mycont);

	}
	sort(addons.begin(), addons.end());
	reverse(addons.begin(), addons.end());
	int cans = 0;
	int tprints = 1;
	cout << 1 << " ";
	for (int i = 0; i < addons.size(); i++) {
		cans += addons[i];
		cout << cans << " ";
		tprints++;
	}
	while (tprints < N) {
		cout << cans << " ";
		tprints++;
	}
	cout << endl;
	cin >> N;

}