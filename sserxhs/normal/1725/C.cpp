//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename typC> bool cmin(typC &x,const typC &y) { if (x>y) { x=y; return 1; } return 0; }
template<typename typC> bool cmax(typC &x,const typC &y) { if (x<y) { x=y; return 1; } return 0; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
// void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
// void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
const int N=1e6+5;
namespace _fac
{
	typedef unsigned int ui;
	typedef unsigned long long ll;
	const int N=1e6+2;
	const ui p=998244353;
	ui fac[N];
	ui ifac[N];
	ui inv[N];
	ui ksm(ui x,int y)
	{
		ui r=1;
		while (y)
		{
			if (y&1) r=(ll)r*x%p;
			x=(ll)x*x%p;
			y>>=1;
		}
		return r;
	}
	ui C(int n,int m)
	{
		if (n<m||m<0) return 0;
		return (ll)fac[n]*ifac[m]%p*ifac[n-m]%p;
	}
	void init_fac()
	{
		int i;
		fac[0]=1;
		for (i=1; i<N; i++) fac[i]=(ll)fac[i-1]*i%p;

		ifac[N-1]=ksm(fac[N-1],p-2);
		for (i=N-1; i; i--) ifac[i-1]=(ll)ifac[i]*i%p;

		ui x; inv[1]=1;
		for (i=2; i<N; i++)
		{
			x=p/i;
			inv[i]=(ll)x*(p-inv[p-x*i])%p;
		}
	}
}
using _fac::init_fac; using _fac::fac; using _fac::ifac; using _fac::inv;
using _fac::ksm; using _fac::C; using _fac::p;
int main()
{
	init_fac();
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m,i;
	cin>>n>>m;
	vector<int> d(n);
	cin>>d;
	ll tot=accumulate(all(d),0ll);
	if (n<3||tot%2)
	{
		cout<<ksm(m,n)<<endl;
		return 0;
	}
	tot>>=1;
	vector<ll> x(n);
	for (i=1; i<n; i++) x[i]=x[i-1]+d[i];
	int cnt=0;
	for (i=0; i<n; i++) if (auto it=lower_bound(i+all(x),x[i]+tot); it!=x.end()&&*it==x[i]+tot) ++cnt;
	ui r=0;
	for (i=0; i<=cnt&&i<=m; i++) r=(r+(ll)C(cnt,i)*C(m,i)%p*fac[i]%p*ksm(m-i,n-cnt-i)%p*ksm(m-i-1,cnt-i))%p;
	cout<<r<<endl;
}