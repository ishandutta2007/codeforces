#include <bits/stdc++.h>
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
	const int N=2e5+2;
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
ui dp[N],f[N];
inline void inc(ui &x,const ui &y) {if ((x+=y)>=p) x-=p;}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	init_fac();
	int n,i,S;
	ui cur=0;
	cin>>n;S=n+1>>1;
	dp[1]=fac[n-1];
	for (i=2;i-1<=n-S;i++) dp[i]=(ll)fac[i-1]*fac[n-i]%p*C(n-S,i-1)%p;
	for (i=n-S+1;i;i--)
	{
		f[i]=(dp[i]+(ll)(p-inv[i])*cur)%p;
		inc(cur,f[i]);
	}
	for (i=1;i<=n;i++) cout<<f[i]<<" \n"[i==n];
}