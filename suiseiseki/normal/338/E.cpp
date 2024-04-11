#include <cstdio>
#include <algorithm>
using namespace std;
int b[150005];
int a[150005];
int f[600005],minv[600005];
int n,m,h;
int mn(int a,int b){
	return a<b?a:b;
}
int search(int x){
	int left,right,mid;
	left=1,right=m;
	while(left<right){
		mid=(left+right+1)>>1;
		if(x>=b[mid]){
			left=mid;
		}
		else{
			right=mid-1;
		}
	}
	return left;
}
void build(int root,int left,int right){
	f[root]=0;
	minv[root]=left-m-1;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
}
void pushdown(int root){
	if(f[root]){
		f[root<<1]+=f[root];
		f[root<<1|1]+=f[root];
		minv[root<<1]+=f[root];
		minv[root<<1|1]+=f[root];
		f[root]=0;
	}
}
void update(int root,int left,int right,int l,int r,int x){
	if(l<=left&&r>=right){
		minv[root]+=x;
		f[root]+=x;
		return;
	}
	pushdown(root);
	int mid=(left+right)>>1;
	if(l<=mid){
		update(root<<1,left,mid,l,r,x);
	}
	if(r>mid){
		update(root<<1|1,mid+1,right,l,r,x);
	}
	minv[root]=mn(minv[root<<1],minv[root<<1|1]);
}
int main(){
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		b[i]=h-b[i];
	}
	sort(b+1,b+1+m);
	build(1,1,m);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i>m&&a[i-m]>=b[1]){
			update(1,1,m,1,search(a[i-m]),-1);
		}
		if(a[i]>=b[1]){
			update(1,1,m,1,search(a[i]),1);
		}
		if(i>=m&&minv[1]>=0){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}