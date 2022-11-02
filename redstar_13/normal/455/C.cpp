#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> VI;
#define NN 300010
VI adj[NN];
bool vst[NN];
int dp[NN][2];
int root[NN];
int cnt[NN];
int dst[NN];
int find_root(int u) {
	if(root[u]==u) return u;
	return root[u]=find_root(root[u]);
}

void reunion(int u,int v){
	u=find_root(u);
	v=find_root(v);
	if(u==v) return;
	if(cnt[u]<cnt[v]) swap(u,v);
	cnt[u]+=cnt[v];
	root[v]=u;
	dst[u]=max(dst[u],(dst[u]+1)/2+(dst[v]+1)/2+1);
	dst[u]=max(dst[u],dst[v]);
}
int val;
void dfs(int u,int fa=0){
	vst[u]=1;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
	VI vt;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(v==fa) continue;
		vt.pb(dp[v][0]);
	}
	sort(vt.begin(),vt.end());
	reverse(vt.begin(),vt.end());
	if(vt.size()) dp[u][0]=vt[0]+1;
	if(vt.size()>1) dp[u][1]=vt[1]+1;
	val=max(val,dp[u][0]+dp[u][1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) root[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
		reunion(u,v);
	}
	for(int i=1;i<=n;i++){
		if(!vst[i]){
			val=0;
			dfs(i);
			int fa=find_root(i);
			dst[fa]=val;
		}
	}
	while(q--){
		int ok;
		scanf("%d",&ok);
		if(ok==2){
			int u,v;
			scanf("%d%d",&u,&v);
			reunion(u,v);
		}
		else{
			int u;
			scanf("%d",&u);
			u=find_root(u);
			printf("%d\n",dst[u]);
		}
	}
    return 0;
}