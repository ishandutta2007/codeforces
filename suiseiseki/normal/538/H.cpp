#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=100000;
int t,T;
int n,m;
struct Segment{
	int l,r;
	int flag;
}seg[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
bool vis[Maxn+5];
bool no_ans;
void work_dfs(int u){
	if(vis[u]){
		return;
	}
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(seg[v].flag!=0&&seg[v].flag!=3-seg[u].flag){
			no_ans=1;
			return;
		}
		seg[v].flag=3-seg[u].flag;
		work_dfs(v);
		if(no_ans){
			return;
		}
	}
}
int main(){
	scanf("%d%d",&t,&T);
	scanf("%d%d",&n,&m);
	int n_1=T,n_2=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&seg[i].l,&seg[i].r);
		n_1=min(n_1,seg[i].r);
		n_2=max(n_2,seg[i].l);
	}
	if(n_1+n_2<t){
		n_2=t-n_1;
	}
	if(n_1+n_2>T){
		n_1=T-n_2;
	}
	if(n_1<0||n_2<0){
		puts("IMPOSSIBLE");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(seg[i].l<=n_1&&seg[i].r>=n_1&&seg[i].l<=n_2&&seg[i].r>=n_2){
			seg[i].flag=0;
		}
		else if(seg[i].l<=n_1&&seg[i].r>=n_1){
			seg[i].flag=1;
		}
		else if(seg[i].l<=n_2&&seg[i].r>=n_2){
			seg[i].flag=2;
		}
		else{
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		if(seg[i].flag!=0){
			work_dfs(i);
			if(no_ans){
				puts("IMPOSSIBLE");
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(seg[i].flag==0){
			seg[i].flag=1;
		}
		work_dfs(i);
		if(no_ans){
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	puts("POSSIBLE");
	printf("%d %d\n",n_1,n_2);
	for(int i=1;i<=n;i++){
		printf("%d",seg[i].flag);
	}
	puts("");
	return 0;
}