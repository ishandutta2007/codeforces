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
int n;
int a[10010];
int minn[20010],pos[20010];
void build(int p,int l,int r){
	if(l==r){
		minn[p]=a[l];pos[p]=l;return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	if(minn[p<<1]<minn[p<<1|1]) minn[p]=minn[p<<1],pos[p]=pos[p<<1];
	else minn[p]=minn[p<<1|1],pos[p]=pos[p<<1|1];
}
int query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R){
		return pos[p];
	}
	int mid=l+r>>1;
	int ans=0x3f3f3f3f,res=-1;
	if(L<=mid){
		int x=query(p<<1,l,mid,L,R);if(a[x]<ans) ans=a[x],res=x;
	}
	if(R>mid){
		int x=query(p<<1|1,mid+1,r,L,R);if(a[x]<ans) ans=a[x],res=x;
	}
	return res;
}
int solve(int l,int r,int det){
	if(l>r) return 0;
	int x=query(1,1,n,l,r);
	return min(r-l+1,a[x]-det+solve(l,x-1,a[x])+solve(x+1,r,a[x]));
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),minn[i]=minn[i+n]=0x3f3f3f3f;
	build(1,1,n);
	printf("%d\n",solve(1,n,0));
	return 0;
}