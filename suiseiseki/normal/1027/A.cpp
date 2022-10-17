#include <cstdio>
char s[105];
int n;
bool ok(char a,char b){
	if(a==b){
		return 1;
	}
	if(a+1==b-1){
		return 1;
	}
	if(a-1==b+1){
		return 1;
	}
	return 0;
}
bool check(){
	int i=1,j=n;
	while(i<j){
		if(!ok(s[i],s[j])){
			return 0;
		}
		i++,j--;
	}
	return 1;
}
struct Segment_Node{
	int left,right;
	int sum;
	int lazy_tag;
}seg[(100000<<2)|5];
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	seg[root].lazy_tag=0;
	if(left==right){
		scanf("%d",&seg[root].sum);
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum;
}
void update(int root){
	if(root==0){
		return;
	}
	seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum;
	update(root>>1);
}
void push_down(int root){
	seg[root<<1].sum+=seg[root].lazy_tag*(seg[root<<1].right-seg[root<<1].left+1);
	seg[root<<1|1].sum+=seg[root].lazy_tag*(seg[root<<1|1].right-seg[root<<1|1].left+1);
	seg[root<<1].lazy_tag+=seg[root].lazy_tag;
	seg[root<<1|1].lazy_tag+=seg[root].lazy_tag;
	seg[root].lazy_tag=0;
}
void add(int root,int left,int right,int x){
	if(seg[root].left==left&&seg[root].right==right){
		seg[root].sum+=(seg[root].right-seg[root].left+1)*x;
		seg[root].lazy_tag+=x;
		return;
	}
	push_down(root);
	root<<=1;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			add(root,left,right,x);
		}
		else{
			add(root,left,seg[root].right,x);
		}
	}
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			add(root,left,right,x);
		}
		else{
			add(root,seg[root].left,right,x);
		}
	}
	root>>=1;
	seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum;
}
int query(int root,int left,int right){
	if(seg[root].left==left&&seg[root].right==right){
		return seg[root].sum;
	}
	int ans=0;
	root<<=1;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			ans+=query(root,left,right);
		}
		else{
			ans+=query(root,left,seg[root].right);
		}
	}
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			ans+=query(root,left,right);
		}
		else{
			ans+=query(root,seg[root].left,right);
		}
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",s+1);
		if(check()){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}