#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n,q;
int a[Maxn+5],dep[Maxn+5];
struct Question{
	int u,k;
}qu[Maxn+5];
int ans[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
std::vector<int> q_lis[Maxn+5];
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
void init_dfs(int u,int fa){
	a[u]=-1;
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs(v,u);
		a[u]++;
	}
}
std::vector<int> f[Maxn+5];
void work_dfs(int u,int fa){
	if(a[u]<0){
		return;
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		work_dfs(v,u);
		if(f[u].size()<f[v].size()){
			std::swap(f[u],f[v]);
		}
		for(int j=0;j<(int)f[v].size();j++){
			f[u][j]+=f[v][j];
		}
	}
	for(int i:q_lis[u]){
		if(qu[i].k<(int)f[u].size()){
			ans[i]=f[u][qu[i].k];
		}
	}
	if((int)f[u].size()<a[u]){
		f[u].resize(a[u]);
	}
	for(int i=0;i<(int)f[u].size();i++){
		f[u][i]+=a[u]-i;
	}
	while(!f[u].empty()&&f[u].back()<0){
		f[u].pop_back();
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	init_dfs(1,0);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qu[i].u,&qu[i].k);
		q_lis[qu[i].u].push_back(i);
	}
	work_dfs(1,0);
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i]+a[qu[i].u]+1);
	}
	return 0;
}