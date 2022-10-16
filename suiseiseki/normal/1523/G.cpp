#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=50000;
const int Maxm=100000;
const int Inf=0x3f3f3f3f;
int n,m;
struct Segment{
	int l,r;
}a[Maxm+5];
std::vector<int> lis[Maxn+5];
struct Semgent_Node{
	int lson,rson;
	int minn;
}seg[Maxn*17*17+5];
int id_tot;
void seg_insert(int &root,int x,int v,int left=1,int right=n){
	if(root==0){
		root=++id_tot;
		seg[root].minn=Inf;
	}
	seg[root].minn=std::min(seg[root].minn,v);
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		seg_insert(seg[root].lson,x,v,left,mid);
	}
	else{
		seg_insert(seg[root].rson,x,v,mid+1,right);
	}
}
int seg_query(int root,int l,int r,int left=1,int right=n){
	if(l>right||r<left||root==0){
		return Inf;
	}
	if(l<=left&&r>=right){
		return seg[root].minn;
	}
	int mid=(left+right)>>1;
	return std::min(seg_query(seg[root].lson,l,r,left,mid),seg_query(seg[root].rson,l,r,mid+1,right));
}
int f_root[Maxn+5];
void insert(int l,int r,int v){
	for(int i=r;i<=n;i+=(i&(-i))){
		seg_insert(f_root[i],l,v);
	}
}
int query(int l,int r){
	int ans=Inf;
	for(int i=r;i>0;i-=(i&(-i))){
		ans=std::min(ans,seg_query(f_root[i],l,r));
	}
	return ans;
}
int solve(int l,int r){
	if(l>r){
		return 0;
	}
	int id=query(l,r);
	if(id>=Inf){
		return 0;
	}
	int ans=a[id].r-a[id].l+1;
	return ans+solve(l,a[id].l-1)+solve(a[id].r+1,r);
}
int ans[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
		lis[a[i].r-a[i].l+1].push_back(i);
	}
	for(int i=n;i>0;i--){
		for(int j=0;j<(int)lis[i].size();j++){
			insert(a[lis[i][j]].l,a[lis[i][j]].r,lis[i][j]);
		}
		ans[i]=solve(1,n);
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}