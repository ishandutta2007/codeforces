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
const ll inf=1e18;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	ll p1,t1,p2,t2,n,m,i,j,t;
	cin>>p1>>t1>>p2>>t2>>n>>m;
	vector f(n+1,inf);
	f[0]=0;
	for (i=1; i<=n; i++)
	{
		for (j=0; j<=i; j++)
		{
			cmin(f[i],max(j*t1,((i-j*(p1-m)+p2-m-1)/(p2-m))*t2));
		}
		for (j=0; j<=i; j++)
		{
			t=((j+1)*t1+t2-1)/t2-1;
			cmin(f[i],(t+1)*t2+f[max<ll>(0,i-j*(p1-m)-t*(p2-m)-(p1+p2-m))]);
		}
		swap(p1,p2); swap(t1,t2);
		for (j=0; j<=i; j++)
		{
			t=((j+1)*t1+t2-1)/t2-1;
			cmin(f[i],(t+1)*t2+f[max<ll>(0,i-j*(p1-m)-t*(p2-m)-(p1+p2-m))]);
		}
		swap(p1,p2); swap(t1,t2);
	}
	// dbg(f);
	cout<<f[n]<<endl;
}