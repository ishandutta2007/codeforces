#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
int n,q;
namespace Segment_Tree_1{
	struct Segment_Node{
		ll sum;
		int lazy;
	}seg[Maxn<<2|5];
	void update_tag(int root,int left,int right,int a){
		seg[root].lazy+=a;
		seg[root].sum+=1ll*(right-left+1)*a;
	}
	void push_down(int root,int left,int right){
		if(seg[root].lazy){
			int mid=(left+right)>>1;
			update_tag(root<<1,left,mid,seg[root].lazy);
			update_tag(root<<1|1,mid+1,right,seg[root].lazy);
			seg[root].lazy=0;
		}
	}
	void push_up(int root){
		seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum;
	}
	void update(int l,int r,int a,int root=1,int left=1,int right=n){
		if(l>right||r<left){
			return;
		}
		if(l<=left&&r>=right){
			update_tag(root,left,right,a);
			return;
		}
		push_down(root,left,right);
		int mid=(left+right)>>1;
		update(l,r,a,root<<1,left,mid);
		update(l,r,a,root<<1|1,mid+1,right);
		push_up(root);
	}
	ll query(int l,int r,int root=1,int left=1,int right=n){
		if(l>right||r<left){
			return 0;
		}
		if(l<=left&&r>=right){
			return seg[root].sum;
		}
		push_down(root,left,right);
		int mid=(left+right)>>1;
		return query(l,r,root<<1,left,mid)+query(l,r,root<<1|1,mid+1,right);
	}
}
namespace Segment_Tree_2{
	struct Segment_Node{
		int max_r,max_num;
		int nxt_r;
		int lazy_max;
	}seg[Maxn<<2|5];
	void update_tag(int root,int lazy){
		seg[root].max_r=std::min(seg[root].max_r,lazy);
		seg[root].lazy_max=std::min(seg[root].lazy_max,lazy);
	}
	void push_down(int root){
		if(seg[root].lazy_max!=n+1){
			update_tag(root<<1,seg[root].lazy_max);
			update_tag(root<<1|1,seg[root].lazy_max);
			seg[root].lazy_max=n+1;
		}
	}
	void push_up(int root){
		seg[root].max_r=seg[root<<1].max_r;
		seg[root].max_num=seg[root<<1].max_num;
		seg[root].nxt_r=seg[root<<1].nxt_r;
		if(seg[root<<1|1].max_r>seg[root].max_r){
			seg[root].nxt_r=std::max(seg[root].max_r,seg[root<<1|1].nxt_r);
			seg[root].max_r=seg[root<<1|1].max_r;
			seg[root].max_num=seg[root<<1|1].max_num;
		}
		else if(seg[root<<1|1].max_r==seg[root].max_r){
			seg[root].max_num+=seg[root<<1|1].max_num;
			seg[root].nxt_r=std::max(seg[root].nxt_r,seg[root<<1|1].nxt_r);
		}
		else{
			seg[root].nxt_r=std::max(seg[root].nxt_r,seg[root<<1|1].max_r);
		}
	}
	void build(int root=1,int left=1,int right=n){
		seg[root].lazy_max=n+1;
		if(left==right){
			seg[root].max_r=left;
			Segment_Tree_1::update(left,left,1);
			seg[root].max_num=1;
			seg[root].nxt_r=-1;
			return;
		}
		int mid=(left+right)>>1;
		build(root<<1,left,mid),build(root<<1|1,mid+1,right);
		push_up(root);
	}
	void update_min(int l,int r,int v,int root=1,int left=1,int right=n){
		if(l>right||r<left){
			return;
		}
		if(l<=left&&r>=right){
			if(v>=seg[root].max_r){
				return;
			}
			if(v>seg[root].nxt_r){
				Segment_Tree_1::update(v+1,seg[root].max_r,-seg[root].max_num);
				seg[root].max_r=seg[root].lazy_max=v;
				return;
			}
		}
		push_down(root);
		int mid=(left+right)>>1;
		update_min(l,r,v,root<<1,left,mid);
		update_min(l,r,v,root<<1|1,mid+1,right);
		push_up(root);
	}
	void update_node(int x,int v,int root=1,int left=1,int right=n){
		if(left==right){
			Segment_Tree_1::update(x,seg[root].max_r,-1);
			seg[root].max_r=v;
			Segment_Tree_1::update(x,seg[root].max_r,1);
			return;
		}
		push_down(root);
		int mid=(left+right)>>1;
		if(x<=mid){
			update_node(x,v,root<<1,left,mid);
		}
		else{
			update_node(x,v,root<<1|1,mid+1,right);
		}
		push_up(root);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	Segment_Tree_2::build();
	for(int t=1;t<=q;t++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int c,g;
			scanf("%d%d",&c,&g);
			Segment_Tree_2::update_min(1,c-1,c-1);
			Segment_Tree_2::update_node(c,g);
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			ll ans=Segment_Tree_1::query(l,r);
			printf("%lld\n",ans);
		}
	}
	return 0;
}