#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n,q,wmax,tot;
int dep[100010];
int head[100010],nxt[200010],to[200010],w[200010];
int tin[100010],tout[100010];
int pos[200010],idx,eto[100010],val[100010];
int maxn[800010],minn[800010],lm[800010],rm[800010],ln[800010],tag[800010];
void dfs(int x,int fa){
	pos[++idx]=x;tin[x]=idx;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue ;
		eto[(i+1ll)>>1ll]=v;
		val[(i+1ll)>>1ll]=w[i];
		dep[v]=dep[x]+w[i];
		dfs(v,x);
		pos[++idx]=x;
	}
	tout[x]=idx;
}
void pushup(int p){
	maxn[p]=max(maxn[p<<1ll],maxn[p<<1ll|1ll]);
	minn[p]=min(minn[p<<1ll],minn[p<<1ll|1ll]);
	lm[p]=max(max(lm[p<<1ll],lm[p<<1ll|1ll]),maxn[p<<1ll]-(minn[p<<1ll|1ll]<<1ll));
	rm[p]=max(max(rm[p<<1ll],rm[p<<1ll|1ll]),maxn[p<<1ll|1ll]-(minn[p<<1ll]<<1ll));
	ln[p]=max(max(ln[p<<1ll],ln[p<<1ll|1ll]),max(lm[p<<1ll]+maxn[p<<1ll|1ll],maxn[p<<1ll]+rm[p<<1ll|1ll]));
}
void pushdown(int p){
	if(tag[p]){
		maxn[p<<1ll]+=tag[p];maxn[p<<1ll|1ll]+=tag[p];minn[p<<1ll]+=tag[p];minn[p<<1ll|1ll]+=tag[p];
		tag[p<<1ll]+=tag[p];tag[p<<1ll|1ll]+=tag[p];
		lm[p<<1]-=tag[p];rm[p<<1]-=tag[p];
		lm[p<<1|1]-=tag[p];rm[p<<1|1]-=tag[p];
		tag[p]=0;
	}
}
int query(){
	return ln[1ll];
}
void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		maxn[p]+=k;minn[p]+=k;tag[p]+=k;lm[p]-=k,rm[p]-=k;return ;
	}
	pushdown(p);
	int mid=l+r>>1ll;
	if(L<=mid) update(p<<1ll,l,mid,L,R,k);
	if(R>mid) update(p<<1ll|1ll,mid+1ll,r,L,R,k);
	pushup(p);
	return ;
}
void build(int p,int l,int r){
	if(l==r){
		maxn[p]=minn[p]=dep[pos[l]];ln[p]=0;lm[p]=rm[p]=-dep[pos[l]];
		return ;
	}
	int mid=l+r>>1ll;
	build(p<<1ll,l,mid);
	build(p<<1ll|1ll,mid+1ll,r);
	pushup(p);
}
void add(int x,int y,int z){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z;
}
signed main(){
	n=read(),q=read(),wmax=read();
	for(int i=1ll;i<n;++i){
		int a=read(),b=read(),c=read();
		add(a,b,c),add(b,a,c);
	}
	dfs(1ll,0);
	build(1ll,1ll,idx);
	int last=0;
	while(q--){
		int d=read(),e=read();
		d=(d+last)%(n-1ll)+1ll;e=(e+last)%wmax;
		update(1ll,1ll,idx,tin[eto[d]],tout[eto[d]],e-val[d]);
		val[d]=e;
		printf("%lld\n",last=query());
	}
	return 0;
}