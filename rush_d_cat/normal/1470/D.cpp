#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int t, n, m;
vector<int> g[N];
int par[N];
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}
bool chk(){
	for(int i=1;i<=n;i++) par[i]=i;
	for(int u=1;u<=n;u++){
		for(auto v:g[u])par[find(u)]=find(v);
	}
	for(int i=1;i<=n;i++)if(find(i)!=find(1))return false;
	return true;
}
void sovle() {
	set<int> s;
	vector<int> col(n+1, -1);
	s.insert(1);
	while(s.size()) {
		int u=*s.begin(); s.erase(u); 
		if(col[u]!=-1) continue;
		col[u]=1;
		for(auto v: g[u]) {
			if(col[v]==-1) {
				col[v]=0; 
				for(auto w: g[v]) {
					if (col[w]==-1) {
						s.insert(w);
					}
				}
			}
		}
	} 
	printf("YES\n");
	vector<int> ans;
	for(int i=1;i<=n;i++) if(col[i]) ans.push_back(i);
	printf("%d\n", ans.size());
	for(auto x:ans) {
		printf("%d ", x); 
	}
	printf("\n");
}
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=m;i++) {
			int u,v; scanf("%d%d",&u,&v);
			g[u].push_back(v); g[v].push_back(u);
		}

		if(!chk()) {
			printf("NO\n"); continue;
		}
		sovle();
	}
}