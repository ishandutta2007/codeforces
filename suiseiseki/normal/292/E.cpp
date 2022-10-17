#include <cstdio>
#define Maxn 100000
struct Segment_Tree{
	int left,right;
	int lazy;
}seg[Maxn<<2|5];
int a[Maxn+5];
int b[Maxn+5];
int n;
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	seg[root].lazy=-1;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
}
void push_down(int root){
	if(seg[root].lazy==-1){
		return;
	}
	seg[root<<1].lazy=seg[root].lazy;
	seg[root<<1|1].lazy=seg[root].lazy+seg[root<<1|1].left-seg[root].left;
	seg[root].lazy=-1;
}
void update(int root,int left,int right,int x){
	if(seg[root].left==left&&seg[root].right==right){
		seg[root].lazy=x;
		return;
	}
	push_down(root);
	root<<=1;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			update(root,left,right,x);
		}
		else{
			update(root,left,seg[root].right,x);
		}
	}
	root>>=1;
	if(seg[root<<1|1].left>left){
		x+=seg[root<<1|1].left-left;
	}
	root<<=1;
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			update(root,left,right,x);
		}
		else{
			update(root,seg[root].left,right,x);
		}
	}
}
int query(int root,int x){
	if(seg[root].left==seg[root].right){
		return seg[root].lazy;
	}
	push_down(root);
	if(seg[root<<1].right>=x){
		return query(root<<1,x);
	}
	else{
		return query(root<<1|1,x);
	}
}
int main(){
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	build(1,1,n);
	int x,y,z;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x==2){
			z=query(1,y);
			if(z==-1){
				printf("%d\n",b[y]);
			}
			else{
				printf("%d\n",a[z]);
			}
		}
		else{
			x=y;
			scanf("%d%d",&y,&z);
			update(1,y,y+z-1,x);
		}
	}
	return 0;
}