#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int T;cin>>T;while(T--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const int mod=998244353;
const int _mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
template <typename T> void rd(T &x){x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}while(isdigit(ch))x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y){if(y&1)ret=ret*x;y>>=1;x=x*x;}return ret;}
/*
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
inline int minn(int a,int b){return a<b?a:b;}
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
int a[2000010],b[2000010],n,m,p[2000010],c[2000010];
ll ans;
inline bool cmp(int x,int y){return a[x]<a[y];}
struct Seg{
	int l,r,mn,tag;
}t[8000010];
void build(int p,int l,int r)
{
	t[p].mn=t[p].tag=0;
	t[p].l=l,t[p].r=r;
	int mid=l+r>>1;
	if (l==r) return;
	build(rs(p),mid+1,r),build(ls(p),l,mid);
	t[p].mn=minn(t[ls(p)].mn,t[rs(p)].mn);
}
void update(int p,int l,int r,int v)
{
	if (t[p].r<=r&&l<=t[p].l) return t[p].tag+=v,t[p].mn+=v,void();
	if (l>t[p].r||t[p].l>r) return;
	if (t[p].tag)
	{
		t[rs(p)].mn+=t[p].tag;
		t[rs(p)].tag+=t[p].tag;
		t[ls(p)].mn+=t[p].tag;
		t[ls(p)].tag+=t[p].tag;
	}
	t[p].tag=0;
	update(rs(p),l,r,v);
	update(ls(p),l,r,v);
	t[p].mn=minn(t[ls(p)].mn,t[rs(p)].mn);
}
int query(int p,int l,int r)
{
	if (t[p].r<=r&&l<=t[p].l) return t[p].mn;
	if (l>t[p].r||t[p].l>r) return inf;
	if (t[p].tag)
	{
		t[rs(p)].mn+=t[p].tag;
		t[rs(p)].tag+=t[p].tag;
		t[ls(p)].mn+=t[p].tag;
		t[ls(p)].tag+=t[p].tag;
	}
	t[p].tag=0;
	return minn(query(rs(p),l,r),query(ls(p),l,r));
}
int main()
{
	DC
	{
		ans=0;
		cin>>n>>m;
		F(i) rd(a[i]);
		rep(i,1,m) rd(b[i]);
		F(i) p[i]=i,c[i]=a[i];
		sort(p+1,p+n+1,cmp);
		Z(a,n),Z(b,m);
		build(1,1,n+1);
		F(i)
		{
			auto p=lower_bound(a+1,a+n+1,c[i]);
			c[i]=p-a;
			ans+=query(1,c[i],c[i]);
			update(1,1,c[i]-1,1);
		}
		build(1,1,n+1);
		F(i) update(1,i+1,n+1,1);
		int v1=1,v2=1;
		rep(i,1,m)
		{
			while(v1<=n&&b[i]>=a[v1]) v1++,update(1,p[v1-1]+1,n+1,-1);
			while(v2<=n&&b[i]>a[v2]) v2++,update(1,1,p[v2-1],1);
			ans+=query(1,1,n+1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}