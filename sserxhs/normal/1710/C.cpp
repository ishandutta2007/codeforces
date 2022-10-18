//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a){for (auto &x:a) cin>>x;return cin;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a){for (auto &x:a) cout<<x<<'\n';return cout;}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a){int n=a.size();if (!n) return cout;cout<<a[0];for (int i=1;i<n;i++) cout<<' '<<a[i];return cout;}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
const ui p=998244353;
int a[N];
ui f[N][2][2][2];
void inc(ui &x,const ui &y) {if ((x+=y)>=p) x-=p;}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i,j,k;
	ui tot=0;
	{
		string s;
		cin>>s;
		n=s.size();
		for (i=0;i<n;i++) a[i]=s[i]-'0',tot=(tot*2+a[i])%p;
		++tot;
	}
	// int tt=0;
	// for (i=0;i<tot;i++) for (j=0;j<tot;j++) for (k=0;k<tot;k++) if (((i^j)&(j^k))==0) ++tt;
	// dbg(tt);
	f[0][1][1][1]=1;
	for (i=0;i<n;i++) if (a[i])
	{
		int j,k,l,x,y,z;
		for (j=0;j<2;j++) for (k=0;k<2;k++) for (l=0;l<2;l++)
		for (x=0;x<2;x++) for (y=0;y<2;y++) for (z=0;z<2;z++)
		if (x==y||y==z)
		inc(f[i+1][j&&x][k&&y][l&&z],f[i][j][k][l]);
	}
	else
	{
		int j,k,l,x,y,z;
		for (j=0;j<2;j++) for (k=0;k<2;k++) for (l=0;l<2;l++)
		for (x=0;x<2-j;x++) for (y=0;y<2-k;y++) for (z=0;z<2-l;z++)
		if (x==y||y==z)
		inc(f[i+1][j][k][l],f[i][j][k][l]);
	}
	ui r=0;
	for (i=0;i<2;i++) for (j=0;j<2;j++) for (k=0;k<2;k++) r=(r+f[n][i][j][k])%p;
	r=r*3%p;
	// dbg(r);
	r=(r+(ll)(p-3)*tot%p*tot+tot)%p;
	// dbg(r);
	tot=(ll)tot*tot%p*tot%p;
	r=(tot+p-r)%p;
	cout<<r<<endl;
}