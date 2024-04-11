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
const ui p=1e9+7;
void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
const int N=505;
int nxt[N];
struct Q
{
	ui x,y;
	Q operator+(const int &z) { return {x+z,y}; }
	void operator+=(const Q &o)
	{
		if (x==o.x) inc(y,o.y);
		else if (x>o.x) *this=o;
	}
};
Q f[2][N][N];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j,k;
		string s,t;
		cin>>s>>t; n=s.size(); m=t.size();
		s=' '+s; t=' '+t;
		if (m>n) { cout<<"0 1\n"; continue; }
		nxt[1]=0; j=0;
		for (i=2; i<=m; i++)
		{
			while (j&&t[j+1]!=t[i]) j=nxt[j];
			nxt[i]=j+=(t[j+1]==t[i]);
		}
		f[0][0][0]={0,1};
		for (i=0; i<n; i++)
		{
			int x=i&1,y=x^1;
			for (j=0; j<=n+1; j++) for (k=0; k<=n+1; k++) f[y][j][k]={p,0};
			for (j=0; j<=i&&j<m; j++)
			{
				int jj=j;
				while (jj&&s[i+1]!=t[jj+1]) jj=nxt[jj];
				if (jj+1==m&&s[i+1]==t[jj+1])
				{
					for (k=0; k<m; k++) f[y][0][0]+=f[x][j][k]+1;
					for (k=0; k<m-1; k++) f[y][nxt[m]][max(1,k+1)]+=f[x][j][k];
				}
				else
				{
					jj+=s[i+1]==t[jj+1];
					for (k=1; k<m-1; k++) f[y][jj][k+1]+=f[x][j][k];
					f[y][jj][0]+=f[x][j][0];
				}
			}
		}
		// for (i=1; i<=n; i++) for (j=0; j<=i&&j<m; j++) for (k=0; k<=m; k++) if (f[i][j][k].y) dbg(i,j,k,f[i][j][k].x,f[i][j][k].y);
		Q r={p,0};
		for (j=0; j<m; j++) r+=f[n&1][j][0];
		cout<<r.x<<' '<<r.y<<'\n';
	}
}