#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define int long long
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
int n,q;
int a[200010]; 
int maxn[800010],tag[800010];
inline int max(int x,int y){
	return x>y?x:y;
}
inline void pushdown(int p){
	if(tag[p]){
		maxn[p<<1]+=tag[p],maxn[p<<1|1]+=tag[p];
		tag[p<<1]+=tag[p],tag[p<<1|1]+=tag[p];
		tag[p]=0;
	}
}
inline void pushup(int p){
	maxn[p]=max(maxn[p<<1],maxn[p<<1|1]);
}
inline void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		maxn[p]+=k,tag[p]+=k;return ;
	}
	pushdown(p);
	int mid=l+r>>1;
	if(L<=mid) update(p<<1,l,mid,L,R,k);
	if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
inline int query(int p,int l,int r,int k){
	if(l==r) return l;
	pushdown(p);
	int mid=l+r>>1;
	if(maxn[p<<1]>=k) return query(p<<1,l,mid,k);
	else if(maxn[p<<1|1]>=k) return query(p<<1|1,mid+1,r,k);
	else return 0x3f3f3f3f;
}
//inline int qry(int p,int l,int r ,int L,int R,int k){
//	if(l>=L&&r<=R){
//		return query(p,l,r,k);
//	}
//	int mid=l+r>>1;
//	int res=0x3f3f3f3f;
//	if(L<=mid) res=min(res,qry(p<<1,l,mid,L,R,k));
//	if(R>mid) res=min(res,qry(p<<1|1,mid+1,r,L,R,k));
//	return res;
//}
inline int Query(int p,int l,int r,int k){
	if(k==0) return 0;
	if(l==r) return maxn[p];
	pushdown(p);
	int mid=l+r>>1;
	if(k<=mid) return Query(p<<1,l,mid,k);
	else return Query(p<<1|1,mid+1,r,k);
}
inline void find(){
	int pos=1;
	if(a[1]==0){
		print(1);putchar('\n');return ;
	}
	while(pos<=n){
		int k=Query(1,1,n,pos-1);
//		printf("pos:%d,k:%d\n",pos,k);
		if(a[pos]==k){
			print(pos);putchar('\n');return ;
		}
		k+=a[pos];
		pos=query(1,1,n,k<<1);
	}
	print(-1);putchar('\n');
}
signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read(),update(1,1,n,i,n,a[i]);
	while(q--){
		int p=read(),x=read();
		update(1,1,n,p,n,x-a[p]);
		a[p]=x;
		find();
	}
}