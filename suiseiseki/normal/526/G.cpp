#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Maxn=100000;
int n,q;
int head[Maxn+5],arrive[Maxn<<1|5],val[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to,int w){
	arrive[++tot]=to;
	val[tot]=w;
	nxt[tot]=head[from];
	head[from]=tot;
}
struct Tree{
	int mx_dis,root;
	int dis[Maxn+5],max_dis[Maxn+5],dep[Maxn+5];
	int fa[17][Maxn+5],son[Maxn+5],top[Maxn+5],len[Maxn+5];
	vector<int> v[Maxn+5];
	void init_dfs_1(int u){
		dep[u]=dep[fa[0][u]]+1;
		for(int i=1;fa[i-1][fa[i-1][u]];i++){
			fa[i][u]=fa[i-1][fa[i-1][u]];
		}
		max_dis[u]=dis[u];
		if(mx_dis==0||dis[mx_dis]<dis[u]){
			mx_dis=u;
		}
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(v==fa[0][u]){
				continue;
			}
			fa[0][v]=u;
			dis[v]=dis[u]+val[i];
			init_dfs_1(v);
			max_dis[u]=max(max_dis[u],max_dis[v]);
			if(son[u]==0||max_dis[son[u]]<max_dis[v]){
				son[u]=v;
			}
		}
	}
	void init_dfs_2(int u,int tp){
		top[u]=tp;
		v[tp].push_back(u);
		if(son[u]){
			init_dfs_2(son[u],tp);
		}
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(v==fa[0][u]||v==son[u]){
				continue;
			}
			init_dfs_2(v,v);
			len[v]=max_dis[v]-dis[u];
		}
	}
	int ans[Maxn+5];
	int col[Maxn+5],s[Maxn+5],c;
	bool cmp(int p,int q){
		return len[p]>len[q];
	}
	int init(int x){
		mx_dis=0;
		dis[x]=0;
		init_dfs_1(x);
		root=mx_dis;
		memset(dis,0,sizeof dis);
		memset(fa,0,sizeof fa);
		memset(dis,0,sizeof dis);
		memset(son,0,sizeof son);
		mx_dis=0;
		init_dfs_1(root);
		init_dfs_2(root,root);
		len[root]=max_dis[root];
		for(int i=1;i<=n;i++){
			if(top[i]==i){
				s[++c]=i;
			}
		}
		sort(s+1,s+1+c,[&](int p,int q){return len[p]>len[q];});
		for(int i=1;i<=c;i++){
			ans[i]=ans[i-1]+len[s[i]];
			for(int u=s[i];u;u=son[u]){
				col[u]=i;
			}
		}
		return root;
	}
	int find_ans(int x,int y,int *a){
		int u=x;
		for(int i=16;i>=0;i--){
			if(col[fa[i][u]]>y){
				u=fa[i][u];
			}
		}
		u=fa[0][u];
		return ans[y]+max_dis[x]-a[u];
	}
	int query(int x,int y){
		y=(y<<1)-1;
		if(y>=c){
			return ans[c];
		}
		if(col[x]<=y){
			return ans[y];
		}
		return max(find_ans(x,y-1,dis),find_ans(x,y,max_dis));
	}
}tree_1,tree_2;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	tree_2.init(tree_1.init(1));
	int ans=0;
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x=(x+ans-1)%n+1;
		y=(y+ans-1)%n+1;
		printf("%d\n",(ans=max(tree_1.query(x,y),tree_2.query(x,y))));
	}
	return 0;
}