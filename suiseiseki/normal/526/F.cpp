#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
typedef long long ll;
const int Maxn=300000;
int n;
int a[Maxn+5];
int st_1[Maxn+5],top_1;
int st_2[Maxn+5],top_2;
struct Segment_Node{
	int lazy;
	int minn,num;
}seg[Maxn<<2|5];
void push_up(int root){
	seg[root].minn=min(seg[root<<1].minn,seg[root<<1|1].minn);
	seg[root].num=0;
	if(seg[root].minn==seg[root<<1].minn){
		seg[root].num+=seg[root<<1].num;
	}
	if(seg[root].minn==seg[root<<1|1].minn){
		seg[root].num+=seg[root<<1|1].num;
	}
}
void push_down(int root){
	if(seg[root].lazy==0){
		return;
	}
	seg[root<<1].lazy+=seg[root].lazy;
	seg[root<<1].minn+=seg[root].lazy;
	seg[root<<1|1].lazy+=seg[root].lazy;
	seg[root<<1|1].minn+=seg[root].lazy;
	seg[root].lazy=0;
}
void build(int root=1,int left=1,int right=n){
	seg[root].lazy=0;
	if(left==right){
		seg[root].minn=left;
		seg[root].num=1;
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	push_up(root);
}
void update(int l,int r,int a,int root=1,int left=1,int right=n){
	if(l>right||r<left){
		return;
	}
	if(l<=left&&r>=right){
		seg[root].lazy+=a;
		seg[root].minn+=a;
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	update(l,r,a,root<<1,left,mid);
	update(l,r,a,root<<1|1,mid+1,right);
	push_up(root);
}
int query(int l,int r,int root=1,int left=1,int right=n){
	if(l>right||r<left){
		return 0;
	}
	if(l<=left&&r>=right){
		return seg[root].minn==0?seg[root].num:0;
	}
	push_down(root);
	int mid=(left+right)>>1;
	return query(l,r,root<<1,left,mid)+query(l,r,root<<1|1,mid+1,right);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x]=y;
	}
	build();
	ll ans=0;
	for(int i=1;i<=n;i++){
		update(1,n,-1);
		while(top_1>0&&a[st_1[top_1]]<a[i]){
			update(st_1[top_1-1]+1,st_1[top_1],a[i]-a[st_1[top_1]]);
			top_1--;
		}
		while(top_2>0&&a[st_2[top_2]]>a[i]){
			update(st_2[top_2-1]+1,st_2[top_2],a[st_2[top_2]]-a[i]);
			top_2--;
		}
		ans+=query(1,i);
		st_1[++top_1]=i;
		st_2[++top_2]=i;
	}
	printf("%lld\n",ans);
	return 0;
}