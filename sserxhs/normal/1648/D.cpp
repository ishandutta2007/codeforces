#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=5e5+2;
const ll inf=9e18;
ll a[3][N],pref[2][N],suf[N],L[N],R[N],f[N];
template<typename typC,int N> struct bit
{
	typC a[N];
	int n;
	void init(int nn)
	{
		n=++nn;
		fill_n(a,n+1,-inf);
	}
	void mdf(int x,typC y)
	{
		//cerr<<"mdf "<<x<<' '<<y<<endl;
		++x;
		a[x]=max(a[x],y);
		while (x^=x&-x) a[x]=max(a[x],y); 
	}
	typC sum(int x)
	{
		//cerr<<"ask "<<x<<' ';
		++x;
		typC r=a[x];
		while ((x+=x&-x)<=n) r=max(r,a[x]);
		//cerr<<r<<endl;
		return r;
	}
};
vector<pair<int,int>> bel[N],fb[N];
bit<ll,N> s;
ll st[20][N];
int yS[N];
ll rmq(int l,int r)
{
	int z=yS[r-l+1];
	return max(st[z][l],st[z][r-(1<<z)+1]);
}
int l[N*4],r[N*4];
struct Q
{
	ll sf,sr,ss;
	Q operator+(const Q &o) const {return {max(sf,o.sf),max(sr,o.sr),max({ss,o.ss,sf+o.sr})};}
};
Q S[N*4],anss;
void build(int x,int l,int r)
{
	if (l==r)
	{
		S[x]={max(f[r],L[r+1]),R[r],-inf};
		return;
	}
	int c=x*2,m=l+r>>1;
	build(c,l,m);build(c+1,m+1,r);
	S[x]=S[c]+S[c+1];
}
int z,y;
void ask(int x,int l,int r)
{
	if (z<=l&&r<=y)
	{
		anss=anss+S[x];
		return;
	}
	int c=x*2,m=l+r>>1;
	if (z<=m) ask(c,l,m);
	if (y>m) ask(c+1,m+1,r);
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j;
	ll ans=-inf;
	cin>>n>>m;s.init(n);
	for (i=0;i<3;i++) for (j=1;j<=n;j++) cin>>a[i][j];
	for (i=0;i<2;i++) for (j=1;j<=n;j++) pref[i][j]=pref[i][j-1]+a[i][j];
	for (i=n;i;i--) suf[i]=suf[i+1]+a[2][i];
	for (i=1;i<=n;i++) L[i]=pref[0][i]-pref[1][i-1];
	for (i=1;i<=n;i++) R[i]=suf[i]+pref[1][i];
	memcpy(st[0],R,sizeof R);
	for (i=2;i<=n;i++) yS[i]=yS[i>>1]+1;
	for (j=1;j<=yS[n];j++)
	{
		for (i=1;i+(1<<j)-1<=n;i++) st[j][i]=max(st[j-1][i],st[j-1][i+(1<<j-1)]);
	}
	f[0]=L[n+1]=-inf;
	//static ll ML[N],MR[N];
	///ML[n]=L[n];MR[1]=R[1];
	//for (i=n-1;i;i--) ML[i]=max(L[i],ML[i+1]);
	//for (i=2;i<=n;i++) MR[i]=max(R[i],MR[i-1]);
	while (m--)
	{
		int l,r,k;
		cin>>l>>r>>k;
	//	ans=max(ans,ML[l]+MR[r]-k);
		bel[r].push_back({l,k});
		//fb[l].push_back({r,k});
	}
	//for (i=1;i<=n;i++) cerr<<L[i]<<" \n"[i==n];
	for (i=1;i<=n;i++)
	{
		//cerr<<i<<endl;
		s.mdf(i-1,L[i]);
		f[i]=-inf;
		for (auto [x,y]:bel[i])
		{
			ll cur=s.sum(x-1)-y;
			f[i]=max(f[i],cur);
			//ans=max(ans,cur+rmq(x,i));
		}
		//ans=max(ans,f[i]+R[i]);
		s.mdf(i,f[i]);
		//f[i]=max(f[i],L[i]);
		//for (auto [x,y]:fb[i]) s.mdf(x,f[i]-y);
		//cerr<<f[i]<<" \n"[i==n];
	}
	//for (i=1;i<=n;i++) cerr<<R[i]<<" \n"[i==n];
	//for (i=1;i<=n;i++) cerr<<f[i]<<" \n"[i==n];
	build(1,0,n);
	for (i=1;i<=n;i++) for (auto [x,k]:bel[i])
	{
		anss={-inf,-inf,-inf};
		z=x-1;y=i;
		ask(1,0,n);
		ans=max(ans,anss.ss-k);
	}
	cout<<ans<<endl;

	//for (i=1;i<=n;i++) cerr<<L[i]<<" \n"[i==n];
	//for (i=1;i<=n;i++) cerr<<R[i]<<" \n"[i==n];
}