//In the name of God
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int Maxn = 1e5 + 1e3;
vector<pair<int,int> >  al[Maxn];
vector<int> Num[Maxn];
set<pair<pair<int,int>,int> > ver;
int dis[Maxn];
int W[Maxn];
int par[Maxn];
int Work[Maxn];
bool isIn[Maxn];
bool isShort[Maxn];
vector<pair<int,int> > edges;
void call(int now){
	for(int i = 0; i < al[now].size();i++){
		int u = al[now][i].first;
		if(u == par[now])
			isShort[Num[now][i]] = 1;
	}
	if(par[now])
		call(par[now]);
}
void relax(int v){
	isIn[v] = true;
	for(int i = 0; i < al[v].size();i++){
		int u = al[v][i].first,work = al[v][i].second;
		if(isIn[u])
			continue;
		ver.erase(make_pair(make_pair(dis[u],W[u]),u));
		if(dis[u] == dis[v]+1 && W[v]+work < W[u]){
			W[u] = W[v] + work;
			par[u] = v;
		}
		if(dis[u] > dis[v]+1){
			dis[u] = dis[v]+1;
			W[u] = W[v] + work;
			par[u] = v;
		}
		ver.insert(make_pair(make_pair(dis[u],W[u]),u));
	}
	return;
}
int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m;i++){
		int u,v,work;
		cin >> u >> v >> work;
		al[--u].push_back(make_pair(--v,1-work));
		al[v].push_back(make_pair(u,1-work));
		Num[v].push_back(i);
		Num[u].push_back(i);
		Work[i] = work;
		edges.push_back(make_pair(u,v));
	}
	for(int i = 1; i < n;i++)
		dis[i] = 1e6,W[i] = 1e6;
	dis[0] = 0;
	W[0] = 0;
	par[0] = -1;
	relax(0);
	while(ver.size()){
		pair<pair<int,int>,int> curr = *(ver.begin());
		int u = curr.second;
		ver.erase(curr);
		if(!isIn[u])
			relax(u);
	}
	call(n-1);
	int ans = 0;
	for(int i = 0; i < m;i++){
		if(isShort[i] && !Work[i]){
			ans++;
		}
		if(!isShort[i] && Work[i]){
			ans++;
		}
	}
	cout << ans << endl;
	for(int i = 0; i < m;i++){
		if(isShort[i] && !Work[i]){
			ans++;
			cout << edges[i].first+1 << ' ' << edges[i].second+1 << ' ' << 1 << endl;
		}
		if(!isShort[i] && Work[i]){
			ans++;
			cout << edges[i].first+1 << ' ' << edges[i].second+1 << ' ' << 0 << endl;
		}
	}
	return 0;
}