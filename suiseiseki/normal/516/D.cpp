#include <cstdio>
#include <algorithm>
using namespace std;
template<typename Elem>
void read(Elem &a){
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
const int Maxn=100000;
typedef long long ll;
int head[Maxn+5],arrive[Maxn<<1|5],val[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to,int value){
	arrive[++tot]=to;
	val[tot]=value;
	nxt[tot]=head[from];
	head[from]=tot;
}
int n,q;
ll f[Maxn+5];
ll dis[Maxn+5];
int root;
int id[Maxn+5];
int fa[Maxn+5],sz[Maxn+5];
bool vis[Maxn+5];
void init_dfs(int u,int fa){
	f[u]=max(f[u],dis[u]);
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		dis[v]=dis[u]+val[i];
		init_dfs(v,u);
	}
}
bool cmp(int p,int q){
	return f[p]>f[q];
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	fa[fa_y]=fa_x;
	sz[fa_x]+=sz[fa_y];
}
int main(){
	read(n);
	int u,v,w;
	for(int i=1;i<n;i++){
		read(u),read(v),read(w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dis[1]=0;
	root=1;
	init_dfs(root,0);
	for(int i=1;i<=n;i++){
		if(dis[i]>dis[root]){
			root=i;
		}
	}
	dis[root]=0;
	init_dfs(root,0);
	for(int i=1;i<=n;i++){
		if(dis[i]>dis[root]){
			root=i;
		}
	}
	dis[root]=0;
	init_dfs(root,0);
	for(int i=1;i<=n;i++){
		if(f[i]<f[root]){
			root=i;
		}
	}
	for(int i=1;i<=n;i++){
		id[i]=i;
	}
	sort(id+1,id+1+n,cmp);
	read(q);
	int ans;
	ll l;
	for(int i=1;i<=q;i++){
		ans=1;
		read(l);
		for(int j=1;j<=n;j++){
			fa[j]=j;
			sz[j]=1;
			vis[j]=0;
		}
		for(int j=1,k=1;j<=n;j++){
			while(k<j&&f[id[k]]-f[id[j]]>l){
				sz[find(id[k])]--;
				k++;
			}
			vis[id[j]]=1;
			for(int to=head[id[j]];to;to=nxt[to]){
				int v=arrive[to];
				if(!vis[v]){
					continue;
				}
				merge(id[j],v);
			}
			ans=max(ans,sz[find(id[j])]);
		}
		printf("%d\n",ans);
	}
	return 0;
}