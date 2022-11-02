#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define g() getchar()
template<class Q>inline void Scan(Q&x){
	char c; int f=1;
	while(c=g(),c<48||c>57)if(c=='-')f=-1;
	for(x=0;c>47&&c<58;c=g())x=10*x+c-48;
	x*=f;
}

const int MAXN=100005;
const int Mod=1e9+7;

#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define lch lc(x),l,mid
#define rch rc(x),mid+1,r
#define add(x) pool[x].add
#define sum(x) pool[x].sum
#define sum2(x) pool[x].sum2
struct node{
	int sum,sum2,add;
}pool[MAXN<<2];

int w[MAXN];

inline void update(int x){
	sum(x)=(sum(lc(x))+sum(rc(x)))%Mod;
	sum2(x)=(sum2(lc(x))+sum2(rc(x)))%Mod;
}

inline void AddIt(int x,int a,int sz){
	sum2(x)=(sum2(x)+2ll*a%Mod*sum(x)%Mod)%Mod;
	sum2(x)=(sum2(x)+1ll*a*a%Mod*sz%Mod)%Mod;
	sum(x)=(sum(x)+1ll*a*sz%Mod)%Mod;
	add(x)=(add(x)+a)%Mod;
}

inline void down(int x,int l,int r){
	if(!add(x))return;
	int mid=(l+r)>>1;
	AddIt(lc(x),add(x),mid-l+1);
	AddIt(rc(x),add(x),r-mid);
	add(x)=0;
}

void build(int x,int l,int r){
	if(l==r){
		sum(x)=w[l];
		sum2(x)=1ll*w[l]*w[l]%Mod;
		return;
	}
	int mid=(l+r)>>1;
	build(lch),build(rch);
	update(x);
}

void modify(int x,int l,int r,int ll,int rr,int a){
	if(ll>rr)return;
	if(ll<=l&&r<=rr)return AddIt(x,a,r-l+1);
	int mid=(l+r)>>1;
	down(x,l,r);
	if(ll<=mid)modify(lch,ll,rr,a);
	if(rr>mid) modify(rch,ll,rr,a);
	update(x);
}

int query(int x,int l,int r,int ll,int rr){
	if(l==ll&&r==rr)return sum2(x);
	int mid=(l+r)>>1;
	down(x,l,r);
	if(rr<=mid)return query(lch,ll,rr);
	if(ll>mid) return query(rch,ll,rr);
	int t1=query(lch,ll,mid);
	int t2=query(rch,mid+1,rr);
	return (t1+t2)%Mod;
}

struct edge{
	int t,d,n;
	edge(int t=0,int d=0,int n=0):
		t(t),d(d),n(n){}
}e[MAXN<<1];
int head[MAXN],tot;
inline void AddEdge(int s,int t,int d){
	e[++tot]=edge(t,d,head[s]),head[s]=tot;
	e[++tot]=edge(s,d,head[t]),head[t]=tot;
}

int dis[MAXN];

int l[MAXN],r[MAXN],cnt;

void prev(int x,int p){
	l[x]=++cnt;
	w[cnt]=dis[x];
	for(int i=head[x],y;i;i=e[i].n)
		if((y=e[i].t)!=p){
			dis[y]=(dis[x]+e[i].d)%Mod;
			prev(y,x);
		}
	r[x]=cnt;
}

struct qy{
	int x,id,n;
	qy(int x=0,int id=0,int n=0):
		x(x),id(id),n(n){}
}q[MAXN];
int qhd[MAXN],qtot;
inline void AddQuery(int x,int y,int id){
	q[++qtot]=qy(y,id,qhd[x]),qhd[x]=qtot;
}

int n,m,ans[MAXN];

void dfs(int x,int p){
	int Sum=sum2(1);
	for(int i=qhd[x],y,Id;i;i=q[i].n){
		y=q[i].x,Id=q[i].id;
		int res=query(1,1,n,l[y],r[y]);
		ans[Id]=(res<<1)%Mod;
		ans[Id]=(ans[Id]+Mod-Sum)%Mod;
	}
	for(int i=head[x],y;i;i=e[i].n)
		if((y=e[i].t)!=p){
			modify(1,1,n,1,l[y]-1,e[i].d);
			modify(1,1,n,r[y]+1,n,e[i].d);
			modify(1,1,n,l[y],r[y],Mod-e[i].d);
			dfs(y,x);
			modify(1,1,n,l[y],r[y],e[i].d);
			modify(1,1,n,r[y]+1,n,Mod-e[i].d);
			modify(1,1,n,1,l[y]-1,Mod-e[i].d);
		}
}

int main(){
//	freopen("fact.in","r",stdin);
//	freopen("fact.out","w",stdout);
	Scan(n);
	for(int i=1,u,v,w;i<n;++i){
		Scan(u),Scan(v),Scan(w);
		AddEdge(u,v,w);
	}
	Scan(m);
	for(int i=1,u,v;i<=m;++i){
		Scan(u),Scan(v);
		AddQuery(u,v,i);
	}
	prev(1,0);
	build(1,1,n);
	dfs(1,0);
	for(int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}