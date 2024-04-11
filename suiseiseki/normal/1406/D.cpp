#include <cstdio>
template<typename Elem>
Elem max(Elem a,Elem b){
	return a>b?a:b;
}
typedef long long ll;
const int Maxn=100000;
int n;
int a[Maxn+5];
ll lazy[Maxn<<2|5];
void update(int l,int r,int a,int root=1,int left=1,int right=n){
	if(l>right||r<left){
		return;
	}
	if(l<=left&&r>=right){
		lazy[root]+=a;
		return;
	}
	int mid=(left+right)>>1;
	update(l,r,a,root<<1,left,mid);
	update(l,r,a,root<<1|1,mid+1,right);
}
ll query(int x,int root=1,int left=1,int right=n){
	if(left==right){
		return lazy[root]+a[left];
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		return query(x,root<<1,left,mid)+lazy[root];
	}
	return query(x,root<<1|1,mid+1,right)+lazy[root];
}
ll sum=0;
void change(int l,int r,int x){
	if(l>1){
		sum-=max(0ll,query(l)-query(l-1));
	}
	if(r<n){
		sum-=max(0ll,query(r+1)-query(r));
	}
	update(l,r,x);
	if(l>1){
		sum+=max(0ll,query(l)-query(l-1));
	}
	if(r<n){
		sum+=max(0ll,query(r+1)-query(r));
	}
}
ll find_ans(){
	return (sum+query(1)+1)>>1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			sum+=a[i]-a[i-1];
		}
	}
	printf("%lld\n",find_ans());
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		change(l,r,x);
		printf("%lld\n",find_ans());
	}
	return 0;
}