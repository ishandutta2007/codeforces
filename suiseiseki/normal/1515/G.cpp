#include <cstdio>
#include <algorithm>
template<typename Elem>
Elem gcd(Elem a,Elem b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
typedef long long ll;
const int Maxn=200000;
int n,m;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],val[Maxn<<1|5],tot;
void add_edge(int from,int to,int w){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	val[tot]=w;
	head[from]=tot;
}
ll dis[Maxn+5];
int bel[Maxn+5],bel_tot;
int dfn[Maxn+5],low[Maxn+5],dfn_tot;
bool in_st[Maxn+5];
bool vis[Maxn+5];
int st[Maxn+5],top;
ll g[Maxn+5];
void tarjan(int u){
	in_st[u]=1;
	st[++top]=u;
	dfn[u]=low[u]=++dfn_tot;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(dfn[v]==0){
			tarjan(v);
			low[u]=std::min(low[u],low[v]);
		}
		else if(in_st[v]){
			low[u]=std::min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		bel[u]=++bel_tot;
		in_st[u]=0;
		while(st[top]!=u){
			bel[st[top]]=bel[u];
			in_st[st[top]]=0;
			top--;
		}
		top--;
	}
}
void work_dfs(int u){
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(bel[v]!=bel[u]){
			continue;
		}
		if(!vis[v]){
			dis[v]=dis[u]+val[i];
			work_dfs(v);
		}
		else{
			g[bel[u]]=gcd(g[bel[u]],std::abs(dis[u]-dis[v]+val[i]));
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
	}
	for(int i=1;i<=n;i++){
		if(dfn[i]==0){
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			work_dfs(i);
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int v,s,t;
		scanf("%d%d%d",&v,&s,&t);
		if(g[bel[v]]==0){
			if(s==0){
				puts("YES");
			}
			else{
				puts("NO");
			}
		}
		else{
			ll val=gcd(g[bel[v]],1ll*t);
			if(s%val==0){
				puts("YES");
			}
			else{
				puts("NO");
			}
		}
	}
	return 0;
}