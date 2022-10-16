#include <vector>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],val[Maxn<<1|5],tot;
void add_edge(int from,int to,int w){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	val[tot]=w;
	head[from]=tot;
}
ll dis[Maxn+5];
int sz[Maxn+5];
void init_dfs(int u,int fa){
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		dis[v]=dis[u]+val[i];
		init_dfs(v,u);
		sz[u]+=sz[v];
	}
}
ll ans_1,ans_2;
int work_dfs_1(int u,int fa){
	int num=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		num+=work_dfs_1(v,u);
	}
	ans_1-=(num/2)*dis[u]*2;
	return num%2;
}
void work_dfs_2(int u,int fa,int last){
	int mx_val=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		mx_val=std::max(mx_val,sz[v]);
	}
	if(sz[u]-mx_val>=mx_val){
		ans_2-=dis[u]*2*(last/2);
	}
	else{
		int max_num=(sz[u]-mx_val);
		if(max_num*2>=last){
			ans_2-=dis[u]*2*(last/2);
		}
		else{
			ans_2-=dis[u]*2*max_num;
			for(int i=head[u];i;i=nxt[i]){
				int v=arrive[i];
				if(v==fa||sz[v]!=mx_val){
					continue;
				}
				work_dfs_2(v,u,last-max_num*2);
			}
		}
	}
}
void solve(){
	scanf("%d",&n);
	n<<=1;
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w),add_edge(v,u,w);
	}
	init_dfs(1,0);
	ans_1=ans_2=0;
	for(int i=1;i<=n;i++){
		ans_1+=dis[i],ans_2+=dis[i];
	}
	work_dfs_1(1,0);
	work_dfs_2(1,0,n);
	printf("%lld %lld\n",ans_1,ans_2);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}