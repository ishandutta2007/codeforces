//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC> istream & operator>>(istream &in,vector<typC> &a)
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
template<typename T> struct tork
{
	vector<T> a;
	int n;
	tork(const vector<T> &b):a(all(b))
	{
		sort(all(a));
		a.resize(unique(all(a))-a.begin());
		n=a.size();
	}
	tork(const T* first,const T* last):a(first,last)
	{
		sort(all(a));
		a.resize(unique(all(a))-a.begin());
		n=a.size();
	}
	void get(T &x) {x=lower_bound(all(a),x)-a.begin();}
	T operator[](const int &x) {return a[x];}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,ans=1,l=0,r=0,xx;
		cin>>n;
		vector<int> a(n);
		for (int &x:a) cin>>x;xx=a[0];
		tork s(a);
		for (int &x:a) s.get(x);
		m=s.a.size();
		vector<vector<int>> p(m);
		for (i=0;i<n;i++) p[a[i]].push_back(i);
		for (i=0;i<m;i++) if (p[i].size())
		{
			n=p[i].size();auto &v=p[i];
			vector<int> sum(n);
			int lst=0,L=0;
			for (j=0;j<n;j++) sum[j]=j-(v[j]-j);
			for (j=0;j<n;j++)
			{
				if (sum[j]-lst+1>ans)
				{
					ans=sum[j]-lst+1;
					l=L;
					r=v[j];
					xx=s[i];
				}
				if (lst>sum[j])
				{
					lst=sum[j];
					L=v[j];
				}
			} 
		}
		cout<<xx<<' '<<l+1<<' '<<r+1<<'\n';
	}
}