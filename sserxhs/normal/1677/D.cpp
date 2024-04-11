//114514min
#include "bits/stdc++.h"
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
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
		for (i=1;i<N;i++) fac[i]=(ll)fac[i-1]*i%p;

		ifac[N-1]=ksm(fac[N-1],p-2);
		for (i=N-1;i;i--) ifac[i-1]=(ll)ifac[i]*i%p;

		ui x;inv[1]=1;
		for (i=2;i<N;i++)
		{
			x=p/i;
			inv[i]=(ll)x*(p-inv[p-x*i])%p;
		}
	}
}
using _fac::init_fac;using _fac::fac;using _fac::ifac;using _fac::inv;
using _fac::ksm;using _fac::C;using _fac::p;
int a[N],v[N];
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	init_fac();
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,k;
		cin>>n>>m;
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=n-m+1;i<=n;i++) if (a[i]>0) break;
		if (i<=n) {cout<<"0\n";continue;}
		ui r=fac[m];
		int cnt=0;
		for (i=1;i<=n-m;i++) if (a[i]==0) r=(ll)r*(m+1)%p;
		for (i=1;i<=n-m;i++) if (a[i]==-1) r=(ll)r*(i+m)%p;
		cout<<r<<'\n';
	}
}