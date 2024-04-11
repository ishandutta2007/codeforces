#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn=200000;
typedef long long ll;
int p[Maxn+5],a[Maxn+5];
int rnk[Maxn+5];
ll sum[Maxn+5];
int n;
struct Segment_Node{
	int left,right;
	ll lazy;
	ll minn;
}seg[Maxn<<2|5];
ll mn(ll a,ll b){
	return a<b?a:b;
}
void push_down(int root){
	if(seg[root].lazy){
		seg[root<<1].lazy+=seg[root].lazy;
		seg[root<<1].minn+=seg[root].lazy;
		seg[root<<1|1].lazy+=seg[root].lazy;
		seg[root<<1|1].minn+=seg[root].lazy;
		seg[root].lazy=0;
	}
}
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	seg[root].lazy=0;
	if(left==right){
		seg[root].minn=sum[left];
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	seg[root].minn=mn(seg[root<<1].minn,seg[root<<1|1].minn);
}
void update(int root,int left,int right,int val){
	if(seg[root].left==left&&seg[root].right==right){
		seg[root].lazy+=val;
		seg[root].minn+=val;
		return;
	}
	push_down(root);
	root<<=1;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			update(root,left,right,val);
		}
		else{
			update(root,left,seg[root].right,val);
		}
	}
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			update(root,left,right,val);
		}
		else{
			update(root,seg[root].left,right,val);
		}
	}
	root>>=1;
	seg[root].minn=mn(seg[root<<1].minn,seg[root<<1|1].minn);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		rnk[p[i]]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	build(1,1,n-1);
	ll ans=seg[1].minn;
	for(int i=1;i<=n;i++){
		if(rnk[i]>1){
			update(1,1,rnk[i]-1,a[rnk[i]]);
		}
		if(rnk[i]<n){
			update(1,rnk[i],n-1,-a[rnk[i]]);
		}
		ans=mn(ans,seg[1].minn);
	}
	cout<<ans<<endl;
	return 0;
}