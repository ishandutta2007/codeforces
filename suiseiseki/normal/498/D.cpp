#include <cstdio>
#define ll long long
#define tmax 60
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
int tree[400005][tmax];
int b[100005];
void build(int a,int l,int r){
	if(l==r){
		for(int i=0;i<tmax;i++){
			if(i%b[l]){
				tree[a][i]=i+1;
			}
			else{
				tree[a][i]=i+2;
			}
		}
		return;
	}
	int mid=(l+r)>>1;
	build(a<<1,l,mid);
	build(a<<1|1,mid+1,r);
	for(int i=0;i<tmax;i++){
		tree[a][i]=tree[a<<1|1][tree[a<<1][i]%tmax]+tree[a<<1][i]/tmax*tmax;
	}
	return;
}
int check(int a,int l,int r,int l1,int r1,int t){
	if(l>r1||r<l1){
		return t;
	}
	if(l1<=l&&r<=r1){
		return tree[a][t%tmax]+t/tmax*tmax;
	}
	int mid=(l+r)>>1;
	int k1=check(a<<1,l,mid,l1,r1,t);
	int k2=check(a<<1|1,mid+1,r,l1,r1,k1);
	return k2;
}
void gai(int a,int l,int r,int x,int y){
	if(x<l||r<x){
		return;
	}
	if(l==x&&x==r){
		b[l]=y;
		for(int i=0;i<tmax;i++){
			if(i%b[l]){
				tree[a][i]=i+1;
			}
			else{
				tree[a][i]=i+2;
			}
		}
		return;
	}
	int mid=(l+r)>>1;
	gai(a<<1,l,mid,x,y);
	gai(a<<1|1,mid+1,r,x,y);
	for(int i=0;i<tmax;i++){
		tree[a][i]=tree[a<<1|1][tree[a<<1][i]%tmax]+tree[(a<<1)][i]/tmax*tmax;
	}
	return;
}
int main(){
	int n;
	read(n);
	for(int i=1;i<=n;i++){
		read(b[i]);
	}
	build(1,1,n);
	int q;
	read(q);
	char qu[3];
	for(int i=1;i<=q;i++){
		scanf("%s",qu);
		int x,y;
		read(x),read(y);
		if((*qu)=='A'){
			printf("%d\n",check(1,1,n,x,y-1,0));
		}
		else{
			gai(1,1,n,x,y);
		}
	}
	return 0;
}