//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a)
{
	for (auto &x:a) cin>>x;
	return cin;
}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a)
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
const int N=1e6+5;
const int inf=1e9;
template<typename T,int n> struct matrix
{
	#define all(x) (x).begin(),(x).end()
	array<pair<int,T>,n> a;
	matrix(int L=0,int R=0)
	{
		if (L||R)
		{
			if (L&&R)
			{
				a[0]={0,1};
				a[1]={0,0};
				a[2]={0,0};
			}
			else if (L)
			{
				a[0]={1,1};
				a[1]={1,0};
				a[2]={0,0};
			}
			else
			{
				a[0]={2,1};
				a[1]={0,0};
				a[2]={2,0};
			}
		}
		else
		{
			a[0]={0,0};
			a[1]={1,0};
			a[2]={2,0};
		}
	}
	matrix operator+(const matrix &o) const
	{
		matrix r;
		int i,j,k;
		for (i=0;i<n;i++)
		{
			auto [x,y]=a[i];
			r.a[i]={o.a[x].first,o.a[x].second+y};
		}
		return r;
	}
};
//#define revsum
template<typename T> struct sgt_nt
{
	int L,R,n;
	vector<int> _ys;
	int *ys;
	T *a;
	vector<T> _s;
	T *s;
	#ifdef revsum
	vector<T> _rs;
	T *rs;
	#endif
	int z,y,fir;
	T dt;
private:
	void build(int x,int l,int r)
	{
		if (l==r)
		{
			ys[l]=x;
			s[x]=a[l];
			#ifdef revsum
			rs[x]=a[l];
			#endif
			return;
		}
		int c=x*2,m=l+r>>1;
		build(c,l,m);build(c+1,m+1,r);
		s[x]=s[c]+s[c+1];
		#ifdef revsum
		rs[x]=rs[c+1]+rs[c];
		#endif
	}
	void init(int n)
	{
		_ys.resize(n+1);ys=_ys.data();
		n<<=2;
		_s.resize(n);s=_s.data();
		#ifdef revsum
		_rs.resize(n);rs=_rs.data();
		#endif
	}
public: 
	sgt_nt(T b,int lt,int rt)
	{
		assert(lt<=rt);
		L=lt;R=rt;init(n=R-L+1);
		vector<T> _a(n,b);
		a=_a.data()-1;
		build(1,1,n);
	}
	sgt_nt(T *b,int lt,int rt)
	{
		assert(lt<=rt);
		L=lt;R=rt;init(n=R-L+1);
		a=b+L-1;
		build(1,1,n);
	}
	void modify(int p,T b)
	{
		assert(L<=p&&p<=R);
		//cerr<<"modify "<<p<<" to "<<b<<endl;
		p=ys[p-L+1];
		s[p]=b;
		#ifdef revsum
		rs[p]=b;
		#endif
		while (p>>=1)
		{
			s[p]=s[p*2]+s[p*2+1];
			#ifdef revsum
			rs[p]=rs[p*2+1]+rs[p*2];
			#endif
		}
	}
private: void ask_sum(int x,int l,int r)
	{
		if (z<=l&&r<=y)
		{
			dt=fir?s[x]:dt+s[x];
			fir=0;
			return;
		}
		int c=x*2,m=l+r>>1;
		if (z<=m) ask_sum(c,l,m);
		if (y>m) ask_sum(c+1,m+1,r);
	}
public: T ask_sum(int l,int r)
	{
		assert(L<=l&&l<=r&&r<=R);
		z=l-L+1;y=r-L+1;fir=1;
		ask_sum(1,1,n);
		//cerr<<"sum of ["<<l<<','<<r<<"] = "<<dt<<endl;
		return dt;
	}
	#ifdef revsum
	private: void ask_revsum(int x,int l,int r)
	{
		if (z<=l&&r<=y)
		{
			dt=fir?rs[x]:dt+rs[x];
			fir=0;
			return;
		}
		int c=x*2,m=l+r>>1;
		if (y>m) ask_revsum(c+1,m+1,r);
		if (z<=m) ask_revsum(c,l,m);
	}
public: T ask_revsum(int l,int r)
	{
		assert(L<=r&&r<=l&&l<=R);
		z=r-L+1;y=l-L+1;fir=1;
		ask_revsum(1,1,n);
		//cerr<<"revsum of ["<<l<<','<<r<<"] = "<<dt<<endl;
		return dt;
	}
	#endif
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i;
	cin>>n;
	vector<int> a(n),r(n+1),l(n+1);
	for (int &x:a) cin>>x,++r[x];
	l[0]=1;++r[0];
	vector<matrix<int,3>> b;
	for (i=0;i<=n;i++) b.emplace_back(l[i],r[i]);
	sgt_nt s(b.data(),0,n);
	ll ans=0;
	for (int x:a) if (x)
	{
		ans+=s.ask_sum(1,x).a[0].second;
		++l[x];--r[x];
		if (l[x]==1||r[x]==0) s.modify(x,matrix<int,3>(l[x],r[x]));
	}
	cout<<ans<<endl;
}