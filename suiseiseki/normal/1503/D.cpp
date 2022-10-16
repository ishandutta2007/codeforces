#include <cstdio>
#include <algorithm>
const int Maxn=200000;
const int Inf=0x3f3f3f3f;
int n;
struct Node{
	int a,b;
	bool flag;
}a[Maxn+5];
bool cmp_Node_a(Node a,Node b){
	return a.a<b.a;
}
struct Segment_Tree{
	struct Segment_Node{
		int minn;
		int lazy;
	}seg[Maxn<<2|5];
	void build(int root=1,int left=1,int right=n+1){
		if(left==right){
			seg[root].minn=Inf;
			seg[root].lazy=0;
			return;
		}
		int mid=(left+right)>>1;
		build(root<<1,left,mid);
		build(root<<1|1,mid+1,right);
	}
	void update_tag(int root,int a){
		seg[root].minn=std::min(Inf,seg[root].minn+a);
		seg[root].lazy=std::min(Inf,seg[root].lazy+a);
	}
	void push_down(int root){
		if(seg[root].lazy==0){
			return;
		}
		update_tag(root<<1,seg[root].lazy);
		update_tag(root<<1|1,seg[root].lazy);
		seg[root].lazy=0;
	}
	void push_up(int root){
		seg[root].minn=std::min(seg[root<<1].minn,seg[root<<1|1].minn);
	}
	void update_sum(int l,int r,int a,int root=1,int left=1,int right=n+1){
		if(l>right||r<left){
			return;
		}
		if(l<=left&&r>=right){
			update_tag(root,a);
			return;
		}
		push_down(root);
		int mid=(left+right)>>1;
		update_sum(l,r,a,root<<1,left,mid);
		update_sum(l,r,a,root<<1|1,mid+1,right);
		push_up(root);
	}
	void update_node(int x,int a,int root=1,int left=1,int right=n+1){
		if(left==right){
			seg[root].minn=std::min(seg[root].minn,a);
			return;
		}
		push_down(root);
		int mid=(left+right)>>1;
		if(x<=mid){
			update_node(x,a,root<<1,left,mid);
		}
		else{
			update_node(x,a,root<<1|1,mid+1,right);
		}
		push_up(root);
	}
	int query(int l,int r,int root=1,int left=1,int right=n+1){
		if(l>right||r<left){
			return Inf;
		}
		if(l<=left&&r>=right){
			return seg[root].minn;
		}
		push_down(root);
		int mid=(left+right)>>1;
		return std::min(query(l,r,root<<1,left,mid),query(l,r,root<<1|1,mid+1,right));
	}
}seg[2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].a,&a[i].b);
		if(a[i].a<=n&&a[i].b<=n){
			puts("-1");
			return 0;
		}
		if(a[i].a>a[i].b){
			std::swap(a[i].a,a[i].b);
			a[i].flag=1;
		}
		else{
			a[i].flag=0;
		}
		a[i].b-=n;
	}
	std::sort(a+1,a+1+n,cmp_Node_a);
	seg[0].build(),seg[1].build();
	seg[0].update_node(n+1,a[1].flag);
	seg[1].update_node(n+1,a[1].flag^1);
	int min_1=a[1].b,min_2=n+1;
	for(int i=2;i<=n;i++){
		if(a[i].b>min_2){
			puts("-1");
			return 0;
		}
		else if(a[i].b>min_1){
			min_2=a[i].b;
		}
		else{
			min_1=a[i].b;
		}
		int tmp_0=seg[0].query(a[i].b,n+1)+(a[i].flag^1),tmp_1=seg[1].query(a[i].b,n+1)+a[i].flag;
		if(a[i].b<a[i-1].b){
			seg[0].update_sum(1,n+1,a[i].flag);
			seg[1].update_sum(1,n+1,a[i].flag^1);
			seg[0].update_node(a[i-1].b,tmp_1);
			seg[1].update_node(a[i-1].b,tmp_0);
		}
		else{
			seg[0].update_sum(1,n+1,Inf);
			seg[1].update_sum(1,n+1,Inf);
			seg[0].update_node(a[i-1].b,tmp_1);
			seg[1].update_node(a[i-1].b,tmp_0);
		}
	}
	printf("%d\n",std::min(seg[0].query(1,n+1),seg[1].query(1,n+1)));
	return 0;
}