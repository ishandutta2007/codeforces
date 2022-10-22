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
int fa[300010];
int f[300010][19];
int idx;
int dep[300010],dfn[300010],siz[300010];
int logt[300010];
vector<int>vec[300010];
void dfs(int x){
	dfn[x]=++idx;f[x][0]=fa[x];siz[x]=1;
	for(int i=1;i<=18;++i) f[x][i]=f[f[x][i-1]][i-1];
	for(int v:vec[x]){
		dep[v]=dep[x]+1;dfs(v);siz[x]+=siz[v];
	}
}
int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]){
		x=f[x][logt[dep[x]-dep[y]]];
	}
	for(int i=18;i>=0;--i) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return x==y?x:f[x][0];
}
int getf(int x,int k){
	for(int i=18;i>=0;--i){
		if(dep[f[x][i]]>=k) x=f[x][i];
	}
	return x;
}
struct node{
	int x,y;
	bool operator <(const node &p)const{
		return mp(dep[x],x)==mp(dep[p.x],p.x)?mp(dep[y],y)>mp(dep[p.y],p.y):mp(dep[x],x)>mp(dep[p.x],p.x);
	}
};
set<node>st;
PII oth[300010];
int cnt;
int tre[300010];
void update(int x,int k){
	while(x<=n){
		tre[x]+=k;x+=x&-x;
	}
}
int qry(int x){
	int res=0;
	while(x){
		res+=tre[x];x-=x&-x;
	}
	return res;
}
int query(int l,int r){
	return qry(r)-qry(l-1);
}
int main(){
	n=read(),m=read();
	for(int i=2;i<=n;++i) logt[i]=logt[i>>1]+1;
	for(int i=2;i<=n;++i) fa[i]=read(),vec[fa[i]].pb(i);
	dfs(1);
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		int lca=LCA(x,y);
		// printf("lca:%d\n",lca);
		if(lca!=x&&lca!=y){
			oth[++cnt]=mp(x,y);
		}
		else{
			if(lca==y) swap(x,y);
			st.insert(node{x,y});
		}
	}
	int ans=0;
	for(node i:st){
		int P=getf(i.y,dep[i.x]+1);
		// printf("%d %d\n",i.x,i.y);
		if(P==i.y){
			puts("-1");return 0;
		}
		int res=query(dfn[P],dfn[P]+siz[P]-1)-query(dfn[i.y],dfn[i.y]+siz[i.y]-1);
		if(!res){
			++ans;update(dfn[P],1);
		}
		// if(!check(i.x,i.y)){
		// 	++ans;ins(getf(i.y,dep[i.x]+1));
		// }
	}
	for(int i=1;i<=cnt;++i){
		int lca=LCA(oth[i].fi,oth[i].se);
		int res=ans-query(dfn[oth[i].fi],dfn[oth[i].fi]+siz[oth[i].fi]-1)-query(dfn[oth[i].se],dfn[oth[i].se]+siz[oth[i].se]-1);
		if(!res){
			++ans;break ;
		}
	}
	printf("%d\n",ans);
}