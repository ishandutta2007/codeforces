#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
const int jsb=1000000000;
const int MAXN=210000;
struct ww{
	int a00,a01,a10,a11;
	inline ww(int a=0,int b=0,int c=0,int d=0){
		a00=a;a01=b;a10=c;a11=d;
	}
};
inline ww operator *(const ww &a,const ww &b){
	ww c;c=ww(0,0,0,0);
	c.a00=(a.a01*1ll*b.a10+a.a00*1ll*b.a00)%jsb;
	c.a01=(a.a01*1ll*b.a11+a.a00*1ll*b.a01)%jsb;
	c.a10=(a.a11*1ll*b.a10+a.a10*1ll*b.a00)%jsb;
	c.a11=(a.a11*1ll*b.a11+a.a10*1ll*b.a01)%jsb;
	return c;
}
inline ww operator +(const ww &a,const ww &b){
	ww c;c=a;
	c.a00+=b.a00;c.a01+=b.a01;c.a10+=b.a10;c.a11+=b.a11;
	if(c.a00>=jsb)c.a00-=jsb;
	if(c.a01>=jsb)c.a01-=jsb;
	if(c.a10>=jsb)c.a10-=jsb;
	if(c.a11>=jsb)c.a11-=jsb;
	return c;
}
inline ww operator *(const ww &a,const int &b){
	ww c;c=a;
	c.a00=c.a00*1ll*b%jsb;
	c.a01=c.a01*1ll*b%jsb;
	c.a10=c.a10*1ll*b%jsb;
	c.a11=c.a11*1ll*b%jsb;
	return c;
}
int lazy[MAXN*4];ww sum[MAXN*4];
ww pre[MAXN],po[MAXN];int n,m;int a[MAXN];
ww res;int size;
inline void init(){
	po[0]=ww(1,0,0,1);
	po[1]=ww(1,1,1,0);
	rep(i,2,n)po[i]=po[i-1]*po[1];
	pre[0]=po[0];
	rep(i,1,n)pre[i]=pre[i-1]+po[i];
}
inline void relax(ww ha,int len){
	res=res+ha*po[size];
	size+=len;
}
inline void upd(int me,int l,int r){
	int midd=(l+r)>>1;int mid=midd-l+1;
	sum[me]=sum[me*2]+sum[me*2+1]*po[mid];
}
inline void down(int me,int l,int r){
	if(!lazy[me]||l==r)return;
	int midd=(l+r)>>1;int mid;
	rep(u,0,1){
		if(!u)mid=midd-l+1;
		else mid=r-midd;
		lazy[me*2+u]=(lazy[me*2+u]+lazy[me])%jsb;
		sum[me*2+u]=sum[me*2+u]+pre[mid-1]*lazy[me];
	}
	lazy[me]=0;
}	
inline void build(int me,int l,int r){
	if(l==r){
		sum[me]=po[0]*a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(me*2,l,mid);
	build(me*2+1,mid+1,r);
	upd(me,l,r);
}
inline void modify(int me,int l,int r,int x,int v){
	down(me,l,r);
	if(l==r){
		sum[me]=po[0]*v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)modify(me*2,l,mid,x,v);
	else modify(me*2+1,mid+1,r,x,v);
	upd(me,l,r);
}
inline void ask(int me,int l,int r,int x,int y){
	down(me,l,r);
	if(x<=l&&r<=y){
		relax(sum[me],r-l+1);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)ask(me*2,l,mid,x,y);
	if(y>mid)ask(me*2+1,mid+1,r,x,y);
}
inline void add(int me,int l,int r,int x,int y,int v){
	down(me,l,r);
	if(x<=l&&r<=y){
		sum[me]=sum[me]+pre[r-l]*v;
		lazy[me]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(me*2,l,mid,x,y,v);
	if(y>mid)add(me*2+1,mid+1,r,x,y,v);
	upd(me,l,r);
}
int main(){
	scanf("%d%d",&n,&m);init();
	rep(i,1,n)scanf("%d",&a[i]);
	build(1,1,n);
	while(m--){
		res=ww(0,0,0,0);
		size=0;
		int opt;scanf("%d",&opt);
		if(opt==1){
			int x,v;scanf("%d%d",&x,&v);
			modify(1,1,n,x,v);
		}
		else if(opt==2){
			int l,r;scanf("%d%d",&l,&r);
			ask(1,1,n,l,r);
			printf("%d\n",res.a00);
		}
		else{
			int l,r,v;scanf("%d%d%d",&l,&r,&v);
			add(1,1,n,l,r,v);
		}
	}
	return 0;
}