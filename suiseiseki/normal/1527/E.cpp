#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=35000;
const int Maxk=100;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int n,k;
struct Segment_Tree{
	struct Segment_Node{
		ll lazy,val;
	}seg[Maxn<<2|5];
	void build(int root=1,int left=0,int right=n){
		seg[root].lazy=0;
		seg[root].val=Inf;
		if(left==right){
			return;
		}
		int mid=(left+right)>>1;
		build(root<<1,left,mid);
		build(root<<1|1,mid+1,right);
	}
	void update_tag(int root,ll a){
		seg[root].lazy+=a;
		seg[root].val+=a;
	}
	void push_down(int root){
		if(seg[root].lazy){
			update_tag(root<<1,seg[root].lazy);
			update_tag(root<<1|1,seg[root].lazy);
			seg[root].lazy=0;
		}
	}
	void push_up(int root){
		seg[root].val=std::min(seg[root<<1].val,seg[root<<1|1].val);
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
		push_up(root);
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
		push_up(root);
	}
	ll query(int l,int r,int root=1,int left=0,int right=n){
		if(l>right||r<left){
			return Inf;
		}
		if(l<=left&&r>=right){
			return seg[root].val;
		}
		push_down(root);
		int mid=(left+right)>>1;
		return std::min(query(l,r,root<<1,left,mid),query(l,r,root<<1|1,mid+1,right));
	}
}seg[Maxk+5];
ll f[Maxn+5][Maxk+5];
int a[Maxn+5];
int lst[Maxn+5];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			f[i][j]=Inf;
		}
	}
	f[0][0]=0;
	for(int i=0;i<=k;i++){
		seg[i].build();
	}
	seg[0].update_node(0,0);
	for(int i=1;i<=n;i++){
		if(lst[a[i]]>0){
			for(int j=0;j<=k;j++){
				seg[j].update_add(0,lst[a[i]]-1,i-lst[a[i]]);
			}
		}
		lst[a[i]]=i;
		for(int j=1;j<=k;j++){
			f[i][j]=seg[j-1].query(0,i-1);
			seg[j].update_node(i,f[i][j]);
		}
	}
	ll ans=Inf;
	for(int i=0;i<=k;i++){
		ans=std::min(ans,f[n][i]);
	}
	printf("%lld\n",ans);
	return 0;
}