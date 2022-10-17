#include <cstdio>
#define Maxn 300000
int fa[Maxn+5];
int x[Maxn+5];
int n;
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
bool nl[Maxn+5];
int f[Maxn+5];
int g[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int dfs(int root){
	if(!nl[root]){
		return 0;
	}
	if(x[root]==1){
		f[root]=(1<<30);
		g[root]=1;
		for(int i=head[root];i;i=nxt[i]){
			f[root]=mn(f[root],dfs(arrive[i]));
			if(g[arrive[i]]==0){
				g[root]=0;
			}
		}
	}
	else{
		f[root]=0;
		int now;
		for(int i=head[root];i;i=nxt[i]){
			now=dfs(arrive[i]);
			if(now==0){
				now++;
			}
			f[root]+=now;
		}
		g[root]=1;
	}
	return f[root];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	nl[1]=1;
	for(int i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		add_edge(fa[i],i);
		nl[fa[i]]=1;
	}
	int k=0;
	for(int i=1;i<=n;i++){
		if(!nl[i]){
			k++;
		}
	}
	printf("%d\n",k-dfs(1)+g[1]);
	return 0;
}