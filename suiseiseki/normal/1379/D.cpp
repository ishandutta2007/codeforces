#include <cstdio>
const int Maxn=100000;
const int Inf=1000000000;
int n,h,m,k;
struct Train{
	int h,m;
}a[Maxn+5];
struct Segment_Node{
	int lson,rson;
	int num;
}seg[Maxn*30+5];
int id_tot;
int Root;
void insert(int x,int a,int &root=Root,int left=1,int right=Inf){
	if(root==0){
		root=++id_tot;
	}
	seg[root].num+=a;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		insert(x,a,seg[root].lson,left,mid);
	}
	else{
		insert(x,a,seg[root].rson,mid+1,right);
	}
}
int query(int l,int r,int root=Root,int left=1,int right=Inf){
	if(l>r){
		return 0;
	}
	if(root==0){
		return 0;
	}
	if(l>right||r<left){
		return 0;
	}
	if(l<=left&&r>=right){
		return seg[root].num;
	}
	int mid=(left+right)>>1;
	return query(l,r,seg[root].lson,left,mid)+query(l,r,seg[root].rson,mid+1,right);
}
int main(){
	scanf("%d%d%d%d",&n,&h,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].h,&a[i].m);
		a[i].m%=(m>>1);
		insert(a[i].m+1,1);
	}
	int ans=n+1,pos;
	for(int i=1;i<=n;i++){
		int left=a[i].m-k,right=a[i].m;
		int tmp;
		if(left<0){
			tmp=query(1,right+1-1)+query((m>>1)+left+1+1,(m>>1));
		}
		else{
			tmp=query(left+1+1,right+1-1);
		}
		if(tmp<ans){
			ans=tmp;
			pos=a[i].m;
		}
		left=a[i].m,right=a[i].m+k;
		if(right>=(m>>1)){
			tmp=query(left+1+1,(m>>1))+query(1,right-(m>>1)+1-1);
		}
		else{
			tmp=query(left+1+1,right+1-1);
		}
		if(tmp<ans){
			ans=tmp;
			pos=(a[i].m+k)%(m>>1);
		}
	}
	printf("%d %d\n",ans,pos);
	for(int i=1;i<=n;i++){
		if(pos-k>=0){
			if(a[i].m>pos-k&&a[i].m<pos){
				printf("%d ",i);
			}
		}
		else{
			if(a[i].m<pos||a[i].m>pos-k+(m>>1)){
				printf("%d ",i);
			}
		}
	}
	puts("");
	return 0;
}