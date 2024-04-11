#include <vector>
#include <cstdio>
#include <algorithm>
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
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int n,m;
int sum[Maxn+5];
int fa[Maxn+5];
int dep[Maxn+5];
void init_dfs(int u){
	dep[u]=dep[fa[u]]+1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		if(dep[v]==0){
			fa[v]=u;
			init_dfs(v);
			sum[u]+=sum[v];
		}
		else if(dep[v]<dep[u]){
			sum[u]++;
			sum[v]--;
		}
	}
}
int start,bottom;
struct Edge{
	int u,v;
}edge[5];
int len;
void work_dfs(int u){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		if(dep[v]==dep[u]+1){
			work_dfs(v);
		}
		else if(dep[v]<dep[start]){
			edge[++len].u=u;
			edge[len].v=v;
		}
		if(len>=2){
			break;
		}
	}
}
vector<int> ans[3];
void calc_path(int u,int v,vector<int>& ans){
	static vector<int> path;
	path.clear();
	bool flag=0;
	if(dep[u]<dep[v]){
		swap(u,v);
		flag=1;
	}
	while(u!=v){
		path.push_back(u);
		u=fa[u];
	}
	path.push_back(v);
	if(flag){
		reverse(path.begin(),path.end());
	}
	for(int i=0;i<(int)path.size();i++){
		ans.push_back(path[i]);
	}
}
int main(){
	read(n),read(m);
	for(int i=1;i<=m;i++){
		int u,v;
		read(u),read(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		if(fa[i]==0){
			init_dfs(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(sum[i]>1&&(start==0||dep[i]<dep[start])){
			start=i;
		}
	}
	if(start==0){
		puts("NO");
		return 0;
	}
	work_dfs(start);
	start=fa[start];
	int u=edge[1].u,v=edge[2].u;
	while(u!=v){
		if(dep[u]>dep[v]){
			u=fa[u];
		}
		else{
			v=fa[v];
		}
	}
	bottom=u;
	calc_path(start,bottom,ans[0]);
	calc_path(start,edge[1].v,ans[1]);
	calc_path(edge[1].u,bottom,ans[1]);
	calc_path(start,edge[2].v,ans[2]);
	calc_path(edge[2].u,bottom,ans[2]);
	puts("YES");
	for(int i=0;i<3;i++){
		printf("%u ",ans[i].size());
		for(int j=0;j<(int)ans[i].size();j++){
			printf("%d ",ans[i][j]);
		}
		puts("");
	}
	return 0;
}