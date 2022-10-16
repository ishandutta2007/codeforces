#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
const int Maxn=200000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
std::vector<int> v_lis[Maxn+5];
struct Segment_Tree{
	struct Segment_Node{
		int minn,maxn;
		int lazy;
	}seg[Maxn<<2|5];
	void update_tag(int root,int a){
		seg[root].lazy+=a;
		seg[root].minn+=a,seg[root].maxn+=a;
	}
	void push_up(int root){
		seg[root].minn=std::min(seg[root<<1].minn,seg[root<<1|1].minn);
		seg[root].maxn=std::max(seg[root<<1].maxn,seg[root<<1|1].maxn);
	}
	void push_down(int root){
		if(seg[root].lazy==0){
			return;
		}
		update_tag(root<<1,seg[root].lazy);
		update_tag(root<<1|1,seg[root].lazy);
		seg[root].lazy=0;
	}
	void update(int l,int r,int v,int root=1,int left=0,int right=n){
		if(l>right||r<left){
			return;
		}
		if(l<=left&&r>=right){
			update_tag(root,v);
			return;
		}
		push_down(root);
		int mid=(left+right)>>1;
		update(l,r,v,root<<1,left,mid);
		update(l,r,v,root<<1|1,mid+1,right);
		push_up(root);
	}
	int query_min(int l,int r,int root=1,int left=0,int right=n){
		if(l>right||r<left){
			return Inf;
		}
		if(l<=left&&r>=right){
			return seg[root].minn;
		}
		push_down(root);
		int mid=(left+right)>>1;
		return std::min(query_min(l,r,root<<1,left,mid),query_min(l,r,root<<1|1,mid+1,right));
	}
	int query_max(int l,int r,int root=1,int left=0,int right=n){
		if(l>right||r<left){
			return -Inf;
		}
		if(l<=left&&r>=right){
			return seg[root].maxn;
		}
		push_down(root);
		int mid=(left+right)>>1;
		return std::max(query_max(l,r,root<<1,left,mid),query_max(l,r,root<<1|1,mid+1,right));
	}
}seg_1,seg_2;
int ans[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v_lis[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		seg_1.update(i>>1,(n-1)>>1,1);
		seg_2.update((i+1)>>1,n>>1,1);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)v_lis[i].size();j++){
			int pos=v_lis[i][j];
			int pos_1_max=seg_1.query_max(pos>>1,(n-1)>>1);
			int pos_1_min=seg_1.query_min(0,(pos>>1)-1);
			int pos_2_max=seg_2.query_max((pos+1)>>1,n>>1);
			int pos_2_min=seg_2.query_min(0,(pos-1)>>1);
			ans[pos]=std::max(std::max((pos_2_max-pos_2_min)>>1,(pos_1_max-pos_1_min)>>1),\
			std::max((pos_2_max-pos_1_min-1)>>1,(pos_1_max-pos_2_min-1)>>1));
		}
		for(int j=0;j<(int)v_lis[i].size();j++){
			seg_1.update(v_lis[i][j]>>1,(n-1)>>1,-2);
			seg_2.update((v_lis[i][j]+1)>>1,n>>1,-2);
		}
		for(int j=0;j<(int)v_lis[i].size();j++){
			int pos=v_lis[i][j];
			int pos_1_min=seg_1.query_min(pos>>1,(n-1)>>1);
			int pos_1_max=seg_1.query_max(0,(pos>>1)-1);
			int pos_2_min=seg_2.query_min((pos+1)>>1,n>>1);
			int pos_2_max=seg_2.query_max(0,(pos-1)>>1);
			ans[pos]=std::max(ans[pos],std::max(
			std::max((pos_2_max-pos_2_min)>>1,(pos_1_max-pos_1_min)>>1)-1,\
			std::max((pos_2_max-pos_1_min-1)>>1,(pos_1_max-pos_2_min-1)>>1)));
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");;
	return 0;
}