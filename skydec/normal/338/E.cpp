#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
const int MAXN=160000;
int val[MAXN*4],b[MAXN],h,a[MAXN],n,m,lazy[MAXN*4];
void build(int me,int l,int r){
	if(l==r){
		val[me]=-l;
		return;
	}
	int mid=(l+r)>>1;
	build(me*2,l,mid);
	build(me*2+1,mid+1,r);
	val[me]=min(val[me*2],val[me*2+1]);
}
inline void down(int me){
	if(lazy[me]==0)return;
	rep(i,0,1){
		lazy[me*2+i]+=lazy[me];
		val[me*2+i]+=lazy[me];
	}
	lazy[me]=0;
}
void add(int me,int l,int r,int x,int y,int v){
	if(l^r)down(me);
	if(x<=l&&r<=y){
		lazy[me]+=v;val[me]+=v;return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(me*2,l,mid,x,y,v);
	if(y>mid)add(me*2+1,mid+1,r,x,y,v);
	val[me]=min(val[me*2],val[me*2+1]);
}
inline int go(int x){
	int l=1;int r=m;int res=m+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(b[mid]+x>=h)res=mid,r=mid;
		else l=mid+1;
	}
	if(b[l]+x>=h)res=l;
	return res;
}
int main(){
	scanf("%d%d%d",&n,&m,&h);
	rep(i,1,m)scanf("%d",&b[i]);
	build(1,1,m);sort(b+1,b+1+m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m){
		int lu=go(a[i]);
		if(lu>m)continue;
		add(1,1,m,lu,m,1);
	}
	int res=(val[1]>=0);
	rep(i,m+1,n){
		int lu=go(a[i-m]);
		if(lu<=m)add(1,1,m,lu,m,-1);
		lu=go(a[i]);
		if(lu<=m)add(1,1,m,lu,m,1);
		res+=(val[1]>=0);
	}
	printf("%d\n",res);
	return 0;
}