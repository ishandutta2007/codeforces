//orz YJN
//
//
//
//IGM
//
//
//
//
//
//Orz Orz Orz Orz Orz
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
#define eps (1e-9)
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
const int MAXN=1005;
int n,vx,vy;
int a[MAXN][MAXN],b[MAXN][MAXN];
db q[MAXN*MAXN*2];int top=0;
int mi[MAXN*MAXN*8];
struct seg{
	int l,r,h,heave;
	inline seg(int a=0,int b=0,int c=0,int e=0){
		l=a;r=b;h=c;heave=e;
	}
}c[MAXN*MAXN];int s=0;
inline bool cmp(const seg &a,const seg &b){
	return a.heave>b.heave;
}
int lazy[MAXN*MAXN*8];
inline void down(int me){
	rep(i,0,1){
		lazy[me*2+i]=max(lazy[me],lazy[me*2+i]);
		mi[me*2+i]=max(mi[me*2+i],lazy[me]);
	}
	lazy[me]=0;
}
void cover(int me,int l,int r,int x,int y,int h){
	if(l^r)down(me);
	if(x<=l&&r<=y){
		mi[me]=max(mi[me],h);
		lazy[me]=h;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)cover(me*2,l,mid,x,y,h);
	if(y>mid)cover(me*2+1,mid+1,r,x,y,h);
	mi[me]=min(mi[me*2],mi[me*2+1]);
}
int rp;
void Get(int me,int l,int r,int x,int y){
	if(l^r)down(me);
	if(x<=l&&r<=y){
		rp=min(rp,mi[me]);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)Get(me*2,l,mid,x,y);
	if(y>mid)Get(me*2+1,mid+1,r,x,y);
}
int N;
inline int find(db x){
	return lower_bound(q+1,q+1+N,x-eps)-q;
}
int main(){
	scanf("%d%d%d",&n,&vx,&vy);
	rep(i,1,n)rep(j,1,n)scanf("%d",&a[i][j]);
	vx*=-1;vy*=-1;
	if(vy<0){
		vy*=-1;
		rep(i,1,n)rep(j,1,n/2)swap(a[i][j],a[i][n+1-j]);
	}
	if(vx<0){
		vx*=-1;
		rep(j,1,n)rep(i,1,n/2)swap(a[i][j],a[n+1-i][j]);
	}
	if(!vx){
		swap(vx,vy);
		rep(i,1,n)rep(j,1,n)b[i][j]=a[i][j];
		rep(i,1,n)rep(j,1,n)a[j][n-i+1]=b[i][j];
	}
	rep(i,0,n)rep(j,0,n)q[++top]=j-(i*1.*vy/vx);
	sort(q+1,q+1+top);
	N=unique(q+1,q+1+top)-q-1;
	rep(i,1,n)rep(j,0,n-1){
		c[++s]=seg(find(j-((i)*1.*vy/vx)),find(j+1-((i-1)*1.*vy/vx))-1,a[i][j+1],i+j);
	}
	sort(c+1,c+1+s,cmp);
	LL res=0;
	rep(i,1,s){
		rp=1000000005;
		Get(1,1,N,c[i].l,c[i].r);
		res+=max(c[i].h-rp,0);
		cover(1,1,N,c[i].l,c[i].r,c[i].h);
	}
	printf("%I64d\n",res);
	return 0;
}