#include <set>
#include <cstdio>
#include <algorithm>
const int Maxn=500000;
const int Inf=0x3f3f3f3f;
int n;
int p[Maxn+5],q[Maxn+5];
struct BIT{
	int f[Maxn+5];
	void init(){
		for(int i=1;i<=n;i++){
			f[i]=(i&(-i));
		}
	}
	void add(int x,int a){
		for(int i=x;i<=n;i+=(i&(-i))){
			f[i]+=a;
		}
	}
	int query(int x){
		int ans=0;
		for(int i=x;i>0;i-=(i&(-i))){
			ans+=f[i];
		}
		return ans;
	}
}t_x,t_y;
int query_c(int x){
	return t_x.query(x)-t_y.query(p[x]);
}
struct Semgent_Tree_1{
	struct Segment_Node{
		int mn_val,mn_pos;
		int lazy;
	}seg[Maxn<<2|5];
	void build(int root=1,int left=1,int right=n){
		seg[root].mn_val=Inf,seg[root].mn_pos=left;
		seg[root].lazy=0;
		if(left==right){
			return;
		}
		int mid=(left+right)/2;
		build(root<<1,left,mid),build(root<<1|1,mid+1,right);
	}
	void push_up(int root){
		seg[root].mn_val=std::min(seg[root<<1].mn_val,seg[root<<1|1].mn_val);
		seg[root].mn_pos=seg[root].mn_val==seg[root<<1].mn_val?seg[root<<1].mn_pos:seg[root<<1|1].mn_pos;
		seg[root].mn_val+=seg[root].lazy;
	}
	void modify(int l,int r,int v,int root=1,int left=1,int right=n){
		if(l>right||r<left){
			return;
		}
		if(l<=left&&r>=right){
			seg[root].mn_val+=v,seg[root].lazy+=v;
			return;
		}
		int mid=(left+right)/2;
		modify(l,r,v,root<<1,left,mid),modify(l,r,v,root<<1|1,mid+1,right);
		push_up(root);
	}
	void update(int x,int v,int root=1,int left=1,int right=n){
		if(left==right){
			seg[root].mn_val=v;
			return;
		}
		v-=seg[root].lazy;
		int mid=(left+right)/2;
		if(x<=mid){
			update(x,v,root<<1,left,mid);
		}
		else{
			update(x,v,root<<1|1,mid+1,right);
		}
		push_up(root);
	}
}seg_mx,seg_mn;
std::set<int> st_mx,st_mn;
namespace Segment_Tree_2{
	struct Segment_Node{
		int mn_val,mx_val;
	}seg[Maxn<<2|5];
	void push_up(int root){
		seg[root].mn_val=std::min(seg[root<<1].mn_val,seg[root<<1|1].mn_val);
		seg[root].mx_val=std::max(seg[root<<1].mx_val,seg[root<<1|1].mx_val);
	}
	void build(int root=1,int left=1,int right=n){
		if(left==right){
			if(left<p[left]){
				seg[root].mn_val=p[left],seg[root].mx_val=-Inf;
			}
			else{
				seg[root].mx_val=p[left],seg[root].mn_val=Inf;
			}
			return;
		}
		int mid=(left+right)/2;
		build(root<<1,left,mid),build(root<<1|1,mid+1,right);
		push_up(root);
	}
	void clear(int x,int root=1,int left=1,int right=n){
		if(left==right){
			seg[root].mn_val=Inf,seg[root].mx_val=-Inf;
			return;
		}
		int mid=(left+right)/2;
		if(x<=mid){
			clear(x,root<<1,left,mid);
		}
		else{
			clear(x,root<<1|1,mid+1,right);
		}
		push_up(root);
	}
	void update_mx(int l,int r,int &mx_val,int root=1,int left=1,int right=n){
		if(l>right||r<left){
			return;
		}
		if(seg[root].mx_val<mx_val){
			return;
		}
		if(left==right){
			if(!st_mx.insert(p[left]).second){
				return;
			}
			seg_mx.update(left,query_c(left));
			mx_val=p[left];
			return;
		}
		int mid=(left+right)/2;
		update_mx(l,r,mx_val,root<<1,left,mid),update_mx(l,r,mx_val,root<<1|1,mid+1,right);
	}
	void update_mn(int l,int r,int &mn_val,int root=1,int left=1,int right=n){
		if(l>right||r<left){
			return;
		}
		if(seg[root].mn_val>mn_val){
			return;
		}
		if(left==right){
			if(!st_mn.insert(p[left]).second){
				return;
			}
			seg_mn.update(left,-query_c(left));
			mn_val=p[left];
			return;
		}
		int mid=(left+right)/2;
		update_mn(l,r,mn_val,root<<1|1,mid+1,right),update_mn(l,r,mn_val,root<<1,left,mid);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		q[p[i]]=i;
	}
	t_x.init(),t_y.init(),seg_mx.build(),seg_mn.build(),Segment_Tree_2::build();
	int tmp_val=0;
	Segment_Tree_2::update_mx(1,n,tmp_val);
	tmp_val=n+1;
	Segment_Tree_2::update_mn(1,n,tmp_val);
	int ans=0;
	for(int i=1;i<=n;i++){
		int pos;
		if(seg_mx.seg[1].mn_val<seg_mn.seg[1].mn_val){
			ans=std::max(ans,seg_mx.seg[1].mn_val);
			pos=seg_mx.seg[1].mn_pos;
			t_x.add(pos,-1),t_y.add(p[pos],-1);
			std::set<int>::iterator it=st_mn.upper_bound(p[pos]);
			if(it!=st_mn.end()){
				if(q[*it]<pos){
					seg_mn.modify(q[*it],pos-1,-1);
				}
			}
			Segment_Tree_2::clear(pos);
			it=st_mx.erase(st_mx.find(p[pos]));
			int nxt=(it==st_mx.end()?n:q[*it]-1);
			tmp_val=(it==st_mx.begin()?0:*(--it));
			Segment_Tree_2::update_mx(pos+1,nxt,tmp_val);
		}
		else{
			ans=std::max(ans,seg_mn.seg[1].mn_val);
			pos=seg_mn.seg[1].mn_pos;
			t_x.add(pos,-1),t_y.add(p[pos],-1);
			std::set<int>::iterator it=st_mx.upper_bound(p[pos]);
			if(it!=st_mx.begin()){
				it--;
				if(q[*it]>pos){
					seg_mx.modify(pos+1,q[*it],-1);
				}
			}
			Segment_Tree_2::clear(pos);
			it=st_mn.erase(st_mn.find(p[pos]));
			tmp_val=(it==st_mn.end()?n+1:*it);
			int lst=(it==st_mn.begin()?0:q[*(--it)]+1);
			Segment_Tree_2::update_mn(lst,pos-1,tmp_val);
		}
		seg_mx.update(pos,Inf),seg_mn.update(pos,Inf);
	}
	printf("%d\n",ans);
	return 0;
}