#include<bits/stdc++.h>
#define For(i,x,y) for (int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (int i=(x);i<(y);i++)
#define Dow(i,x,y) for (int i=(x);i>=(y);i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
 
const int N = 2e5+10;
int n,a[N];
 
int t[N<<2][2],tag[N<<2][2],tag2[N<<2][2];
inline void Build(int u,int l,int r){
	tag[u][0]=n+1,tag[u][1]=0;
	if (l==r) return;
	int mid=l+r>>1;
	Build(u<<1,l,mid),Build(u<<1^1,mid+1,r);
}
inline void cov(int u,int x,int y){
	t[u][y]=x,tag2[u][y]=x,tag[u][y]=(y==0?n+1:0);
}
inline void upd(int u,int x,int y){
	if (y==0) tag[u][y]=min(tag[u][y],x),t[u][y]=min(t[u][y],x);
		else tag[u][y]=max(tag[u][y],x),t[u][y]=max(t[u][y],x);
}
inline void push_up(int u){
	t[u][0]=max(t[u<<1][0],t[u<<1^1][0]);
	t[u][1]=min(t[u<<1][1],t[u<<1^1][1]);
}
inline void push_down(int u){
	For(i,0,1) if (tag2[u][i]){
		cov(u<<1,tag2[u][i],i),cov(u<<1^1,tag2[u][i],i);
		tag2[u][i]=0;
	}
	if (tag[u][0]!=n+1){
		upd(u<<1,tag[u][0],0),upd(u<<1^1,tag[u][0],0);
		tag[u][0]=n+1;
	}
	if (tag[u][1]!=0){
		upd(u<<1,tag[u][1],1),upd(u<<1^1,tag[u][1],1);
		tag[u][1]=0;
	}
}
inline void insert(int u,int l,int r,int ql,int x,int y){
	if (l==r) return t[u][y]=x,void(0);
	int mid=l+r>>1;push_down(u);
	if (ql<=mid) insert(u<<1,l,mid,ql,x,y);
		else insert(u<<1^1,mid+1,r,ql,x,y);
	push_up(u);
}
inline void update(int u,int l,int r,int ql,int qr,int x,int y){
	if (ql>qr) return;
	if (l>=ql&&r<=qr) return upd(u,x,y),void(0);
	int mid=l+r>>1;push_down(u);
	if (ql<=mid) update(u<<1,l,mid,ql,qr,x,y);
	if (qr>mid) update(u<<1^1,mid+1,r,ql,qr,x,y);
	push_up(u);
}
inline void cover(int u,int l,int r,int ql,int qr,int x,int y){
	if (ql>qr) return;
	if (l>=ql&&r<=qr) return cov(u,x,y),void(0);
	int mid=l+r>>1;push_down(u);
	if (ql<=mid) cover(u<<1,l,mid,ql,qr,x,y);
	if (qr>mid) cover(u<<1^1,mid+1,r,ql,qr,x,y);
	push_up(u);
}
inline int Find(int u,int l,int r,int ql,int qr,int x,int y){
	if (l>=ql&&r<=qr){
		if (y==0){
			if (t[u][y]<x) return -1;
		} else {
			if (t[u][y]>x) return -1;
		}
	}
	if (l==r) return l;
	int mid=l+r>>1;push_down(u);
	if (ql>mid) return Find(u<<1^1,mid+1,r,ql,qr,x,y);
	if (qr<=mid) return Find(u<<1,l,mid,ql,qr,x,y);
	int tmp=Find(u<<1,l,mid,ql,qr,x,y);
	if (tmp!=-1) return tmp;
	return Find(u<<1^1,mid+1,r,ql,qr,x,y);
}
 
inline int Query(int u,int l,int r,int ql,int y){
	if (l==r) return t[u][y];
	int mid=l+r>>1;push_down(u);
	if (ql<=mid) return Query(u<<1,l,mid,ql,y);
	return Query(u<<1^1,mid+1,r,ql,y);
}
 
int main(){
	n=read();
	For(i,1,n) a[i]=read();
	ll ans=1;
	Build(1,1,n);
	insert(1,1,n,n,0,0);
	insert(1,1,n,n,n+1,1);
	int r0=n,r1=n;
	Dow(i,n-1,1){
		insert(1,1,n,i,0,0);
		insert(1,1,n,i,n+1,1);
		int tmp1=Find(1,1,n,i,r0,a[i],0);
		int tmp2=Find(1,1,n,i,r1,a[i],1);
		if (tmp1==-1) tmp1=r0+1;
		if (tmp2==-1) tmp2=r1+1;
		--tmp2,--tmp1;
		if (a[i]<a[i+1]){
			if (tmp2<=r0) update(1,1,n,i,tmp2,a[i+1],0);
			else {
				update(1,1,n,i,r0,a[i+1],0);
				cover(1,1,n,r0+1,tmp2,a[i+1],0);
				r0=tmp2;
			}
			r1=min(r1,tmp1);
			cover(1,1,n,i+1,r1,a[i+1],1);
		} else {
			if (tmp1<=r1) update(1,1,n,i,tmp1,a[i+1],1);
			else {
				update(1,1,n,i,r1,a[i+1],1);
				cover(1,1,n,r1+1,tmp1,a[i+1],1);
				r1=tmp1;
			}
			r0=min(r0,tmp2);
			cover(1,1,n,i+1,r0,a[i+1],0);
		}
		ans+=max(r0,r1)-i+1;
//		printf("at %d %d %d\n",i,r0,r1);
//		For(j,i,n) printf("%d ",Query(1,1,n,j,0));puts("");
//		For(j,i,n) printf("%d ",Query(1,1,n,j,1));puts("");
//		puts("");
	}
	printf("%lld\n",ans);
}