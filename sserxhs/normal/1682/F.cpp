//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<typC,typD> &a)
{
	for (auto &x:a) cout<<x<<'\n';
	return cout;
}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a)
{
	int n=a.size(),i;
	if (!n) return cout;
	cout<<a[0];
	for (i=1;i<n;i++) cout<<' '<<a[i];
	return cout;
}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int p=1e9+7;
const int N=2e5+5;
int a[N],sa[N],cnt[N],tb[N];
ll b[N],ans[N],dj[N],ori[N],c[N],sc[N];
template<typename typC> struct bit
{
	vector<typC> a;
	int n;
	bit(){}
	bit(int nn):n(nn),a(nn+1){}
	template<typename T> bit(int nn,T *b):n(nn),a(nn+1)
	{
		for (int i=1;i<=n;i++) a[i]=b[i];
		for (int i=1;i<=n;i++) if (i+(i&-i)<=n) a[i+(i&-i)]+=a[i];
	}
	void clear() {fill(all(a),0);}
	void add(int x,typC y)
	{
		//cerr<<"add "<<x<<" by "<<y<<endl;
		assert(1<=x&&x<=n);
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y; 
	}
	typC sum(int x)
	{
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
struct Q
{
	int l,r,pos;
	ll ord,val;
	bool operator<(const Q &o) const {return ord>o.ord;}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m,i,j;
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++) a[i]=a[i+1]-a[i];
	for (i=1;i<=n;i++) sa[i]=sa[i-1]+a[i];
	for (i=1;i<=n;i++) cin>>b[i],b[i]+=b[i-1];
	for (i=1;i<=n;i++) tb[i]=((ll)p*p+b[i])%p;
	for (i=1;i<=n;i++) sc[i]=sc[i-1]+(c[i]=(ll)a[i]*tb[i]%p);
	vector<Q> d,e;
	for (i=1;i<n;i++)
	{
		d.push_back({i,i,0,b[i],a[i]});
		e.push_back({i,i,0,b[i],c[i]});
	}
	for (i=1;i<=m;i++)
	{
		int l,r;
		cin>>l>>r;
		--r;
		ans[i]=((ll)(sa[r]-sa[l-1])*tb[l-1]+(ll)p*p+sc[l-1]-sc[r])%p;
		e.push_back({l,r,i,b[l-1],2});
		d.push_back({l,r,i,b[l-1],(ll)(p-2)*tb[l-1]%p});
		//ll cur=0;
		//for (j=l;j<=r;j++) cur+=a[j]*(b[j]-b[l-1])*2*(b[j]>b[l-1]);
		//cout<<ans[i]+cur<<endl;
	}
	sort(all(d));sort(all(e));
	bit<ll> s(n);
	for (auto [l,r,pos,ord,val]:d) if (pos)
	{
		ans[pos]=(ans[pos]+s.sum(l,r)%p*val)%p;
	}
	else
	{
		s.add(l,val);
	}
	s.clear();
	for (auto [l,r,pos,ord,val]:e) if (pos)
	{
		ans[pos]=(ans[pos]+s.sum(l,r)%p*val)%p;
	}
	else
	{
		s.add(l,val);
	}
	for (i=1;i<=m;i++) cout<<ans[i]<<'\n';
}