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
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
// void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
const int N=1e6+5;
const ll p=1e9+7;
void inc(ll &x,const ll &y) { if ((x+=y)>=p) x-=p; }
ll im[N],f[N],g[N],mi[N];
int main()
{
	mi[0]=1; mi[1]=2;
	for (int i=2; i<N; i++) mi[i]=mi[i-1]*mi[1]%p;
	im[0]=1; im[1]=p+1>>1;
	for (int i=2; i<N; i++) im[i]=im[i-1]*im[1]%p;
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		ll cur=0;
		int n,i,j;
		cin>>n;
		f[1]=0;
		f[n]=im[n-1>>1];
		for (i=n+2>>1; i<=n; i++) g[i]=1,cur=(cur+g[i]*im[i])%p;
		for (i=n>>1,j=n; i; i--)
		{
			while (j>2*i-1) cur=(cur+(p-g[j])*im[j])%p,--j;
			g[i]=mi[i]*cur%p;
			inc(cur,cur);
		}
		for (i=n-1; i>1; i--) f[i]=im[i+1>>1]*g[i]%p;
		for (i=1; i<=n; i++) cout<<f[i]<<'\n';
	}
}