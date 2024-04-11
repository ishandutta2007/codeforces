#include <cstdio>
#define Maxn 200000
int a[Maxn+5];
int visit[Maxn+5];
struct Seg_Node{
	int left,right;
	int minn;
}seg[Maxn<<2|5];
int mn(int a,int b){
	return a<b?a:b;
}
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	if(left==right){
		seg[root].minn=a[left];
		if(a[left]==0){
			seg[root].minn=(1<<30);
		}
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	seg[root].minn=mn(seg[root<<1].minn,seg[root<<1|1].minn);
}
int query(int root,int left,int right){
	if(left==seg[root].left&&right==seg[root].right){
		return seg[root].minn;
	}
	int ans=(1<<30);
	root<<=1;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			ans=mn(ans,query(root,left,right));
		}
		else{
			ans=mn(ans,query(root,left,seg[root].right));
		}
	}
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			ans=mn(ans,query(root,left,right));
		}
		else{
			ans=mn(ans,query(root,seg[root].left,right));
		}
	}
	return ans;
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	bool h_m=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==q){
			h_m=1;
		}
		if(a[i]>q){
			puts("NO");
			return 0;
		}
	}
	if(!h_m){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				a[i]=q;
				h_m=1;
				break;
			}
			if(i==n){
				puts("NO");
				return 0;
			}
		}
	}
	build(1,1,n);
	visit[a[1]]=1;
	for(int i=2;i<=n;i++){
		if(a[i]==0){
			continue;
		}
		if(visit[a[i]]==0){
			visit[a[i]]=i;
			continue;
		}
		if(query(1,visit[a[i]],i)<a[i]){
			puts("NO");
			return 0;
		}
	}
	if(a[1]==0){
		for(int i=2;i<=n;i++){
			if(a[i]!=0){
				a[1]=a[i];
				break;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(a[i]==0){
			a[i]=a[i-1];
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}