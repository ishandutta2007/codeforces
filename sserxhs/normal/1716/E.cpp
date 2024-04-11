//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,i,j;
	cin>>n;
	vector<int> a(1<<n);
	vector<vector<ll>> ls(4<<n),rs(4<<n),s(4<<n);
	vector<ll> sum(4<<n);
	cin>>a;
	function<void(int,int,int)> build=[&](int x,int l,int r){
		if (l+1==r)
		{
			ls[x]=rs[x]=s[x]={max(0,a[l])};
			sum[x]=a[l];
			return;
		}
		int m=l+r>>1,c=x*2,len=r-l>>1;
		build(c,l,m); build(c+1,m,r);
		s[x].resize(len<<1); ls[x].resize(len<<1); rs[x].resize(len<<1);
		sum[x]=sum[c]+sum[c+1];
		for (i=0; i<len; i++)
		{
			s[x][i]=max({s[c][i],s[c+1][i],rs[c][i]+ls[c+1][i]});
			ls[x][i]=max(ls[c][i],sum[c]+ls[c+1][i]);
			rs[x][i]=max(rs[c+1][i],sum[c+1]+rs[c][i]);
		}
		for (i=0; i<len; i++)
		{
			s[x][i|len]=max({s[c][i],s[c+1][i],rs[c+1][i]+ls[c][i]});
			ls[x][i|len]=max(ls[c+1][i],sum[c+1]+ls[c][i]);
			rs[x][i|len]=max(rs[c][i],sum[c]+rs[c+1][i]);
		}
		// dbg(x,l,r,s[x],ls[x],rs[x]);
	};
	build(1,0,1<<n);
	int q,sta=0;
	cin>>q;
	while (q--)
	{
		int x;
		cin>>x;
		sta^=1<<x;
		// dbg(sta,s[1].size());
		cout<<s[1][sta]<<'\n';
	}
}