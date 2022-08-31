#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=210000;
int ma[N<<2];
int n,a[N];
int fd(int me,int l,int r,int x,int y,int v){
	if(ma[me]<=v)return 0;
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(x<=mid){
		int rp=fd(me<<1,l,mid,x,y,v);
		if(rp)return rp;
	}
	if(y>mid){
		int rp=fd(me<<1|1,mid+1,r,x,y,v);
		if(rp)return rp;
	}
	return 0;
}
void del(int me,int l,int r,int x){
	if(l==r){
		ma[me]=0;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)del(me<<1,l,mid,x);
	else del(me<<1|1,mid+1,r,x);
	ma[me]=max(ma[me<<1],ma[me<<1|1]);
}
void build(int me,int l,int r){
	if(l==r){
		ma[me]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(me<<1,l,mid);
	build(me<<1|1,mid+1,r);
	ma[me]=max(ma[me<<1],ma[me<<1|1]);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	build(1,1,n);
	int st=0;
	while(st=fd(1,1,n,1,n,0)){
		del(1,1,n,st);
		printf("%d ",a[st]);
		while(st=fd(1,1,n,st+1,n,a[st])){
			del(1,1,n,st);
			printf("%d ",a[st]);
		}
		putchar('\n');
	}
	return 0;
}