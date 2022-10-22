#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m,k,T;
int dis[100010];
struct edge{
	int u,v,w;
	bool operator <(const edge &x)const{
		return w<x.w;
	}
}e[1000010];
vector<PII>vec[100010];
int dsu[300010];
vector<int>kru[300010];
int val[300010];
int dep[300010],fa[300010][22];
int cnt;
void dij(){
	memset(dis,0x3f,sizeof(dis));
	priority_queue<PII,vector<PII>,greater<PII> >Q;
	for(int i=1;i<=k;++i) dis[i]=0,Q.push(mp(0,i));
	while(!Q.empty()){
		PII u=Q.top();Q.pop();
		if(dis[u.se]!=u.fi) continue ;
		for(auto i:vec[u.se]){
			PII v;v.fi=u.fi+i.se,v.se=i.fi;
			if(dis[v.se]>v.fi){
				dis[v.se]=v.fi;Q.push(v);
			}
		}
	}
}
int find(int x){
	return dsu[x]==x?x:dsu[x]=find(dsu[x]);
}
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=1;(1<<i-1)<=dep[x];++i) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int v:kru[x]){
		dfs(v,x);
	}
}
int logt[300010];
int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]){
		x=fa[x][logt[dep[x]-dep[y]]];
	}
	if(x==y) return x;
	for(int i=20;i>=0;--i){
		if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
} 
signed main(){
	n=read(),m=read(),k=read(),T=read();cnt=n;
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		e[i]={u,v,w};
		vec[u].pb(mp(v,w));
		vec[v].pb(mp(u,w));
	}
	dij();
	for(int i=1;i<=m;++i){
		e[i].w=dis[e[i].u]+dis[e[i].v]+e[i].w;
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;++i) dsu[i]=i;
	for(int i=1;i<=m;++i){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fx=find(u),fy=find(v);
		if(fx!=fy){
			val[++cnt]=e[i].w;
			kru[cnt].pb(fx),kru[cnt].pb(fy);
			dsu[fx]=dsu[fy]=dsu[cnt]=cnt;
		}
	}
	for(int i=2;i<=cnt;++i) logt[i]=logt[i>>1]+1;
	dfs(cnt,0);
	while(T--){
		int a=read(),b=read();
		printf("%lld\n",val[LCA(a,b)]);
	}
	return 0;
}