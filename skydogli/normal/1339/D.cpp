#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MN 200005
int T,n;
int fa[MN],dep[MN],deg[MN],fk[MN];;
vector<int>edge[MN];
void dfs(int x){
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;
		dep[v]=dep[x]+1;
		dfs(v);
	}
	if(deg[x]==1){
		if(fa[x])fk[fa[x]]++;
		else fk[edge[x][0]]++;
	}
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<n;++i){
		int a,b;
		scanf("%lld%lld",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
		deg[a]++;deg[b]++;
	}
	dfs(1);
	int vis[2];vis[0]=vis[1]=0;
	for(int i=1;i<=n;++i)if(deg[i]==1)vis[dep[i]&1]=1;
	int mx=n-1;
	for(int i=1;i<=n;++i)if(fk[i]>1)mx-=fk[i]-1;	
	printf("%lld %lld",(vis[0]+vis[1]==2)?3ll:1ll,mx);
	return 0;
}