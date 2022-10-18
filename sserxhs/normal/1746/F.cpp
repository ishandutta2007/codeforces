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
const int N=3e5+5;
mt19937 rnd(345);
map<int,ui> mp;
ui hs(int x)
{
	if (mp.count(x)) return mp[x];
	return mp[x]=rnd();
}
struct Q
{
	ui op,l,r,k;
};
template<typename typC> struct bit
{
	vector<typC> a;
	int n;
	bit() {}
	bit(int nn):n(nn),a(nn+1) {}
	template<typename T> bit(int nn,T *b):n(nn),a(nn+1)
	{
		for (int i=1; i<=n; i++) a[i]=b[i];
		for (int i=1; i<=n; i++) if (i+(i&-i)<=n) a[i+(i&-i)]+=a[i];
	}
	void add(int x,typC y)
	{
		++x;
		//cerr<<"add "<<x<<" by "<<y<<endl;
		assert(1<=x&&x<=n);
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y;
	}
	typC sum(int x)
	{
		++x;
		//cerr<<"sum "<<x;
		assert(0<=x&&x<=n);
		typC r=a[x];
		while (x^=x&-x) r+=a[x];
		//cerr<<"= "<<r<<endl;
		return r;
	}
	typC sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m,i,j;
	cin>>n>>m;
	vector<ui> a(n);
	cin>>a;
	for (ui &x:a) x=hs(x);
	auto b=a;
	vector<Q> q(m);
	for (auto &[op,l,r,k]:q)
	{
		cin>>op>>l>>r; --l;
		if (op==2) cin>>k,--r; else r=hs(r);
	}
	int W=32;
	vector s(W,bit<int>(n));
	for (i=0; i<n; i++)
	{
		for (j=0; j<W; j++) if (a[i]>>j&1) s[j].add(i,1);
	}
	for (auto [op,l,r,k]:q)
	{
		if (op==1)
		{
			for (i=0; i<W; i++) if (a[l]>>i&1) s[i].add(l,-1);
			a[l]=r;
			for (i=0; i<W; i++) if (a[l]>>i&1) s[i].add(l,1);
		}
		else
		{
			bool flg=0;
			if ((r-l+1)%k==0)
			{
				flg=1;
				for (auto &t:s)  if (t.sum(l,r)%k)
				{
					flg=0;
					break;
				}
			}
			if (flg) cout<<"YES\n"; else cout<<"NO\n";
		}
	}
}