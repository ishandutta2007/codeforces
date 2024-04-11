#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=410000;
struct LCT{
	int fa[N],l[N],r[N],s[N];bool rev[N];
	inline bool top(int x){return (!fa[x])||(l[fa[x]]!=x&&r[fa[x]]!=x);}
	inline void up(int x){s[x]=s[l[x]]+s[r[x]]+1;}
	inline void down(int x){if(!rev[x])return;swap(l[x],r[x]);rev[l[x]]^=1;rev[r[x]]^=1;rev[x]=0;}
	inline void left(int x){
		int y=fa[x];int z=fa[y];
		r[y]=l[x];if(l[x])fa[l[x]]=y;
		fa[x]=z;if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;
		fa[y]=x;l[x]=y;up(y);up(x);
	}
	inline void right(int x){
		int y=fa[x];int z=fa[y];
		l[y]=r[x];if(r[x])fa[r[x]]=y;
		fa[x]=z;if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;
		fa[y]=x;r[x]=y;up(y);up(x);
	}
	int q[N];
	inline void splay(int x){
		q[q[0]=1]=x;for(int k=x;!top(k);k=fa[k])q[++q[0]]=fa[k];per(i,q[0],1)down(q[i]);
		while(!top(x)){
			int y=fa[x];int z=fa[y];
			if(top(y)){
				if(l[y]==x)right(x);else left(x);
			}
			else{
				if(r[z]==y){
					if(r[y]==x)left(y),left(x);
					else right(x),left(x);
				}
				else{
					if(l[y]==x)right(y),right(x);
					else left(x),right(x);
				}
			}
		}
		up(x);
	}
	inline int access(int x){
		int y=0;
		for(;x;y=x,x=fa[x]){
			splay(x);r[x]=y;up(x);
		}
		return y;
	}
	inline void gen(int x){access(x);splay(x);rev[x]^=1;}
	inline void cut(int x,int y){
		gen(x);access(y);splay(y);l[y]=0;fa[x]=0;up(y);
	}
	inline void link(int x,int y){
		gen(x);splay(x);fa[x]=y;
	}
	inline int findkfa(int x,int k){
		gen(1);access(x);splay(x);down(x);x=l[x];k=s[x]-k+1;
		while(1){
			down(x);
			if(s[l[x]]+1==k)return x;
			if(s[l[x]]+1<k){
				k-=s[l[x]]+1;x=r[x];
			}
			else x=l[x];
		}
	}
	inline int distance(int x,int y){
		gen(x);access(y);splay(y);return s[l[y]];
	}
}lct;
//--------------------------------------------------------------------------------------------------------------------------------//
int n,m;int st[N],ed[N];int fy[N];int tot;vector<int>p[N];int dis[N];
int fa[N],l[N],r[N],mi[N],ma[N];
void dfs(int x,int fa){
	st[x]=++tot;fy[tot]=x;if(!fa)dis[x]=0;else dis[x]=dis[x+n]=dis[fa]+1;
	rep(i,0,p[x].size()-1)dfs(p[x][i],x);
	ed[x]=++tot;fy[tot]=x+n;
}
inline void up(int x){
	mi[x]=ma[x]=dis[fy[x]];
	if(l[x]){
		mi[x]=min(mi[x],mi[l[x]]);
		ma[x]=max(ma[x],ma[l[x]]);
	}
	if(r[x]){
		mi[x]=min(mi[x],mi[r[x]]);
		ma[x]=max(ma[x],ma[r[x]]);
	}
}
int lazy[N];
inline void down(int x){
	if(lazy[x]==0)return;
	if(l[x]){
		lazy[l[x]]+=lazy[x];dis[fy[l[x]]]+=lazy[x];mi[l[x]]+=lazy[x];ma[l[x]]+=lazy[x];
	}
	if(r[x]){
		lazy[r[x]]+=lazy[x];dis[fy[r[x]]]+=lazy[x];mi[r[x]]+=lazy[x];ma[r[x]]+=lazy[x];
	}
	lazy[x]=0;
}
inline void left(int x){
	int y=fa[x];int z=fa[y];
	r[y]=l[x];if(l[x])fa[l[x]]=y;
	fa[x]=z;if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;
	fa[y]=x;l[x]=y;up(y);up(x);
}
inline void right(int x){
	int y=fa[x];int z=fa[y];
	l[y]=r[x];if(r[x])fa[r[x]]=y;
	fa[x]=z;if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;
	fa[y]=x;r[x]=y;up(y);up(x);
}
int q[N];
inline void splay(int x){
	q[q[0]=1]=x;for(int k=x;fa[k];k=fa[k])q[++q[0]]=fa[k];per(i,q[0],1)down(q[i]);
	while(fa[x]){
		int y=fa[x];int z=fa[y];
		if(!z){
			if(l[y]==x)right(x);else left(x);
		}
		else{
			if(r[z]==y){
				if(r[y]==x)left(y),left(x);
				else right(x),left(x);
			}
			else{
				if(l[y]==x)right(y),right(x);
				else left(x),right(x);
			}
		}
	}
	up(x);
}
int build(int ll,int rr,int fas){
	if(ll>rr)return 0;
	int mid=(ll+rr)>>1;
	mi[mid]=ma[mid]=dis[fy[mid]];
	l[mid]=build(ll,mid-1,mid);
	r[mid]=build(mid+1,rr,mid);
	fa[mid]=fas;up(mid);
	return mid;
}
int after(int x){
	splay(x);x=r[x];
	while(1){
		if(!l[x])return x;
		x=l[x];
	}
}
int prefix(int x){
	splay(x);x=l[x];
	while(1){
		if(!r[x])return x;
		x=r[x];
	}
}
void splay_until(int x,int md){
	q[q[0]=1]=x;for(int k=x;fa[k];k=fa[k])q[++q[0]]=fa[k];per(i,q[0],1)down(q[i]);
	while(fa[x]!=md){
		int y=fa[x];int z=fa[y];
		if(z==md){
			if(l[y]==x)right(x);else left(x);
		}
		else{
			if(r[z]==y){
				if(r[y]==x)left(y),left(x);
				else right(x),left(x);
			}
			else{
				if(l[y]==x)right(y),right(x);
				else left(x),right(x);
			}
		}
	}
	up(x);
}
void add(int ll,int rr,int v){
	ll=prefix(ll);rr=after(rr);
	assert(ll);assert(rr);
	splay(ll);
	splay_until(rr,ll);
	int rr1=l[rr];
	down(rr1);
	lazy[rr1]+=v;mi[rr1]+=v;ma[rr1]+=v;dis[fy[rr1]]+=v;
	up(rr);up(ll);
}
void merge(int x,int y){
	splay(y);while(l[y])y=l[y];splay(y);splay(x);
	l[y]=x;fa[x]=y;up(y);
}
inline void movefrom(int x,int y){
	int l1,r1;
	l1=st[x];r1=ed[x];int r11=after(r1);
	int d1,d2,d3,d4;
	splay(l1);
	d1=l[l1];fa[d1]=0;l[l1]=0;up(l1);
	splay(r11);
	d2=l[r11];fa[d2]=0;l[r11]=0;up(r11);
	splay(ed[y]);
	d3=l[ed[y]];fa[d3]=0;l[ed[y]]=0;up(ed[y]);
	d4=ed[y];
	merge(d1,d3);
	merge(d1,d2);
	merge(d1,d4);
}
int work(int k){
	splay(1);int rt=1;
	if(ma[rt]<k||mi[rt]>k)return 0;
	while(1){
		down(rt);
		if(r[rt]&&ma[r[rt]]>=k&&mi[r[rt]]<=k)rt=r[rt];
		else {
			if(dis[fy[rt]]==k)return rt;
			else {
				if(l[rt]==0)return 0;else
				rt=l[rt];
				}
		}
	}
}
void DD(int x){
	if(!x)return;
	down(x);
	DD(l[x]);DD(r[x]);
	up(x);
}
int main(){
	scanf("%d%d",&n,&m);rep(i,1,n)lct.s[i]=1;
	rep(i,1,n){
		int k;scanf("%d",&k);
		rep(j,1,k){
			int v;scanf("%d",&v);p[i].pb(v);
			lct.link(i,v);
		}
	}
	dfs(1,0);
	build(1,2*n,0);
	while(m--){
		int type;scanf("%d",&type);
		if(type==1){
			int x,y;scanf("%d%d",&x,&y);printf("%d\n",lct.distance(x,y));
		}
		else if(type==2){
			int x,h;scanf("%d%d",&x,&h);
			int fa1=lct.findkfa(x,1);
			int fah=lct.findkfa(x,h);
			lct.cut(x,fa1);lct.link(x,fah);
			movefrom(x,fah);
			splay(st[x]);splay(st[fah]);
			add(st[x],ed[x],(dis[fah]+1-dis[x]));
		}
		else{
			int k;scanf("%d",&k);int bi=fy[work(k)];if(bi>n)bi-=n;
			printf("%d\n",bi);
		}
	}
	return 0;
}