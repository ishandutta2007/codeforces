#include <set>
#include <vector>
#include <cstdio>
#include <cassert>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
const int Maxm=200000;
const int Inf=0x7f7f7f7f;
struct Edge{
	int u,v,w;
}edge[Maxm+5];
int n,m;
ll num;
std::set<std::pair<int,int> > st;
std::vector<int> g[Maxn+5];
std::set<int> id;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],val[Maxn<<1|5],tot;
void add_edge(int from,int to,int w){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	val[tot]=w;
	head[from]=tot;
}
bool vis[Maxn+5],del_e[Maxm+5];
std::set<std::pair<std::pair<int,int>,int> > in_e;
ll ans;
void calc(int u){
	for(int i=0;i<(int)g[u].size();i++){
		in_e.insert(std::make_pair(std::make_pair(edge[g[u][i]].w,edge[g[u][i]].v==u?edge[g[u][i]].u:edge[g[u][i]].v),g[u][i]));
	}
	std::set<int>::iterator it;
	int lst=0;
	while(lst<=n&&(!id.empty())){
		it=id.lower_bound(lst);
		if(it==id.end()){
			break;
		}
		lst=(*it)+1;
		if(st.count(std::make_pair(u,*it))==0){
			int v=(*it);
			add_edge(u,v,0),add_edge(v,u,0);
			num--;
			id.erase(v);
			vis[v]=1;
			calc(v);
		}
	}
	if(u==1){
		while(!id.empty()){
			while(vis[(in_e.begin()->first).second]){
				in_e.erase(in_e.begin());
			}
			int v=(in_e.begin()->first).second,e=(in_e.begin()->second);
			ans+=edge[e].w;
			add_edge(edge[e].u,edge[e].v,edge[e].w),add_edge(edge[e].v,edge[e].u,edge[e].w);
			del_e[e]=1;
			vis[v]=1;
			id.erase(v);
			calc(v);
		}
	}
}
int dep[Maxn+5];
int dfn[Maxn+5],rnk[Maxn+5],fa[Maxn+5],fa_val[Maxn+5],dfn_tot;
int f_min[20][Maxn+5],f_max[20][Maxn+5];
int sz[Maxn+5],son[Maxn+5],top[Maxn+5];
int log_2[Maxn+5];
void init_dfs_1(int u){
	dep[u]=dep[fa[u]]+1;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		fa_val[v]=val[i];
		init_dfs_1(v);
		sz[u]+=sz[v];
		if(son[u]==0||sz[son[u]]<sz[v]){
			son[u]=v;
		}
	}
}
void init_dfs_2(int u,int tp){
	dfn[u]=++dfn_tot;
	rnk[dfn[u]]=u;
	top[u]=tp;
	if(son[u]){
		init_dfs_2(son[u],tp);
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]||v==son[u]){
			continue;
		}
		init_dfs_2(v,v);
	}
}
void init_tree(){
	init_dfs_1(1);
	init_dfs_2(1,1);
	for(int i=1;i<=n;i++){
		f_min[0][i]=fa_val[rnk[i]];
	}
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			f_min[i][j]=std::min(f_min[i-1][j],f_min[i-1][j+(1<<(i-1))]);
		}
	}
	log_2[0]=-1;
	for(int i=1;i<=n;i++){
		log_2[i]=log_2[i>>1]+1;
	}
}
int st_query_min(int l,int r){
	if(l>r){
		return Inf;
	}
	int k=log_2[r-l+1];
	return std::min(f_min[k][l],f_min[k][r-(1<<k)+1]);
}
int query_path(int u,int v){
	int ans_min=Inf;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]){
			std::swap(u,v);
		}
		ans_min=std::min(ans_min,st_query_min(dfn[top[u]],dfn[u]));
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]){
		std::swap(u,v);
	}
	ans_min=std::min(ans_min,st_query_min(dfn[u]+1,dfn[v]));
	return ans_min;
}
int main(){
	scanf("%d%d",&n,&m);
	num=(1ll*n*(n-1)>>1)-m;
	int t=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		t^=edge[i].w;
		st.insert(std::make_pair(edge[i].u,edge[i].v));
		st.insert(std::make_pair(edge[i].v,edge[i].u));
		g[edge[i].u].push_back(i);
		g[edge[i].v].push_back(i);
	}
	for(int i=2;i<=n;i++){
		id.insert(i);
	}
	vis[1]=1;
	calc(1);
	init_tree();
	if(num>0||t==0){
		printf("%lld\n",ans);
		return 0;
	}
	int val=t;
	for(int i=1;i<=m;i++){
		if(query_path(edge[i].u,edge[i].v)==0){
			val=std::min(val,edge[i].w);
		}
	}
	/*std::set<std::pair<std::pair<int,int>,int> >::iterator it=in_e.begin();
	while(it!=in_e.end()){
		int e=(it->second);
		if(edge[e].w>=t){
			ans+=t;
			break;
		}
		if(!del_e[e]&&query_path(edge[e].u,edge[e].v)==0){
			ans+=edge[e].w;
			break;
		}
		it++;
	}
	if(it==in_e.end()){
		ans+=t;
	}*/
	printf("%lld\n",ans+val);
	return 0;
}