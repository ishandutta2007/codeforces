#include <cstdio>
#define Maxn 35000
#define Maxk 50
int a[Maxn+5];
int f[Maxk+5][Maxn+5];
int now_k;
struct Segment_Node{
	int left,right;
	int maxn,lazy;
}seg[Maxn<<2|5];
int mx(int a,int b){
	return a>b?a:b;
}
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	seg[root].lazy=0;
	if(left==right){
		seg[root].maxn=f[now_k][left-1];
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	seg[root].maxn=mx(seg[root<<1].maxn,seg[root<<1|1].maxn);
}
void push_down(int root){
	if(seg[root].lazy==0){
		return;
	}
	seg[root<<1].lazy+=seg[root].lazy;
	seg[root<<1].maxn+=seg[root].lazy;
	seg[root<<1|1].lazy+=seg[root].lazy;
	seg[root<<1|1].maxn+=seg[root].lazy;
	seg[root].lazy=0;
}
void update(int root,int left,int right,int x){
	if(seg[root].left==left&&seg[root].right==right){
		seg[root].lazy+=x;
		seg[root].maxn+=x;
		return;
	}
	push_down(root);
	root<<=1;
	if(right<=seg[root].right){
		update(root,left,right,x);
		root>>=1;
		seg[root].maxn=mx(seg[root<<1].maxn,seg[root<<1|1].maxn);
		return;
	}
	root|=1;
	if(left>=seg[root].left){
		update(root,left,right,x);
		root>>=1;
		seg[root].maxn=mx(seg[root<<1].maxn,seg[root<<1|1].maxn);
		return;
	}
	root>>=1;
	update(root<<1,left,seg[root<<1].right,x);
	update(root<<1|1,seg[root<<1|1].left,right,x);
	seg[root].maxn=mx(seg[root<<1].maxn,seg[root<<1|1].maxn);
}
int query(int root,int left,int right){
	if(seg[root].left==left&&seg[root].right==right){
		return seg[root].maxn;
	}
	push_down(root);
	root<<=1;
	if(right<=seg[root].right){
		return query(root,left,right);
	}
	root|=1;
	if(left>=seg[root].left){
		return query(root,left,right);
	}
	root>>=1;
	return mx(query(root<<1,left,seg[root<<1].right),query(root<<1|1,seg[root<<1|1].left,right));
}
int pre[Maxn+5],pos[Maxn+5];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=pos[a[i]]+1;
		pos[a[i]]=i;
	}
	for(int i=1;i<=k;i++){
		now_k=i-1;
		build(1,1,n);
		for(int j=1;j<=n;j++){
			update(1,pre[j],j,1);
			f[i][j]=query(1,1,j);
		}
	}
	printf("%d\n",f[k][n]);
	return 0;
}