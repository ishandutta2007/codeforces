#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 200005
#define int long long
int n,m,a[MN];
int Min[MN<<2],Max[MN<<2],tag[MN<<2],sum[MN<<2];
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
void pushup(int x){
	Min[x]=Min[Rs];
	Max[x]=Max[Ls];
	sum[x]=sum[Ls]+sum[Rs];
}
void build(int x,int l,int r){
	if(l==r){sum[x]=Min[x]=Max[x]=a[l];return;}
	build(Ls,l,mid);
	build(Rs,mid+1,r);
	pushup(x);
}
void pushdown(int x,int l,int r){
	if(tag[x]){
		Max[Ls]=Min[Ls]=Max[Rs]=Min[Rs]=tag[x];
		sum[Ls]=(mid-l+1)*tag[x];
		sum[Rs]=(r-mid)*tag[x];
		tag[Ls]=tag[Rs]=tag[x];
		tag[x]=0;
	}
}
void change(int x,int l,int r,int p,int v){
	if(Min[x]>=v)return;
	if(l>p)return;
	if(r<=p&&Max[x]<=v){
		Max[x]=Min[x]=tag[x]=v;
		sum[x]=v*(r-l+1);
		return;
	}
	if(r<=p&&Min[x]>v)return;
	pushdown(x,l,r);
	change(Ls,l,mid,p,v);
	change(Rs,mid+1,r,p,v);
	pushup(x);
}
int findnxt(int x,int l,int r,int pos,int v){
	if(Min[x]>v)return 0;
	if(l>=pos){
		if(Max[x]<=v)return l;
	}
	if(r<pos)return 0;
	pushdown(x,l,r);
	int p=findnxt(Ls,l,mid,pos,v);
	if(p)return p;
	return findnxt(Rs,mid+1,r,pos,v);
}
int cnt;
int upd(int x,int l,int r,int pos,int &y){
	if(l>=pos&&sum[x]<=y){y-=sum[x];cnt+=(r-l+1);return r;}
	if(l>=pos&&Min[x]>y)return l-1;
	if(r<pos)return r;
	pushdown(x,l,r);
	int p=upd(Ls,l,mid,pos,y);
	if(p==mid){
		return upd(Rs,mid+1,r,pos,y);	
	}
	else return p;
}
signed main(){
	n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	build(1,1,n);
	for(int i=1;i<=m;++i){
		int op=read(),x=read(),y=read();
		if(op==1){
			change(1,1,n,x,y);
			if(x==n)a[n]=max(a[n],y);
		}
		else {
			int p=x;
			cnt=0;
			while(y>=a[n]&&p<=n){
				p=findnxt(1,1,n,p,y);
//				cerr<<"p: "<<p<<endl;
				p=upd(1,1,n,p,y);
				p++;
//				cerr<<"to: "<<p<<endl;
			}
			printf("%lld\n",cnt);
		}
	}
	return 0;
}