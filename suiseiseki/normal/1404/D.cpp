#include <cstdio>
const int Maxn=1000000;
int n;
int a[Maxn+5],b[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int col[Maxn+5];
void work_dfs(int u){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(col[v]){
			continue;
		}
		col[v]=((col[u]-1)^1)+1;
		work_dfs(v);
	}
}
int main(){
	scanf("%d",&n);
	if(n&1){
		puts("Second");
		fflush(stdout);
		for(int i=1;i<=(n<<1);i++){
			scanf("%d",&a[i]);
			if(b[a[i]]==0){
				b[a[i]]=i;
			}
			else{
				add_edge(b[a[i]],i);
				add_edge(i,b[a[i]]);
				b[a[i]]=0;
			}
		}
		for(int i=1;i<=n;i++){
			add_edge(i,i+n);
			add_edge(i+n,i);
		}
		for(int i=1;i<=n;i++){
			if(col[i]==0){
				col[i]=1;
				work_dfs(i);
			}
		}
		int ans=0;
		for(int i=1;i<=(n<<1);i++){
			if(col[i]==1){
				ans=(ans+i)%(n<<1);
			}
		}
		if(ans==0){
			for(int i=1;i<=(n<<1);i++){
				if(col[i]==1){
					printf("%d ",i);
				}
			}
			puts("");
		}
		else{
			for(int i=1;i<=(n<<1);i++){
				if(col[i]==2){
					printf("%d ",i);
				}
			}
			puts("");
		}
	}
	else{
		puts("First");
		for(int i=1;i<=(n<<1);i++){
			printf("%d ",i%n==0?n:i%n);
		}
		puts("");
		fflush(stdout);
	}
	return 0;
}