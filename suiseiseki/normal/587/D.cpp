#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=50000;
const int Maxm=500000;
int n,m;
int l,r;
struct Edge{
	int u,v,c,t;
	void read(){
		scanf("%d%d%d%d",&u,&v,&c,&t);
		r=std::max(r,t);
	}
}edge[Maxn+5];
int ans[Maxn+5],ans_len;
std::vector<int> g[Maxn+5],e[Maxm+5];
bool cmp(int p,int q){
	return edge[p].c<edge[q].c;
}
std::vector<int> s;
int id_tot;
void work_1(){
	int S,T;
	for(int i=0;i<(int)s.size();i++){
		int x=s[i],y=s[i]+m;
		int a=++id_tot,b=++id_tot;
		e[x].push_back(a),e[b].push_back(y);
		if(i){
			e[S].push_back(a);
			e[b].push_back(T);
			e[S].push_back(y);
			e[x].push_back(T);
		}
		S=a;
		T=b;
	}
	s.clear();
}
void work_2(){
	int S,T;
	for(int i=0;i<(int)s.size();i++){
		int x=s[i],y=s[i]+m;
		int a=++id_tot,b=++id_tot;
		e[a].push_back(x),e[y].push_back(b);
		if(i){
			e[a].push_back(S);
			e[T].push_back(b);
			e[y].push_back(S);
			e[T].push_back(x);
		}
		S=a;
		T=b;
	}
	s.clear();
}
int dfn[Maxm+5],low[Maxm+5],dfn_tot;
bool in[Maxm+5];
int st[Maxm+5],top;
int bel[Maxm+5],bel_tot;
void tarjan(int u){
	dfn[u]=low[u]=++dfn_tot;
	in[u]=1;
	st[++top]=u;
	for(int i=0;i<(int)e[u].size();i++){
		int v=e[u][i];
		if(dfn[v]==0){
			tarjan(v);
			low[u]=std::min(low[u],low[v]);
		}
		else if(in[v]){
			low[u]=std::min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		bel[u]=++bel_tot;
		in[u]=0;
		while(st[top]!=u){
			bel[st[top]]=bel[u];
			in[st[top]]=0;
			top--;
		}
		top--;
	}
}
void init(int val){
	for(int i=1;i<=m;i++){
		if(edge[i].t>val){
			e[i].pop_back();
		}
	}
}
bool check(int val){
	for(int i=1;i<=m;i++){
		if(edge[i].t>val){
			e[i].push_back(i+m);
		}
	}
	for(int i=1;i<=id_tot;i++){
		dfn[i]=0;
	}
	top=0;
	bel_tot=dfn_tot=0;
	for(int i=1;i<=id_tot;i++){
		if(dfn[i]==0){
			tarjan(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(bel[i]==bel[i+m]){
			init(val);
			return 0;
		}
	}
	init(val);
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	id_tot=(m<<1);
	for(int i=1;i<=m;i++){
		edge[i].read();
		g[edge[i].u].push_back(i);
		g[edge[i].v].push_back(i);
	}
	for(int i=1;i<=n;i++){
		std::sort(g[i].begin(),g[i].end(),cmp);
		s=g[i];
		work_1();
		for(int l=0,r=0;l<(int)g[i].size();l=r+1){
			r=l;
			while(r<(int)g[i].size()&&edge[g[i][r]].c==edge[g[i][l]].c){
				s.push_back(g[i][r]);
				r++;
			}
			r--;
			work_2();
		}
	}
	if(!check(r)){
		puts("No");
		return 0;
	}
	puts("Yes");
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	check(l);
	for(int i=1;i<=m;i++){
		if(bel[i]<bel[i+m]){
			ans[++ans_len]=i;
		}
	}
	printf("%d %d\n",l,ans_len);
	for(int i=1;i<=ans_len;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}