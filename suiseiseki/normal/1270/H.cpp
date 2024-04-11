#include <cstdio>
#include <algorithm>
const int Maxn=1000000;
const int Inf=0x3f3f3f3f;
int n,q;
int a[Maxn+5];
struct Segment_Node{
	int minn;
	int num;
	int lazy;
}seg[(Maxn+1)<<2|5];
void build(int root=1,int left=0,int right=Maxn){
	seg[root].minn=Inf;
	seg[root].num=right-left+1;
	seg[root].lazy=0;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
}
void update_tag(int root,int a){
	seg[root].minn+=a;
	seg[root].lazy+=a;
}
void push_down(int root){
	if(seg[root].lazy){
		update_tag(root<<1,seg[root].lazy);
		update_tag(root<<1|1,seg[root].lazy);
		seg[root].lazy=0;
	}
}
void push_up(int root){
	seg[root].minn=std::min(seg[root<<1].minn,seg[root<<1|1].minn);
	seg[root].num=0;
	if(seg[root].minn==seg[root<<1].minn){
		seg[root].num+=seg[root<<1].num;
	}
	if(seg[root].minn==seg[root<<1|1].minn){
		seg[root].num+=seg[root<<1|1].num;
	}
}
void update(int l,int r,int a,int root=1,int left=0,int right=Maxn){
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
	push_up(root);
}
int main(){
	build();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		update(a[i],a[i],-Inf);
	}
	a[0]=Maxn+1,a[n+1]=0;
	for(int i=0;i<=n;i++){
		update(std::min(a[i],a[i+1]),std::max(a[i],a[i+1])-1,1);
	}
	for(int t=1;t<=q;t++){
		int p,x;
		scanf("%d%d",&p,&x);
		auto calc=[&](int x,int v)->void{
			update(std::min(a[x],a[x+1]),std::max(a[x],a[x+1])-1,v);
		};
		update(a[p],a[p],Inf);
		update(x,x,-Inf);
		calc(p-1,-1),calc(p,-1);
		a[p]=x;
		calc(p-1,1),calc(p,1);
		int ans=(seg[1].minn==1?seg[1].num:0);
		printf("%d\n",ans);
	}
	return 0;
}
//