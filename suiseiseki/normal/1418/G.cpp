#include <cstdio>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
int max(int a,int b){
	return a>b?a:b;
}
typedef long long ll;
const int Maxn=500000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
int pos[Maxn+5];
int pre[Maxn+5];
int left[Maxn+5],right[Maxn+5];
struct Value{
	int maxn,num;
	Value(int _maxn=-Inf,int _num=0){
		maxn=_maxn;
		num=_num;
	}
};
struct Segment_Node{
	Value val;
	int lazy;
}seg[Maxn<<2|5];
void push_down(int root){
	if(seg[root].lazy==0){
		return;
	}
	seg[root<<1].val.maxn+=seg[root].lazy;
	seg[root<<1].lazy+=seg[root].lazy;
	seg[root<<1|1].val.maxn+=seg[root].lazy;
	seg[root<<1|1].lazy+=seg[root].lazy;
	seg[root].lazy=0;
}
Value push_up(Value u,Value v){
	Value ans;
	ans.maxn=max(u.maxn,v.maxn);
	ans.num=0;
	if(ans.maxn==u.maxn){
		ans.num+=u.num;
	}
	if(ans.maxn==v.maxn){
		ans.num+=v.num;
	}
	return ans;
}
void build(int root=1,int left=1,int right=n){
	if(left==right){
		seg[root].val.maxn=left;
		seg[root].val.num=1;
		seg[root].lazy=0;
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	seg[root].val=push_up(seg[root<<1].val,seg[root<<1|1].val);
}
void update(int l,int r,int a,int root=1,int left=1,int right=n){
	if(l>right||r<left){
		return;
	}
	if(l<=left&&r>=right){
		seg[root].lazy+=a;
		seg[root].val.maxn+=a;
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	update(l,r,a,root<<1,left,mid);
	update(l,r,a,root<<1|1,mid+1,right);
	seg[root].val=push_up(seg[root<<1].val,seg[root<<1|1].val);
}
Value query(int l,int r,int root=1,int left=1,int right=n){
	if(l>right||r<left){
		return Value(-Inf,1);
	}
	if(l<=left&&r>=right){
		return seg[root].val;
	}
	push_down(root);
	int mid=(left+right)>>1;
	return push_up(query(l,r,root<<1,left,mid),query(l,r,root<<1|1,mid+1,right));
}
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		pre[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		left[i]=pre[pre[pre[i]]]+1;
		right[i]=pre[pre[i]];
	}
	build();
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(right[pre[i]]){
			update(left[pre[i]],right[pre[i]],-3);
		}
		if(right[i]){
			update(left[i],right[i],3);
		}
		Value now=query(1,i);
		if(now.maxn==i+1){
			ans+=now.num;
		}
	}
	printf("%lld\n",ans);
	return 0;
}