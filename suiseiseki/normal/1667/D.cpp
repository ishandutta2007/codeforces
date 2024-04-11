#include <vector>
#include <cstdio>
const int Maxn=200000;
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to,nxt[tot]=head[from],head[from]=tot;
}
int col[Maxn+5];
bool flag_ans;
void init_dfs(int u,int fa){
	int num=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs(v,u);
		if(col[v]){
			num++;
		}
		else{
			num--;
		}
	}
	if(u!=1){
		if(num>0){
			col[u]=0;
			num--;
		}
		else{
			col[u]=1;
			num++;
		}
	}
	if(num>1||num<0){
		flag_ans=0;
	}
}
void work_dfs(int u,int fa){
	std::vector<int> lis[2];
	int deg=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		deg++;
		if(v==fa){
			lis[col[u]].push_back(u);
			continue;
		}
		lis[col[v]].push_back(v);
	}
	while(deg>0){
		int v=lis[deg&1].back();
		if(v==u){
			printf("%d %d\n",u,fa);
		}
		else{
			work_dfs(v,u);
		}
		lis[deg&1].pop_back();
		deg--;
	}
}
void solve(){
	scanf("%d",&n);
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	flag_ans=1;
	init_dfs(1,0);
	if(!flag_ans){
		puts("NO");
		return;
	}
	puts("YES");
	work_dfs(1,0);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}