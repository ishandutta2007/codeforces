#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n,m;
struct Nod {
	int d,u,p;
	bool operator<(const Nod&o)const{
		return d>o.d;
	}
};

int dis[52][N];
vector< pair<int,int> > g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	priority_queue<Nod> q; 
	memset(dis,-1,sizeof(dis));
	dis[0][1]=0; q.push((Nod){0,1,0});
	while(q.size()) {
		Nod now = q.top(); q.pop();
		int d=now.d,u=now.u,p=now.p;
		if(d>dis[p][u])continue;
		for(auto e: g[u]) {
			int v=e.first, w=e.second;
			if(p==0){
				if(dis[w][v]==-1 || dis[w][v]>d){
					dis[w][v]=d; q.push((Nod){dis[w][v],v,w});
				} 
			} else {
				if(dis[0][v]==-1 || dis[0][v]>d+(p+w)*(p+w)) {
					dis[0][v]=d+(p+w)*(p+w); q.push((Nod){dis[0][v],v,0});
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dis[0][i]<<" \n"[i==n];
	}
}