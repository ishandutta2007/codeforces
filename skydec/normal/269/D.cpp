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
const int MAXN=510000;
const int left=-1e9;
const int right=1e9;
int co[MAXN*8],lazy[MAXN*8];
int finish[MAXN];int cho;int now;
struct water{
	int l,r,h;
	inline water(int a=0,int b=0,int c=0){
		l=a;r=b;h=c;
	}
}a[MAXN];
int ord[MAXN];
int n,t;int tot=1;
int f[MAXN];
int b[MAXN*8];int N;
inline int find(int x){
	return lower_bound(b+1,b+1+N,x)-b;
}
inline void down(int me){
	if(lazy[me]){
		lazy[me*2]=co[me*2]=lazy[me*2+1]=co[me*2+1]=lazy[me];
		lazy[me]=0;
	}
}
inline void updata(int me){
	if(co[me*2])co[me]=co[me*2];
	if(co[me*2+1]){
		if(co[me*2]){
			if(co[me*2]==co[me*2+1])co[me]=co[me*2+1];
			else co[me]=-1;
		}
		else co[me]=co[me*2+1];
	}
}
inline bool chun(int me,int l,int r,int x,int y,int c){
	if(!co[me])return 1;
	if(l^r)down(me);
	if(x<=l&&r<=y)return c==co[me];
	int mid=(l+r)>>1;
	bool flag=1;
	if(x<=mid)flag&=chun(me*2,l,mid,x,y,c);
	if(y>mid)flag&=chun(me*2+1,mid+1,r,x,y,c);
	return flag;
}
inline void Do(int coci){
	finish[coci]=cho;
	int l=max(a[now].l,a[coci].l);
	int r=min(a[now].r,a[coci].r);
	if(min(r-l+1,f[coci])<=f[now])return;
	if(!chun(1,1,N,find(l),find(r),coci))return;
	f[now]=min(r-l+1,f[coci]);
}
void cover(int me,int l,int r,int x,int y,int c){
	if(l^r)down(me);
	if(x<=l&&r<=y){
		co[me]=lazy[me]=c;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)cover(me*2,l,mid,x,y,c);
	if(y>mid)cover(me*2+1,mid+1,r,x,y,c);
	updata(me);
}
void query(int me,int l,int r,int x,int y){
	if(!co[me])return;
	if(l^r)down(me);
	if(x<=l&&r<=y){
		if(co[me]>0){
			if(finish[co[me]]==cho)return;
			Do(co[me]);
			return;
		}
		int mid=(l+r)>>1;
		query(me*2,l,mid,x,y);
		query(me*2+1,mid+1,r,x,y);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)query(me*2,l,mid,x,y);
	if(y>mid)query(me*2+1,mid+1,r,x,y);
}
inline void work(int x){
	cho++;now=x;
	query(1,1,N,find(a[x].l),find(a[x].r));
}
inline bool cmp_h(const water &a,const water &b){
	return a.h>b.h;
}
int main(){
	scanf("%d%d",&n,&t);
	rep(i,1,n)scanf("%d%d%d",&a[i].h,&a[i].l,&a[i].r),++a[i].l;
	a[++n]=water(left,right,t);
	a[++n]=water(left,right,0);
	sort(a+1,a+1+n,cmp_h);
	rep(i,1,n){
		b[++N]=a[i].l;
		b[++N]=a[i].l-1;
		b[++N]=a[i].l+1;
		b[++N]=a[i].r-1;
		b[++N]=a[i].r+1;
		b[++N]=a[i].r;
	}
	sort(b+1,b+1+N);
	N=unique(b+1,b+1+N)-b-1;
	
	f[1]=right-left;
	cover(1,1,N,1,N,1);
	for(int i=2;i<=n;i++){
		int j=i;while(j<n&&a[j+1].h==a[i].h)j++;
		rep(k,i,j)work(k);
		rep(k,i,j)cover(1,1,N,find(a[k].l),find(a[k].r),k);
		i=j;
	}
	printf("%d\n",f[n]);
	return 0;
}