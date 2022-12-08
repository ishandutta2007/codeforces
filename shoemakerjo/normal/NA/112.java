#include <bits/stdc++.h>

using namespace std;
int n;
const int maxn = 1000010;
#define pii pair<int, int>

vector<int> adj[maxn];
int dep[maxn];
int siz[maxn];
int res[maxn]; //store the depth

void predfs(int u, int p = -1) {

	dep[u] = p == -1 ? 1 : dep[p]+1;
	siz[u] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		predfs(v, u);
		siz[u] += siz[v];
	}
}

void dfs(int u, int p, map<int, int> &mp) {
	int bigch = -1;
	for (int v : adj[u]) {
		if (v == p) continue;
		if (bigch == -1 || siz[v] > siz[bigch]) bigch = v;
	}
	res[u] = dep[u];
	if (bigch != -1) {
		dfs(bigch, u, mp);
		res[u] = res[bigch];
	}

	mp[dep[u]]++;
	if (mp[res[u]] == 1) res[u] = dep[u];
	int ct;
	for (int v : adj[u]) {
		if (v == p || v == bigch) continue;
		map<int, int> tmp;
		dfs(v, u, tmp);
		for (pii vp : tmp) {
			mp[vp.first] += vp.second;
			ct = mp[vp.first];
			if (ct > mp[res[u]]) res[u] = vp.first;
			else if (vp.first < res[u] && ct == mp[res[u]]) res[u] = vp.first;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	predfs(1);
	map<int, int> tmp;
	dfs(1, -1, tmp);

	for (int i = 1; i <= n; i++) {
		cout << res[i] - dep[i] << '\n';
	}
	cout.flush();

}