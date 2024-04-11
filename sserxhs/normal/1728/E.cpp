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
const int N=3e5+5,B=550;
ll ans[N],mx[B][B];
struct Q
{
	int a,b;
	bool operator<(const Q &o) const { return a-b>o.a-o.b; }
};
Q a[N];
pair<ll,ll> exgcd(ll a,ll b,ll c)//ax+by=c{-1,-1} b=0  {c/a,0} x
{
	assert(a||b);
	if (!b) return {c/a,0};
	if (a<0) a=-a,b=-b,c=-c;
	ll d=gcd(a,b);
	if (c%d) return {-1,-1};
	ll x=1,x1=0,p=a,q=b,k;
	b=abs(b);
	while (b)
	{
		k=a/b;
		x-=k*x1; a-=k*b;
		swap(x,x1);
		swap(a,b);
	}
	b=abs(q/d);
	x=x*(c/d)%b;
	if (x<0) x+=b;
	return {x,(c-p*x)/q};
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m,i,j;
	cin>>n;
	for (i=1; i<=n; i++) cin>>a[i].a>>a[i].b,ans[0]+=a[i].b;
	sort(a+1,a+n+1);
	for (i=1; i<=n; i++) ans[i]=ans[i-1]+a[i].a-a[i].b;
	memset(mx,-0x3f,sizeof mx);
	for (j=1; j<B; j++) for (i=0; i<=n; i++) cmax(mx[j][i%j],ans[i]);
	cin>>m;
	while (m--)
	{
		ll x,y;
		cin>>x>>y;
		auto [x0,y0]=exgcd(x,y,n);
		if (x0==-1&&y0==-1) { cout<<"-1\n"; continue; }
		y=y/gcd(x,y)*x;
		x0*=x;
		if (x0%y>n) { cout<<"-1\n"; continue; }
		if (y<B) cout<<mx[y][x0%y]<<'\n';
		else
		{
			ll r=-1e18;
			for (ll i=x0%y; i<=n; i+=y) cmax(r,ans[i]);
			cout<<r<<'\n';
		}
		//x0+(y/gcd(x,y))k
	}
}