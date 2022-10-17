#include <cstdio>
#include <vector>
using namespace std;
#define Maxn 100000
struct Segment_Node{
	int left,right;
	int maxn,minn;
	int lazy_tag;
}seg[Maxn<<2|5];
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int a[Maxn+5];
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	seg[root].lazy_tag=0;
	if(left==right){
		seg[root].maxn=a[left];
		seg[root].minn=a[left];
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	seg[root].maxn=mx(seg[root<<1].maxn,seg[root<<1|1].maxn);
	seg[root].minn=mn(seg[root<<1].minn,seg[root<<1|1].minn);
}
void push_down(int root){
	seg[root<<1].lazy_tag+=seg[root].lazy_tag;
	seg[root<<1|1].lazy_tag+=seg[root].lazy_tag;
	seg[root<<1].maxn+=seg[root].lazy_tag;
	seg[root<<1].minn+=seg[root].lazy_tag;
	seg[root<<1|1].maxn+=seg[root].lazy_tag;
	seg[root<<1|1].minn+=seg[root].lazy_tag;
	seg[root].lazy_tag=0;
}
void update(int root,int left,int right,int x){
	if(seg[root].left==left&&seg[root].right==right){
		seg[root].lazy_tag+=x;
		seg[root].maxn+=x;
		seg[root].minn+=x;
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
	seg[root].maxn=mx(seg[root<<1].maxn,seg[root<<1|1].maxn);
	seg[root].minn=mn(seg[root<<1].minn,seg[root<<1|1].minn);
}
int query_max(int root,int left,int right){
	if(seg[root].left==left&&seg[root].right==right){
		return seg[root].maxn;
	}
	push_down(root);
	root<<=1;
	int ans;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			return query_max(root,left,right);
		}
		else{
			ans=query_max(root,left,seg[root].right);
		}
	}
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			return query_max(root,left,right);
		}
		else{
			ans=mx(ans,query_max(root,seg[root].left,right));
		}
	}
	return ans;
}
int query_min(int root,int left,int right){
	if(seg[root].left==left&&seg[root].right==right){
		return seg[root].minn;
	}
	push_down(root);
	root<<=1;
	int ans;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			return query_min(root,left,right);
		}
		else{
			ans=query_min(root,left,seg[root].right);
		}
	}
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			return query_min(root,left,right);
		}
		else{
			ans=mn(ans,query_min(root,seg[root].left,right));
		}
	}
	return ans;
}
struct Segment{
	int left,right;
}se[305];
vector<int> _start[Maxn+5],_end[Maxn+5];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&se[i].left,&se[i].right);
		_start[se[i].left].push_back(i);
		_end[se[i].right].push_back(i);
	}
	int p=-1,ans=0;
	int now;
	build(1,1,n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)_end[i-1].size();j++){
			update(1,se[_end[i-1][j]].left,se[_end[i-1][j]].right,1);
		}
		for(int j=0;j<(int)_start[i].size();j++){
			update(1,se[_start[i][j]].left,se[_start[i][j]].right,-1);
		}
		now=query_max(1,1,n)-query_min(1,1,n);
		if(now>ans){
			ans=now;
			p=i;
		}
	}
	printf("%d\n",ans);
	int len=0;
	for(int i=1;i<=m;i++){
		if(se[i].left<=p&&p<=se[i].right){
			len++;
		}
	}
	printf("%d\n",len);
	for(int i=1;i<=m;i++){
		if(se[i].left<=p&&p<=se[i].right){
			printf("%d ",i);
		}
	}
	puts("");
	return 0;
}