#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <cstdio>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
typedef long long ll;
const int Maxn=50000;
const int Inf=0x3f3f3f3f;
int n,q;
int a[Maxn+5];
int fa[Maxn+5];
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int dep[Maxn+5],dis[Maxn+5];
int dfn[Maxn+5],right[Maxn+5],rnk[Maxn+5],dfn_tot,sz[Maxn+5];
int sum[Maxn+5];
ll f[Maxn+5];
void init_dfs(int u){
	dep[u]=dep[fa[u]]+1;
	if(a[u]!=1){
		dfn[u]=++dfn_tot;
		dis[dfn_tot]=dep[u];
		rnk[dfn_tot]=u;
		sz[u]=1;
		sum[u]=0;
	}
	else{
		dfn[u]=dfn_tot+1;
		sz[u]=0;
		sum[u]=1;
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		init_dfs(v);
		sz[u]+=sz[v];
		sum[u]+=sum[v];
		f[u]+=f[v];
		f[u]+=sum[v];
	}
	right[u]=dfn[u]+sz[u]-1;
}
int del[Maxn+5];
int main(){
	read(n),read(q);
	for(register int i=1;i<=n;++i){
		read(a[i]);
		del[i]=-Inf;
	}
	for(register int i=2;i<=n;++i){
		read(fa[i]);
		add_edge(fa[i],i);
	}
	init_dfs(1);
	for(register int i=1;i<=q;++i){
		int u;
		read(u);
		ll ans_1=0;
		int ans_2=0;
		for(register int j=dfn[u];j<=right[u];++j){
			int tmp=(i>=del[j]);
			ans_1+=dis[j]*tmp;
			ans_2+=tmp;
			del[j]=(tmp?i+a[rnk[j]]:del[j]);
		}
		ans_1-=1ll*ans_2*dep[u];
		ans_1+=f[u],ans_2+=sum[u];
		printf("%lld %d\n",ans_1,ans_2);
	}
	return 0;
}