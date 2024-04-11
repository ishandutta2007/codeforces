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
// void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
// void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
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
		build(c,l,m); build(c+1,m+1,r);
		s[x]=s[c]+s[c+1];
#ifdef revsum
		rs[x]=rs[c+1]+rs[c];
#endif
	}
	void init(int n)
	{
		_ys.resize(n+1); ys=_ys.data();
		n<<=2;
		_s.resize(n); s=_s.data();
#ifdef revsum
		_rs.resize(n); rs=_rs.data();
#endif
	}
public:
	sgt_nt(T b,int lt,int rt)
	{
		assert(lt<=rt);
		L=lt; R=rt; init(n=R-L+1);
		vector<T> _a(n,b);
		a=_a.data()-1;
		build(1,1,n);
	}
	sgt_nt(T *b,int lt,int rt)
	{
		assert(lt<=rt);
		L=lt; R=rt; init(n=R-L+1);
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
	z=l-L+1; y=r-L+1; fir=1;
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
	z=r-L+1; y=l-L+1; fir=1;
	ask_revsum(1,1,n);
	//cerr<<"revsum of ["<<l<<','<<r<<"] = "<<dt<<endl;
	return dt;
}
#endif
};
const ll p=998244353;
template<int n> struct matrix
{
#define all(x) (x).begin(),(x).end()
	typedef unsigned int ui;
	typedef unsigned long long ll;
	array<array<ll,n>,n> a;
	matrix(char c='O')
	{
		int i;
		if (c=='O') for (i=0; i<n; i++) fill(all(a[i]),0);
		else if (c=='E') for (i=0; i<n; i++) fill(all(a[i]),0),a[i][i]=1;
		else assert(0);
	}
	matrix(char c,int x)
	{
		if (x==0)
		{
			a[0]={3,0};
			a[1]={1,2};
		}
		else
		{
			a[0]={1,2};
			a[1]={1,2};
		}
	}
	matrix operator+(const matrix &o) const
	{
		matrix r;
		int i,j,k;
		for (k=0; k<n; k++)
		{
			for (i=0; i<n; i++) for (j=0; j<n; j++) r.a[i][j]+=a[i][k]*o.a[k][j];
			if (k==n-1||(k&15)==15) for (i=0; i<n; i++) for (j=0; j<n; j++) r.a[i][j]%=p;
		}
		return r;
	}
	static_assert(numeric_limits<ll>::max()/(p-1)/(p-1)>=17);
};
template<int n> ostream &operator<<(ostream &cout,const matrix<n> &o)
{
	int i,j;
	for (i=0; i<n; i++) for (j=0; j<n; j++) cout<<o.a[i][j]<<" \n"[j+1==n];
	return cout;
}
const int N=3e5+5;
matrix<3> a[N];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i,m=3e5;
	cin>>n;
	vector<vector<int>> l(m+2),r(m+2);
	int L,R;
	for (i=1; i<=n; i++)
	{
		int x,y;
		cin>>x>>y;
		if (i==1) L=x,R=y;
		else
		{
			l[x].push_back(i);
			r[y+1].push_back(i);
		}
	}
	sgt_nt s(matrix<3>('0',0),2,n);
	ll res=0;
	for (i=0; i<=m; i++)
	{
		for (int x:l[i]) s.modify(x,matrix<3>(1,1));
		for (int x:r[i]) s.modify(x,matrix<3>(0,0));
		res+=s.ask_sum(2,n).a[L<=i&&i<=R][1];
	}
	cout<<res%p<<endl;
}