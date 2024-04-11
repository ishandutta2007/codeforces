#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
int n,m,k,p[N],dis[N],can[N];
vector<int> g[N];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[v].push_back(u);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++)scanf("%d",&p[i]);
	memset(dis,-1,sizeof(dis));
	dis[p[k]]=0; 
	queue<int> q; q.push(p[k]);
	while(q.size()){
		int u=q.front(); q.pop();
		for(auto v:g[u]){
			if(dis[v]==-1){
				dis[v]=dis[u]+1; q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(auto v:g[i]){
			if(dis[v]==dis[i]+1){
				can[v]++;
			}
		}
	}
	//printf("dis = %d\n", dis[p[1]]);
	int mn=0,mx=0;
	for(int i=1;i<k;i++){
		if(dis[p[i]]<=dis[p[i+1]])mn++,mx++;
		else {
			if(can[p[i]]>=2)mx++;
		}
	}
	cout<<mn<<" "<<mx<<endl;
}