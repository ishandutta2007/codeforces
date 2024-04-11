#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int Maxm=1500;
const int Maxv=5000;
const int Maxn=3000000;
const int Mod=998244353;
int n,m;
int fa[Maxv+5];
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int siz[Maxn+5],sz[Maxn+5];
int f[Maxv+5][Maxm+5];
vector<int> g[Maxv+5];
struct Edge{
	int u,v;
	Edge(int _u=0,int _v=0){
		u=_u;
		v=_v;
	}
}edge[Maxn+5];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void dfs(int u){
	if(u<=n){
		siz[u]=1;
		f[u][1]=1;
		return;
	}
	int tmp[Maxm+5]={0};
	f[u][0]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		dfs(v);
		for(int j=0;j<=siz[u];j++){
			tmp[j]=0;
		}
		for(int j=0;j<=siz[u];j++){
			for(int k=0;k<=siz[v];k++){
				tmp[j+k]=(tmp[j+k]+1ll*f[u][j]*f[v][k])%Mod;
			}
		}
		siz[u]+=siz[v];
		for(int j=0;j<=siz[u];j++){
			f[u][j]=tmp[j];
		}
	}
	f[u][1]++;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int a;
			scanf("%d",&a);
			edge[a].u=i;
			edge[a].v=j;
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
		g[i].push_back(i);
		siz[i]=1;
	}
	int k=n;
	for(int i=1;i<=(n*(n-1)>>1);i++){
		int a=find(edge[i].u),b=find(edge[i].v);
		if(a!=b){
			fa[a]=b;
			for(int it:g[a]){
				g[b].push_back(it);
			}
			g[a].clear();
			siz[b]+=siz[a];
			sz[b]+=sz[a];
		}
		sz[b]++;
		if(sz[b]==(siz[b]*(siz[b]-1)>>1)){
			k++;
			for(int it:g[b]){
				add_edge(k,it);
			}
			g[b].clear();
			g[b].push_back(k);
		}
	}
	memset(siz,0,sizeof siz);
	dfs(k);
	for(int i=1;i<=n;i++){
		printf("%d ",f[k][i]);
	}
	puts("");
	return 0;
}