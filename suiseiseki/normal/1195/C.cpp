/*#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 100000
ll f[2][Maxn+5];
int h[2][Maxn+5];
int x[2][Maxn+5];
ll mx(ll a,ll b){
	return a>b?a:b;
}
map<int,int> mp;
int tmp;
struct Segment_Tree{
	struct Segment_Node{
		int left,right;
		ll maxn;
		ll lazy;
	}seg[Maxn<<3|5];
	void build(int root,int left,int right){
		seg[root].lazy=seg[root].maxn=0;
		seg[root].left=left;
		seg[root].right=right;
		if(left==right){
			return;
		}
		int mid=(left+right)>>1;
		build(root<<1,left,mid);
		build(root<<1|1,mid+1,right);
	}
	void push_down(int root){
		if(!seg[root].lazy){
			return;
		}
		seg[root<<1].maxn=mx(seg[root<<1].maxn,seg[root].lazy);
		seg[root<<1].lazy=mx(seg[root<<1].lazy,seg[root].lazy);
		seg[root<<1|1].maxn=mx(seg[root<<1|1].maxn,seg[root].lazy);
		seg[root<<1|1].lazy=mx(seg[root<<1|1].lazy,seg[root].lazy);
		seg[root].lazy=0;
	}
	ll query(int root,int left,int right){
		if(left>right){
			return 0;
		}
		if(seg[root].left==left&&seg[root].right==right){
			return seg[root].maxn;
		}
		push_down(root);
		ll ans=0;
		root<<=1;
		if(left<=seg[root].right){
			if(right<=seg[root].right){
				ans=mx(ans,query(root,left,right));
			}
			else{
				ans=mx(ans,query(root,left,seg[root].right));
			}
		}
		root|=1;
		if(right>=seg[root].left){
			if(left>=seg[root].left){
				ans=mx(ans,query(root,left,right));
			}
			else{
				ans=mx(ans,query(root,seg[root].left,right));
			}
		}
		return ans;
	}
	void update(int root,int left,int right,ll x){
		if(seg[root].left==left&&seg[root].right==right){
			seg[root].maxn=mx(seg[root].maxn,x);
			seg[root].lazy=mx(seg[root].lazy,x);
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
	}
}seg[2];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[0][i]);
		mp[h[0][i]];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&h[1][i]);
		mp[h[1][i]];
	}
	map<int,int>::iterator it;
	it=mp.begin();
	while(it!=mp.end()){
		(it->second)=++tmp;
		it++;
	}
	for(int i=1;i<=n;i++){
		x[0][i]=mp[h[0][i]];
		x[1][i]=mp[h[1][i]];
	}
	seg[0].build(1,1,tmp);
	seg[1].build(1,1,tmp);
	f[0][1]=h[0][1];
	f[1][1]=h[1][1];
	seg[0].update(1,1,x[0][1],f[0][1]);
	seg[1].update(1,1,x[1][1],f[1][1]);
	for(int i=2;i<=n;i++){
		f[0][i]=seg[1].query(1,x[0][i]+1,tmp)+h[0][i];
		f[1][i]=seg[0].query(1,x[1][i]+1,tmp)+h[1][i];
		seg[0].update(1,1,x[0][i],f[0][i]);
		seg[1].update(1,1,x[1][i],f[1][i]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=mx(ans,f[0][i]);
		ans=mx(ans,f[1][i]);
	}
	cout<<ans<<endl;
	return 0;
}*/
#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 100000
int h[2][Maxn+5];
ll f[2][Maxn+5];
ll g[2][Maxn+5];
ll mx(ll a,ll b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[0][i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&h[1][i]);
	}
	for(int i=1;i<=n;i++){
		f[0][i]=g[1][i-1]+h[0][i];
		g[0][i]=mx(g[0][i-1],f[0][i]);
		f[1][i]=g[0][i-1]+h[1][i];
		g[1][i]=mx(g[1][i-1],f[1][i]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=mx(ans,f[0][i]);
		ans=mx(ans,f[1][i]);
	}
	cout<<ans<<endl;
	return 0;
}