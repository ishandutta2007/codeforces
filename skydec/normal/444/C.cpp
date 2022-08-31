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
LL sum[N*4];int cov[N*4];LL lazy[N*4];int n,m;
inline void updata(int x){
	sum[x]=sum[x*2]+sum[x*2+1];
	if((!cov[x*2])||(!cov[x*2+1])||(cov[x*2]^cov[x*2+1]))cov[x]=0;
	else cov[x]=cov[x*2];
}
inline void down(int me,int l,int r){
	if(cov[me]){
		cov[me*2]=cov[me*2+1]=cov[me];
	}
	if(!lazy[me])return;
	int mid=(l+r)>>1;
	lazy[me*2]+=lazy[me];
	sum[me*2]+=lazy[me]*1ll*(mid-l+1);
	
	lazy[me*2+1]+=lazy[me];
	sum[me*2+1]+=lazy[me]*1ll*(r-mid);
	
	lazy[me]=0;
}
LL ask(int me,int l,int r,int x,int y){
	if(l^r)down(me,l,r);
	if(x<=l&&r<=y)return sum[me];
	int mid=(l+r)>>1;
	LL ans=0;
	if(x<=mid)ans+=ask(me*2,l,mid,x,y);
	if(y>mid)ans+=ask(me*2+1,mid+1,r,x,y);
	return ans;
}
void cover(int me,int l,int r,int x,int  y,int co){
	if(l^r)down(me,l,r);
	if(x<=l&&r<=y&&cov[me]>0){
		lazy[me]+=1ll*abs(co-cov[me]);
		sum[me]+=(r-l+1)*1ll*abs(co-cov[me]);
		cov[me]=co;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)cover(me*2,l,mid,x,y,co);
	if(y>mid)cover(me*2+1,mid+1,r,x,y,co);
	updata(me);
}
void build(int me,int l,int r){
	if(l==r){
		cov[me]=l;
		return;
	}
	int mid=(l+r)>>1;
	build(me*2,l,mid);
	build(me*2+1,mid+1,r);
	updata(me);
}
int main(){
	scanf("%d%d",&n,&m);
	build(1,1,n);
	while(m--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int l,r,co;scanf("%d%d%d",&l,&r,&co);
			cover(1,1,n,l,r,co);
		}
		else{
			int l,r;scanf("%d%d",&l,&r);
			printf("%I64d\n",ask(1,1,n,l,r));
		}
	}
	return 0;
}