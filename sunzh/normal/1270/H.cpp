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
int n,q;
int a[1000010];
int mn[4000010],tag[4000010],cnt[4000010];
const int Mx=1e6+5;
void pushup(int p){
	if(mn[p<<1]<mn[p<<1|1]) mn[p]=mn[p<<1],cnt[p]=cnt[p<<1];
	else if(mn[p<<1]==mn[p<<1|1]) mn[p]=mn[p<<1],cnt[p]=cnt[p<<1]+cnt[p<<1|1];
	else mn[p]=mn[p<<1|1],cnt[p]=cnt[p<<1|1];
}
void pushtag(int p,int k){
	tag[p]+=k;mn[p]+=k;
}
void pushdown(int p){
	pushtag(p<<1,tag[p]);pushtag(p<<1|1,tag[p]);tag[p]=0;
}
void update(int p,int l,int r,int L,int R,int k){
	// printf("l:%d,r:%d,L:%d,R:%d,k:%d\n",l,r,L,R,k);
	if(l>=L&&r<=R){
		pushtag(p,k);return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
void upd(int x,int y,int k){
	if(x>y) swap(x,y);
	// printf("%d,%d,%d\n",x+1,y,k.);
	update(1,1,Mx,x+1,y,k);
}
void modify(int p,int l,int r,int pos,int k){
	if(l==r){
		cnt[p]+=k;return ;
	}
	int mid=l+r>>1;pushdown(p);
	if(pos<=mid) modify(p<<1,l,mid,pos,k);
	else modify(p<<1|1,mid+1,r,pos,k);
	pushup(p);
}
int main(){
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read();
	a[0]=Mx;
	a[n+1]=0;
	// build(1,0,Mx);
	for(int i=1;i<=n+1;++i){
		upd(a[i-1],a[i],1);
	}
	for(int i=1;i<=n;++i) modify(1,1,Mx,a[i],1);
	for(int i=1;i<=q;++i){
		int pos=read(),w=read();
		upd(a[pos-1],a[pos],-1);upd(a[pos],a[pos+1],-1);modify(1,1,Mx,a[pos],-1);
		modify(1,1,Mx,w,1);upd(a[pos-1],w,1);upd(w,a[pos+1],1);a[pos]=w;
		// printf("%d %d\n",mn[1],cnt[1]);
		printf("%d\n",mn[1]==1?cnt[1]:0);
	}
}