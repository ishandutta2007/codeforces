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
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	ll n,res=0;
	cin>>n;
	vector<ll> a(11);
	int i,j,k;
	for (i=1; i<=10; i++) cin>>a[i];
	for (i=10; i; i--)
	{
		ll tmp=max(0ll,min((n-1000)/i,a[i]-100));
		a[i]-=tmp;
		res+=tmp*i;
		n-=tmp*i;
	}
	for (i=1; i<=10; i++) cmin(a[i],n/i);
	ll tot=0;
	for (i=1; i<=10; i++) tot+=a[i]*i;
	n=min(n,tot);
	for (i=1; i<=10; i++) cmin(a[i],n/i);
	vector<ll> f(1+n);
	f[0]=1;
	for (i=1; i<=10; i++)
	{
		for (j=1; j<=a[i]; j++)
		{
			for (k=n; k>=i; k--) f[k]|=f[k-i];
		}
	}
	for (i=n; i; i--) if (f[i]) break;
	cout<<res+i<<endl;
}