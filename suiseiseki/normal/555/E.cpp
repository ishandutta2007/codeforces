#include <vector>
#include <cstdio>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=200000;
const int Maxm=200000;
int n,m,q;
int col[Maxn+5],col_tot;
int head[Maxn+5],arrive[Maxm<<1|5],nxt[Maxm<<1|5],tot;
bool un_able[Maxm<<1|5];
int dfn[Maxn+5],low[Maxn+5],dfn_tot;
int bel[Maxn+5];
struct Question{
	int s,t;
}qu[Maxn+5];
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
void tarjan(int u,int in_edge){
	dfn[u]=low[u]=++dfn_tot;
	for(int i=head[u];i;i=nxt[i]){
		if(((i-1)^1)+1==in_edge){
			continue;
		}
		int v=arrive[i];
		if(!dfn[v]){
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
		}
		else{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
void col_dfs(int u,int c){
	col[u]=c;
	for(int i=head[u];i;i=nxt[i]){
		if(un_able[i]){
			continue;
		}
		int v=arrive[i];
		if(col[v]){
			continue;
		}
		col_dfs(v,c);
	}
}
vector<int> g[Maxn+5];
void bel_dfs(int u,int c){
	bel[u]=c;
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i];
		if(bel[v]){
			continue;
		}
		bel_dfs(v,c);
	}
}
int sum_1[Maxn+5],sum_2[Maxn+5];
int fa[18][Maxn+5],dep[Maxn+5];
void init_dfs(int u){
	dep[u]=dep[fa[0][u]]+1;
	for(int i=1;fa[i-1][fa[i-1][u]];i++){
		fa[i][u]=fa[i-1][fa[i-1][u]];
	}
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i];
		if(v==fa[0][u]){
			continue;
		}
		fa[0][v]=u;
		init_dfs(v);
	}
}
int find_lca(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	for(int i=17;i>=0;i--){
		if(dep[fa[i][u]]>=dep[v]){
			u=fa[i][u];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=17;i>=0;i--){
		if(fa[i][u]!=fa[i][v]){
			u=fa[i][u];
			v=fa[i][v];
		}
	}
	return fa[0][u];
}
bool work_dfs(int u){
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i];
		if(v==fa[0][u]){
			continue;
		}
		if(!work_dfs(v)){
			return 0;
		}
		sum_1[u]+=sum_1[v];
		sum_2[u]+=sum_2[v];
	}
	return sum_1[u]==0||sum_2[u]==0;
}
int main(){
	read(n),read(m),read(q);
	int u,v;
	for(int i=1;i<=m;i++){
		read(u),read(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=q;i++){
		read(qu[i].s),read(qu[i].t);
	}
	for(int i=1;i<=n;i++){
		if(dfn[i]==0){
			tarjan(i,0);
		}
	}
	for(int u=1;u<=n;u++){
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(low[v]>dfn[u]){
				un_able[i]=un_able[((i-1)^1)+1]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(col[i]==0){
			col_dfs(i,++col_tot);
		}
	}
	for(int u=1;u<=n;u++){
		for(int i=head[u];i;i=nxt[i]){
			if(un_able[i]){
				int v=arrive[i];
				g[col[u]].push_back(col[v]);
			}
		}
	}
	for(int i=1;i<=col_tot;i++){
		if(bel[i]==0){
			bel_dfs(i,i);
		}
	}
	for(int i=1;i<=col_tot;i++){
		if(bel[i]==i){
			init_dfs(i);
		}
	}
	for(int i=1;i<=q;i++){
		if(col[qu[i].s]==col[qu[i].t]){
			continue;
		}
		qu[i].s=col[qu[i].s];
		qu[i].t=col[qu[i].t];
		if(bel[qu[i].s]!=bel[qu[i].t]){
			puts("No");
			return 0;
		}
		int lca=find_lca(qu[i].s,qu[i].t);
		sum_1[qu[i].s]++;
		sum_2[qu[i].t]++;
		sum_1[lca]--;
		sum_2[lca]--;
	}
	for(int i=1;i<=col_tot;i++){
		if(bel[i]==i){
			if(!work_dfs(i)){
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	return 0;
}