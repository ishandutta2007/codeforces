#include <bits/stdc++.h>

using namespace std;
#define maxn 1000010
#define ll long long
#define pil pair<int, ll>

int n, m;
vector<vector<pil>> adj;
int dfs_num[maxn];
int dfs_low[maxn];
bool visited[maxn];
int loc[maxn];
stack<int> S;
int dfsNumberCounter;
int numSCC;
ll inner[maxn];

ll bes[maxn];
bool vis[maxn];

vector<vector<int>> ccs;

void scc(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push(u);
	visited[u] = true;
	for (int j = 0; j < (int) adj[u].size(); j++) {
		int v = adj[u][j].first;
		ll d = adj[u][j].second;
		if (dfs_num[v] == -1) {
			scc(v);
		}
		if (visited[v]) {
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}
	if (dfs_low[u] == dfs_num[u]) {
		numSCC++;
		inner[numSCC] = 0LL;
		vis[numSCC] = false;
		bes[numSCC] = 0LL;
		vector<int> nc;
		while (1) {

			int v = S.top();
			S.pop();
			visited[v] = false;
			nc.push_back(v);
			loc[v] = numSCC;
			if (v == u) break;
		}
		ccs.push_back(nc);
	}
}

ll dfs(int spot) {
	if (visited[spot]) {
		return bes[spot];
	}

	ll cb = 0LL;
	for (int i = 0; i < ccs[spot].size(); i++) {
		int u = ccs[spot][i];
		// cout << "u: " << u << endl;
		for (int j = 0; j < adj[u].size(); j++) {
			int v = adj[u][j].first;
			ll d = adj[u][j].second;
			if (loc[v] != spot) {
				cb = max(cb, d + dfs(loc[v]));
			}
		}
	}
	visited[spot] = true;
	bes[spot] = cb+inner[spot];
	return bes[spot];	
}

ll getval(ll d) {
	ll ans = 0LL;
	ll low = 0LL;
	ll high = d;
	while (low < high) {
		ll mid = (low+high+1LL)/2LL;
		if ((mid*(mid+1))/2LL >= d) {
			high = mid-1;
		}
		else low = mid;
	}
	ans = (low+1)*d;
	ll prod = (low*(low+1)*(low+2))/6LL;
	// cout << "here " << d << "  " << low << endl;
	return ans-prod;
}

int main() {
	// int n, m;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		vector<pil> b;
		adj.push_back(b);
	}
	int x, y;
	ll w;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		adj[x].push_back(pil(y, w));
	}
	dfsNumberCounter = numSCC = 0;
	numSCC = -1;
	for (int i = 0; i <= n; i++) {
		visited[i] = false;
		dfs_low[i] = 0;
		dfs_num[i] = -1;
	}
	for (int i = 1; i <= n; i++) {
		if (dfs_num[i] == -1) {
			scc(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			int v = adj[i][j].first;
			ll d = adj[i][j].second;
			if (loc[i] == loc[v]) {
				inner[loc[i]] += getval(d);
			}
		}
	}
	//for each scc, process it all

	int s;
	cin >> s;
	int start = loc[s];
	cout << dfs(start) << endl;
	cin >> s;

}