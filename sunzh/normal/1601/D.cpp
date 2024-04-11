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
int n,d;
PII a[500010];
int c[1000010];
int mx[4000010],mn[4000010],tag1[4000010],tag2[4000010],sc[4000010];
void pushup(int p){
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
	if(mn[p<<1]>mn[p<<1|1]){
		mn[p]=mn[p<<1|1];sc[p]=min(sc[p<<1|1],mn[p<<1]);
	}
	else if(mn[p<<1]==mn[p<<1|1]){
		mn[p]=mn[p<<1],sc[p]=min(sc[p<<1],sc[p<<1|1]);
	}
	else mn[p]=mn[p<<1],sc[p]=min(sc[p<<1],mn[p<<1|1]);
}
void pushdown(int p){
	if(tag1[p]){
		mx[p<<1]+=tag1[p];mn[p<<1]+=tag1[p],sc[p<<1]+=tag1[p];tag1[p<<1]+=tag1[p];
		mx[p<<1|1]+=tag1[p];mn[p<<1|1]+=tag1[p],sc[p<<1|1]+=tag1[p];tag1[p<<1|1]+=tag1[p];
		tag1[p]=0;
	}
	if(tag2[p]){
		int x=min(mn[p<<1],mn[p<<1|1]);
		if(mn[p<<1]==x){
			mn[p<<1]+=tag2[p];tag2[p<<1]+=tag2[p];mx[p<<1]=max(mx[p<<1],mn[p<<1]);
		}
		if(mn[p<<1|1]==x){
			mn[p<<1|1]+=tag2[p];tag2[p<<1|1]+=tag2[p];mx[p<<1|1]=max(mx[p<<1|1],mn[p<<1|1]);
		}
		tag2[p]=0;
	}
}
void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		if(l==r){
			mn[p]=mx[p]=max(mx[p],k);sc[p]=0x3f3f3f3f;
			return ;
		}
		mx[p]=max(mx[p],k);
		if(k<=mn[p]) return ;
		else if(k<sc[p]){
			tag2[p]+=k-mn[p];mn[p]=k;return ;
		}
		int mid=l+r>>1;
		pushdown(p);
		update(p<<1,l,mid,L,R,k);
		update(p<<1|1,mid+1,r,L,R,k);
		pushup(p);
	}
	int mid=l+r>>1;
	pushdown(p);
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
void modify(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		mx[p]+=k;tag1[p]+=k;mn[p]+=k;sc[p]+=k;
		return ;
	}
	int mid=l+r>>1;
	pushdown(p);
	if(L<=mid) modify(p<<1,l,mid,L,R,k);
	if(R>mid) modify(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
int query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return mx[p];
	int mid=l+r>>1;
	int res=-0x3f3f3f3f;
	pushdown(p);
	if(L<=mid) res=max(res,query(p<<1,l,mid,L,R));
	if(R>mid) res=max(res,query(p<<1|1,mid+1,r,L,R));
	return res;
}
void build(int p,int l,int r){
	if(l==r){
		if(c[l]<d) mn[p]=mx[p]=-0x3f3f3f3f;
		else mn[p]=mx[p]=0;sc[p]=0x3f3f3f3f;
		return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);pushup(p);
}
int main(){
	n=read(),d=read();
	for(int i=1;i<=n;++i) a[i].fi=read(),a[i].se=read(),c[i]=a[i].fi,c[i+n]=a[i].se;
	sort(a+1,a+n+1,[&](PII x,PII y){
		return max(x.fi,x.se)==max(y.fi,y.se)?x<y:max(x.fi,x.se)<max(y.fi,y.se);
	});sort(c+1,c+n+n+1);
	int N=unique(c+1,c+n+n+1)-c-1;
	build(1,1,N);
	for(int i=1;i<=n;++i){
		int p1=lower_bound(c+1,c+N+1,a[i].fi)-c,p2=lower_bound(c+1,c+N+1,a[i].se)-c;
		if(p1>=p2){
			int x=query(1,1,N,1,p2);
			modify(1,1,N,p2,p1,1);
			update(1,1,N,p2,N,x+1);
		}
		else{
			int x=query(1,1,N,1,p1);
			update(1,1,N,p2,N,x+1);
		}
		// for(int j=1;j<=N;++j) printf("%d ",query(1,1,N,j,j));printf("\n");
	}
	printf("%d\n",mx[1]);
}