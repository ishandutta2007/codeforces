//114514min
//ACM 
#pragma GCC target("popcnt")
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
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
const ui N=1<<17;
const ui p=998244353;
ui f[N][18],mi[18][1003];
void inc(ui &x,const ui &y) {if ((x+=y)>=p) x-=p;}
ui ksm(ui x,int y)
{
	ui r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i,j,m,k,qs=0;
	for (i=1;i<=17;i++)
	{
		mi[i][0]=1;
		for (j=1;j<=1000;j++) mi[i][j]=(ll)mi[i][j-1]*i%p;
	}
	string S;
	ui tot=0,l;
	cin>>n>>S;
	vector<int> a(n*2-1);
	a[0]=S[0]=='?'?20:S[0]-'a';
	for (i=1;i<n;i++) a[i*2-1]=21,a[i*2]=S[i]=='?'?20:S[i]-'a';
	n=n*2-1;
	for (int x:a) qs+=x==20;
	//for (i=0;i<n;i++) cerr<<a[i]<<" \n"[i+1==n];
	for (i=0;i<n;i++)
	{
		int mask=0,cnt=0,res=qs;
		for (int l=i,r=i;l>=0&&r<n;l--,r++) if (a[l]!=21)
		{
			res-=(a[l]==20)+(l<r&&a[r]==20);
			if (a[l]!=a[r])
			{
				if (max(a[l],a[r])==20) mask|=1<<min(a[l],a[r]); else break;
			}
			else cnt+=a[l]==20;
			//dbgn(l,r,mask,cnt);
			for (j=__builtin_popcount(mask);j<18;j++) inc(f[mask][j],mi[j][cnt+res]);
		}
	}
	//for (i=0;i<4;i++) cout<<f[i][2]<<" \n"[i+1==4];
	for (j=1;j<N;j<<=1) for (k=0;k<N;k+=j<<1) for (i=0;i<j;i++) for (l=__builtin_popcount(k|i);l<18;l++) inc(f[k|i|j][l],f[k|i][l]);
	//for (i=0;i<4;i++) cout<<f[i][2]<<" \n"[i+1==4];
	cin>>m;
	while (m--)
	{
		string s;
		cin>>s;
		int mask=0;
		for (auto c:s) mask|=1<<c-'a';
		cout<<f[mask][s.size()]<<'\n';
	}
}