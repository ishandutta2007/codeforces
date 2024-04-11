#include <bits/stdc++.h>
using namespace std;
const int N = 500000 + 10;
vector<int> g[N], vec[N];
int n, m, c[N], vis[N], fg[N];
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		int x; scanf("%d",&x);c[i]=x;
		vec[x].push_back(i);
		mx=max(mx, x);
	}
	vector<int> ans; int ok=1;
	for(int i=1;i<=mx;i++){
		for(auto x: vec[i]) {
			ans.push_back(x);
			for(auto y: g[x]){
				if(vis[y]) fg[c[y]]=1;
			}
			for(int it=1;;it++) if(fg[it]==0) {
				//printf("x=%d, it=%d\n", x,it);
				if(c[x]!=it) ok=0;
				break;
			}
			for(auto y: g[x]){
				if(vis[y]) fg[c[y]]=0;
			}
			vis[x]=1;
		}
	}
	if(ok==0) return !printf("-1\n"); 
	for(auto x: ans) printf("%d ", x); printf("\n");
}