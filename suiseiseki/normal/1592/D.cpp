#include <queue>
#include <vector>
#include <cstdio>
#include <cassert>
#include <numeric>
#include <algorithm>
const int Maxn=1000;
int query(const std::vector<int> &lis){
	printf("? %d ",(int)lis.size());
	for(int i=0;i<(int)lis.size();i++){
		printf("%d%c",lis[i]," \n"[i==(int)lis.size()-1]);
	}
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int n;
struct Edge{
	int u,v;
	friend bool operator <(Edge a,Edge b){
		if(a.u==b.u){
			return a.v<b.v;
		}
		return a.u<b.u;
	}
	friend bool operator ==(Edge a,Edge b){
		return a.u==b.u&&a.v==b.v;
	}
	Edge(int _u=0,int _v=0){
		u=_u,v=_v;
	}
};
std::vector<Edge> e_lis;
int deg[Maxn+5];
std::vector<int> g[Maxn+5];
void build_graph(){
	for(int i=1;i<=n;i++){
		g[i].clear();
		deg[i]=0;
	}
	for(Edge e:e_lis){
		g[e.u].push_back(e.v);
		g[e.v].push_back(e.u);
		deg[e.u]++,deg[e.v]++;
	}
}
bool vis[Maxn+5];
void work_dfs(int u,int &m,std::vector<Edge> &ans){
	if(m==0||vis[u]){
		return;
	}
	vis[u]=1;
	for(int v:g[u]){
		if(vis[v]){
			continue;
		}
		ans.push_back(u<v?Edge(u,v):Edge(v,u));
		m--;
		work_dfs(v,m,ans);
		if(m==0){
			break;
		}
	}
}
std::vector<Edge> get_edge_size(int &m){
	int tmp_m=m;
	std::vector<Edge> ans_lis;
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&deg[i]>0){
			work_dfs(i,m,ans_lis);
		}
	}
	assert((int)ans_lis.size()==tmp_m);
	return ans_lis;
}
std::vector<int> get_node_lis(const std::vector<Edge>& val){
	static bool vis[Maxn+5];
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	for(Edge e:val){
		vis[e.u]=vis[e.v]=1;
	}
	std::vector<int> node_lis;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			node_lis.push_back(i);
		}
	}
	return node_lis;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u>v){
			std::swap(u,v);
		}
		e_lis.push_back(Edge(u,v));
	}
	std::sort(e_lis.begin(),e_lis.end());
	int ans_val;
	std::vector<int> node_lis;
	node_lis.resize(n);
	std::iota(node_lis.begin(),node_lis.end(),1);
	ans_val=query(node_lis);
	while((int)e_lis.size()>1){
		int m=(int)e_lis.size()>>1;
		build_graph();
		std::vector<Edge> cur_lis=get_edge_size(m);
		if(query(get_node_lis(cur_lis))==ans_val){
			e_lis=cur_lis;
		}
		else{
			for(Edge &e:e_lis){
				if(e.u>e.v){
					std::swap(e.u,e.v);
				}
			}
			for(Edge &e:cur_lis){
				if(e.u>e.v){
					std::swap(e.u,e.v);
				}
			}
			std::sort(e_lis.begin(),e_lis.end());
			std::sort(cur_lis.begin(),cur_lis.end());
			std::vector<Edge> nxt_lis;
			int pos_j=0;
			for(Edge e:e_lis){
				if(pos_j<(int)cur_lis.size()&&e==cur_lis[pos_j]){
					pos_j++;
				}
				else{
					nxt_lis.push_back(e);
				}
			}
			assert(nxt_lis.size()==e_lis.size()-cur_lis.size());
			e_lis=nxt_lis;
		}
	}
	printf("! %d %d\n",e_lis.front().u,e_lis.front().v);
	return 0;
}