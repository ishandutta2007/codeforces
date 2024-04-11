#include <cstdio>
#include <vector>
#include <algorithm>
const int Maxn=400000;
int n,m,d;
int all;
std::vector<int> g[Maxn+5];
int dfn[Maxn+5],low[Maxn+5],dfn_tot;
int bel[Maxn+5],bel_tot;
void tarjan(int u){
	static int st[Maxn+5],st_top=0;
	static bool in_st[Maxn+5];
	dfn[u]=low[u]=++dfn_tot;
	st[++st_top]=u,in_st[u]=1;
	for(int v:g[u]){
		if(dfn[v]==0){
			tarjan(v),low[u]=std::min(low[u],low[v]);
		}
		else if(in_st[v]){
			low[u]=std::min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		bel[u]=++bel_tot;
		while(st[st_top]!=u){
			bel[st[st_top]]=bel[u];
			in_st[st[st_top]]=0;
			st_top--;
		}
		st_top--;
		in_st[u]=0;
	}
}
int get_id(int x,int y,int z){
	return ((x-1)*d+y-1)*2+z+1;
}
int get_op(int u){
	if(u&1){
		return u+1;
	}
	else{
		return u-1;
	}
}
void add_edge(int u,int v){
	// printf("Edge : %d %d %d-->%d %d-->%d\n",u,v,u,v,get_op(v),get_op(u));
	g[u].push_back(v),g[get_op(v)].push_back(get_op(u));
}
void add_node(int u){
	// printf("Node : %d %d-->%d\n",u,u,get_op(u));
	g[u].push_back(get_op(u));
}
void solve(){
	scanf("%d%d%d",&n,&m,&d);
	all=n*d*2;
	for(int i=1;i<=all;i++){
		g[i].clear();
	}
	for(int i=1;i<=n;i++){
		add_node(get_id(i,d,0));
		for(int j=1;j<=d;j++){
			if(j+1<=d){
				add_edge(get_id(i,j,1),get_id(i,j+1,1));
			}
			if(i-1>0){
				add_edge(get_id(i,j,1),get_id(i-1,j,1));
			}
		}
	}
	for(int t=1;t<=m;t++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x,v;
			scanf("%d%d",&x,&v);
			if(v==1){
				add_node(get_id(x,v,1));
			}
			else{
				add_edge(get_id(x,v,1),get_id(x,v-1,1));
			}
		}
		else if(op==2){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			for(int k=1;k<d;k++){
				int tmp=v-k-1;
				if(tmp<1){
					add_node(get_id(x,k,0)),add_node(get_id(y,k,0));
				}
				else if(tmp<=d){
					add_edge(get_id(x,k,0),get_id(y,tmp,1)),add_edge(get_id(y,k,0),get_id(x,tmp,1));
				}
			}
		}
		else{
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			for(int k=1;k<=d;k++){
				int tmp=v-k-1;
				if(tmp>=d){
					add_node(get_id(x,k,1)),add_node(get_id(y,k,1));
				}
				else if(tmp>0){
					add_edge(get_id(x,k,1),get_id(y,tmp,0)),add_edge(get_id(y,k,1),get_id(x,tmp,0));
				}
			}
		}
	}
	dfn_tot=bel_tot=0;
	for(int i=1;i<=all;i++){
		dfn[i]=low[i]=bel[i]=0;
	}
	for(int i=1;i<=all;i++){
		if(dfn[i]==0){
			tarjan(i);
		}
	}
	for(int i=1;i<=all;i+=2){
		if(bel[i]==bel[i+1]){
			puts("-1");	
			return;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++){
			if(bel[get_id(i,j,1)]<bel[get_id(i,j,0)]){
				printf("%d ",j);
				break;
			}
		}
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}