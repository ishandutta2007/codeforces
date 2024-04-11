#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+2;
ui i2[N];
namespace _fac
{
	typedef unsigned int ui;
	typedef unsigned long long ll;
	const int N=1e6+2;
	const ui p=1e9+7;
	ui fac[N];
	ui ifac[N];
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
		fac[0]=1;i2[0]=1;
		for (i=1;i<N;i++) fac[i]=(ll)fac[i-1]*i%p;
		for (i=1;i<N;i++) i2[i]=(ll)i2[i-1]*(p+1>>1)%p;
		ifac[N-1]=ksm(fac[N-1],p-2);
		for (i=N-1;i;i--) ifac[i-1]=(ll)ifac[i]*i%p;
	}
}
using _fac::init_fac;using _fac::fac;using _fac::ifac;
using _fac::ksm;using _fac::C;using _fac::p;
int main()
{
	init_fac();
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,k;
		cin>>n>>m>>k;
		if (n==m) {cout<<((ll)m*k%p)<<'\n';continue;}
		ui r=0;
		for (i=1;i<=m;i++) r=(r+(ll)i*C(n-i-1,m-i)%p*i2[n-i])%p;
		r=(ll)r*k%p;
		cout<<r<<'\n';
	}
}