//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e3+5;
namespace _fac
{
	typedef unsigned int ui;
	typedef unsigned long long ll;
	const int N=4e3+5;
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
ui s2[N][N];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	{
		int n=2000,i,j;
		for (i=0; i<=n; i++) s2[i][0]=0;
		for (i=0; i<=n; i++) s2[i][i]=1;
		for (i=2; i<=n; i++) for (j=1; j<=i-1; j++) s2[i][j]=((ll)j*s2[i-1][j]+s2[i-1][j-1])%p;
		// for (i=0; i<=5; i++) for (j=0; j<=i; j++) cerr<<s2[i][j]<<" \n"[j==i];
	}
	// return 0;
	init_fac();
	while (T--)
	{
		int n,m,k,i,a,b;
		cin>>n>>m>>k;
		a=m+1>>1; b=m>>1;
		ui r=0;
		ui x=1,y=1;
		ui im=ksm(m,p-2);
		m=ksm(m,n);
		for (i=0; i<=min(n,k); x=(ll)x*(n-i)%p,i++)
		{
			// dbg(i,(ll)ksm(a,i)*ksm(b,p-1-i)%p);
			r=(r+(ll)y*s2[k][i]%p*x%p*m)%p;
			y=(ll)y*a%p;
			m=(ll)m*im%p;
		}
		cout<<r<<'\n';
		cout.flush();
	}
}