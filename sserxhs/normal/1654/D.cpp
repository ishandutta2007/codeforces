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
namespace Prime
{
	const int N=2e5+2;
	int pr[N],mn[N],cnt;
	vector<pair<int,int>> w[N];
	bool ed[N];
	void init_prime()
	{
		int i,j,k;
		for (i=2;i<N;i++)
		{
			if (!ed[i])
			{
				pr[cnt++]=i;
				mn[i]=i;
			}
			for (j=0;(k=i*pr[j])<N;j++)
			{
				mn[k]=pr[j];
				ed[k]=1;
				if (i%pr[j]==0) break;
			}
		}
		//for (i=2;i<N;i++) if (mu[i]<0) mu[i]+=p;
	}
	void getw()
	{
		for (ui i=1;i<N;i++)
		{
			ui x=i;
			while (x>1)
			{
				ui y=mn[x],z=1;
				x/=y;
				while (x%y==0) x/=y,++z;
				w[i].push_back({y,z});
			}
		}
	}
}
using Prime::pr;using Prime::w;
using Prime::init_prime,Prime::getw;
const int N=2e5+5;
struct Q
{
	int v,x,y;
};
vector<Q> e[N];
int f[N];
ui dep[N];
int mx[N],now[N];
void dfs1(int u)
{
	for (auto [v,x,y]:e[u]) if (v!=f[u])
	{
		f[v]=u;dep[v]=(ll)dep[u]*y%p*inv[x]%p;
		dfs1(v);
	}
}
void del(int x)
{
	for (auto [y,z]:w[x]) now[y]-=z;
}
void add(int x)
{
	for (auto [y,z]:w[x]) mx[y]=max(mx[y],now[y]+=z);
}
void dfs2(int u)
{
	for (auto [v,x,y]:e[u]) if (v!=f[u])
	{
		del(y);add(x);
		dfs2(v);
		del(x);add(y);
	}
}
int main()
{
	init_fac();init_prime();getw();//dbg(1);
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;fill_n(f+1,n,0);
		for (i=1;i<=n;i++) e[i].clear();
		for (i=1;i<n;i++)
		{
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			int D=gcd(c,d);c/=D;d/=D;
			e[a].push_back({b,c,d});
			e[b].push_back({a,d,c});
		}
		dfs1(dep[1]=1);
		ui r=accumulate(dep+1,dep+n+1,0ull)%p;
		memset(mx+1,0,n*sizeof mx[0]);
		memset(now+1,0,n*sizeof now[0]);
		dfs2(1);
		//for (i=1;i<=n;i++) cerr<<mx[i]<<" \n"[i==n];
		for (i=1;i<=n;i++) r=(ll)r*ksm(i,mx[i])%p;
		cout<<r<<'\n';
	}
}