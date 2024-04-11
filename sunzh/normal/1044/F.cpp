#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<map>
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
int dfn[200010],siz[200010];
int idx;
int n,q;
vector<int>vec[200010];
map<int,int>Map[200010];
int dep[200010],fa[22][200010];
void dfs(int x,int f){
	dfn[x]=++idx;siz[x]=1;dep[x]=dep[f]+1;
	fa[0][x]=f;
	for(int i=1;i<=18;++i) fa[i][x]=fa[i-1][fa[i-1][x]];
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs(v,x);siz[x]+=siz[v];
	}
}
int getfa(int x,int d){
	for(int i=18;i>=0;--i){
		if(dep[fa[i][x]]>=d) x=fa[i][x];
	}
	return x;
}

int s[800010],tag[800010];
void pushup(int p,int l,int r){
	if(tag[p]>0) s[p]=r-l+1;
	else if(l==r) s[p]=0;
	else s[p]=s[p<<1]+s[p<<1|1]; 
}
void update(int p,int l,int r,int L,int R,int k){
	if(L>R) return ;
	if(l>=L&&r<=R){
		tag[p]+=k;
		pushup(p,l,r);
		return ;
	}
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p,l,r);
}
int main(){
	n=read(),q=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();vec[u].pb(v),vec[v].pb(u);
	}
	dfs(1,0);
	while(q--){
		int u=read(),v=read();
		if(u==v) goto p;
		if(u>v) swap(u,v);
		if(Map[u][v]){
			Map[u][v]=0;
			if(dfn[u]>dfn[v]) swap(u,v);
			if(dfn[v]<dfn[u]+siz[u]){
				int x=getfa(v,dep[u]+1);
				update(1,1,n,dfn[x],dfn[v]-1,-1);
				update(1,1,n,dfn[v]+siz[v],dfn[x]+siz[x]-1,-1);
			}
			else{
				update(1,1,n,1,dfn[u]-1,-1);
				update(1,1,n,dfn[u]+siz[u],dfn[v]-1,-1);
				update(1,1,n,dfn[v]+siz[v],n,-1);
			}
		}
		else{
			Map[u][v]=1;
			if(dfn[u]>dfn[v]) swap(u,v);
			if(dfn[v]<dfn[u]+siz[u]){
				int x=getfa(v,dep[u]+1);
				update(1,1,n,dfn[x],dfn[v]-1,1);
				update(1,1,n,dfn[v]+siz[v],dfn[x]+siz[x]-1,1);
			}
			else{
				update(1,1,n,1,dfn[u]-1,1);
				update(1,1,n,dfn[u]+siz[u],dfn[v]-1,1);
				update(1,1,n,dfn[v]+siz[v],n,1);
			}
		}
		p: printf("%d\n",n-s[1]);
	}
	return 0;
}