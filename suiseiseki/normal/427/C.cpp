#include <cstdio>
#include <cstring>
#define Mod 1000000007
int head[100005],arrive[300005],nxt[300005],tot;
int f_head[100005],f_arrive[300005],f_nxt[300005],f_tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
	f_arrive[++f_tot]=from;
	f_nxt[f_tot]=f_head[to];
	f_head[to]=f_tot;
}
struct Node{
	int cost;
	int k;
	int id;
}a[100005];
int min_cost[100005],number_min[100005];
bool visit[100005];
int node_list[100005];
int node_len;
void dfs_1(int x){
	visit[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		if(!visit[arrive[i]]){
			dfs_1(arrive[i]);
		}
	}
	node_list[++node_len]=x;
}
void dfs_2(int x,int k){
	visit[x]=1;
	a[x].k=k;
	if(a[x].cost<min_cost[k]){
		min_cost[k]=a[x].cost;
		number_min[k]=0;
	}
	if(a[x].cost==min_cost[k]){
		number_min[k]++;
	}
	for(int i=f_head[x];i;i=f_nxt[i]){
		if(!visit[f_arrive[i]]){
			dfs_2(f_arrive[i],k);
		}
	}
}
int main(){
	int k=0;
	int n,m;
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].cost);
		a[i].id=i;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			dfs_1(i);
		}
	}
	memset(visit,0,sizeof(visit));
	for(int i=node_len;i>0;i--){
		if(!visit[node_list[i]]){
			min_cost[k+1]=1<<30;
			dfs_2(node_list[i],++k);
		}
	}
	long long ans_1=0;
	int ans_2=1;
	for(int i=1;i<=k;i++){
		ans_1+=min_cost[i];
		ans_2=(int)(((long long)ans_2*number_min[i])%Mod);
	}
	printf("%I64d %d\n",ans_1,ans_2);
	return 0;
}