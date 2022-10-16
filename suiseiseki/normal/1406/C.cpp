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
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=100000;
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int sz[Maxn+5];
int maxn[Maxn+5];
void init_dfs(int u,int fa){
	sz[u]=1;
	maxn[u]=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs(v,u);
		sz[u]+=sz[v];
		maxn[u]=max(maxn[u],sz[v]);
	}
}
int fa[Maxn+5];
int col[Maxn+5];
void col_dfs(int u,int c){
	col[u]=c;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		col_dfs(v,c);
		sz[u]+=sz[v];
	}
}
int main(){
	int T;
	read(T);
	while(T--){
		read(n);
		for(int i=1;i<=n;i++){
			head[i]=0;
		}
		tot=0;
		for(int i=1;i<n;i++){
			int u,v;
			read(u),read(v);
			add_edge(u,v);
			add_edge(v,u);
		}
		init_dfs(1,0);
		int num=n,sum=0;
		for(int i=1;i<=n;i++){
			maxn[i]=max(maxn[i],n-sz[i]);
			if(maxn[i]<num){
				num=maxn[i];
				sum=0;
			}
			if(maxn[i]==num){
				sum++;
			}
		}
		if(sum==1){
			int u=1,v=arrive[head[1]];
			printf("%d %d\n%d %d\n",u,v,u,v);
			continue;
		}
		int u=0,v=0;
		for(int i=1;i<=n;i++){
			if(maxn[i]==num){
				if(u==0){
					u=i;
				}
				else{
					v=i;
				}
			}
		}
		fa[u]=v;
		fa[v]=u;
		col_dfs(u,0);
		col_dfs(v,1);
		for(int i=1;i<=n;i++){
			if(sz[i]==1){
				if(col[i]==1){
					printf("%d %d\n",fa[i],i);
					printf("%d %d\n",i,u);
				}
				else{
					printf("%d %d\n",fa[i],i);
					printf("%d %d\n",i,v);
				}
				break;
			}
		}
	}
	return 0;
}