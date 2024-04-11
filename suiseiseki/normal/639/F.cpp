#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
const int Maxn=300000;
const int Maxm=600000;
int n,m,q;
struct Graph{
	int head[Maxn+5],arrive[Maxm<<1|5],nxt[Maxm<<1|5],tot;
	void unuse_add_edge(int from,int to){
		arrive[++tot]=to;
		nxt[tot]=head[from];
		head[from]=tot;
	}
	void add_edge(int from,int to){
		unuse_add_edge(from,to);
		unuse_add_edge(to,from);
	}
	bool un_able[Maxm<<1|5];
	int find_next_edge(int x){
		return ((x-1)^1)+1;
	}
	int dfn[Maxn+5],low[Maxn+5],dfn_tot;
	std::vector<int> bridge,bel_edge[Maxn+5];
	void tarjan(int u,int lst){
		dfn[u]=low[u]=++dfn_tot;
		for(int i=head[u];i;i=nxt[i]){
			if(find_next_edge(i)==lst){
				continue;
			}
			int v=arrive[i];
			if(dfn[v]==0){
				tarjan(v,i);
				low[u]=std::min(low[u],low[v]);
				if(low[v]>dfn[u]){
					un_able[i]=un_able[find_next_edge(i)]=1;
					bridge.push_back(i);
				}
			}
			else{
				low[u]=std::min(low[u],dfn[v]);
			}
		}
	}
	int bel[Maxn+5],bel_tot;
	void bel_dfs(int u){
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(bel[v]||un_able[i]){
				continue;
			}
			bel[v]=bel[u];
			bel_dfs(v);
		}
	}
	void init_dfn(){
		for(int i=1;i<=n;i++){
			if(dfn[i]==0){
				tarjan(i,0);
			}
		}
	}
	void edge_cc(){
		init_dfn();
		for(int i=1;i<=n;i++){
			if(bel[i]==0){
				bel[i]=++bel_tot;
				bel_dfs(i);
			}
		}
	}
	void init_dfn(const std::vector<int> &lis){
		for(int i=0;i<(int)lis.size();i++){
			if(dfn[lis[i]]==0){
				tarjan(lis[i],0);
			}
		}
	}
	void edge_cc(const std::vector<int> &lis){
		init_dfn(lis);
		for(int i=0;i<(int)lis.size();i++){
			if(bel[lis[i]]==0){
				bel[lis[i]]=++bel_tot;
				bel_dfs(lis[i]);
			}
		}
	}
	void work(){
		edge_cc();
		for(int i=1;i<=tot;i++){
			if(un_able[i]){
				bel_edge[bel[arrive[i]]].push_back(bel[arrive[find_next_edge(i)]]);
			}
		}
	}
	void clear(const std::vector<int> &lis){
		bel_tot=dfn_tot=0;
		tot=0;
		for(int i=0;i<(int)lis.size();i++){
			dfn[lis[i]]=low[lis[i]]=bel[lis[i]]=head[lis[i]]=0;
		}
		for(int i=0;i<(int)bridge.size();i++){
			un_able[bridge[i]]=un_able[find_next_edge(bridge[i])]=0;
		}
		bridge.clear();
	}
}main_g,query_g;
int dfn[Maxn+5],dfn_tot;
int root[Maxn+5];
int fa[20][Maxn+5],dep[Maxn+5];
void fa_dfs(int u){
	dep[u]=dep[fa[0][u]]+1;
	dfn[u]=++dfn_tot;
	for(int i=1;fa[i-1][fa[i-1][u]];i++){
		fa[i][u]=fa[i-1][fa[i-1][u]];
	}
	for(int i=0;i<(int)main_g.bel_edge[u].size();i++){
		int v=main_g.bel_edge[u][i];
		if(v==fa[0][u]){
			continue;
		}
		root[v]=root[u];
		fa[0][v]=u;
		fa_dfs(v);
	}
}
int find_lca(int u,int v){
	if(dep[u]<dep[v]){
		std::swap(u,v);
	}
	for(int i=19;i>=0;i--){
		if(dep[fa[i][u]]>=dep[v]){
			u=fa[i][u];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=19;i>=0;i--){
		if(fa[i][u]!=fa[i][v]){
			u=fa[i][u];
			v=fa[i][v];
		}
	}
	return fa[0][u];
}
bool cmp_dfn(int u,int v){
	return dfn[u]<dfn[v];
}
void build_tree(std::vector<int>& lis){
	static int st[Maxn+5],top;
	std::sort(lis.begin(),lis.end(),cmp_dfn);
	top=0;
	st[0]=0;
	int last=0;
	std::vector<int> tmp=lis;
	for(int i=0;i<(int)lis.size();i++){
		if(top>0&&root[lis[i]]!=last){
			while(--top){
				query_g.add_edge(st[top],st[top+1]);
			}
		}
		int lca=find_lca(st[top],lis[i]);
		if(lca!=st[top]){
			while(top&&dep[st[top-1]]>=dep[lca]){
				query_g.add_edge(st[top],st[top-1]);
				top--;
			}
			if(st[top]!=lca){
				query_g.add_edge(st[top],lca);
				st[top]=lca;
				tmp.push_back(lca);
			}
		}
		st[++top]=lis[i];
		last=root[lis[i]];
	}
	if(top>0){
		while(--top){
			query_g.add_edge(st[top],st[top+1]);
		}
	}
	lis=tmp;
}
void rotate_node(int &x,int ans){
	x=(x+ans>n?x+ans-n:x+ans);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		main_g.add_edge(u,v);
	}
	main_g.work();
	for(int i=1;i<=main_g.bel_tot;i++){
		if(root[i]==0){
			root[i]=i;
			fa_dfs(i);
		}
	}
	int all_ans=0;
	for(int t=1;t<=q;t++){
		int t_n,t_m;
		scanf("%d%d",&t_n,&t_m);
		std::vector<int> v_node,v_lis;
		for(int i=1;i<=t_n;i++){
			int x;
			scanf("%d",&x);
			rotate_node(x,all_ans);
			x=main_g.bel[x];
			v_node.push_back(x);
			v_lis.push_back(x);
		}
		std::vector<std::pair<int,int> > v_edge;
		for(int i=1;i<=t_m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			rotate_node(u,all_ans),rotate_node(v,all_ans);
			u=main_g.bel[u],v=main_g.bel[v];
			if(u==v){
				continue;
			}
			v_edge.push_back(std::make_pair(u,v));
			v_lis.push_back(u),v_lis.push_back(v);
		}
		std::sort(v_lis.begin(),v_lis.end());
		v_lis.erase(std::unique(v_lis.begin(),v_lis.end()),v_lis.end());
		build_tree(v_lis);
		for(int i=0;i<(int)v_edge.size();i++){
			query_g.add_edge(v_edge[i].first,v_edge[i].second);
		}
		query_g.edge_cc(v_lis);
		bool flag=1;
		for(int i=1;i<(int)v_node.size();i++){
			if(query_g.bel[v_node[i]]!=query_g.bel[v_node[0]]){
				flag=0;
				break;
			}
		}
		if(flag){
			all_ans=(all_ans+t)%n;
			puts("YES");
		}
		else{
			puts("NO");
		}
		query_g.clear(v_lis);
	}
	return 0;
}