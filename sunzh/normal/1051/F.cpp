#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define ep emplace_back
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n,m;
vector<PII>vec[100010],Vec[100010];
long long dep[100010];
int fa[100010],top[100010];
struct edge{
	int u,v,w;
	friend bool operator <(const edge &x,const edge &y){
		return x.w<y.w;
	}
}e[100010];
vector<int>noi;
bool itre[100010];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void kruskal(){
	int tot=0;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			++tot;
			fa[fx]=fy;
			itre[i]=1;vec[e[i].u].ep(e[i].v,e[i].w);vec[e[i].v].ep(e[i].u,e[i].w);
//			if(tot==n-1) break ;
		}else noi.pb(e[i].u),noi.pb(e[i].v );
	}
	memset(fa,0,sizeof(fa));
}
int siz[100010],son[100010];
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]<=dep[y]) return x;else return y;
}
long long dist(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
void dfs1(int x,int f){
	fa[x]=f;siz[x]=1;
	for(auto i:vec[x]){
		int v=i.fi;
		if(v==f) continue ;
		dep[v]=dep[x]+i.se;
		dfs1(v,x);
		if(siz[v]>siz[son[x]]) son[x]=v;
		siz[x]+=siz[v];
	}
}
void dfs2(int x,int topf){
	top[x]=topf;
	if(!son[x]) return ;
	else{
		dfs2(son[x],topf);
	}
	for(auto i:vec[x]){
		int v=i.fi;
		if(v==fa[x]||v==son[x]) continue ;
		dfs2(v,v);
	}
}
long long dis[50][100010];
struct Node{
	int x;long long dis;
	bool operator <(const Node &y)const{
		return dis<y.dis;
	}
};
void dijkstra(int x){
//	printf("X:%d,%d\n",x,noi[x]);
	memset(dis[x],0x3f,sizeof(dis[x]));
	priority_queue<Node>Q;
	Node s;s.x=noi[x],s.dis=0;Q.push(s);
	dis[x][noi[x]]=0;
	while(!Q.empty()){
		Node u=Q.top();Q.pop();
		if(u.dis!=dis[x][u.x]) continue ;
		for(auto i:Vec[u.x]){
			int v=i.fi;
			long long d=u.dis+i.se;
			if(d<dis[x][v]){
				dis[x][v]=d;Node V;V.x=v,V.dis=d;Q.push(V);
			}
		}
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
		Vec[e[i].u].ep(e[i].v,e[i].w);
		Vec[e[i].v].ep(e[i].u,e[i].w);
	}
	sort(e+1,e+m+1);
	kruskal();
	dfs1(1,0);dfs2(1,1);
	sort(noi.begin(),noi.end());
	auto it=unique(noi.begin(),noi.end());
	noi.erase(it,noi.end());
	for(int i=0;i<noi.size();++i) dijkstra(i);
//	printf("%d %d %d %d\n",dis[5][7],dis[5][8],dis[6][7],dis[6][8]);
	int q=read();
	while(q--){
		int u=read(),v=read();
		long long res=dist(u,v);
		for(int i=0;i<noi.size();++i) res=min(res,dis[i][u]+dis[i][v]);
		printf("%lld\n",res);
	}
}