#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 200000
#define ll long long
struct Segment_Node{
	ll minn;
	ll lazy;
	int left,right;
}seg[Maxn<<2|5];
int a[Maxn+5];
ll mn(ll a,ll b){
	return a<b?a:b;
}
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	seg[root].lazy=0;
	if(left==right){
		seg[root].minn=a[left];
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	seg[root].minn=mn(seg[root<<1].minn,seg[root<<1|1].minn);
}
void push_down(int root){
	seg[root<<1].lazy+=seg[root].lazy;
	seg[root<<1|1].lazy+=seg[root].lazy;
	seg[root<<1].minn+=seg[root].lazy;
	seg[root<<1|1].minn+=seg[root].lazy;
	seg[root].lazy=0;
}
void add(int root,int left,int right,int x){
	if(seg[root].left==left&&seg[root].right==right){
		seg[root].lazy+=x;
		seg[root].minn+=x;
		return;
	}
	if(seg[root].lazy!=0){
		push_down(root);
	}
	if(right<=seg[root<<1].right){
		add(root<<1,left,right,x);
	}
	else if(left>=seg[root<<1|1].left){
		add(root<<1|1,left,right,x);
	}
	else{
		add(root<<1,left,seg[root<<1].right,x);
		add(root<<1|1,seg[root<<1|1].left,right,x);
	}
	seg[root].minn=mn(seg[root<<1].minn,seg[root<<1|1].minn);
}
ll query(int root,int left,int right){
	if(seg[root].left==left&&seg[root].right==right){
		return seg[root].minn;
	}
	if(seg[root].lazy!=0){
		push_down(root);
	}
	if(right<=seg[root<<1].right){
		return query(root<<1,left,right);
	}
	else if(left>=seg[root<<1|1].left){
		return query(root<<1|1,left,right);
	}
	else{
		return mn(query(root<<1,left,seg[root<<1].right),query(root<<1|1,seg[root<<1|1].left,right));
	}
}
char read(int &a){
	char c=getchar();
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	a=0;
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
	a*=f;
	return c;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	int m;
	scanf("%d",&m);
	char c;
	int left,right,x;
	for(int i=1;i<=m;i++){
		read(left);
		c=read(right);
		left++,right++;
		if(c=='\n'){
			if(left<=right){
				cout<<query(1,left,right)<<endl;
			}
			else{
				cout<<mn(query(1,left,n),query(1,1,right))<<endl;
			}
		}
		else{
			read(x);
			if(left<=right){
				add(1,left,right,x);
			}
			else{
				add(1,left,n,x);
				add(1,1,right,x);
			}
		}
	}
	return 0;
}
//