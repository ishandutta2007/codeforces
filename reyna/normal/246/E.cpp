//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define hash Tavas
const int N = 2e5 + 9;
const int base = 97;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
int hash[N], sz[N], h[N], ans[N];
vector<int> adj[N];
vector<pii> query[N];
set<int> st[N];
map<int, int> cnt[N];
void dfs_sz(int v, int p = -1) {
	sz[v] = 1;
	for (auto u : adj[v])
		h[u] = h[v] + 1, dfs_sz(u, v), sz[v] += sz[u];	
}
void ins(int hh, int x, int p) {
	int &c = cnt[hh][x];
	c += p;
	if (c)
		st[hh].insert(x);
	if (!c)
		st[hh].erase(x);
		
}
void dfs_fill(int v, int p = -1, int to = 1) {
	ins(h[v], hash[v], to);
	for (auto u : adj[v])
		dfs_fill(u, v, to);
	return;
			
}
void dfs_ans(int v, int p = -1) {
	int id = -1;
	for (auto u : adj[v])
		if (id == -1 || sz[u] > sz[id])
			id = u;
	for (auto u : adj[v]) if (u != id)
		dfs_ans(u, v), dfs_fill(u, v, -1);
	if (id != -1)
		dfs_ans(id, v);
	for (auto u : adj[v]) if (u != id)
		dfs_fill(u, v, 1);
	ins(h[v], hash[v], 1);
	for (auto q : query[v]) {
		int dep = q.first + h[v];
		ans[q.second] = st[dep].size();
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector<int> root;
	for (int i = 0; i < n; ++i) {
		string name; int p;
		cin >> name >> p;
		if (!p)
			root.push_back(i);
		for (int j = 0; j < name.size(); ++j)
			hash[i] *= base, hash[i] %= mod, hash[i] += name[j];
		p--;
		if (p != -1)
			adj[p].push_back(i);
	}
	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int v, r; cin >> v >> r; --v;
		query[v].push_back({r, i});
	}
	for (auto u: root)
		dfs_sz(u),
		dfs_ans(u),
		dfs_fill(u, -1, -1);
	for (int i = 0; i < q; ++i)
		cout << ans[i] << '\n';
	return 0;
}