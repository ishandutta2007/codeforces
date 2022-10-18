#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt","sse3","sse2","sse","avx","sse4","sse4.1","sse4.2","ssse3","f16c","fma","avx2","xop","fma4")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
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
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	string s;
	cin>>s;
	int n=s.size(),i,j;
	vector<int> nxt(n+10,-1);
	vector<array<int,26>> f(n+10,array<int,26>{});
	for (i=0; i<n+10; i++) fill(all(f[i]),-2);
	i,j=-1;
	for (i=1; i<n; i++)
	{
		while (j!=-1&&s[i]!=s[j+1]) j=nxt[j];
		nxt[i]=j+=s[i]==s[j+1];
	}
	int kk=j;
	int q;
	cin>>q;
	while (q--)
	{
		string t;
		cin>>t;
		int m=t.size();
		int k=kk;
		s+=t;
		for (i=max(0,n-15); i<n+m; i++) fill(all(f[i]),-2);
		function<int(int,int)> F=[&](int x,int c)
		{
			if (x==-1) return x;
			if (f[x][c]!=-2) return f[x][c];
			if (s[x+1]-'a'==c) return f[x][c]=x;
			return f[x][c]=F(nxt[x],c);
		};
		for (i=1; i<=m; i++)
		{
			k=F(k,t[i-1]-'a');
			nxt[n+i-1]=(k+=t[i-1]==s[k+1]);
		}
		for (i=0; i<m; i++) cout<<1+nxt[n+i]<<" \n"[i+1==m],nxt[n+i]=-1,s.pop_back();
	}
}