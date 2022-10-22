#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n,q;
int cnt;
int a[300010];
int lim[300010];
int rt[300010];
struct chairmt{
	int sum[10000010];
	int ls[10000010],rs[10000010];
	void build(int &p,int l,int r){
		p=++cnt;
		if(l==r) return ;
		int mid=l+r>>1;
		build(ls[p],l,mid);
		build(rs[p],mid+1,r);
	}
	void modify(int p,int l,int r,int k,int &t){
//		printf("p:%d,l:%d,r:%d,k:%d\n",p,l,r,k);
		t=++cnt;
		ls[t]=ls[p],rs[t]=rs[p],sum[t]=sum[p];
		if(k==-1) return ;
		++sum[t];
		if(l==r) return ;
		int mid=l+r>>1;
		if(k<=mid) modify(ls[p],l,mid,k,ls[t]);
		else modify(rs[p],mid+1,r,k,rs[t]);
	}
	int binery_search(int p,int l,int r,int k){
		if(sum[p]<k) return -1;
//		printf("p:%d,l:%d,r:%d,k:%d,sumls:%d,sumrs:%d\n",p,l,r,k,sum[ls[p]],sum[rs[p]]);
		if(l==r) return l;
		int mid=l+r>>1;
		if(sum[rs[p]]>=k) return binery_search(rs[p],mid+1,r,k);
		else return binery_search(ls[p],l,mid,k-sum[rs[p]]);
	}
	int query(int p,int l,int r,int L,int R){
		if(l>=L&&r<=R) return sum[p];
		int mid=l+r>>1;
		int res=0;
		if(L<=mid) res+=query(ls[p],l,mid,L,R);
		if(R>mid) res+=query(rs[p],mid+1,r,L,R);
		return res;
	}
}T;
int main(){
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read();
	T.build(rt[0],0,n);
	for(int i=1;i<=n;++i){
		int b=i-a[i];
		if(b<0) lim[i]=-1;
		else if(b==0) lim[i]=i-1;
		else lim[i]=T.binery_search(rt[i-1],0,n,b);
		T.modify(rt[i-1],0,n,lim[i],rt[i]);
//		printf("%d\n",lim[i]);
	}
	for(int i=1;i<=q;++i){
		int x=read(),y=read();
		print(T.query(rt[n-y],0,n,x,n));putchar('\n'); 
	}
	return 0;
}