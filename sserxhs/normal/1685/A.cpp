//114514min
//ACM 
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
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;
		vector<int> a(n),b(n);
		for (int &x:a) cin>>x;
		sort(all(a));j=0;
		for (i=0;i<n;i+=2) b[i]=a[j++];
		for (i=1;i<n;i+=2) b[i]=a[j++];
		b.push_back(b[0]);
		for (i=1;i<n;i++) if (b[i]>b[i-1]&&b[i]>b[i+1]||b[i]<b[i-1]&&b[i]<b[i+1]); else break;
	//	dbg(b);
		if (i==n)
		{
			cout<<"YES\n";
			for (i=0;i<n;i++) cout<<b[i]<<" \n"[i==n-1];
		} else cout<<"NO\n";
	}
}