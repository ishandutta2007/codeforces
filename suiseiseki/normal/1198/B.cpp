#include <cstdio>
#define Maxn 200000
struct Segment_Node{
	int left,right;
	int val;
}seg[Maxn<<2|5];
int fa[Maxn+5];
int a[Maxn+5];
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	if(left==right){
		fa[left]=root;
		seg[root].val=a[left];
		return;
	}
	seg[root].val=-1;
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
}
int mx(int a,int b){
	return a>b?a:b;
}
void push_down(int root){
	if(seg[root].val==-1){
		return;
	}
	seg[root<<1].val=mx(seg[root<<1].val,seg[root].val);
	seg[root<<1|1].val=mx(seg[root<<1|1].val,seg[root].val);
	seg[root].val=-1;
}
void update_1(int root,int left,int right,int x){
	if(seg[root].left==left&&seg[root].right==right){
		seg[root].val=x;
		return;
	}
	push_down(root);
	root<<=1;
	if(left<=seg[root].right){
		update_1(root,left,right,x);
	}
	root|=1;
	if(right>=seg[root].left){
		update_1(root,left,right,x);
	}
}
void update_2(int x){
	seg[1].val=mx(seg[1].val,x);
}
void push(int root){
	if(seg[root].left==seg[root].right){
		return;
	}
	push_down(root);
	push(root<<1);
	push(root<<1|1);
}
int main(){
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	scanf("%d",&q);
	int p,x,t;
	while(q--){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&p,&x);
			update_1(1,p,p,x);
		}
		else{
			scanf("%d",&x);
			update_2(x);
		}
	}
	push(1);
	for(int i=1;i<=n;i++){
		printf("%d ",seg[fa[i]].val);
	}
	puts("");
	return 0;
}