#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define int long long
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int tag[400010];
int tre[400010];
int n;
int a[400010];
int res;
inline void pushup(int p){
	tre[p]=min(tre[p<<1],tre[p<<1|1]);
}
inline void pushdown(int p){
	if(tag[p]){
		tre[p<<1]+=tag[p],tre[p<<1|1]+=tag[p];
		tag[p<<1]+=tag[p],tag[p<<1|1]+=tag[p]; 
		tag[p]=0;
	}
}
void build(int p,int l,int r){
	if(l==r){
		tre[p]=a[l];return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p); 
}
inline void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		tre[p]+=k,tag[p]+=k;return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
inline int query(int p,int l,int r,int k){
	if(l==r) return tre[p];
	int mid=l+r>>1;
	pushdown(p);
	if(k<=mid) return query(p<<1,l,mid,k);
	else return query(p<<1|1,mid+1,r,k);
}
void getans(){
	int x=query(1,1,n,1);
//	printf("x:%d,res:5d\n",x,res);
	int a=x+res>>1;
	int b=x+res-a;
	printf("%lld\n",max(a,b));
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<n;++i) res=res+max(0ll,a[i+1]-a[i]);
	build(1,1,n);
	getans();
	int q=read();
	while(q--){
		int l=read(),r=read(),k=read();
		int x,y;
		if(l>1){
			x=query(1,1,n,l-1),y=query(1,1,n,l);
			res=res-max(0ll,y-x);
		}
		if(r<n){
			x=query(1,1,n,r),y=query(1,1,n,r+1);
			res=res-max(0ll,y-x);
		}
		update(1,1,n,l,r,k);
		if(l>1){
			x=query(1,1,n,l-1),y=query(1,1,n,l);
			res=res+max(0ll,y-x);
		}
		if(r<n){
			x=query(1,1,n,r),y=query(1,1,n,r+1);
			res=res+max(0ll,y-x);
		}
		getans();
	}
	return 0;
}