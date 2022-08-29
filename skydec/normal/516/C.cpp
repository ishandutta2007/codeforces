#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=210000;
struct info{
	LL val1;int x1;
	LL val2;int x2;
	void init(){
		x1=x2=val1=val2=0;
	}
}bo1[N*4],bo2[N*4];
LL sum[N];int d[N];int h[N];
int n,q;
inline info operator +(const info &a,const info &b){
	info ans;
	if(!a.x1)return b;
	if(!b.x1)return a;
	if(a.val1>=b.val1){
		ans=a;
		if((!a.x2)||(b.val1>=a.val2)){
			ans.x2=b.x1;ans.val2=b.val1;
		}
	}
	else{
		ans=b;
		if((!b.x2)||(a.val1>=b.val2)){
			ans.x2=a.x1;ans.val2=a.val1;
		}
	}
	return ans;
}
inline void build1(int me,int l,int r){
	if(l==r){
		bo1[me].val1=2ll*h[l]+sum[l-1];bo1[me].x1=l;
		return;
	}
	int mid=(l+r)>>1;
	build1(me*2,l,mid);
	build1(me*2+1,mid+1,r);
	bo1[me]=bo1[me*2]+bo1[me*2+1];
}
inline void build2(int me,int l,int r){
	if(l==r){
		bo2[me].val1=2ll*h[l]-sum[l-1];bo2[me].x1=l;
		return;
	}
	int mid=(l+r)>>1;
	build2(me*2,l,mid);
	build2(me*2+1,mid+1,r);
	bo2[me]=bo2[me*2]+bo2[me*2+1];
	//printf("__%d %d\n",bo2[me].x1,bo2[me].x2);
}
inline info ask1(int me,int l,int r,int x,int y){
	if(x<=l&&r<=y)return bo1[me];
	info ans;ans.init();
	int mid=(l+r)>>1;
	if(x<=mid)ans=ans+ask1(me*2,l,mid,x,y);
	if(y>mid)ans=ans+ask1(me*2+1,mid+1,r,x,y);
	return ans;
}
inline info ask2(int me,int l,int r,int x,int y){
	if(x<=l&&r<=y)return bo2[me];
	info ans;ans.init();
	int mid=(l+r)>>1;
	if(x<=mid)ans=ans+ask2(me*2,l,mid,x,y);
	if(y>mid)ans=ans+ask2(me*2+1,mid+1,r,x,y);
	return ans;
}
inline void work(int l,int r){
	info a,b;
	a=ask1(1,1,2*n,l,r);
	b=ask2(1,1,2*n,l,r);
	LL ans=0;
	//printf("%d %d %d %d\n",a.x1,a.x2,b.x1,b.x2);
	if(a.x1!=b.x1)ans=a.val1+b.val1;
	else{
		ans=-210000000000000ll;
		if(a.x2)ans=max(ans,a.val2+b.val1);
		if(b.x2)ans=max(ans,a.val1+b.val2);
	}
	printf("%I64d\n",ans);
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n){
		scanf("%d",&d[i]);
		d[i+n]=d[i];
	}
	rep(i,1,n){
		scanf("%d",&h[i]);
		h[i+n]=h[i];
	}
	rep(i,1,2*n)sum[i]=sum[i-1]+d[i]*1ll;
	build1(1,1,2*n);
	build2(1,1,2*n);
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		if(l<=r){
			work(r+1,l-1+n);
		}
		else work(r+1,l-1);
	}
}