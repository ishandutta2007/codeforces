#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Maxn 2000
#define Inf 0x3f3f3f3f3f3f3f3fll
struct City{
	int x,y,c,k;
}a[Maxn+5];
int n;
int ab(int a){
	return a<0?-a:a;
}
int dist(int i,int j){
	return ab(a[i].x-a[j].x)+ab(a[i].y-a[j].y);
}
ll dis[Maxn+5];
int fa[Maxn+5];
bool vis[Maxn+5];
ll ans;
void prim(){
	memset(dis,0x3f,sizeof dis);
	fa[1]=0;
	dis[1]=0;
	int u;
	ll now;
	for(int k=1;k<=n;k++){
		u=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]<dis[u]){
				u=i;
			}
		}
		if(u==0){
			break;
		}
		vis[u]=1;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				continue;
			}
			now=(a[u].k+a[i].k)*1ll*dist(u,i);
			if(now<dis[i]){
				dis[i]=now;
				fa[i]=u;
			}
		}
	}
}
struct Edge{
	int u,v;
	ll w;
	friend bool operator <(Edge p,Edge q){
		return p.w>q.w;
	}
}e[Maxn+5];
bool broke[Maxn+5];
int m;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
bool bad[Maxn+5][Maxn+5];
void add_edge(int u,int v){
	arrive[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
bool in[Maxn+5];
int col[Maxn+5];
int n_u,n_v;
void dfs(int u,int c){
	col[u]=c;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(col[v]||((u==n_u&&v==n_v)||(u==n_v&&v==n_u)||bad[u][v])){
			continue;
		}
		dfs(v,c);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	int u=0,v;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].c);
		if(u==0||a[i].c<a[u].c){
			u=i;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].k);
	}
	prim();
	for(int i=2;i<=n;i++){
		e[++m].u=fa[i];
		e[m].v=i;
		e[m].w=(a[i].k+a[fa[i]].k)*1ll*dist(i,fa[i]);
		ans+=e[m].w;
		add_edge(e[m].u,e[m].v);
		add_edge(e[m].v,e[m].u);
	}
	in[u]=1;
	ans+=a[u].c;
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++){
		n_u=e[i].u;
		n_v=e[i].v;
		memset(col,0,sizeof col);
		dfs(e[i].u,1);
		dfs(e[i].v,2);
		u=0,v=0;
		for(int j=1;j<=n;j++){
			if(col[j]==1&&u!=-1){
				if(in[j]){
					u=-1;
				}
				if(u==0||a[j].c<a[u].c){
					u=j;
				}
			}
			if(col[j]==2&&v!=-1){
				if(in[j]){
					v=-1;
				}
				if(v==0||a[j].c<a[v].c){
					v=j;
				}
			}
		}
		if(u==-1&&v==-1){
			ans-=e[i].w;
		}
		else{
			if(u==-1){
				if(a[v].c<e[i].w){
					in[v]=1;
					ans-=e[i].w;
					ans+=a[v].c;
					broke[i]=1;
					bad[e[i].u][e[i].v]=bad[e[i].v][e[i].u]=1;
				}
			}
			else{
				if(a[u].c<e[i].w){
					in[u]=1;
					ans-=e[i].w;
					ans+=a[u].c;
					broke[i]=1;
					bad[e[i].u][e[i].v]=bad[e[i].v][e[i].u]=1;
				}
			}
		}
	}
	cout<<ans<<endl;
	int num=0;
	for(int i=1;i<=n;i++){
		if(in[i]){
			num++;
		}
	}
	printf("%d\n",num);
	for(int i=1;i<=n;i++){
		if(in[i]){
			printf("%d ",i);
		}
	}
	puts("");
	num=0;
	for(int i=1;i<=m;i++){
		if(!broke[i]){
			num++;
		}
	}
	printf("%d\n",num);
	for(int i=1;i<=m;i++){
		if(!broke[i]){
			printf("%d %d\n",e[i].u,e[i].v);
		}
	}
	return 0;
}