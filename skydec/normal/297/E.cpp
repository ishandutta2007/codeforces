//orz YJN
//
//
//
//IGM
//
//
//
//
//
//Orz Orz Orz Orz Orz
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
const int MAXN=210000;
int Result[MAXN];
struct gt{
	int l,r,id,v;
	inline gt(int a=0,int b=0,int c=0,int d=0){l=a;r=b;id=c;v=d;}
};
int cnt[MAXN];
struct Matrix{  // 
	vector<int>p[MAXN];
	vector<gt>ask[MAXN];
	int n;
	inline void init(int val){
		n=val;memset(cnt,0,sizeof cnt);
		memset(Result,0,sizeof Result);
		rep(i,1,n){
			while(p[i].size())p[i].pop_back();
			while(ask[i].size())ask[i].pop_back();
		}
	}
	inline void ap(pii gt){
		p[gt.fi].pb(gt.se);
	}
	inline void work(){
		rep(i,1,n){
			rep(j,0,p[i].size()-1)for(int x=p[i][j];x<=n;x+=x&-x)cnt[x]++;
			rep(j,0,ask[i].size()-1){
				for(int x=ask[i][j].r;x;x-=x&-x)Result[ask[i][j].id]+=cnt[x]*ask[i][j].v;
				for(int x=ask[i][j].l-1;x;x-=x&-x)Result[ask[i][j].id]-=cnt[x]*ask[i][j].v;
			}
		}
	}
	inline void insert(int x,int y,int l,int r,int id){
		if(x>y||l>r)return;
		ask[y].pb(gt(l,r,id,1));ask[x-1].pb(gt(l,r,id,-1));
	}
}jabby;
pii a[MAXN];int n;
int tmp[MAXN];
inline LL NoCross(){
  // for the shape like ""
	LL res=0;
	jabby.init(2*n);rep(i,1,n)jabby.ap(a[i]);
	rep(i,1,n)jabby.insert(a[i].fi+1,a[i].se-1,a[i].fi+1,a[i].se-1,i);
	jabby.work();
	rep(i,1,n){
		tmp[i]=Result[i];
		//printf("_%d %d\n",i,tmp[i]);
	}
	
	jabby.init(2*n);rep(i,1,n)jabby.ap(a[i]);
	rep(i,1,n){
		jabby.insert(1,a[i].fi-1,a[i].se+1,2*n,i);
		jabby.insert(1,a[i].fi-1,1,a[i].fi-1,i);
		jabby.insert(a[i].se+1,2*n,a[i].se+1,2*n,i);
	}
	jabby.work();
	rep(i,1,n){
		res+=Result[i]*1ll*tmp[i];
		//printf("__%d %d\n",i,Result[i]);
	}
	return res;
}
inline LL Cross(){
	LL res=0;
	jabby.init(2*n);rep(i,1,n)jabby.ap(a[i]);
	rep(i,1,n){
		jabby.insert(a[i].fi+1,a[i].se-1,a[i].fi+1,a[i].se-1,i);
		jabby.insert(1,a[i].fi-1,a[i].se+1,2*n,i);
		jabby.insert(1,a[i].fi-1,1,a[i].fi-1,i);
		jabby.insert(a[i].se+1,2*n,a[i].se+1,2*n,i);
	}
	jabby.work();
	rep(i,1,n)res+=Result[i]*1ll*(n-1-Result[i]);
	return res/2;
}
int main(){
	scanf("%d",&n);rep(i,1,n){
		scanf("%d%d",&a[i].fi,&a[i].se);
		if(a[i].fi>a[i].se)swap(a[i].fi,a[i].se);
	}
	LL res=n*1ll*(n-1)*1ll*(n-2)/6;
	res-=NoCross();
	res-=Cross();
	printf("%I64d\n",res);
	return 0;
}