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
vector<int> lg(2);
template <typename T> struct mintable
{
	vector<T> a;
	vector<vector<T>> st;
	mintable(const vector<T> &b):a(all(b))
	{
		int n=a.size(),i,j,k,r;
		while (lg.size()<=n) lg.push_back(lg[lg.size()>>1]+1);
		st.assign(lg[n]+1,vector<T>(n));
		iota(all(st[0]),0);
		for (j=1;j<=lg[n];j++)
		{
			r=n-(1<<j);
			k=1<<j-1;
			for (i=0;i<=r;i++) st[j][i]=a[st[j-1][i]]<a[st[j-1][i+k]]?st[j-1][i]:st[j-1][i+k];
		}
	}
	T rmq(int l,int r) const
	{
		assert(0<=l&&l<=r&&r<a.size());
		int z=lg[r-l+1];
		return min(a[st[z][l]],a[st[z][r-(1<<z)+1]]);
	}
	int rmp(int l,int r) const
	{
		assert(0<=l&&l<=r&&r<a.size());
		int z=lg[r-l+1];
		return a[st[z][l]]<a[st[z][r-(1<<z)+1]]?st[z][l]:st[z][r-(1<<z)+1];
	}
};
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
		for (j=1;j<=lg[n];j++)
		{
			r=n-(1<<j);
			k=1<<j-1;
			for (i=0;i<=r;i++) st[j][i]=a[st[j-1][i]]<a[st[j-1][i+k]]?st[j-1][i+k]:st[j-1][i];
		}
	}
	T rmq(int l,int r) const
	{
		assert(0<=l&&l<=r&&r<a.size());
		int z=lg[r-l+1];
		return max(a[st[z][l]],a[st[z][r-(1<<z)+1]]);
	}
	int rmp(int l,int r) const
	{
		assert(0<=l&&l<=r&&r<a.size());
		int z=lg[r-l+1];
		return a[st[z][l]]<a[st[z][r-(1<<z)+1]]?st[z][r-(1<<z)+1]:st[z][l];
	}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,r=0;
		cin>>n;
		vector<int> a(n);
		cin>>a;
		maxtable s(a);
		mintable t(a);
		i=0;
		while (i<n-1)
		{
			j=i+1;
			if (a[j]>a[i])
			{
				int l=j,r=n-1,m;
				while (l<r)
				{
					m=l+r+1>>1;
					if (t.rmq(i,m)>=a[i]) l=m; else r=m-1;
				}
				i=s.rmp(i,l);
			}
			else
			{
				int l=j,r=n-1,m;
				while (l<r)
				{
					m=l+r+1>>1;
					if (s.rmq(i,m)<=a[i]) l=m; else r=m-1;
				}
				i=t.rmp(i,l);
			}
			++r;
		}
		cout<<r<<'\n';
	}
}