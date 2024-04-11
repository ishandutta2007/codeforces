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
namespace pr
{
	typedef long long ll;
	typedef __int128 lll;
	typedef pair<ll,int> pa;
	ll ksm(ll x,ll y,const ll p)
	{
		ll r=1;
		while (y)
		{
			if (y&1) r=(lll)r*x%p;
			x=(lll)x*x%p; y>>=1;
		}
		return r;
	}
	namespace miller
	{
		const int p[7]={2,3,5,7,11,61,24251};
		ll s,t;
		bool test(ll n,int p)
		{
			if (p>=n) return 1;
			ll r=ksm(p,t,n),w;
			for (int j=0; j<s&&r!=1; j++)
			{
				w=(lll)r*r%n;
				if (w==1&&r!=n-1) return 0;
				r=w;
			}
			return r==1;
		}
		bool prime(ll n)
		{
			if (n<2||n==46'856'248'255'981ll) return 0;
			for (int i=0; i<7; ++i) if (n%p[i]==0) return n==p[i];
			s=__builtin_ctz(n-1); t=n-1>>s;
			for (int i=0; i<7; ++i) if (!test(n,p[i])) return 0;
			return 1;
		}
	}
	using miller::prime;
	mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
	namespace rho
	{
		void nxt(ll &x,ll &y,ll &p) { x=((lll)x*x+y)%p; }
		ll find(ll n,ll C)
		{
			ll l,r,d,p=1;
			l=rnd()%(n-2)+2,r=l;
			nxt(r,C,n);
			int cnt=0;
			while (l^r)
			{
				p=(lll)p*llabs(l-r)%n;
				if (!p) return gcd(n,llabs(l-r));
				++cnt;
				if (cnt==127)
				{
					cnt=0;
					d=gcd(llabs(l-r),n);
					if (d>1) return d;
				}
				nxt(l,C,n); nxt(r,C,n); nxt(r,C,n);
			}
			return gcd(n,p);
		}
		vector<pa> w;
		vector<ll> d;
		void dfs(ll n,int cnt)
		{
			if (n==1) return;
			if (prime(n)) return w.emplace_back(n,cnt),void();
			ll p=n,C=rnd()%(n-1)+1;
			while (p==1||p==n) p=find(n,C++);
			int r=1; n/=p;
			while (n%p==0) n/=p,++r;
			dfs(p,r*cnt); dfs(n,cnt);
		}
		vector<pa> getw(ll n)
		{
			w=vector<pa>(0); dfs(n,1);
			if (n==1) return w;
			sort(w.begin(),w.end());
			int i,j;
			for (i=1,j=0; i<w.size(); i++) if (w[i].first==w[j].first) w[j].second+=w[i].second; else w[++j]=w[i];
			w.resize(j+1);
			return w;
		}
		void dfss(int x,ll n)
		{
			if (x==w.size()) return d.push_back(n),void();
			dfss(x+1,n);
			for (int i=1; i<=w[x].second; i++) dfss(x+1,n*=w[x].first);
		}
		vector<ll> getd(ll n)
		{
			if (n==0) return {0};
			getw(n); d=vector<ll>(0); dfss(0,1);
			sort(d.begin(),d.end());
			return d;
		}
	}
	using rho::getw,rho::getd;
	using miller::prime;
}
using pr::getw,pr::getd;
typedef __int128 lll;
const ll inf=1e10;
int sgn(ll x) { return x>0?1:-1; }
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;
		vector<ll> a(n),b(n);
		cin>>a>>b;
		sort(all(a)); sort(all(b));
		reverse(all(a)); reverse(all(b));
		vector<ll> v;
		for (i=0; i<n; i++) for (int j:{-1,1}) for (int k:{-1,1}) v.push_back(a[0]*j+b[i]*k);
		sort(all(v)); v.resize(unique(all(v))-v.begin());
		vector<ll> h(n);
		ll p2;
		for (ll p:v)
		{
			// dbg(p);
			multiset<ll> s(all(b));
			for (i=0; i<n; i++)
			{
				bool flg=0;
				for (ll d:{-sgn(p)*a[i],sgn(p) *a[i]}) if (s.find(abs(d-p))!=s.end())
				{
					flg=1;
					s.erase(s.find(abs(d-p)));
					h[i]=d;
					break;
				}
				if (!flg) break;
			}
			if (i==n) { p2=p; goto yes; }
		}
		cout<<"NO\n"; continue;
		yes:cout<<"YES\n";
		ll p1=0;
		ll mn=min({p1,p2,*min_element(all(h))});
		for (ll &x:h) x-=mn;
		p1-=mn; p2-=mn;
		assert((max({p1,p2,*max_element(all(h))})<=2'000'000'000));
		cout<<h<<'\n'<<p1<<' '<<p2<<'\n';
	}
}