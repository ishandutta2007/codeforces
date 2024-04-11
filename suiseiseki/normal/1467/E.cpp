#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=200000;
int n;
int a[Maxn+5];
int f[Maxn+5],g[Maxn+5];
int d[Maxn+5],d_len;
int num[Maxn+5];
int sum[Maxn+5];
int col[Maxn+5],col_fa[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
void init_dfs_1(int u,int fa){
	sum[a[u]]++;
	if(fa){
		col_fa[u]=-sum[a[fa]];
	}
	col[u]=-sum[a[u]];
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs_1(v,u);
		f[u]+=f[v];
	}
	col[u]+=sum[a[u]];
	f[u]+=col[u];
	if(fa){
		col_fa[u]+=sum[a[fa]];
	}
}
void init_dfs_2(int u,int fa){
	if(fa){
		g[u]=g[fa]+(num[a[u]]-col[u]-1);
		g[u]+=f[fa]-f[u]-col_fa[u];
	}
	else{
		g[u]=0;
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs_2(v,u);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[++d_len]=a[i];
	}
	sort(d+1,d+1+d_len);
	d_len=unique(d+1,d+1+d_len)-d-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(d+1,d+1+d_len,a[i])-d;
		num[a[i]]++;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init_dfs_1(1,0);
	init_dfs_2(1,0);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(f[i]+g[i]==0){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}