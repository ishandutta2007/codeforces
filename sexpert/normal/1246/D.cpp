#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int sz[MAXN], dep[MAXN];
vector<int> adj[MAXN];
vector<int> label[MAXN], seq[MAXN];
vector<int> labans, seqans;

void dfs_sz(int s) {
	sz[s] = 1;
	dep[s] = 0;
	for(auto v : adj[s])
		dfs_sz(v);
	sort(adj[s].begin(), adj[s].end(), [&](int u, int v){return dep[u] < dep[v];});
	for(auto v : adj[s]) {
		sz[s] += sz[v];
		dep[s] = max(dep[s], dep[v] + 1);
	}
}

void dfs_build(int s) {
	labans.push_back(s);
	for(auto v : adj[s])
		dfs_build(v);
	for(int i = 1; i < adj[s].size(); i++) {
		for(int j = 0; j <= dep[adj[s][i - 1]]; j++)
			seqans.push_back(adj[s][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i < n; i++) {
		int p;
		cin >> p;
		adj[p].push_back(i);
	}
	dfs_sz(0);
	dfs_build(0);
	reverse(label[0].begin(), label[0].end());
	reverse(seq[0].begin(), seq[0].end());
	for(auto x : labans)
		cout << x << " ";
	cout << '\n';
	cout << seqans.size() << '\n';
	for(auto x : seqans)
		cout << x << " ";
	cout << '\n';
}