//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 9;
int dis1[N],dis2[N];
int vis[N];
int n,m;
int w[N],h[N],cut_edge[N];
set<pair<int,int> > st;
vector<pair<int,int> > edge;
vector<pair<int,int> > al[N];
void relax(int v,int *dis) {
	vis[v] = 1;
	for(auto &u : al[v]) {
		int ver = u.first;
		if(vis[ver]) continue;
		st.erase({dis[ver],ver});
		dis[ver] = min(dis[ver],dis[v] + u.second);
		st.insert({dis[ver],ver});
	}
	return;
}
void dj(int s,int *dis) {
	memset(vis,0,sizeof vis);
	for(int i = 0; i < N; ++i) dis[i] = 1e18;
	dis[s] = 0;
	relax(s,dis);
	while(st.size()) {
		pair<int,int> cur = *(st.begin());
		int v = cur.second;
		st.erase(cur);
		if(vis[v]) continue;
		relax(v,dis);
	}
	return;
}
int dfs(int v,int p = -1,int eid = -1) {
	if(vis[v]) return h[v];
	vis[v] = 1;
	h[v] = (p + 1 ? h[p] + 1 : 0);
	int res = h[v];
	for(auto e : al[v]) {
		int u = e.first,id = e.second;
		if(id == eid) continue;
		res = min(dfs(u,v,id),res);
	}
	if(eid + 1 && res >= h[v]) cut_edge[eid] = 1;
	return res;
}
main() {
	ios_base::sync_with_stdio(0);
	int s,t; cin >> n >> m >> s >> t; --s,--t;
	for(int i = 0; i < m; ++i) {
		int u,v; cin >> u >> v >> w[i]; --u,--v;
		al[u].push_back({v,w[i]});
		edge.push_back({u,v});
	}
	dj(s,dis1);
	for(int i = 0; i < n; ++i) al[i].clear();
	for(int i = 0; i < m; ++i) al[edge[i].second].push_back({edge[i].first,w[i]});
	dj(t,dis2);
	for(int i = 0; i < n; ++i) al[i].clear();
	for(int i = 0; i < m; ++i) {
		int u = edge[i].first,v = edge[i].second,len = w[i];
		int dis = dis1[u] + dis2[v] + len;
		if(dis == dis1[t]) {
			al[u].push_back({v,i});
			al[v].push_back({u,i});
		}
	}
	memset(vis,0,sizeof vis);
	dfs(s);
	for(int i = 0; i < m; ++i) {
		int u = edge[i].first,v = edge[i].second,len = w[i];
		int dis = dis1[u] + dis2[v] + len;
		if(dis == dis1[t] && cut_edge[i]) cout << "YES\n";
		else if(dis - dis1[t] + 1 < len) cout << "CAN " << dis - dis1[t] + 1 << '\n';
		else cout << "NO\n";
	}
}