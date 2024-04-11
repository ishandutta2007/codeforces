#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
int n,m,k;
vector< pair<int,int> > g[N];
int s[N],t[N];


struct Nod{
	int dis,u;
	bool operator<(const Nod&o)const{
		return dis>o.dis;
	}
};
int dis[N][N];
void dij(int src){
	priority_queue<Nod> q; 
	for(int i=1;i<=n;i++) dis[src][i]=-1;
	dis[src][src]=0; q.push((Nod){0,src});
	while(q.size()){
		Nod now=q.top(); q.pop();
		if(dis[src][now.u] < now.dis) continue;
		for(auto e:g[now.u]){
			int u=now.u;
			int v=e.first;
			int w=e.second;
			if(dis[src][v]==-1 || dis[src][v] > dis[src][u]+w) {
				dis[src][v]=dis[src][u]+w;
				q.push((Nod){dis[src][v],v});
			}
		}
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=n;i++) dij(i);

	for(int i=1;i<=k;i++){
		scanf("%d%d",&s[i],&t[i]);
	}

	int ans=1e9+7;
	for(int u=1;u<=n;u++)
		for(auto e:g[u]){
			int v=e.first;
			int tmp=0;
			for(int i=1;i<=k;i++){
				tmp+=min(min(dis[s[i]][t[i]], dis[s[i]][u] + dis[t[i]][v]), dis[s[i]][v] + dis[t[i]][u]);
			}
			ans=min(ans,tmp);
		}
	printf("%d\n", ans);
}