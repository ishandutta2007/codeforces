#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 200000
struct Segment{
	int left,right;
	int id;
	friend bool operator <(Segment p,Segment q){
		return p.right<q.right;
	}
}a[Maxn+5];
bool cmp(Segment p,Segment q){
	return p.left<q.left;
}
int ans[Maxn+5],ans_len;
int k,n;
multiset<Segment> st;
struct Segment_Node{
	int left,right;
	int maxn,lazy;
}seg[Maxn<<2|5];
int mx(int a,int b){
	return a>b?a:b;
}
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	seg[root].maxn=seg[root].lazy=0;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
}
void push_down(int root){
	if(seg[root].lazy==0){
		return;
	}
	seg[root<<1].lazy+=seg[root].lazy;
	seg[root<<1].maxn+=seg[root].lazy;
	seg[root<<1|1].lazy+=seg[root].lazy;
	seg[root<<1|1].maxn+=seg[root].lazy;
	seg[root].lazy=0;
}
void update(int root,int left,int right,int a){
	if(seg[root].left==left&&seg[root].right==right){
		seg[root].maxn+=a;
		seg[root].lazy+=a;
		return;
	}
	push_down(root);
	root<<=1;
	if(left<=seg[root].right){
		if(right<=seg[root].right){
			update(root,left,right,a);
		}
		else{
			update(root,left,seg[root].right,a);
		}
	}
	root|=1;
	if(right>=seg[root].left){
		if(left>=seg[root].left){
			update(root,left,right,a);
		}
		else{
			update(root,seg[root].left,right,a);
		}
	}
	root>>=1;
	seg[root].maxn=mx(seg[root<<1].maxn,seg[root<<1|1].maxn);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].left,&a[i].right);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	build(1,1,Maxn);
	multiset<Segment>::iterator it;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&(st.begin()->right)<a[i].left){
			st.erase(st.begin());
		}
		update(1,a[i].left,a[i].right,1);
		st.insert(a[i]);
		while(seg[1].maxn>k){
			it=st.end();
			it--;
			ans[++ans_len]=(it->id);
			update(1,(it->left),(it->right),-1);
			st.erase(it);
		}
	}
	printf("%d\n",ans_len);
	for(int i=1;i<=ans_len;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}