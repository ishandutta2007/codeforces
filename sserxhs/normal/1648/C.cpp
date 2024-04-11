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
const int N=2e5+2;
template<typename typC,int N> struct bit
{
	typC a[N],s[N];
	int n;
	void init(int nn)
	{
		n=nn;
		memset(a,0,(n+1)*sizeof a[0]);
		memset(s,0,(n+1)*sizeof s[0]);
	}
	template<typename T> void init(int nn,T *b)
	{
		n=nn;
		for (int i=1;i<=n;i++) s[i]=s[i-1]+b[i];
		memset(a+1,0,n*sizeof a[0]);
	}
	void mdf(int x,typC y)
	{
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y; 
	}
	typC sum(int x)
	{
		typC r=s[x]+a[x];
		while (x^=x&-x) r+=a[x];
		return r;
	}
	typC sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
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
bit<int,N> s;
int a[N],b[N],cnt[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j;
	ui r=0,xs=1;
	cin>>n>>m;init_fac();
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=m;i++) cin>>b[i];
	for (i=1;i<=n;i++) ++cnt[a[i]];
	for (i=1;i<=200000;i++) xs=(ll)xs*ifac[cnt[i]]%p;
	s.init(200000,cnt);
	for (i=1;i<=min(n,m);i++)
	{
		r=(r+(ll)fac[n-i+1]*xs%p*inv[n-i+1]%p*s.sum(b[i]-1))%p;
		if (--cnt[b[i]]<0) break;
		xs=(ll)xs*fac[1+cnt[b[i]]]%p*ifac[cnt[b[i]]]%p;
		s.mdf(b[i],-1);
	}
	if (i>n&&i<=m) {++r;r%=p;}
	cout<<r<<endl;
}