#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
typedef long long ll;
const int Maxn=200000;
int n,q;
int a[Maxn+5];
struct Segment_Node{
	ll sum;
	int maxn,minn;
	int lazy;
}seg[Maxn<<2|5];
void update_tag(int root,int a,int left,int right){
	if(a>=seg[root].maxn){
		seg[root].maxn=seg[root].minn=a;
		seg[root].sum=1ll*(right-left+1)*a;
		seg[root].lazy=a;
	}
}
void push_down(int root,int left,int right){
	if(seg[root].lazy){
		int mid=(left+right)>>1;
		update_tag(root<<1,seg[root].lazy,left,mid);
		update_tag(root<<1|1,seg[root].lazy,mid+1,right);
		seg[root].lazy=0;
	}
}
void push_up(int root){
	seg[root].minn=min(seg[root<<1].minn,seg[root<<1|1].minn);
	seg[root].maxn=max(seg[root<<1].maxn,seg[root<<1|1].maxn);
	seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum;
}
void build(int root=1,int left=1,int right=n){
	seg[root].lazy=0;
	if(left==right){
		seg[root].maxn=seg[root].minn=seg[root].sum=a[left];
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	push_up(root);
}
void update(int l,int r,int a,int root=1,int left=1,int right=n){
	if(l>right||r<left){
		return;
	}
	if(l<=left&&r>=right){
		if(seg[root].minn>=a){
			return;
		}
		if(a>=seg[root].maxn){
			update_tag(root,a,left,right);
			return;
		}
	}
	push_down(root,left,right);
	int mid=(left+right)>>1;
	update(l,r,a,root<<1,left,mid);
	update(l,r,a,root<<1|1,mid+1,right);
	push_up(root);
}
int query(int l,int r,int &val,int root=1,int left=1,int right=n){
	if(l>right||r<left){
		return 0;
	}
	if(l<=left&&r>=right){
		if(val>=seg[root].sum){
			val-=seg[root].sum;
			return right-left+1;
		}
		if(val<seg[root].minn){
			return 0;
		}
	}
	push_down(root,left,right);
	int mid=(left+right)>>1;
	return query(l,r,val,root<<1,left,mid)+query(l,r,val,root<<1|1,mid+1,right);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build();
	for(int i=1;i<=q;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x,y;
			scanf("%d%d",&x,&y);
			update(1,x,y);
		}
		else{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",query(x,n,y));
		}
	}
	return 0;
}