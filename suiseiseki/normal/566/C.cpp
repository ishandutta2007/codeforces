#include <cmath>
#include <cstdio>
#include <algorithm>
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
const int Maxn=200000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],val[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to,int w){
	arrive[++tot]=to;
	val[tot]=w;
	nxt[tot]=head[from];
	head[from]=tot;
}
bool vis[Maxn+5];
int sz[Maxn+5],max_sz[Maxn+5];
int tot_sz;
int root,root_val;
void sz_dfs(int u,int fa){
	sz[u]=1,max_sz[u]=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa||vis[v]){
			continue;
		}
		sz_dfs(v,u);
		max_sz[u]=std::max(max_sz[u],sz[v]);
		sz[u]+=sz[v];
	}
	max_sz[u]=std::max(max_sz[u],tot_sz-sz[u]);
	if(max_sz[u]<root_val){
		root=u;
		root_val=max_sz[u];
	}
}
double f[Maxn+5],sum_1,sum_2;
void work_dfs(int u,int fa,int dep){
	sum_1+=1.0*a[u]*dep*sqrt(dep);
	sum_2+=1.0*a[u]*sqrt(dep)*3/2;
	f[u]=1.0*a[u]*sqrt(dep)*3/2;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		work_dfs(v,u,dep+val[i]);
		f[u]+=f[v];
	}
}
double ans_val;
int ans_u;
void work(int u){
	if(vis[u]){
		return;
	}
	root=0,root_val=Inf;
	sz_dfs(u,0);
	u=root;
	sum_1=sum_2=0;
	vis[u]=1;
	work_dfs(u,0,0);
	if(sum_1<ans_val){
		ans_u=u;
		ans_val=sum_1;
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(sum_2-f[v]*2<0){
			tot_sz=sz[v];
			work(v);
		}
	}
}
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=1;i<n;i++){
		int u,v,w;
		read(u),read(v),read(w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	ans_val=1e19;
	tot_sz=n;
	work(1);
	printf("%d %.10lf\n",ans_u,ans_val);
	return 0;
}