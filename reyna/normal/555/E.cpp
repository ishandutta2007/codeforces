//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 9;
const int lg = 21;
int cnt,cmp[Maxn],cut[Maxn];
int h[Maxn],s[Maxn],t[Maxn];
vector<pair<int,int> > al[Maxn];
vector<int> vt[Maxn],qt[Maxn];
vector<int> adj[Maxn];
int pl[Maxn];
int par[Maxn][lg];
vector<int> eli[Maxn];
vector<int> ver,query;
pair<int,int> edge[Maxn];
int up[Maxn],down[Maxn];
int to[Maxn];
int mark[Maxn];
int find(int v) {
	if(to[v] == v) return v;
	return to[v] = find(to[v]);
}
void unite(int u,int v) {
	u = find(u) , v = find(v);
	to[u] = v;
	return;
}
int what_the_hell;
int dfs1(int v,int p = -1,int eid = -1) {
//	cout << p << " -> " << v << '\n';
	if(mark[v]) return h[v];
	mark[v] = 1;
	h[v] = (p + 1 ? h[p] + 1 : 0);
	int res = h[v];
	for(int i = 0; i < al[v].size();i++) {
		int u = al[v][i].first,id = al[v][i].second;
		if(id == eid) continue;
		int is = mark[u];
		int x = dfs1(u,v,id);
		if(!is && x > h[v]) cut[id] = 1;
		res = min (res,x);
	}
	return res;
}
void dfs3(int v = 0,int p = -1) {
	memset(par[v],-1,sizeof par[v]);
	h[v] = (p + 1 ? h[p] + 1 : 0);
	par[v][0] = p;
	for(int i = 1; i < lg;i++)
		if(par[v][i-1] + 1)
			par[v][i] = par[par[v][i-1]][i-1];
	for(int i = 0; i < adj[v].size();i++) {
		int u = adj[v][i];
		if(u != p) dfs3(u,v);
	}
	return;
}
int go_up(int v,int x) {
	for(int bit = lg - 1; bit + 1 ;--bit)
		if(x >> bit & 1)
			v = par[v][bit];
	return v;
}
int lca(int u,int v) {
	if(h[u] < h[v]) swap(u,v);
	u = go_up(u,h[u] - h[v]);
	if(u == v) return v;
	for(int bit = lg - 1; bit + 1;--bit)
		if(par[v][bit] != par[u][bit])
			v = par[v][bit],u = par[u][bit];
	return par[v][0];
}
pair<int,int> dfs4(int v,int p = -1) {
	int res1 = up[v],res2 = down[v];
//	cout << p << " -> " << v << " up & down " << up[v] << ' ' << down[v] << '\n';
	for(int i = 0; i < adj[v].size();i++) {
		int u = adj[v][i];
		if(u == p) continue;
		pair<int,int> cur = dfs4(u,v);
//		if(cur.first != 0 && cur.second != 0) {
//			cout << "No\n";
//			exit(0);
//		}
		res1 += cur.first;
		res2 += cur.second;
	}
	if(res1 > 0 && res2 > 0) {
		cout << "No\n";
		exit(0);
	}
	return make_pair(res1,res2);
}
int solve(int vid,int n,int q) {
	ver = vt[vid],query = qt[vid];
	for(int i = 0; i < n;i++) adj[i].clear(),up[i] = 0,down[i] = 0;
	for(int i = 0; i < eli[vid].size();i++) {
		int id = eli[vid][i];
		int u = edge[id].first,v = edge[id].second;
		int pu = cmp[u],pv = cmp[v];
		if(pu == pv) continue;
		adj[pl[pu]].push_back(pl[pv]);
		adj[pl[pv]].push_back(pl[pu]);
	}
	dfs3(0);
	for(int i = 0; i < qt[vid].size();i++) {
		int id = qt[vid][i];
		int ss = pl[cmp[s[id]]],tt = pl[cmp[t[id]]];
		if(ss != tt) {
			int p = lca(ss,tt);
//			cout << p << ' ' << ss << " & " << tt << '\n';
			up[ss]++;
			up[p]--;
			down[tt]++;
			down[p]--;
		}
	}
	dfs4(0);
	return 1;
}
void dfs2(int v) {
	if(mark[v]) return;
	mark[v] = 1; cmp[v] = cnt;
	for(int i = 0; i < al[v].size();i++) {
		int u = al[v][i].first,id = al[v][i].second;
		if(!cut[id]) dfs2(u);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n,m,q; cin >> n >> m >> q;
	if(n == 200000) what_the_hell = 1;
	for(int i = 0; i < n;i++) to[i] = i;
	for(int i = 0; i < m;i++) {
		int u,v; cin >> u >> v; --u,--v; unite(u,v);
		al[u].push_back(make_pair(v,i));
		al[v].push_back(make_pair(u,i));
		edge[i] = make_pair(u,v);
	}
	for(int i = 0; i < q;i++) {
		cin >> s[i] >> t[i]; --s[i],--t[i];
		if(find(s[i]) != find(t[i])) {
			cout << "No\n";
			return 0;
		}
		int v = find(s[i]);
		qt[v].push_back(i);
	}
	for(int i = 0; i < n;i++) if(!mark[i]) dfs1(i);
	memset(mark,0,sizeof mark);
	for(int i = 0; i < n;i++) if(!mark[i]) dfs2(i),cnt++;
	memset(mark,0,sizeof mark);
	for(int i = 0; i < n;i++) {
		int v = find(i),u = cmp[i];
		if(!mark[u]) {
			vt[v].push_back(u);
			pl[u] = vt[v].size() - 1;
			mark[u] = 1;
		}
	}
	for(int i = 0; i < m;i++) {
		int u = edge[i].first,v = edge[i].second;
		int pu = cmp[u],pv = cmp[v];
		if(pu == pv) continue;
		int p = find(u);
		eli[p].push_back(i);
//		al[pl[pu]].push_back(pl[pv]);
//		al[pl[pv]].push_back(pl[pu]);
	}
	int is = 1;
	for(int i = 0; i < n;i++) {
		if(qt[i].size()) {
			is &= solve(i,vt[i].size(),qt[i].size());
		}
	}
//	if(is) {
//		cout << "YES\n";
//	} else {
//		cout << "NO\n";
//	}
	cout << "Yes\n";
}