#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=210000;
int n,Q;
int root[N];
int cl[N*33],cr[N*33],sum[N*33],tot;
void build(int pre,int &me,int l,int r,int x){
	me=++tot;
	cl[me]=cl[pre];
	cr[me]=cr[pre];
	sum[me]=sum[pre]+1;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)build(cl[pre],cl[me],l,mid,x);
	else build(cr[pre],cr[me],mid+1,r,x);
}
int segask(int me,int l,int r,int x,int y){
	if(x>y)return 0;
	if(!me)return 0;
	if(x<=l&&r<=y)return sum[me];
	int res=0;
	int mid=(l+r)>>1;
	if(x<=mid)res+=segask(cl[me],l,mid,x,y);
	if(y>mid)res+=segask(cr[me],mid+1,r,x,y);
	return res;
}
int ask(int l,int r,int x,int y){
	if(l>r)return 0;
	if(x>y)return 0;
	return segask(root[r],1,n,x,y)-segask(root[l-1],1,n,x,y);
}
LL C(int x){return x*1ll*(x-1)/2;}
int main(){
	scanf("%d%d",&n,&Q);
	rep(i,1,n){
		int x;scanf("%d",&x);
		build(root[i-1],root[i],1,n,x);
	}
	while(Q--){
		int l,r,x,y;
		scanf("%d%d%d%d",&l,&x,&r,&y);
		LL ans=C(n);
		ans-=C(l-1);
		ans-=C(n-r);
		ans-=C(x-1);
		ans-=C(n-y);
		//printf("%I64d\n",ans);
		ans+=C(ask(1,l-1,1,x-1));
		ans+=C(ask(1,l-1,y+1,n));
		ans+=C(ask(r+1,n,1,x-1));
		ans+=C(ask(r+1,n,y+1,n));
		printf("%I64d\n",ans);
	}
	return 0;
}