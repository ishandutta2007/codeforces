#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=500000;
const int Inf=0x3f3f3f3f;
struct Segment_Tree_1{
	struct Segment_Node{
		int lazy;
		int val;
	}seg[Maxn<<2|5];
	void build(int root=1,int left=-Maxn,int right=0){
		if(left==right){
			seg[root].val=left;
			return;
		}
		int mid=(left+right)>>1;
		build(root<<1,left,mid);
		build(root<<1|1,mid+1,right);
		seg[root].val=max(seg[root<<1].val,seg[root<<1|1].val);
	}
	void update_tag(int root,int a){
		seg[root].lazy+=a;
		seg[root].val+=a;
	}
	void push_down(int root){
		update_tag(root<<1,seg[root].lazy);
		update_tag(root<<1|1,seg[root].lazy);
		seg[root].lazy=0;
	}
	void update(int l,int r,int a,int root=1,int left=-Maxn,int right=0){
		if(l>right||r<left){
			return;
		}
		if(l<=left&&r>=right){
			update_tag(root,a);
			return;
		}
		push_down(root);
		int mid=(left+right)>>1;
		update(l,r,a,root<<1,left,mid);
		update(l,r,a,root<<1|1,mid+1,right);
		seg[root].val=max(seg[root<<1].val,seg[root<<1|1].val);
	}
	int query(int root=1,int left=-Maxn,int right=0){
		if(left==right){
			return left;
		}
		push_down(root);
		int mid=(left+right)>>1;
		if(seg[root<<1].val>=0){
			return query(root<<1,left,mid);
		}
		else{
			return query(root<<1|1,mid+1,right);
		}
	}
}S;
struct Segment_Tree_2{
	struct Segment_Node{
		int lazy;
		int val;
	}seg[Maxn<<3|5];
	void build(int root=1,int left=-Maxn,int right=Maxn){
		if(left==right){
			seg[root].val=left;
			return;
		}
		int mid=(left+right)>>1;
		build(root<<1,left,mid);
		build(root<<1|1,mid+1,right);
		seg[root].val=min(seg[root<<1].val,seg[root<<1|1].val);
	}
	void update_tag(int root,int a){
		seg[root].lazy+=a;
		seg[root].val+=a;
	}
	void push_down(int root){
		update_tag(root<<1,seg[root].lazy);
		update_tag(root<<1|1,seg[root].lazy);
		seg[root].lazy=0;
	}
	void update(int l,int r,int a,int root=1,int left=-Maxn,int right=Maxn){
		if(l>right||r<left){
			return;
		}
		if(l<=left&&r>=right){
			update_tag(root,a);
			return;
		}
		int mid=(left+right)>>1;
		push_down(root);
		update(l,r,a,root<<1,left,mid);
		update(l,r,a,root<<1|1,mid+1,right);
		seg[root].val=min(seg[root<<1].val,seg[root<<1|1].val);
	}
	int query(int l,int r,int root=1,int left=-Maxn,int right=Maxn){
		if(l>right||r<left){
			return Inf;
		}
		if(l<=left&&r>=right){
			return seg[root].val;
		}
		push_down(root);
		int mid=(left+right)>>1;
		return min(query(l,r,root<<1,left,mid),query(l,r,root<<1|1,mid+1,right));
	}
}T;
int n;
int main(){
	S.build();
	T.build();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(x<0){
			S.update(x,0,1);
		}
		T.update(-Maxn,x-1,1);
		int pos=S.query();
		printf("%d\n",T.query(pos,Maxn));
	}
	return 0;
}