#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
struct edge{
	int u,v;
}e[200010];
vector<int>vec[200010];
int fa[200010];
vector<int>tre[200010];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int ans=0;
bool ok[200010],hengcha[200010];
int Ans[200010];
int dfn[200010],siz[200010],idx;
int Fa[200010][18];
int dep[200010];
void dfs1(int x,int f){
	dfn[x]=++idx;siz[x]=1;
	Fa[x][0]=f;
	for(int i=1;i<18;++i) Fa[x][i]=Fa[Fa[x][i-1]][i-1];
	for(int v:tre[x]) if(v!=f){
		dep[v]=dep[x]+1;
		dfs1(v,x);siz[x]+=siz[v];
	}
}
int jump(int x,int tar){
	for(int j=17;j>=0;--j) if(dep[Fa[x][j]]>=tar) x=Fa[x][j];
	return x;
}
int getnx(int U,int v){
	if(dfn[v]>=dfn[U]&&dfn[v]<=dfn[U]+siz[U]-1){
		return jump(v,dep[U]+1);
	}
	else return Fa[U][0];
}
void movert(int fr,int nx){
	for(int i:vec[fr]){
		ans-=(hengcha[i]&&!ok[i]);
		int a1=getnx(nx,e[i].u),a2=getnx(nx,e[i].v);
		if(a1!=a2) hengcha[i]=1;else hengcha[i]=0;
		ans+=(hengcha[i]&&!ok[i]);
	}
	for(int i:vec[nx]){
		ans-=(hengcha[i]&&!ok[i]);
		hengcha[i]=0;
		ans+=(hengcha[i]&&!ok[i]);
	}
}
void dfs2(int x,int f){
	if(!ans) Ans[x]=1;
	// printf("x:%d\n",x);
	// for(int i=1;i<=m;++i) printf("%d %d\n",hengcha[i],ok[i]);
	for(int v:tre[x]) if(v!=f){
		movert(x,v);
		dfs2(v,x);
		movert(v,x);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i) e[i].u=read(),e[i].v=read(),vec[e[i].u].pb(i),vec[e[i].v].pb(i);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			tre[e[i].u].pb(e[i].v);tre[e[i].v].pb(e[i].u);
			ok[i]=1;
		}
	}
	dfs1(1,0);
	for(int i=1;i<=m;++i){
		if(e[i].u==1||e[i].v==1) continue ;
		if(dfn[e[i].u]>dfn[e[i].v]) swap(e[i].u,e[i].v);
		if(dfn[e[i].v]<=dfn[e[i].u]+siz[e[i].u]-1) hengcha[i]=0;else hengcha[i]=1;
		ans+=(hengcha[i]&&!ok[i]);
	}
	dfs2(1,0);
	for(int i=1;i<=n;++i) printf("%d",Ans[i]);printf("\n");
}