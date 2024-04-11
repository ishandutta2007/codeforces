#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=200000;
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int a[Maxn+5];
void init(){
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
}
int dep[Maxn+5];
int f[Maxn+5];
void dep_dfs(int u,int fa,int c){
	dep[u]=dep[fa]+(a[u]!=c&&a[u]);
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		dep_dfs(v,u,a[u]==0?c:a[u]);
	}
}
void work_dfs(int u,int fa){
	if(a[u]==0){
		a[u]=a[fa];
	}
	f[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		work_dfs(v,u);
		f[u]=max(f[u],f[v]+(a[u]!=a[v]));
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		int root=0;
		for(int i=1;i<=n;i++){
			if(a[i]){
				root=i;
				break;
			}
		}
		if(root==0){
			puts("1");
			continue;
		}
		dep_dfs(root,0,a[root]);
		for(int i=1;i<=n;i++){
			if(a[i]&&dep[i]>dep[root]){
				root=i;
			}
		}
		work_dfs(root,0);
		printf("%d\n",(f[root]>>1)+1);
	}
	return 0;
}