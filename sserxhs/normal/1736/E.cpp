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
vector<int> lg(2);
template <typename T> struct maxtable
{
	vector<T> a;
	vector<vector<T>> st;
	maxtable(const vector<T> &b):a(all(b))
	{
		int n=a.size(),i,j,k,r;
		while (lg.size()<=n) lg.push_back(lg[lg.size()>>1]+1);
		st.assign(lg[n]+1,vector<T>(n));
		iota(all(st[0]),0);
		for (j=1; j<=lg[n]; j++)
		{
			r=n-(1<<j);
			k=1<<j-1;
			for (i=0; i<=r; i++) st[j][i]=a[st[j-1][i]]<a[st[j-1][i+k]]?st[j-1][i+k]:st[j-1][i];
		}
	}
	T rmq(int l,int r) const
	{
		assert(0<=l&&l<=r&&r<a.size());
		int z=lg[r-l+1];
		return max(a[st[z][l]],a[st[z][r-(1<<z)+1]]);
	}
};
const int inf=1e9;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i,j,k,l;
	cin>>n;
	vector<int> a(n),s(n+1);
	vector f(n+1,vector(n+1,vector(n+1,-inf)));
	cin>>a;
	for (i=0; i<n; i++) s[i+1]=s[i]+a[i];
	maxtable t(a);
	f[0][0][0]=0;
	f[1][1][0]=a[0];
	f[1][0][1]=a[1];
	for (i=1; i<n; i++)
	{
		for (j=0; j<=i; j++)
		{
			for (k=0; k<i; k++)
			{
				cmax(f[i+1][j+1][i],f[i][j][k]+a[i]);
				cmax(f[i+1][j][k],f[i][j][k]+a[k]);
			}
			for (k=i; k<n; k++)
			{
				cmax(f[i+1][j+1][k],f[i][j][k]);
				cmax(f[i+1][j][k],f[i][j][k]+a[k]);
			}
		}
		vector g(n+1,-inf);
		for (j=0; j<=i; j++) g[j]=*max_element(all(f[i][j]));
		for (j=0; j<=i; j++) for (k=i+1; k<n&&k-i-1<=j; k++)
		{
			cmax(f[i+1][j-(k-i-1)][k],g[j]+a[k]);
		}
	}
	// for (i=0; i<=n; i++) for (j=0; j<=i; j++) cerr<<f[i][j]<<" \n"[j==i];
	// dbg(f);
	int res=0;
	for (auto &v:f[n]) cmax(res,*max_element(all(v)));
	cout<<res<<endl;
}