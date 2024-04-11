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
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int DEP;
int dep[200010];
int son[200010],siz[200010];
int fa[200010][22];
int top[200010],tail[200010];
vector<int>vec[200010];
void dfs1(int x,int f){
	fa[x][0]=f;
	for(int i=1;i<=19;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
	siz[x]=1;dep[x]=dep[f]+1;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs1(v,x);siz[x]+=siz[v];
		if(siz[v]>siz[son[x]]) son[x]=v;
	}
}
void dfs2(int x,int topf){
	top[x]=topf,tail[topf]=x;
	if(son[x]){
		dfs2(son[x],topf);
	}
	else return ;
	for(int v:vec[x]){
		if(v==fa[x][0]) continue ;
		if(v==son[x]) continue ;
		dfs2(v,v);
	}
}
int findfa(int x,int d){
	for(int i=18;i>=0;--i){
		if(dep[fa[x][i]]>=d) x=fa[x][i];
	}
	return x;
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();vec[u].pb(v),vec[v].pb(u);
	}dep[0]=-1;
	dfs1(1,0);
	dfs2(1,1);
	printf("d 1\n");fflush(stdout);
	DEP=read();
	int tp=1;
	while(1){
		printf("d %d\n",tail[tp]);fflush(stdout);
		int x=read();
		int d=DEP+dep[tail[tp]]-x;d>>=1;
		int lca=findfa(tail[tp],d);
		if(d==DEP){
			printf("! %d\n",lca);return 0;
		}
		printf("s %d\n",lca);fflush(stdout);
		tp=read();
		if(dep[tp]==DEP){
			printf("! %d\n",tp);return 0;
		}
	}
	return 0;
}