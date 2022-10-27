#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
vector<int> g[N];
int n,c[N],dfn[N],mx[N],mn[N],C,L[N],R[N],par[N];
int premx[N],premn[N],sufmx[N],sufmn[N],who[N];
void dfs(int u,int p){
	mx[u]=mn[u]=c[u]; par[u]=p;
	L[u]=++C; who[C]=u;
	for(auto v:g[u]){
		if(v==p)continue;
		dfs(v,u);
		mx[u]=max(mx[u],mx[v]);
		mn[u]=min(mn[u],mn[v]);
	}
	R[u]=C;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	dfs(1,1);
	premx[1]=c[who[1]], premn[1]=c[who[1]];
	for(int i=2;i<=n;i++){
		premx[i]=max(premx[i-1],c[who[i]]);
		premn[i]=min(premn[i-1],c[who[i]]);
	}
	sufmx[n]=c[who[n]], sufmn[n]=c[who[n]];
	for(int i=n-1;i>=1;i--){
		sufmx[i]=max(sufmx[i+1],c[who[i]]);
		sufmn[i]=min(sufmn[i+1],c[who[i]]);
	}
	//printf("# %d %d\n", mn[2],mx[2]);
	for(int i=1;i<=n;i++){
		bool ok=1;
		for(auto j:g[i]){
			if(j==par[i]){
				int l=L[i],r=R[i];
				set<int> s;
				if(l>1) {
					s.insert(premn[l-1]);
					s.insert(premx[l-1]);
				}
				if(r<n){
					s.insert(sufmn[r+1]);
					s.insert(sufmx[r+1]);
				}
				if(s.size()>1) ok=0;
			}else{
				if(mx[j]!=mn[j]) ok=0;
			}
		}
		if(ok)return !printf("YES\n%d\n", i);
	}
	return !printf("NO\n");
}