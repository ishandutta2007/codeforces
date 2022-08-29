#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 110000
pii a[MAXN];int n,m,sum[MAXN*4],len[MAXN*4],x,y,rev[MAXN*4];
vector<pii>zyb[MAXN];
void build(int o,int l,int r){
	if(l==r){len[o]=1;return;}
	int mid=(l+r)>>1;
	build(o*2,l,mid);
	build(o*2+1,mid+1,r);
	len[o]=len[o*2]+len[o*2+1];
}
inline void Pang(int o){rev[o]^=1;sum[o]=len[o]-sum[o];}
inline void down(int o){
	if(len[o]==1||!rev[o])return;
	rev[o]=0;Pang(o*2);Pang(o*2+1);
}
void rever(int now,int l,int r){
	down(now);
	if(x<=l&&r<=y){Pang(now);return;}
	int mid=(l+r)>>1;
	if(x<=mid)rever(now*2,l,mid);
	if(y>mid)rever(now*2+1,mid+1,r);
	sum[now]=sum[now*2]+sum[now*2+1];
}
int ask(int now,int l,int r){
	down(now);
	if(x<=l&&r<=y)return sum[now];
	int mid=(l+r)>>1;int res=0;
	if(x<=mid)res+=ask(now*2,l,mid);
	if(y>mid)res+=ask(now*2+1,mid+1,r);
	return res;
}
inline int high(int x){
	if(x>a[n].fi)return -1;
	int l,r,res;l=1;r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid].fi>=x){res=mid;r=mid;}
		else l=mid+1;
	}
	if(a[l].fi>=x)res=l;
	return res;
}
inline int low(int x){
	if(x<a[1].fi)return -1;
	int l,r,res;l=1;r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid].fi<=x){res=mid;l=mid+1;}
		else r=mid;
	}
	if(a[l].fi<=x)res=l;
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);build(1,1,n);
	rep(i,1,n){scanf("%d",&a[i].fi);a[i].se=i;}
	sort(a+1,a+1+n);rep(i,2,n){zyb[i].pb((pii){1,i-1});if(i<n)zyb[i+1].pb((pii){1,i-1});}
	rep(i,1,m){
		int l,r;scanf("%d%d",&l,&r);
		l=high(l);r=low(r);
		if(l==-1||r==-1)continue;
		zyb[l].pb((pii){l,r});
		zyb[r+1].pb((pii){l,r});
	}
	LL ans=n*1ll*(n-1)*(n-2)/6ll;
	rep(i,1,n){
		for(int j=0;j<zyb[i].size();j++){
			x=zyb[i][j].fi;
			y=zyb[i][j].se;
			rever(1,1,n);
		}
		int res=0;
		if(i>1){x=1;y=i-1;res+=ask(1,1,n);}
		if(i<n){x=i+1;y=n;res+=ask(1,1,n);}
		ans-=res*1ll*(res-1)/2;
	}
	printf("%I64d\n",ans);
	return 0;
}