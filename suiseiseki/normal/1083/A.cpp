#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 300000
int w[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],dist[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to,int dis){
	arrive[++tot]=to;
	dist[tot]=dis;
	nxt[tot]=head[from];
	head[from]=tot;
}
ll f[Maxn+5],g[Maxn+5];
ll mx(ll a,ll b){
	return a>b?a:b;
}
ll ans;
void dfs(int root,int fa){
	ll maxn_1,maxn_2;
	maxn_1=maxn_2=0;
	int v;
	for(int i=head[root];i;i=nxt[i]){
		v=arrive[i];
		if(v==fa){
			continue;
		}
		dfs(v,root);
		if(f[v]-dist[i]>maxn_1){
			maxn_2=maxn_1;
			maxn_1=f[v]-dist[i];
		}
		else if(f[v]-dist[i]>maxn_2){
			maxn_2=f[v]-dist[i];
		}
	}
	f[root]=maxn_1+w[root];
	g[root]=maxn_1+maxn_2+w[root];
	ans=mx(ans,g[root]);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	int u,v,d;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&d);
		add_edge(u,v,d);
		add_edge(v,u,d);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}