#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn (1<<18)
int n,m,mx;
int siz[Maxn<<1|5];
int tree[Maxn<<2|5];
bool tag[Maxn<<2|5];
int ans[Maxn|5];
struct rpg {
	int x,y,id;
}a[Maxn<<1|5],b[Maxn|5];
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x;
}
bool cmp_1(rpg a,rpg b){
	return a.x<b.x;
}
bool cmp_2(rpg a,rpg b){
	return a.id<b.id;
}
bool cmp_3(rpg a,rpg b){
	return a.x>b.x;
}
void build(int k,int l,int r){
	if(l==r){
		tree[k]=siz[l];
		return;
	}
	int i=(k<<1),mid=(l+r)>>1;
	build(i,l,mid);
	build(i|1,mid+1,r);
	tree[k]=tree[i]+tree[i|1];
	return;
}
void ctag(int k,int l,int r,int le,int ri) {
	if(tag[k]){
		return;
	}
	if(le<=l&&ri>=r){
		tree[k]=0;
		tag[k]=1;
		return;
	}
	int i=(k<<1),mid=(l+r)>>1;
	if(le<=mid){
		ctag(i,l,mid,le,ri);
	}
	if(mid<ri){
		ctag(i|1,mid+1,r,le,ri);
	}
	tree[k]=tree[i]+tree[i|1];
	if(!tree[k]){
		tag[k]=1;
	}
	return;
}
int query(int k,int l,int r,int le,int ri) {
	if(tag[k]){
		return 0;
	}
	if(le<=l&&ri>=r){
		return tree[k];
	}
	int i=(k<<1),mid=(l+r)>>1,sum=0;
	if(le<=mid){
		sum+=query(i,l,mid,le,ri);
	}
	if(ri>mid){
		sum+=query(i|1,mid+1,r,le,ri);
	}
	return sum;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].x=read();
		a[i+n].x=read()+a[i].x;
		a[i].id=i;
		a[i+n].id=i+n;
	}
	sort(a+1,a+1+(n<<1),cmp_1);
	a[1].y=1;
	for(int i=2;i<=(n<<1);i++){
		if(a[i].x==a[i-1].x){
			a[i].y=a[i-1].y;
			continue;
		}
		a[i].y=a[i-1].y+1;
		siz[a[i-1].y]=a[i].x-a[i-1].x;
	}
	mx=a[n<<1].y;
	sort(a+1,a+1+(n<<1),cmp_2);
	m=read();
	for(int i=1;i<=m;i++){
		b[i].x=read();
		b[i].y=read();
		b[i].id=i;
	}
	build(1,1,mx);
	sort(b+1,b+1+m,cmp_3);
	int ct=n;
	for(int i=1;i<=m;i++){
		while(ct>=b[i].x){
			ctag(1,1,mx,a[ct].y,a[ct+n].y-1);
			--ct;
		}
		ans[b[i].id]=query(1,1,mx,a[b[i].x].y,a[b[i].y].y-1);
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}