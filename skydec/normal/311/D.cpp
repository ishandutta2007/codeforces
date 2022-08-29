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
const int jsb=95542721;
#define MAXN 110000
int n,b[MAXN];
struct info{
	int sum[48];
	inline void set(int x){
		sum[0]=x%jsb;
		rep(i,1,47){
			sum[i]=sum[i-1]*1ll*sum[i-1]%jsb;
			sum[i]=sum[i]*1ll*sum[i-1]%jsb;
		}
	}
	inline void up(info l,info r){
		rep(i,0,47)sum[i]=(l.sum[i]+r.sum[i])%jsb;
	}
	inline void move(int w){
		int fu[48];rep(i,0,47)fu[i]=sum[i];
		rep(i,0,47)sum[i]=fu[(i+w)%48];
	}
}a[MAXN*4];
int tag[MAXN*4];
void build(int me,int l,int r){
	if(l==r){
		a[me].set(b[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(me*2,l,mid);
	build(me*2+1,mid+1,r);
	a[me].up(a[me*2],a[me*2+1]);
}
inline void down(int me){
	if(!tag[me])return;
	rep(u,0,1){
		tag[me*2+u]+=tag[me];
		a[me*2+u].move(tag[me]);
	}
	tag[me]=0;
}
void add(int me,int l,int r,int x,int y){
	if(l^r)down(me);
	if(x<=l&&r<=y){
		a[me].move(1);tag[me]++;return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(me*2,l,mid,x,y);
	if(y>mid)add(me*2+1,mid+1,r,x,y);
	a[me].up(a[me*2],a[me*2+1]);
}
int sum(int me,int l,int r,int x,int y){
	if(l^r)down(me);
	if(x<=l&&r<=y)return a[me].sum[0];
	int mid=(l+r)>>1;int res=0;
	if(x<=mid)res=(res+sum(me*2,l,mid,x,y))%jsb;
	if(y>mid)res=(res+sum(me*2+1,mid+1,r,x,y))%jsb;
	return res;
}
int main(){
	scanf("%d",&n);rep(i,1,n)scanf("%d",&b[i]);
	build(1,1,n);
	int m;scanf("%d",&m);
	while(m--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int l,r;scanf("%d%d",&l,&r);
			printf("%d\n",sum(1,1,n,l,r));
		}
		else{
			int l,r;scanf("%d%d",&l,&r);
			add(1,1,n,l,r);
		}
	}
	return 0;
}