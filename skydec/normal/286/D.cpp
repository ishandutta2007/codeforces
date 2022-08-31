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
const int MAXN=210000;
int n,m;
struct wall{
	int l,r,t;
	inline wall(int a=0,int b=0,int c=0){l=a;r=b;t=c;}
}a[MAXN];
int b[MAXN];int N;
int mi[MAXN*4];
inline void add(int me,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){
		mi[me]=min(mi[me],v);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(me*2,l,mid,x,y,v);
	if(y>mid)add(me*2+1,mid+1,r,x,y,v);
}
int c[MAXN];//seg from i to i+1
pii q[MAXN];
LL cnt[MAXN];LL res[MAXN];
void dfs(int me,int l,int r,int inf){
	inf=min(inf,mi[me]);
	if(l==r){
		c[l]=inf;
		return;
	}
	int mid=(l+r)>>1;
	dfs(me*2,l,mid,inf);
	dfs(me*2+1,mid+1,r,inf);
}
inline int find(int x){
	return lower_bound(b+1,b+1+N,x)-b;
}
inline int findit(int x){
	int l=1;int r=n;int rp=n+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(q[mid].fi>=x)rp=mid,r=mid;
		else l=mid+1;
	}
	if(q[l].fi>=x)rp=l;
	return rp;
}
LL c2[MAXN];LL c3[MAXN];
inline void work(int l,int r,int u){   //i[l,r] cnt[i]+=u+t[i]
	if(l>r)return;
	c2[r+1]--;c2[l]++;
	c3[r+1]-=u;c3[l]+=u;
}
int tt[MAXN];
int main(){
	scanf("%d%d",&n,&m);memset(mi,63,sizeof mi);
	rep(i,1,m){int l,r,t;scanf("%d%d%d",&l,&r,&t);a[i]=wall(l,r,t);b[++b[0]]=l;b[++b[0]]=r;}
	sort(b+1,b+1+b[0]);N=unique(b+1,b+1+b[0])-b-1;
	rep(i,1,m){
		int l=find(a[i].l);
		int r=find(a[i].r)-1;
		add(1,1,N,l,r,a[i].t);
	}
	dfs(1,1,N,mi[0]);LL all=0;
	rep(i,1,n){int v;scanf("%d",&v);q[i]=pii(v,i);}
	sort(q+1,q+1+n);
	rep(i,1,N-1)if(c[i]<mi[0]){
		int pos=b[i];
		int size=b[i+1]-b[i];
		int p2=findit(c[i]-pos);
		all+=size;
		cnt[p2-1]-=size;
		int p3=findit(c[i]-b[i+1]);
		work(p3,p2-1,b[i+1]-c[i]);
	}
	per(i,n,1)cnt[i]+=cnt[i+1];
	rep(i,1,n){c2[i]+=c2[i-1];c3[i]+=c3[i-1];cnt[i]+=c3[i]+c2[i]*1ll*q[i].fi;}
	rep(i,1,n)res[q[i].se]=cnt[i]+all;
	rep(i,1,n)printf("%I64d\n",res[i]);
	return 0;
}