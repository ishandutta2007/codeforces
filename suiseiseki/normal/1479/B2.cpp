#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=100000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
struct Segment_Node{
	int val,lazy;
}seg[Maxn<<2|5];
void push_up(int root){
	seg[root].val=min(seg[root<<1].val,seg[root<<1|1].val);
}
void update_tag(int root,int a){
	seg[root].val+=a;
	seg[root].lazy+=a;
}
void push_down(int root){
	if(seg[root].lazy==0){
		return;
	}
	update_tag(root<<1,seg[root].lazy);
	update_tag(root<<1|1,seg[root].lazy);
	seg[root].lazy=0;
}
void build(int root=1,int left=0,int right=n){
	seg[root].lazy=0;
	if(left==right){
		if(left==0){
			seg[root].val=0;
		}
		else{
			seg[root].val=Inf;
		}
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	push_up(root);
}
void update_s(int l,int r,int a,int root=1,int left=0,int right=n){
	if(l>right||r<left){
		return;
	}
	if(l<=left&&r>=right){
		update_tag(root,a);
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	update_s(l,r,a,root<<1,left,mid);
	update_s(l,r,a,root<<1|1,mid+1,right);
	push_up(root);
}
void update_p(int x,int a,int root=1,int left=0,int right=n){
	if(left==right){
		seg[root].val=min(seg[root].val,a);
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	if(x<=mid){
		update_p(x,a,root<<1,left,mid);
	}
	else{
		update_p(x,a,root<<1|1,mid+1,right);
	}
	push_up(root);
}
int query(int l,int r,int root=1,int left=0,int right=n){
	if(l>right||r<left||l>r){
		return Inf;
	}
	if(l<=left&&r>=right){
		return seg[root].val;
	}
	push_down(root);
	int mid=(left+right)>>1;
	return min(query(l,r,root<<1,left,mid),query(l,r,root<<1|1,mid+1,right));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build();
	for(int i=1;i<=n;i++){
		int t=min(query(0,a[i]-1),query(a[i]+1,n))+1;
		t=min(t,query(a[i],a[i]));
		if(a[i]!=a[i-1]){
			update_s(0,n,1);
		}
		update_p(a[i-1],t);
	}
	printf("%d\n",query(0,n));
	return 0;
}