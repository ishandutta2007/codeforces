#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

const ll oo = (ll)1<<60;
const int Maxn = 1e3+10;
ll dis[Maxn];
vector<pii > al[Maxn];
vector<pii > adj[Maxn];
pii taxi[Maxn];
set<pair<ll,int> > ver;
bool isIn[Maxn];
int n,m;

void Clear(){
	for(int i = 0; i < n;i++){
		isIn[i] = false;
		dis[i] = oo;
	}
}
void relax1(int v){
	isIn[v] = true;
	for(int i = 0; i < al[v].size();i++){
		int u = al[v][i].x,w = al[v][i].y;
		if(isIn[u])
			continue;
		ver.erase(make_pair(dis[u],u));
		dis[u] = min(dis[u],dis[v]+w);
		ver.insert(make_pair(dis[u],u));
	}
}
void relax2(int v){
	isIn[v] = true;
	for(int i = 0; i < adj[v].size();i++){
		int u = adj[v][i].x,w = adj[v][i].y;
		if(isIn[u])
			continue;
		dis[u] = min(dis[u],dis[v]+w);
	}
}
void dij1(int v){
	Clear();
	dis[v] = 0;
	relax1(v);
	while(ver.size()){
		pair<ll,int> curr = *(ver.begin());
		int u = curr.y;
		if(!isIn[u]){
			relax1(u);
		}
		ver.erase(curr);
	}
	for(int i = 0; i < n;i++){
		if(v == i)
			continue;
		if(dis[i] <= taxi[v].y){
			adj[v].push_back(make_pair(i,taxi[v].x));
		}
	}
}
void dij2(int v){
	Clear();
	dis[v] = 0;
	relax2(v);
	for(int i = 0; i < n;i++){
		ll Min = oo;
		int in = -1;
		for(int curr = 0; curr < n;curr++){
			if(isIn[curr])
				continue;
			if(Min > dis[curr]){
				Min = dis[curr];
				in = curr;
			}
		}
		if(in == -1)
			break;
		relax2(in);
	}
}
int main(){
	cin >> n >> m;
	int X,Y;
	cin >> X >> Y;
	for(int i = 0; i < m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		al[--u].push_back(make_pair(--v,w));
		al[v].push_back(make_pair(u,w));
	}
	for(int i = 0; i < n;i++){
		cin >> taxi[i].y >> taxi[i].x;
	}
	for(int i = 0; i < n;i++){
		dij1(i);
	}
	dij2(--X);
	if(dis[--Y] == oo){
		cout << -1 << endl;
		return 0;
	}
	cout << dis[Y] << endl;
}