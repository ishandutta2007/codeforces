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
struct seg{
	int sum[100010],tag[100010],maxn[100010];
	void pushup(int p){
		sum[p]=sum[p<<1]+sum[p<<1|1];
		maxn[p]=max(maxn[p<<1],maxn[p<<1|1]);
	}
	void pushdown(int p,int l,int r){
		if(tag[p]){
			int mid=l+r>>1;
			sum[p<<1]+=tag[p]*(mid-l+1);
			sum[p<<1|1]+=tag[p]*(r-mid);
			maxn[p<<1]+=tag[p];maxn[p<<1|1]+=tag[p]; 
			tag[p<<1]+=tag[p];tag[p<<1|1]+=tag[p];
			tag[p]=0;
		}
	}
	void update(int p,int l,int r,int L,int R,int k){
		if(l>=L&&r<=R){
			sum[p]+=k*(r-l+1);maxn[p]+=k;tag[p]+=k;return ;
		}
		pushdown(p,l,r);
		int mid=l+r>>1;
		if(L<=mid) update(p<<1,l,mid,L,R,k);
		if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
		pushup(p);
	} 
	void build(int p,int l,int r,int *a){
		if(l==r){
			sum[p]=maxn[p]=a[l];tag[p]=0;
			return ;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid,a);
		build(p<<1|1,mid+1,r,a);
		pushup(p);
	}
	int query(int p,int l,int r,int L,int R){
		if(l>=L&&r<=R){
			return sum[p];
		}
		pushdown(p,l,r);
		pushup(p);
		int mid=l+r>>1;
		int res=0;
		if(L<=mid) res+=query(p<<1,l,mid,L,R);
		if(R>mid) res+=query(p<<1|1,mid+1,r,L,R);
		return res;
	}
	int qmax(int p,int l,int r,int L,int R){
		if(l>=L&&r<=R){
			return maxn[p];
		}
		pushdown(p,l,r);
		pushup(p);
		int mid=l+r>>1;
		int res=0;
		if(L<=mid) res=max(res,qmax(p<<1,l,mid,L,R));
		if(R>mid) res=max(res,qmax(p<<1|1,mid+1,r,L,R));
	}
}T[100],t[100]; 
int n,m,k;
int ans;
int a[100][20010];
int f[100][20010];
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
		T[i].build(1,1,m,a[i]);
	}
	for(int i=1;i+k-1<=m;++i){
		f[1][i]=T[1].query(1,1,m,i,i+k-1)+T[2].query(1,1,m,i,i+k-1);
	}
	t[1].build(1,1,m,f[1]);
	for(int i=2;i<=n;++i){
		for(int j=1;j<=k;++j){
			t[i-1].update(1,1,m,max(j-k+1,1),j,-a[i][j]);
		}
		f[i][1]=t[i-1].qmax(1,1,m,1,m)+T[i].query(1,1,m,1,k)+T[i+1].query(1,1,m,1,k);
		for(int j=2;j+k-1<=m;++j){
			t[i-1].update(1,1,m,max(j-k,1),j-1,a[i][j-1]);
			t[i-1].update(1,1,m,j,j+k-1,-a[i][j+k-1]);
			f[i][j]=t[i-1].qmax(1,1,m,1,m)+T[i].query(1,1,m,j,j+k-1)+T[i+1].query(1,1,m,j,j+k-1); 
		}
		t[i].build(1,1,m,f[i]);
	}
	print(t[n].qmax(1,1,m,1,m));
	return 0;
}