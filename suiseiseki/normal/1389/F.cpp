#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=200000;
struct Segment{
	int l,r,t;
	friend bool operator <(Segment p,Segment q){
		if(p.r==q.r){
			return p.l<q.l;
		}
		return p.r<q.r;
	}
}a[Maxn+5];
int f[Maxn+5];
int n;
int d[Maxn<<1|5],d_len;
struct Segment_Node{
	int lson,rson;
	int val,lazy;
}seg[Maxn<<4|5];
int Root[2];
int id_tot;
void insert(int l,int r,int x,int &root,int left=1,int right=d_len){
	if(l>right||r<left){
		return;
	}
	if(root==0){
		root=++id_tot;
	}
	if(l<=left&&r>=right){
		seg[root].val+=x;
		seg[root].lazy+=x;
		return;
	}
	int mid=(left+right)>>1;
	insert(l,r,x,seg[root].lson,left,mid);
	insert(l,r,x,seg[root].rson,mid+1,right);
	seg[root].val=max(seg[seg[root].lson].val,seg[seg[root].rson].val)+seg[root].lazy;
}
int query(int l,int r,int root,int left=1,int right=d_len){
	if(l>right||r<left){
		return 0;
	}
	if(root==0){
		return 0;
	}
	if(l<=left&&r>=right){
		return seg[root].val;
	}
	int mid=(left+right)>>1;
	return max(query(l,r,seg[root].lson,left,mid),query(l,r,seg[root].rson,mid+1,right))+seg[root].lazy;
}
void update(int x,int a,int &root,int left=1,int right=d_len){
	if(root==0){
		root=++id_tot;
	}
	a-=seg[root].lazy;
	if(left==right){
		seg[root].val=max(seg[root].val,a);
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		update(x,a,seg[root].lson,left,mid);
	}
	else{
		update(x,a,seg[root].rson,mid+1,right);
	}
	seg[root].val=max(seg[seg[root].lson].val,seg[seg[root].rson].val)+seg[root].lazy;
}
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i].l),read(a[i].r),read(a[i].t);
		a[i].t--;
		d[++d_len]=a[i].l;
		d[++d_len]=a[i].r;
	}
	sort(d+1,d+1+d_len);
	d_len=unique(d+1,d+1+d_len)-d-1;
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(d+1,d+1+d_len,a[i].l)-d+1;
		a[i].r=lower_bound(d+1,d+1+d_len,a[i].r)-d+1;
	}
	d_len++;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=query(1,a[i].l-1,Root[a[i].t])+1;
		insert(1,a[i].l-1,1,Root[a[i].t]);
		update(a[i].r,f[i],Root[a[i].t^1]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}