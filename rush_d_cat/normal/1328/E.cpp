#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
int n,k,par[N],dep[N],L[N],R[N],C;
vector<int> g[N]; 
void dfs(int u,int p){
	par[u]=p;dep[u]=dep[p]+1;
	L[u]=++C;
	for(auto v:g[u]){
		if(v==p)continue;
		dfs(v,u);
	}
	R[u]=C;
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs(1,1);
	while(k--){
		int c; scanf("%d",&c);
		vector< pair<int,int> > vec;
		for(int i=1;i<=c;i++){
			int x;scanf("%d",&x);
			x=par[x];
			vec.push_back(make_pair(L[x],R[x]));
		}
		sort(vec.begin(),vec.end());
		bool flag=1;
		for(int i=0;i+1<vec.size();i++){
			if(!(vec[i].first<=vec[i+1].first && vec[i].second>=vec[i+1].second)) flag=0;
		}
		printf("%s\n", flag?"YES":"NO");
	}
}