#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100000;
int m,n;
int a[Maxn+5],p[Maxn+5];
int x[Maxn+5],k[Maxn+5];
int e_pos[Maxn+5],steps[Maxn+5];
int Root[Maxn+5];
struct Segment_Node{
	int lson,rson;
	int val;
}seg[Maxn*25+5];
int id_tot;
void build(int &root,int left=1,int right=n){
	root=++id_tot;
	seg[root].val=right-left+1;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	build(seg[root].lson,left,mid);
	build(seg[root].rson,mid+1,right);
}
int find_kth(int root,int k,int left=1,int right=n){
	if(left==right){
		return left;
	}
	int mid=(left+right)>>1;
	if(k<=seg[seg[root].lson].val){
		return find_kth(seg[root].lson,k,left,mid);
	}
	return find_kth(seg[root].rson,k-seg[seg[root].lson].val,mid+1,right);
}
void update(int &root,int last,int x,int a,int left=1,int right=n){
	root=++id_tot;
	seg[root]=seg[last];
	seg[root].val+=a;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		update(seg[root].lson,seg[last].lson,x,a,left,mid);
	}
	else{
		update(seg[root].rson,seg[last].rson,x,a,mid+1,right);
	}
}
int query(int root,int x,int left=1,int right=n){
	if(left==right){
		return seg[root].val;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		return query(seg[root].lson,x,left,mid);
	}
	return seg[seg[root].lson].val+query(seg[root].rson,x,mid+1,right);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	e_pos[0]=a[1]-1;
	steps[0]=0;
	for(int i=1;i<n;i++){
		int delta=(a[i+1]-e_pos[i-1]-1)/i;
		e_pos[i]=e_pos[i-1]+i*delta;
		steps[i]=steps[i-1]+delta;
	}
	for(int i=2;i<=n;i++){
		p[i]=(p[i-1]+a[i]-a[i-1])%(i-1);
	}
	build(Root[n]);
	for(int i=n;i>0;i--){
		p[i]=find_kth(Root[i],p[i]+1);
		update(Root[i-1],Root[i],p[i],-1);
	}
	for(int t=1;t<=m;t++){
		int x,k;
		scanf("%d%d",&x,&k);
		if(x<a[1]){
			printf("%d\n",x);
			continue;
		}
		int bel=lower_bound(e_pos+1,e_pos+n,x)-e_pos;
		k+=steps[bel-1]+(x-e_pos[bel-1]-1)/bel+1;
		int ord=(x-e_pos[bel-1]-1)%bel+1;
		ord=find_kth(Root[bel],ord);
		bel=lower_bound(steps+1,steps+n,k)-steps;
		printf("%lld\n",e_pos[bel-1]+1ll*(k-steps[bel-1]-1)*bel+query(Root[bel],ord));
	}
	return 0;
}