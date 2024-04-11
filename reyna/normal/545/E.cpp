//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 9;
typedef long long ll;
const ll oo = 1e18;
set<pair<ll,pair<ll,ll> > > st;
ll par[Maxn];
ll dis[Maxn],wei[Maxn],vis[Maxn],len[Maxn];
vector<pair<ll,ll> > al[Maxn];
ll ans = 0;
void relax(int v){
	vis[v] = 1;
	for(int i = 0; i < al[v].size();i++){
		int u = al[v][i].first,id = al[v][i].second,w = len[id];
		if(vis[u]) continue;
		st.erase(make_pair(dis[u],make_pair(wei[u],u)));
		if(dis[u] > dis[v] + w || dis[u] == dis[v] + w && w < wei[u]){
			par[u] = id;
			wei[u] = w;
			dis[u] = dis[v] + w;
		}
		st.insert(make_pair(dis[u],make_pair(wei[u],u)));
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n;i++) dis[i] = oo;
	for(int i = 0; i < m;i++){
		int u,v;
		cin >> u >> v >> len[i];
		--u,--v;
		al[u].push_back(make_pair(v,i));
		al[v].push_back(make_pair(u,i));
	}
	int source;
	cin >> source;
	source--;
	par[source] = Maxn;
	dis[source] = 0;
	relax(source);
	while(st.size()){
		pair<ll,pair<ll,ll> > cur = *(st.begin());
		st.erase(cur);
		ll v = cur.second.second,w = cur.second.first;
		if(vis[v]) continue;
		relax(v);
		ans += w;
	}
	cout << ans << endl;
	for(int i = 0; i < n;i++){
		if(i != source){
			cout << par[i] + 1 << ' ';
		}
	}
	return 0;
}