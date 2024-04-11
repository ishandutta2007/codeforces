#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
int n,m,vis[N],dep[N],par[N],B,B2;
vector<int> g[N],vec[N];
void dfs(int u,int p){
	//printf("u=%d, p=%d\n", u, p);
	dep[u]=dep[p]+1; vis[u]=1; vec[(dep[u]-1)%B2].push_back(u); par[u]=p;
	for(auto v:g[u]){
		if(vis[v]) {
			if(dep[u]-dep[v]+1>=B) {
				printf("2\n");
				vector<int> ans;
				int now=u;
				while(1){
					ans.push_back(now); if(now==v) break;
					now=par[now];
				}
				printf("%d\n", ans.size());
				for(auto x: ans){
					printf("%d ", x);
				}
				exit(0);
			}
			continue;
		}
		dfs(v,u);
	}
}
int main(){
	scanf("%d%d",&n,&m);B=sqrt(n); while(B*B<n) B++; 
	B2=sqrt(n);B2=max(0,B2-2);while((B2+1)*(B2+1)<=n)B2++;
	for(int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v); g[u].push_back(v); g[v].push_back(u);
	}
	dfs(1,1);
	int mx=0,bst=0;
	for(int i=0;i<B2;i++)if(vec[i].size()>mx)mx=vec[i].size(),bst=i;
	printf("1\n");
	for(int i=0;i<B;i++){
		printf("%d ", vec[bst][i]);
	}
}