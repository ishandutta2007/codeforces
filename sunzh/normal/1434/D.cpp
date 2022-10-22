#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,Q;
int idx;
int tin[500010],tout[500010];
int pos[1000010];
int dep[500010],wdep[500010];
vector<pair<PII,int> >vec[500010];
int eto[500010];
int maxn[4000010][2],minn[4000010],lm[4000010][2],rm[4000010][2],ln[4000010][2],tag[4000010];
void dfs(int x,int f){
	dep[x]=dep[f]+1;tin[x]=++idx;
	pos[idx]=x;
	for(auto v:vec[x]){
		if(v.fi.fi==f) continue ;
		wdep[v.fi.fi]=wdep[x]^v.fi.se;
		eto[v.se]=v.fi.fi;
		dfs(v.fi.fi,x);
		pos[++idx]=x;
	}
	tout[x]=idx;
}
void pushup(int p){
	minn[p]=min(minn[p<<1ll],minn[p<<1ll|1ll]);
	for(int k=0;k<2;k++){	
		maxn[p][k]=max(maxn[p<<1][k],maxn[p<<1|1][k]);
		lm[p][k]=max(max(lm[p<<1ll][k],lm[p<<1ll|1ll][k]),maxn[p<<1ll][k]-(minn[p<<1ll|1ll]<<1ll));
		rm[p][k]=max(max(rm[p<<1ll][k],rm[p<<1ll|1ll][k]),maxn[p<<1ll|1ll][k]-(minn[p<<1ll]<<1ll));
		ln[p][k]=max(ln[p<<1][k],ln[p<<1|1][k]);
	}
	for(int k=0;k<2;++k)
		for(int l=0;l<2;++l){
			ln[p][k^l]=max(ln[p][k^l],max(lm[p<<1ll][k]+maxn[p<<1ll|1ll][l],maxn[p<<1ll][k]+rm[p<<1ll|1ll][l]));
		}
}
void build(int p,int l,int r){
	if(l==r){
		int k=wdep[pos[l]];
		maxn[p][k]=minn[p]=dep[pos[l]];
		maxn[p][k^1]=ln[p][k^1]=lm[p][k^1]=rm[p][k^1]=-0x3f3f3f3f;
		ln[p][k]=0;
		lm[p][k]=rm[p][k]=-dep[pos[l]];
		return ;
	}
	int mid=l+r>>1ll;
	build(p<<1ll,l,mid);
	build(p<<1ll|1ll,mid+1ll,r);
	pushup(p);
}
void rev(int x){
	swap(maxn[x][0],maxn[x][1]);
	swap(lm[x][0],lm[x][1]);
	swap(rm[x][0],rm[x][1]);
	tag[x]^=1;
}
void pushdown(int p){
	if(tag[p]){
		rev(p<<1);
		rev(p<<1|1);
		tag[p]=0;
	}
}
void update(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R){
		rev(p);return ;
	}
	pushdown(p);
	int mid=l+r>>1ll;
	if(L<=mid) update(p<<1ll,l,mid,L,R);
	if(R>mid) update(p<<1ll|1ll,mid+1ll,r,L,R);
	pushup(p);
	return ;
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read(),w=read();
		vec[u].pb(mp(mp(v,w),i));
		vec[v].pb(mp(mp(u,w),i));
	}
	dfs(1,0);
	build(1,1,idx);
	Q=read();
	while(Q--){
		int d=read();
		update(1,1,idx,tin[eto[d]],tout[eto[d]]);
		printf("%d\n",ln[1][0]);
	}
}