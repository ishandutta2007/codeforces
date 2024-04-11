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
const ui p=998244353;
void inc(ll &x,const ll &y) { if ((x+=y)>=p) x-=p; }
void dec(ll &x,const ll &y) { if ((x+=p-y)>=p) x-=p; }
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
	matrix(char c,ui ways[n+1][n+1]):a{}
	{
		int i,j,k;
		ll tot=0;
		for (i=1; i<=n; i++) for (j=i-1; j<n; j++) tot+=ways[i][j];
		for (i=0; i<n; i++) a[i][i]=tot;
		static ll d[n],dd[n][n];
		memset(d,0,sizeof d);
		memset(dd,0,sizeof dd);
		for (i=1; i<n; i++) for (j=i; j<n; j++)
		{
			dec(d[i-1],ways[i][j]);
			inc(d[j],ways[i][j]);
			inc(dd[i-1][j],ways[i][j]);
			dec(dd[j][j],ways[i][j]);
		}
		for (i=1; i<n; i++) inc(d[i],d[i-1]);
		for (i=0; i<n; i++) inc(a[i][i],d[i]);
		for (j=0; j<n; j++)
		{
			for (i=1; i<=j; i++) inc(dd[i][j],dd[i-1][j]);
			for (i=0; i<=j; i++) inc(a[i][j],dd[i][j]);
		}
	}
	matrix operator+(const matrix &o) const
	{
		matrix r;
		int i,j,k;
		for (k=0; k<n; k++)
		{
			for (i=0; i<n; i++) for (j=0; j<n; j++) r.a[i][j]+=a[i][k]*o.a[k][j];
			if (k==n-1) for (i=0; i<n; i++) for (j=0; j<n; j++) r.a[i][j]%=p;
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
const int N=3e5+5,M=17;
int l[N],pos[M];
ui pre[N][M],suf[N][M];
ui f[M+1][M+1];
int d,m;
void cal(int p)
{
	memset(f,0,sizeof f);
	int i,j;
	int x=lower_bound(pos+1,pos+m+1,p)-pos,cur=0;
	i=x-1; j=x;
	while (i>=1&&j<=m)
	{
		if (p-pos[i]<pos[j]-p)
		{
			f[i+1][j-1]=(p-pos[i])-cur;
			cur=p-pos[i];
			--i;
		}
		else if (p-pos[i]>pos[j]-p)
		{
			f[i+1][j-1]=(pos[j]-p)-cur;
			cur=pos[j]-p;
			++j;
		}
		else
		{
			f[i+1][j-1]=(pos[j]-p)-cur;
			cur=pos[j]-p;
			++j; --i;
		}
	}
	while (i>=1)
	{
		f[i+1][j-1]=(p-pos[i])-cur;
		cur=p-pos[i];
		--i;
	}
	while (j<=m)
	{
		f[i+1][j-1]=(pos[j]-p)-cur;
		cur=pos[j]-p;
		++j;
	}
	f[i+1][j-1]=d-cur+1;
}
int id[N];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i,j,k;
	cin>>d>>n>>m;
	for (i=1; i<=n; i++) cin>>l[i];
	for (i=1; i<=m; i++) cin>>pos[i];
	sort(pos+1,pos+m+1);
	int q;
	for (i=1; i<=n; i++) id[l[i]]=i;
	matrix<M> tmp('E');
	for (i=0; i<=d; i++)
	{
		if (id[i]) cal(i),tmp=tmp+matrix<M>('S',f);
		for (j=0; j<M; j++) pre[i][j]=tmp.a[0][j];
	}
	tmp=matrix<M>('E');
	for (i=d; i>=0; i--)
	{
		if (id[i]) cal(i),tmp=matrix<M>('S',f)+tmp;
		for (j=0; j<M; j++) suf[i][j]=tmp.a[j][m];
	}
	cin>>q;
	while (q--)
	{
		int np;
		cin>>np;
		cal(np);
		matrix<M> tmp('S',f);
		ui res=0;
		for (i=0; i<M; i++) for (j=0; j<M; j++) res=(res+(ll)pre[np-1][i]*tmp.a[i][j]%p*suf[np+1][j])%p;
		cout<<res<<'\n';
	}
}