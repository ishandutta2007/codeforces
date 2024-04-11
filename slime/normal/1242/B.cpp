#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
#define vi vector<int>
#define iter set<int>::iterator
#define pb push_back
using namespace std;
int fa[maxn], sz[maxn];
vi eg[maxn];
int fl[maxn];
set<int> cur;
int gfa(int u) {
	if (fa[u] == u) return u;
	return fa[u] = gfa(fa[u]);
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v), eg[v].pb(u);
	}
	for (int i = 1; i <= n; i++)	
		fa[i] = i, sz[i] = 1, cur.insert(i);
	for (int i = 1; i <= n; i++) {
		for (auto v : eg[i])
			fl[gfa(v)]++;
		vi er;
		int nf = gfa(i);
		for (iter r = cur.begin(); r != cur.end(); r++) {
			int ns = (*r);
			if (fl[ns] == sz[ns]) continue;
			if (ns == nf) continue;
			fa[ns] = nf, sz[nf] += sz[ns];
			er.pb(ns);
		}
		for (auto v : er)
			cur.erase(v);
		for (auto v : eg[i])
			fl[gfa(v)] = 0;
	}
	cout << cur.size() - 1 << endl;
	return 0;
}