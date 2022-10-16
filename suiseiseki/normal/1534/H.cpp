#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>
const int Maxn=100000;
int query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int f[Maxn+5],g[Maxn+5];
std::vector<int> son_lis[Maxn+5];
int q_pos[Maxn+5];
bool cmp_f(int u,int v){
	return f[u]>f[v];
}
void init_dfs_1(int u,int fa){
	son_lis[u].clear();
	std::vector<int> val_lis;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs_1(v,u);
		son_lis[u].push_back(v);
		val_lis.push_back(std::max(f[v],1));
	}
	std::sort(son_lis[u].begin(),son_lis[u].end(),cmp_f);
	std::sort(val_lis.begin(),val_lis.end(),std::greater<int>());
	f[u]=0;
	for(int i=0;i<(int)val_lis.size();i++){
		f[u]=std::max(f[u],val_lis[i]+i);
	}
	if(son_lis[u].empty()){
		q_pos[u]=u;
	}
	else{
		q_pos[u]=q_pos[son_lis[u].front()];
	}
}
int ans;
void init_dfs_2(int u,int fa){
	std::vector<std::pair<int,int> > val_lis;
	if(fa){
		val_lis.push_back(std::make_pair(std::max(1,g[u]),fa));
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		val_lis.push_back(std::make_pair(std::max(f[v],1),v));
	}
	std::sort(val_lis.begin(),val_lis.end(),std::greater<std::pair<int,int> >());
	static int pre[Maxn+5],suf[Maxn+5];
	int m=val_lis.size();
	pre[0]=0;
	for(int i=0;i<m;i++){
		pre[i+1]=std::max(pre[i],val_lis[i].first+i);
	}
	suf[m]=0;
	for(int i=m-1;i>=0;i--){
		suf[i]=std::max(suf[i+1],val_lis[i].first+i);
	}
	if(m>=2){
		ans=std::max(ans,suf[1]-1+val_lis[0].first);
	}
	else if(m==1){
		ans=std::max(ans,pre[m]);
	}
	for(int i=0;i<m;i++){
		if(val_lis[i].second==fa){
			continue;
		}
		int v=val_lis[i].second;
		g[v]=std::max(pre[i],suf[i+1]-1);
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs_2(v,u);
	}
}
int root;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	init_dfs_1(1,0);
	g[1]=-1;
	init_dfs_2(1,0);
	printf("%d\n",ans);
	fflush(stdout);
	scanf("%d",&root);
	init_dfs_1(root,0);
	std::vector<int> cur_lis;
	for(int i=0;i<(int)son_lis[root].size();i++){
		int u=query(q_pos[son_lis[root][i]]);
		if(u==root){
			continue;
		}
		while(1){
			bool flag=0;
			for(int j=1;j<(int)son_lis[u].size();j++){
				int to_u=son_lis[u][j];
				int to_v=query(q_pos[to_u]);
				if(to_v!=u){
					flag=1;
					u=to_v;
					break;
				}
			}
			if(!flag){
				break;
			}
		}
		cur_lis.push_back(u);
		if(cur_lis.size()==2){
			break;
		}
	}
	while(cur_lis.size()<2){
		cur_lis.push_back(root);
	}
	printf("! %d %d\n",cur_lis[0],cur_lis[1]);
	return 0;
}