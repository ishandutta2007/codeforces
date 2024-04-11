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
struct Q
{
	int x;
	ll y;
	bool operator==(const Q &o) const {return x==o.x&&y==o.y;}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,q,i,j;
		cin>>n>>q;
		vector<int> a(n);
		cin>>a;
		cin>>m;
		vector<int> b(m);
		cin>>b;
		vector<Q> st,stt;
		for (int x:a)
		{
			Q b={x,1};
			while (b.x%q==0) b.x/=q,b.y*=q;
			if (st.size()&&st.back().x==b.x) st.back().y+=b.y; else st.push_back(b);
		}
		stt=st;st.clear();
		for (int x:b)
		{
			Q b={x,1};
			while (b.x%q==0) b.x/=q,b.y*=q;
			if (st.size()&&st.back().x==b.x) st.back().y+=b.y; else st.push_back(b);
		}
		if (st==stt) cout<<"Yes\n"; else cout<<"No\n";
	}
}