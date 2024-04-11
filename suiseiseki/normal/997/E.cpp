#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=120000;
int n,q;
int a[Maxn+5];
struct Question{
	int l,r;
	int id;
	friend bool operator <(Question a,Question b){
		return a.r<b.r;
	}
}qu[Maxn+5];
struct Segment_Node{
	int val_min,val_num;
	int lazy_val,lazy_all;
	ll all_num;
}seg[Maxn<<2|5];
void update_tag_val(int root,int x){
	seg[root].val_min+=x;
	seg[root].lazy_val+=x;
}
void update_tag_all(int root,int x){
	seg[root].lazy_all+=x;
	seg[root].all_num+=1ll*seg[root].val_num*x;
}
void push_down(int root){
	if(seg[root].lazy_val){
		update_tag_val(root<<1,seg[root].lazy_val);
		update_tag_val(root<<1|1,seg[root].lazy_val);
		seg[root].lazy_val=0;
	}
	if(seg[root].lazy_all){
		if(seg[root<<1].val_min==seg[root].val_min){
			update_tag_all(root<<1,seg[root].lazy_all);
		}
		if(seg[root<<1|1].val_min==seg[root].val_min){
			update_tag_all(root<<1|1,seg[root].lazy_all);
		}
		seg[root].lazy_all=0;
	}
}
void push_up(int root){
	seg[root].val_min=min(seg[root<<1].val_min,seg[root<<1|1].val_min);
	seg[root].val_num=0;
	if(seg[root].val_min==seg[root<<1].val_min){
		seg[root].val_num+=seg[root<<1].val_num;
	}
	if(seg[root].val_min==seg[root<<1|1].val_min){
		seg[root].val_num+=seg[root<<1|1].val_num;
	}
	seg[root].all_num=seg[root<<1].all_num+seg[root<<1|1].all_num;
}
void build(int root=1,int left=1,int right=n){
	seg[root].lazy_val=seg[root].lazy_all=0;
	seg[root].all_num=0;
	seg[root].val_min=left;
	seg[root].val_num=1;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	push_up(root);
}
void update(int l,int r,int a,int root=1,int left=1,int right=n){
	if(l>right||r<left||l>r){
		return;
	}
	if(l<=left&&r>=right){
		update_tag_val(root,a);
		return;
	}
	push_down(root);
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
		return seg[root].all_num;
	}
	push_down(root);
	int mid=(left+right)>>1;
	return query(l,r,root<<1,left,mid)+query(l,r,root<<1|1,mid+1,right);
}
ll ans[Maxn+5];
int st_max[Maxn+5],st_min[Maxn+5];
int st_max_top,st_min_top;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qu[i].l,&qu[i].r);
		qu[i].id=i;
	}
	sort(qu+1,qu+1+q);
	build();
	for(int i=1,pos=0;i<=q;i++){
		while(pos<qu[i].r){
			pos++;
			update_tag_val(1,-1);
			while(st_max_top>0&&a[st_max[st_max_top]]<a[pos]){
				update(st_max[st_max_top-1]+1,st_max[st_max_top],a[pos]-a[st_max[st_max_top]]);
				st_max_top--;
			}
			st_max[++st_max_top]=pos;
			while(st_min_top>0&&a[st_min[st_min_top]]>a[pos]){
				update(st_min[st_min_top-1]+1,st_min[st_min_top],a[st_min[st_min_top]]-a[pos]);
				st_min_top--;
			}
			st_min[++st_min_top]=pos;
			update_tag_all(1,1);
		}
		ans[qu[i].id]=query(qu[i].l,qu[i].r);
	}
	for(int i=1;i<=q;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}