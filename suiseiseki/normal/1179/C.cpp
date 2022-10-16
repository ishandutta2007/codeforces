#include <cstdio>
#define Maxn 300000
#define Maxm 1000000
#define ll long long
#define Inf 0x3f3f3f3f
int a[Maxn+5],b[Maxn+5];
int num[Maxm+5];
int n,m;
struct Segment_Node{
	int left,right;
	int minn,lazy;
}seg[Maxm<<2|5];
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	seg[root].minn=Inf;
	seg[root].lazy=0;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
}
int mn(int a,int b){
	return a<b?a:b;
}
void push_down(int root){
	if(seg[root].lazy==0){
		return;
	}
	seg[root<<1].minn+=seg[root].lazy;
	seg[root<<1].lazy+=seg[root].lazy;
	seg[root<<1|1].minn+=seg[root].lazy;
	seg[root<<1|1].lazy+=seg[root].lazy;
	seg[root].lazy=0;
}
void update(int root,int left,int right,int x){
	if(seg[root].left==left&&seg[root].right==right){
		seg[root].minn+=x;
		seg[root].lazy+=x;
		return;
	}
	push_down(root);
	root<<=1;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			update(root,left,right,x);
		}
		else{
			update(root,left,seg[root].right,x);
		}
	}
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			update(root,left,right,x);
		}
		else{
			update(root,seg[root].left,right,x);
		}
	}
	root>>=1;
	seg[root].minn=mn(seg[root<<1].minn,seg[root<<1|1].minn);
}
int query(int root){
	if(seg[root].minn>=0){
		return -1;
	}
	if(seg[root].left==seg[root].right){
		return seg[root].left;
	}
	push_down(root);
	root<<=1;
	root|=1;
	if(seg[root].minn<0){
		return query(root);
	}
	root^=1;
	return query(root);
}
int main(){
	scanf("%d%d",&n,&m);
	build(1,1,Maxm);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(num[a[i]]==0){
			update(1,a[i],a[i],-Inf);
		}
		num[a[i]]++;
		update(1,1,a[i],-1);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		update(1,1,b[i],1);
	}
	int q;
	scanf("%d",&q);
	int op,x,y;
	while(q--){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			update(1,1,a[x],1);
			num[a[x]]--;
			if(num[a[x]]==0){
				update(1,a[x],a[x],Inf);
			}
			a[x]=y;
			if(num[a[x]]==0){
				update(1,a[x],a[x],-Inf);
			}
			num[a[x]]++;
			update(1,1,a[x],-1);
		}
		else{
			update(1,1,b[x],-1);
			b[x]=y;
			update(1,1,b[x],1);
		}
		printf("%d\n",query(1));
	}
	return 0;
}