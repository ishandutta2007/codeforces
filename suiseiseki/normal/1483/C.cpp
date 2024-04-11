#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=300001;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int n;
int h[Maxn+5],b[Maxn+5];
ll f[Maxn+5];
struct Segment_Node{
	ll val,lazy;
}seg[Maxn<<2|5];
void build(int root=1,int left=0,int right=n){
	seg[root].val=-Inf;
	seg[root].lazy=0;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
}
void update_tag(int root,ll a){
	seg[root].val+=a;
	seg[root].lazy+=a;
}
void push_down(int root){
	if(seg[root].lazy){
		update_tag(root<<1,seg[root].lazy);
		update_tag(root<<1|1,seg[root].lazy);
	}
}
void update_add(int l,int r,ll a,int root=1,int left=0,int right=n){
	if(l>right||r<left){
		return;
	}
	if(l<=left&&r>=right){
		update_tag(root,a);
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	update_add(l,r,a,root<<1,left,mid);
	update_add(l,r,a,root<<1|1,mid+1,right);
	seg[root].val=std::max(seg[root<<1].val,seg[root<<1|1].val);
}
void update_node(int x,ll a,int root=1,int left=0,int right=n){
	if(left==right){
		seg[root].val=a;
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
	seg[root].val=std::max(seg[root<<1].val,seg[root<<1|1].val);
}
ll query(int l,int r,int root=1,int left=0,int right=n){
	if(l>right||r<left){
		return -Inf;
	}
	if(l<=left&&r>=right){
		return seg[root].val;
	}
	int mid=(left+right)>>1;
	return std::max(query(l,r,root<<1,left,mid),query(l,r,root<<1|1,mid+1,right));
}
int st[Maxn+5],top;
int main(){
	scanf("%d",&n);
	h[0]=n+1;
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		f[i]=-Inf;
	}
	update_node(0,b[1]);
	st[0]=-1;
	st[++top]=0;
	for(int i=1;i<=n;i++){
		f[i]=query(0,i-1);
		update_node(i,f[i]+b[i+1]);
		if(i==n){
			continue;
		}
		while(top>0&&h[st[top]+1]>h[i+1]){
			update_add(st[top-1]+1,st[top],b[i+1]-b[st[top]+1]);
			top--;
		}
		st[++top]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}