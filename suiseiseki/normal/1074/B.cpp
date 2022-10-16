#include <cstdio>
const int Maxn=1000;
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
bool vis_a[Maxn+5],vis_b[Maxn+5];
bool in_q[Maxn+5];
int a[Maxn+5],a_len;
int b[Maxn+5],b_len;
void solve(){
	scanf("%d",&n);
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
		vis_a[i]=0,vis_b[i]=0;
		in_q[i]=0;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	scanf("%d",&a_len);
	for(int i=1;i<=a_len;i++){
		scanf("%d",&a[i]);
		vis_a[a[i]]=1;
	}
	scanf("%d",&b_len);
	for(int i=1;i<=b_len;i++){
		scanf("%d",&b[i]);
		vis_b[b[i]]=1;
	}
	printf("B %d\n",b[1]);
	fflush(stdout);
	int a_id;
	scanf("%d",&a_id);
	if(vis_a[a_id]){
		printf("C %d\n",a_id);
		fflush(stdout);
		return;
	}
	static int qu[Maxn+5],qu_f,qu_t;
	qu_f=1,qu_t=0;
	qu[++qu_t]=a_id;
	in_q[a_id]=1;
	int ans_u;
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		if(vis_a[u]){
			ans_u=u;
			break;
		}
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(in_q[v]){
				continue;
			}
			qu[++qu_t]=v;
			in_q[v]=1;
		}
	}
	printf("A %d\n",ans_u);
	fflush(stdout);
	int b_id;
	scanf("%d",&b_id);
	if(vis_b[b_id]){
		printf("C %d\n",ans_u);
	}
	else{
		puts("C -1");
	}
	fflush(stdout);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}