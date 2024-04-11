#include <cstdio>
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
const int Maxn=300000;
int n,m;
int qu[Maxn+5],qu_f,qu_t;
int f[Maxn+5];
struct Edge{
	int u,v;
}edge[Maxn+5];
int deg[Maxn+5];
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
void init(){
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
		deg[i]=0;
	}
}
void work_bfs(){
	init();
	qu_f=1,qu_t=0;
	for(int i=1;i<=m;i++){
		deg[edge[i].v]++;
		add_edge(edge[i].u,edge[i].v);
	}
	for(int i=1;i<=n;i++){
		if(deg[i]==0){
			qu[++qu_t]=i;
		}
	}
	int last=n;
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		last--;
		if(qu_f>qu_t){
			f[u]+=last;
		}
		else if(qu_f==qu_t){
			int tmp_u=qu[qu_f];
			bool flag=1;
			for(int i=head[tmp_u];i;i=nxt[i]){
				int v=arrive[i];
				if(deg[v]==1){
					flag=0;
					break;
				}
			}
			if(flag){
				f[u]+=last-1;
			}
		}
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			deg[v]--;
			if(deg[v]==0){
				qu[++qu_t]=v;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&edge[i].u,&edge[i].v);
	}
	work_bfs();
	for(int i=1;i<=m;i++){
		swap(edge[i].u,edge[i].v);
	}
	work_bfs();
	int ans=0;
	for(int i=1;i<=n;i++){
		if(f[i]>=n-2){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}