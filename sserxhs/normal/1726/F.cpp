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
namespace chtholly_tree
{
	typedef int TT;
	struct Q
	{
		int l;
		mutable int r;
		mutable TT v;
		int len() const { return r-l+1; }
		bool operator<(const Q &x) const { return l<x.l; }
	};
	void add(const Q &a) {}
	void del(const Q &a) {}
	class odt: public set<Q>
	{
	public:
		typedef odt::iterator iter;
		iter split(int x)
		{
			iter it=lower_bound({x});
			if (it!=end()&&it->l==x) return it;
			Q t=*--it,a={t.l,x-1,t.v},b={x,t.r,t.v};
			del(*it); add(a); add(b);
			erase(it); insert(a);
			return insert(b).first;
		}
		void modify(int l,int r,TT v)//[l,r]
		{
			iter lt,rt,it;
			rt=r==rbegin()->r?end():split(r+1); lt=split(l);//[lt,rt)
			while (lt!=begin()&&(it=prev(lt))->v==v) l=(lt=it)->l;
			while (rt!=end()&&rt->v==v) r=(rt++)->r;
			for (it=lt; it!=rt; it++) del(*it);
			add({l,r,v});
			erase(lt,rt); insert({l,r,v});
		}
		TT operator[](const int x) const { return prev(upper_bound({x}))->v; }
	};
}
using chtholly_tree::Q,chtholly_tree::odt;
typedef odt::iterator iter;
const int N=2e5+5;
int g[N],c[N],d[N];
ll sd[N],f[N];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,t,i,j;
	cin>>n>>t;
	auto norm=[&](ll x)
	{
		return (x%t+t)%t;
	};
	for (i=1; i<=n; i++) cin>>g[i]>>c[i];
	for (i=2; i<=n; i++) cin>>d[i];
	for (i=2; i<=n; i++) sd[i]=sd[i-1]+d[i];
	odt s;
	s.insert({0,t-1,0});
	for (i=n; i; i--)
	{
		int T=norm(-sd[i]-c[i]);
		int x=s[T];
		if (x)
		{
			int now=norm(sd[x]+c[x]-sd[i]-c[i]);
			assert(now>=g[x]);
			f[i]=f[x]+t-now;
		}
		int L=norm(g[i]-sd[i]-c[i]),R=norm(-sd[i]-c[i]-1);
		if (L<=R) s.modify(L,R,i);
		else s.modify(L,t-1,i),s.modify(0,R,i);
	}
	ll ans=1e18;
	for (auto [l,r,v]:s) if (!v) ans=0; else
	{
		int x=v;
		ll now=norm(l+sd[x]+c[x]);
		ans=min(ans,(now>=g[x]?t-now:0)+f[v]);
		now=norm(r+sd[x]+c[x]);
		ans=min(ans,(now>=g[x]?t-now:0)+f[v]);
	}
	cout<<sd[n]+ans<<endl;
}